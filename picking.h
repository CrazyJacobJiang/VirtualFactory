#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class picking{

	picking(){

	}
public:
	static void ScreenPosToWorldRay(
		int mouseX, int mouseY,             // Mouse position, in pixels, from bottom-left corner of the window
		int screenWidth, int screenHeight,  // Window size, in pixels
		glm::mat4 ViewMatrix,               // Camera position and orientation
		glm::mat4 ProjectionMatrix,         // Camera parameters (ratio, field of view, near and far planes
		glm::vec3& out_direction            // Ouput : Direction, in world space, of the ray that goes "through" the mouse.
							)
	{
		glm::vec4 lRayEnd_NDC(
			((float)mouseX/(float)screenWidth  - 0.5f) * 2.0f,
			(0.5f - (float)mouseY/(float)screenHeight) * 2.0f,
			1.0f,
			1.0f
		);
		//逆矩阵inverse
		glm::vec4 ray_clip = glm::vec4(lRayEnd_NDC.x, lRayEnd_NDC.y, -1.0, 1.0);
		glm::vec4 ray_eye = glm::inverse(ProjectionMatrix) * ray_clip;

		ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);
		out_direction = glm::vec3(glm::inverse(ViewMatrix) * ray_eye);
		out_direction = glm::normalize(out_direction);
	}

//鼠标射线与包围盒检测测试
//经验证，鼠标与源码包围球、包围盒都能很好的完成拾取检测功能，主要原因是射线起点即摄像机位置出问题了。
	static  bool TestRayOBBIntersection(
		glm::vec3 ray_origin,        // Ray origin, in world space
		glm::vec3 ray_direction,     // Ray direction (NOT target position!), in world space. Must be normalize()'d.
		glm::vec3 aabb_min,          // Minimum X,Y,Z coords of the mesh when not transformed at all.
		glm::vec3 aabb_max,          // Maximum X,Y,Z coords. Often aabb_min*-1 if your mesh is centered, but it's not always the case.
		glm::mat4 ModelMatrix,       // Transformation applied to the mesh (which will thus be also applied to its bounding box)
		float& intersection_distance // Output : distance between ray_origin and the intersection with the OBB
	){
	
		// Intersection method from Real-Time Rendering and Essential Mathematics for Games
	
		float tMin = 0.0f;
		float tMax = 100000.0f;

		glm::vec3 OBBposition_worldspace(ModelMatrix[3].x, ModelMatrix[3].y, ModelMatrix[3].z);

		glm::vec3 delta = OBBposition_worldspace - ray_origin;

		// Test intersection with the 2 planes perpendicular to the OBB's X axis
		{
			glm::vec3 xaxis(ModelMatrix[0].x, ModelMatrix[0].y, ModelMatrix[0].z);
			float e = glm::dot(xaxis, delta);
			float f = glm::dot(ray_direction, xaxis);

			if ( fabs(f) > 0.001f ){ // Standard case

				float t1 = (e+aabb_min.x)/f; // Intersection with the "left" plane
				float t2 = (e+aabb_max.x)/f; // Intersection with the "right" plane
				// t1 and t2 now contain distances betwen ray origin and ray-plane intersections

				// We want t1 to represent the nearest intersection, 
				// so if it's not the case, invert t1 and t2
				if (t1>t2){
					float w=t1;t1=t2;t2=w; // swap t1 and t2
				}

				// tMax is the nearest "far" intersection (amongst the X,Y and Z planes pairs)
				if ( t2 < tMax )
					tMax = t2;
				// tMin is the farthest "near" intersection (amongst the X,Y and Z planes pairs)
				if ( t1 > tMin )
					tMin = t1;

				// And here's the trick :
				// If "far" is closer than "near", then there is NO intersection.
				// See the images in the tutorials for the visual explanation.
				if (tMax < tMin )
					return false;

			}else{ // Rare case : the ray is almost parallel to the planes, so they don't have any "intersection"
				if(-e+aabb_min.x > 0.0f || -e+aabb_max.x < 0.0f)
					return false;
			}
		}


		// Test intersection with the 2 planes perpendicular to the OBB's Y axis
		// Exactly the same thing than above.
		{
			glm::vec3 yaxis(ModelMatrix[1].x, ModelMatrix[1].y, ModelMatrix[1].z);
			float e = glm::dot(yaxis, delta);
			float f = glm::dot(ray_direction, yaxis);

			if ( fabs(f) > 0.001f ){

				float t1 = (e+aabb_min.y)/f;
				float t2 = (e+aabb_max.y)/f;

				if (t1>t2){float w=t1;t1=t2;t2=w;}

				if ( t2 < tMax )
					tMax = t2;
				if ( t1 > tMin )
					tMin = t1;
				if (tMin > tMax)
					return false;

			}else{
				if(-e+aabb_min.y > 0.0f || -e+aabb_max.y < 0.0f)
					return false;
			}
		}


		// Test intersection with the 2 planes perpendicular to the OBB's Z axis
		// Exactly the same thing than above.
		{
			glm::vec3 zaxis(ModelMatrix[2].x, ModelMatrix[2].y, ModelMatrix[2].z);
			float e = glm::dot(zaxis, delta);
			float f = glm::dot(ray_direction, zaxis);

			if ( fabs(f) > 0.001f ){

				float t1 = (e+aabb_min.z)/f;
				float t2 = (e+aabb_max.z)/f;

				if (t1>t2){float w=t1;t1=t2;t2=w;}

				if ( t2 < tMax )
					tMax = t2;
				if ( t1 > tMin )
					tMin = t1;
				if (tMin > tMax)
					return false;

			}else{
				if(-e+aabb_min.z > 0.0f || -e+aabb_max.z < 0.0f)
					return false;
			}
		}

		intersection_distance = tMin;
		return true;

	}

//鼠标射线与球体检测测试 来自源码
	static bool ray_sphere(glm::vec3 ray_origin_wor, glm::vec3 ray_direction_wor,
					glm::vec3 sphere_centre_wor, float sphere_radius,
					float *intersection_distance ) {
		// work out components of quadratic
		glm::vec3 dist_to_sphere = ray_origin_wor - sphere_centre_wor;
		float b = dot( ray_direction_wor, dist_to_sphere );
		float c = dot( dist_to_sphere, dist_to_sphere ) - sphere_radius * sphere_radius;
		float b_squared_minus_c = b * b - c;
		// check for "imaginary" answer. == ray completely misses sphere
		if ( b_squared_minus_c < 0.0f ) {
			return false;
		}
		// check for ray hitting twice (in and out of the sphere)
		if ( b_squared_minus_c > 0.0f ) {
			// get the 2 intersection distances along ray
			float t_a = -b + sqrt( b_squared_minus_c );
			float t_b = -b - sqrt( b_squared_minus_c );
			*intersection_distance = t_b;
			// if behind viewer, throw one or both away
			if ( t_a < 0.0 ) {
				if ( t_b < 0.0 ) {
					return false;
				}
			} else if ( t_b < 0.0 ) {
				*intersection_distance = t_a;
			}

			return true;
		}
		// check for ray hitting once (skimming the surface)
		if ( 0.0f == b_squared_minus_c ) {
			// if behind viewer, throw away
			float t = -b + sqrt( b_squared_minus_c );
			if ( t < 0.0f ) {
				return false;
			}
			*intersection_distance = t;
			return true;
		}
		// note: could also check if ray origin is inside sphere radius
		return false;
	}

};