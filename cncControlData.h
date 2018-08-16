#pragma once

#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

//�������ƽṹ��

struct cncControlData
{
	float xPoisition;
	float yPoisition;
	float zPoisition;
	float aPoisition;
	float bPoisition;
};


class cncControl
{
public:

	void initControlWindow()
	{

		Xaxis = 0.0f;
		Yaxis = 0.0f;
		Zaxis = 0.0f;
		Aaxis = 0.0f;
		Baxis = 0.0f;

	}
	void conctrolButton()
	{
		ImGui::SliderFloat("Xaxis", &Xaxis, -500.0f, 500.0f);		//ˮƽ����
		ImGui::SliderFloat("Yaxis", &Yaxis, -500.0f, 500.0f);		//ˮƽ����
		ImGui::SliderFloat("Zaxis", &Zaxis, -500.0f, 500.0f);		//ˮƽ����
		ImGui::SliderFloat("Aaxis", &Aaxis, -0.0f, 90.0f);		//ˮƽ����
		ImGui::SliderFloat("Baxis", &Baxis, -180.0f, 180.0f);		//ˮƽ����
		this->controlData.xPoisition=Xaxis;
		this->controlData.yPoisition=Yaxis;
		this->controlData.zPoisition=Zaxis;
		this->controlData.aPoisition=Aaxis;
		this->controlData.bPoisition=Baxis;
	}

private:

	 float Xaxis ;
	 float Yaxis ;
	 float Zaxis ;
	 float Aaxis ;
	 float Baxis ;

public:
	cncControlData controlData;

};