#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <string>
//IMGUI �����
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

//��������ӹ�ƽ��ͼ
class drawPart
{
public:
	drawPart();

	//���Ƶ�ǰ�ӹ��켣

	void drawMolePart(ImVec2 &wPosition,ImVec2 &wSize);


	void getPartData(std::vector<ImVec2> &tempNum);

	//�������������
	double getRandData(int min,int max);
public:
	std::vector<ImVec2> partNum	;
	bool StarTtestPart;
	bool StartSimulation;
	bool isOpen;
};