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

//IMGUI �����
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
			//�Ӵ���
			ImGui::BeginChild("CNC_condition", ImVec2(0, 160), true, ImGuiWindowFlags_NoScrollbar);
			ImGui::Columns(1);	//�����ʼλ�ã��ú���ȷ����������Լ�ĩ��
			//���Ʊ��
			ImGui::Text("Parameter");
			ImGui::Columns(2, "mycolumns"); // 2��
			ImGui::Separator();
			ImGui::Text("Position"); ImGui::NextColumn();
			ImGui::Text("Power"); ImGui::NextColumn();
			ImGui::Separator();
			//������ݸ����У��������´ν����Ų���ʾ���������л�����һ�б�����á� ImGui::NextColumn();������
			cout << xAxis <<" "<< yAxis << " " << zAxis << endl;
			ImGui::Text("X          %.3f",xAxis);		//��ʾ��������
			ImGui::Text("Y          %.3f",yAxis);		//��ʾ��������
			ImGui::Text("Z          %.3f",zAxis);		//��ʾ��������
			ImGui::Text("A          %.3f",aAxis);		//��ʾ��������
			ImGui::Text("B          %.3f",bAxis);		//��ʾ��������			
			ImGui::NextColumn();
			ImGui::Text("X          %.3f",xPower);		//��ʾ��������
			ImGui::Text("Y          %.3f",yPower);		//��ʾ��������
			ImGui::Text("Z          %.3f",zPower);		//��ʾ��������
			ImGui::Text("A          %.3f",aPower);		//��ʾ��������
			ImGui::Text("B          %.3f",bPower);		//��ʾ��������
			ImGui::Columns(1);	//�����ֹʼλ��
			ImGui::Separator();	//��������Ӧ��ӷָ���
			ImGui::EndChild();	//�Ӵ��ڽ���
			ImGui::Separator();	//��������Ӧ��ӷָ���
		}

		ImGui::Text("Other Parameters");		//��ʾ��������
		//�Ӵ���
		ImGui::BeginChild("plotline", ImVec2(0, 260), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::Separator();	//�ָ���
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
		ImGui::BeginGroup();	//��ʼ��
		ImGui::Text("1.0 A");		//��ʾ��������
		ImGui::Text("");		//��ʾ��������
		ImGui::Text("-1.0 A");		//��ʾ��������
		ImGui::EndGroup();	//������
		ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
		ImGui::PlotLines("", values, IM_ARRAYSIZE(values), 1, "Principal Axis Voltage Vibration", -1.0f, 1.0f, ImVec2(220,60));	ImGui::SameLine();
		ImGui::PopStyleColor();
		ImGui::BeginGroup();	//��ʼ��
		ImGui::Text("10 V");		//��ʾ��������
		ImGui::Text("");		//��ʾ��������
		ImGui::Text("-10 V");		//��ʾ��������
		ImGui::EndGroup();	//������
		//������״ͼ
		ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
		ImGui::PushStyleColor(ImGuiCol_PlotHistogram,ImVec4(1.0f,1.0f,1.0f,1.0f));
		static float arr[30] = { 0 };			
		ImGui::ProgressBar(0.0f, ImVec2(220.0f,0.0f));

		ImGui::SameLine();	//�ӹ�����
		ImGui::PopStyleColor(2);
		ImGui::Text("The Processing Progress");		//��ʾ��������
		ImGui::EndChild();	//�Ӵ��ڽ���

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

	//����λ��
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