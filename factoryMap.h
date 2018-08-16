#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "loadTexture.h"
//IMGUI 界面库
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

using namespace std;

class factoryMap
{
public:

	void loadMap();

	void drawMap();

	void drawSmallMap( glm::vec3 &posVec );




private:
	//厂房地图
	LoadTexture factoryTexture;
	ImTextureID factory_id ; 
	float factory_w;
	float factory_h;

	//柔性线地图
	LoadTexture lineTexture;
	ImTextureID line_id ; 
	float line_w;
	float line_h;

public:
	GLint factory_ID;

	GLint line_ID;


};