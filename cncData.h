#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <string>

#include <GL/glew.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//IMGUI 界面库
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"


class cncData
{
public:
	cncData()
	{

		dataError=false;
	}

	void getcncData(std::vector<float> &tempVec)
	{
			this->xAxis=tempVec[0];
			this->yAxis=tempVec[1];
			this->zAxis=tempVec[2];
			this->aAxis=tempVec[3];
			this->bAxis=tempVec[4];
			this->xPower=tempVec[5];
			this->yPower=tempVec[6];
			this->zPower=tempVec[7];
			this->aPower=tempVec[8];
			this->bPower=tempVec[9];
	}

	void currentData()
	{
		ImGui::Text("tCondition", 123);
		{		
			//子窗口
			ImGui::BeginChild("CNC_condition", ImVec2(0, 160), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::Columns(1);	//表格起始位置，该函数确定表格的起点以及末点
			//绘制表格
			ImGui::Text("Parameter");
			ImGui::Columns(2, "mycolumns"); // 2列
			ImGui::Separator();
			ImGui::Text("Position"); ImGui::NextColumn();
			ImGui::Text("Power"); ImGui::NextColumn();
			ImGui::Separator();
			//表格内容根据行，从上至下次进行排布显示，如有想切换至下一列表格，利用“ ImGui::NextColumn();”代替
			cout << xAxis <<" "<< yAxis << " " << zAxis << endl;
			ImGui::Text("X          %.3f",xAxis);		//显示窗口文字
			ImGui::Text("Y          %.3f",yAxis);		//显示窗口文字
			ImGui::Text("Z          %.3f",zAxis);		//显示窗口文字
			ImGui::Text("A          %.3f",aAxis);		//显示窗口文字
			ImGui::Text("B          %.3f",bAxis);		//显示窗口文字			
			ImGui::NextColumn();
			ImGui::Text("X          %.3f",xPower);		//显示窗口文字
			ImGui::Text("Y          %.3f",yPower);		//显示窗口文字
			ImGui::Text("Z          %.3f",zPower);		//显示窗口文字
			ImGui::Text("A          %.3f",aPower);		//显示窗口文字
			ImGui::Text("B          %.3f",bPower);		//显示窗口文字
			ImGui::Columns(1);	//表格终止始位置
			ImGui::Separator();	//表格结束后应添加分割条
			ImGui::EndChild();	//子窗口结束
			ImGui::Separator();	//表格结束后应添加分割条
		}

		ImGui::Text("Other Parameters");		//显示窗口文字
		//子窗口
		ImGui::BeginChild("plotline", ImVec2(0, 260), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::Separator();	//分割条
		static bool animate = true;
		ImGui::Checkbox("Pause", &animate);
		static float values[10] = { 0.2f,0.5f,0.3f,0.8f,0.1f,0.6f,0.1f,0.2f,0.5f,0.7f };
		static int values_offset = 0;
		static float refresh_time = 0.0f;
		if (!animate || refresh_time == 0.0f)
			refresh_time = ImGui::GetTime();		
		ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
		ImGui::PlotLines("", values, IM_ARRAYSIZE(values), values_offset, "Principal Axis Current Vibration", -1.0f, 1.0f, ImVec2(220,60));	ImGui::SameLine();
		ImGui::PopStyleColor();
		ImGui::BeginGroup();	//开始组
		ImGui::Text("1.0 A");		//显示窗口文字
		ImGui::Text("");		//显示窗口文字
		ImGui::Text("-1.0 A");		//显示窗口文字
		ImGui::EndGroup();	//结束组
		ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
		ImGui::PlotLines("", values, IM_ARRAYSIZE(values), 1, "Principal Axis Voltage Vibration", -1.0f, 1.0f, ImVec2(220,60));	ImGui::SameLine();
		ImGui::PopStyleColor();
		ImGui::BeginGroup();	//开始组
		ImGui::Text("10 V");		//显示窗口文字
		ImGui::Text("");		//显示窗口文字
		ImGui::Text("-10 V");		//显示窗口文字
		ImGui::EndGroup();	//结束组
		//绘制柱状图
		ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
		ImGui::PushStyleColor(ImGuiCol_PlotHistogram,ImVec4(1.0f,1.0f,1.0f,1.0f));
		static float arr[30] = { 0 };			
		ImGui::ProgressBar(0.0f, ImVec2(220.0f,0.0f));

		ImGui::SameLine();	//加工进度
		ImGui::PopStyleColor(2);
		ImGui::Text("The Processing Progress");		//显示窗口文字
		ImGui::EndChild();	//子窗口结束

/*
		if (dataError=true)
		{
			ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
			ImGui::Text("Data error");
			ImGui::PopStyleColor();
		}
		*/
	}


private:

	//机床位置
	float xAxis;
	float yAxis;
	float zAxis;
	float aAxis;
	float bAxis;

	float xPower;
	float yPower;
	float zPower;
	float aPower;
	float bPower;

	bool dataError;

};