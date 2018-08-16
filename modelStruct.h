#pragma once

// GLM 数学库
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

//模型数据结构体
//定点信息
struct Vertex {
	// 顶点
	glm::vec3 Position;
	// 法线
	glm::vec3 Normal;
	// 纹理
	glm::vec2 TexCoords;
};

//纹理信息
struct Texture {
	GLuint id;
	string type;
	aiString path;
};