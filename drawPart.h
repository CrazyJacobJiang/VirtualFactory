#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <string>
//IMGUI 界面库
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

//绘制零件加工平面图
class drawPart
{
public:
	drawPart();

	//绘制当前加工轨迹

	void drawMolePart(ImVec2 &wPosition,ImVec2 &wSize);


	void getPartData(std::vector<ImVec2> &tempNum);

	//生成随机浮点数
	double getRandData(int min,int max);
public:
	std::vector<ImVec2> partNum	;
	bool StarTtestPart;
	bool StartSimulation;
	bool isOpen;
};