#pragma once
#include "drawPart.h"




	drawPart::drawPart()
	{
		StarTtestPart=false;
		StartSimulation=false;
		isOpen=true;
	}

	//绘制当前加工轨迹

	void drawPart::drawMolePart(ImVec2 &wPosition,ImVec2 &wSize)
	{
		ImDrawList* sPart = ImGui::GetWindowDrawList();
		if (StarTtestPart)
		{
			StartSimulation=false;
			ImVec2 poinArry[300];
			for (int i=0;i<300;i++)
			{
				float Num1=getRandData(200,550)+wPosition.x-wSize.x/8.0;
				float Num2=getRandData(200,550)+wPosition.y-wSize.y/8.0;
				poinArry[i]=ImVec2(Num1,Num2);
			}
			sPart->AddPolyline(poinArry, 300, ImColor(ImVec4(1.0, 0.0, 0.0, 1.0)), true, 4, true);
		} 

		if (StartSimulation)
		{
			StarTtestPart=false;
			int Num=partNum.size();

			ImVec2 *poinArry=new ImVec2[Num];
			for (int i=0;i<partNum.size();i++)
			{
				poinArry[i]=partNum[i];
			}
			sPart->AddPolyline(&*poinArry, Num, ImColor(ImVec4(1, 1, 1, 1)), true, 2, true);
			delete[] poinArry;
			this->partNum.clear();
		}
	}



	void drawPart::getPartData(std::vector<ImVec2> &tempNum)
	{	
		this->partNum=tempNum;
	}

	//生成随机浮点数
	double drawPart::getRandData(int min,int max)
	{
		double Num1=(double)(rand()%101)/101;                      
		min++;                                               
		double Num2=(double)((rand()%(max-min+1))+min);    
		Num2=Num2-1;                                                                        
		return Num1+Num2;                                                               
	}
