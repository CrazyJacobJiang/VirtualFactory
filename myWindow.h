#pragma once
#pragma execution_character_set("utf-8")
#include <string>
//IMGUI �����
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

#include "readFiles.h"
#include "drawPart.h"
#include "loadTexture.h"
#include "factoryMap.h"
#include "cncControlData.h"
#include "cncData.h"

//�û�����
class myWindow
{
public:
	//��ʼ������
	myWindow()
	{

		this->myWindowInit();
		//��ʼ��������ǰ����
	//	initEquipData();

		isShowCurrentData=false;
		isOpenControlWindow=false;

		State_No1=false;
		State_No2=false;
		State_No3=false;
		State_No4=false;
		State_No5=false;
		State_No6=false;

	}	

//���˵���
	void mainMenubar()
	{
		/*  push/pop������ʱ�ı䵱ǰ���ڵĸ�ʽ */
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f,5.5f));	//ѹ��˵�����ʽ��ջ���˵���������ã� 
		ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
		// ���˵�
		if (ImGui::BeginMainMenuBar())
		{

			if (ImGui::BeginMenu("Menu"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("File"))
			{
				ImGui::MenuItem("Open NC", NULL, &readyToRead);
				ImGui::Separator();
				ImGui::MenuItem("clearNC", NULL, &confirmClearNc);

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Seting"))
			{
			//	ImGui::MenuItem("CNC Control", NULL, &controlWindow);
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Simulation"))
			{
				ImGui::MenuItem("Open PartLine", NULL, &openPartLine);
				ImGui::Separator();
				ImGui::MenuItem("factoryMap", NULL, &factoryMap);
				
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("help"))
			{
				ImGui::MenuItem("userHelp", NULL, &userhelp);
				ImGui::EndMenu();
			}
			 ImGui::Text(" %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}
		ImGui::EndMainMenuBar();
		ImGui::PopStyleVar();	//������ʽ��ջ
		ImGui::PopStyleColor();
	}

	

	//�ӹ�����
	void ncCode()
	{
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::SetNextWindowPos(ImVec2(342, 601));					//���ó�ʼ����λ��_����֮�󴰿�λ�ò��ܵ���
		ImGui::SetNextWindowSize(ImVec2(1024, 167));				//���ó�ʼ���ڴ�С_�����Ժ󴰿ڴ�С���Ըı�
		ImGui::Begin("",false,  ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoSavedSettings); // ��������
		{
			ImGui::Text("Factory information");		//��ʾ��������
			ImGui::Separator();	//��������Ӧ��ӷָ���
			//�Ӵ���
			vector<string> NCcodeExanple;
			NCcodeExanple.push_back(" NC Code : ");
			NCcodeExanple.push_back(" Use the menu bar to load your NC code ");
			NCcodeExanple.push_back(" Be careful to Operate CNC");
			NCcodeExanple.push_back(" The .txt format would be avalable ");

			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.35f, 0.35f, 0.35f, 0.8f));
			ImGui::BeginChild("currentCode", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
			{
				//�Ӵ���
				ImGui::Columns(1);	//�����ʼλ�ã��ú���ȷ����������Լ�ĩ��
				//���Ʊ��
				ImGui::Columns(2, "mycolumns"); // 2��
				ImGui::Separator();
				ImGui::Text("Factory State"); ImGui::NextColumn();
				ImGui::Text("Current Gcode"); ImGui::NextColumn();
				ImGui::Separator();
				//������ݸ����У��������´ν����Ų���ʾ���������л�����һ�б�����á� ImGui::NextColumn();������

				ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
				ImGui::Text(" This is the information of factory");		//��ʾ��������
				ImGui::PopStyleColor();

				ImGui::NextColumn();

				ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
				ImGui::Text(" NC Code");		//��ʾ��������
				ImGui::PopStyleColor();
				if (readNCHelp)
				{
					for (vector<string>::iterator iter = ncCodeReader.fileContent.begin(); iter != ncCodeReader.fileContent.end(); ++iter)
					{
						string str = *iter; 
						ImGui::Text(str.data());		//��ʾ��������
					}
				}
				else
				{
					for (vector<string>::iterator iter = NCcodeExanple.begin(); iter != NCcodeExanple.end(); ++iter)
					{
						string str = *iter; 
						ImGui::Text(str.data());		//��ʾ��������
					}
				}
				ImGui::Columns(1);	//�����ֹʼλ��
				ImGui::Separator();	//��������Ӧ��ӷָ���
			ImGui::EndChild();
			ImGui::PopStyleColor();
			}
			ImGui::End();
			ImGui::PopStyleColor();
		}
	}



	//������������
	void otherWindow()
	{
		//��ȡNC�ļ�
		if (readyToRead)
		{	
			ImGui::SetNextWindowSize(ImVec2(342, 150));
			ImGui::Begin("confirm", &readyToRead);

			ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
			ImGui::Text("read NC code");
			if (ImGui::Button("confirm"))
			{
				confirmReadNc=true;
			}
			ImGui::PopStyleColor();
			ImGui::End();
		}

		if (confirmReadNc)
		{

			ImGui::SetNextWindowPos(ImVec2(342, 400));	
			ImGui::SetNextWindowSize(ImVec2(342, 150));
			ImGui::Begin("readNc", &confirmReadNc);
			ImGui::Text("read to read NC ");
			readyToRead=false;
			readNCHelp=true;
			ncCodeReader.getFileContex();
			ncCodeReader.printfContex(ncCodeReader.fileContent);
			//��ȡ����
			float prossRead=0.0;
			ImGui::ProgressBar(prossRead, ImVec2(220.0f,0.0f));
			if (prossRead=1.0)
			{
				confirmReadNc=false;
			}
			ImGui::End();
		}

		//���NC����
		if (confirmClearNc)
		{
			ImGui::SetNextWindowSize(ImVec2(342, 150));
			ImGui::Begin("confirm", &readyToRead);

			ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
			ImGui::Text("read to clear");
			if (ImGui::Button("confirm"))
			{
				clearNc=true;
				confirmClearNc=false;
			}
			ImGui::PopStyleColor();

			ImGui::End();
		}

		if (clearNc)
		{
			ImGui::SetNextWindowPos(ImVec2(342, 400));	
			ImGui::SetNextWindowSize(ImVec2(342, 150));
			ImGui::Begin("", &confirmReadNc);
			ImGui::Text("clearing....");
			readyToRead=false;
			ncCodeReader.fileName.clear();
			ncCodeReader.fileContent.clear();
			clearNc=false;
			ImGui::End();
		}
		//���߹켣���洰��
		if (openPartLine)
		{
			std::vector<ImVec2> tempNum;
			ImVec2 size = ImVec2(600, 500);
			ImGui::SetNextWindowSize(size);
			ImGui::Begin("partLine",&openPartLine);
			{
				ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(0.5f,0.5f,0.5f,0.8f));
				if (ImGui::Button("Start test"))
				{
					PartLine.StarTtestPart= true;
				}
				ImGui::SameLine();
				if (ImGui::Button("Stop test"))
				{
					PartLine.StarTtestPart = false;
				}
				ImGui::SameLine();
				if (ImGui::Button("Sart Simulation"))
				{
					PartLine.StarTtestPart  = false;
					PartLine.StartSimulation=true;
				}
				ImGui::SameLine();
				if (ImGui::Button("Close Window"))
				{
					openPartLine=false;
				}
				ImGui::PopStyleColor();

				ImVec2 myWindowsPosition;
				myWindowsPosition=ImGui::GetWindowPos();
				ImVec2 myWindowsSize;
				myWindowsSize=ImGui::GetWindowSize();
				ImGui::BeginChild("Line", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoResize);
				{
					if (PartLine.StartSimulation)
					{
						PartLine.getPartData(tempNum);
					}

					PartLine.drawMolePart(myWindowsPosition,myWindowsSize);

					ImGui::EndChild();
				}
			}
			ImGui::End();
		}

		if (controlWindow)
		{
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
			//���ƴ���
			ImGui::SetNextWindowSize(ImVec2(340, 200));				//���ó�ʼ���ڴ�С_�����Ժ󴰿ڴ�С���Ըı�
			ImGui::Begin("Control Plane",&controlWindow,ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoResize);
			{
				if (ImGui::Button("Quit"))
				{
					controlWindow = false;
				}
				ImGui::Separator();	//��������Ӧ��ӷָ���

				if (isChange(controlWindow ) )
				{

					myCncControlWindow.initControlWindow();

				}
				if (State_No1)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No2)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No3)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No4)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No4)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No5)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else if (State_No6)
				{
					myCncControlWindow.conctrolButton();
					this->controlData=myCncControlWindow.controlData;
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
					ImGui::Text("Equipment error");
					ImGui::PopStyleColor;
				}

				ImGui::End();
				ImGui::PopStyleColor();
			}

		}

		//����������
		if (factoryMap)
		{
			ImVec2 size = ImVec2(810, 470);
			ImGui::SetNextWindowSize(size);
			ImGui::Begin("Map",&factoryMap, ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoResize|
				ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoSavedSettings);
			{
				ImGui::Text("This is the factory map");
				ImGui::Separator();
				myFactoryMap.drawMap();

			}
			ImGui::End();
		}
		//�������ڣ�����˵��
		if (userhelp)
		{
//			ImGui::SetNextWindowPos(ImVec2(300, 300));	
			ImGui::SetNextWindowSize(ImVec2(400, 300));
			ImGui::Begin("userHelp", &userhelp);
			if (ImGui::Button("Close"))
			{
				userhelp=false;
			}
			ImGui::Separator();
			ImGui::BeginChild("currentCode", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
			{
				ImGui::Text("Move Forward = press Key-W");
				ImGui::Text("Move Back = press Key-S");
				ImGui::Text("Move Left = press Key-A");
				ImGui::Text("Move Right = press Key-D");
				ImGui::Text("Turn Left = press Key-PgUp");
				ImGui::Text("Turn Right = press Key-PgDn");
				ImGui::EndChild();
			}
			ImGui::End();
		}
		
		if (isShowCurrentData)
		{
				equipData();
		}
	}


	void currentEquip()
	{
		ImGui::SetNextWindowPos(ImVec2(0, 25));					//���ó�ʼ����λ��_����֮�󴰿�λ�ò��ܵ���
		ImGui::SetNextWindowSize(ImVec2(342, 576));				//���ó�ʼ���ڴ�С_�����Ժ󴰿ڴ�С���Ըı�

		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::Begin("windowTitle",false, ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoSavedSettings|ImGuiWindowFlags_NoFocusOnAppearing|ImGuiWindowFlags_NoScrollbar); // ��������

		{
			ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(0.5f,0.5f,0.5f,0.8f));
			if (ImGui::Button("Equipment"))
			{
			}
			ImGui::PopStyleColor();
			ImGui::Separator();
			ImGui::Text("Condition", 123);
			{		
			//�Ӵ���
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.35f, 0.35f, 0.35f, 0.8f));
			ImGui::BeginChild("CNC_condition", ImVec2(0, 480), true, ImGuiWindowFlags_NoScrollbar);
				if (ImGui::TreeNode("Factory"))
				{
					if (ImGui::TreeNode("Flexible Manufacture System"))
					{
						if (ImGui::TreeNode("CNC NO.1"))
						{
							ImGui::Text("CNC NO.1");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{
//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;
								State_No1=true;
								State_No2=false;
								State_No3=false;
								State_No4=false;
								State_No5=false;
								State_No6=false;
							}
						ImGui::TreePop();
						}

						if (ImGui::TreeNode("CNC NO.2"))
						{
							ImGui::Text("CNC NO.2");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{


//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;
								State_No1=false;
								State_No2=true;
								State_No3=false;
								State_No4=false;
								State_No5=false;
								State_No6=false;

							}
							ImGui::TreePop();
						}

						if (ImGui::TreeNode("CNC NO.3"))
						{
							ImGui::Text("CNC NO.3");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{
//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;

								State_No1=false;
								State_No2=false;
								State_No3=true;
								State_No4=false;
								State_No5=false;
								State_No6=false;
							}
							ImGui::TreePop();
						}

						if (ImGui::TreeNode("CNC NO.4"))
						{
							ImGui::Text("CNC NO.4");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{
//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;

								State_No1=false;
								State_No2=false;
								State_No3=false;
								State_No4=true;
								State_No5=false;
								State_No6=false;
							}
							ImGui::TreePop();
						}

						if (ImGui::TreeNode("CNC NO.5"))
						{
							ImGui::Text("CNC NO.5");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{
//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;

								State_No1=false;
								State_No2=false;
								State_No3=false;
								State_No4=false;
								State_No5=true;
								State_No6=false;
							}
							ImGui::TreePop();
						}

						if (ImGui::TreeNode("Material car"))
						{
							ImGui::Text("Material car");
							ImGui::SameLine(); 
							if (ImGui::SmallButton("Check")) 
							{
//								myCNCData.getcncData(cncCurrentData);
								isShowCurrentData=true;

								State_No1=false;
								State_No2=false;
								State_No3=false;
								State_No4=false;
								State_No5=false;
								State_No6=true;
							}
							ImGui::TreePop();
						}

					ImGui::TreePop();
					}
					if (ImGui::TreeNode("Area No.1"))
					{
					ImGui::TreePop();
					}
					if (ImGui::TreeNode("Area No.2"))
					{
						ImGui::TreePop();
					}
					if (ImGui::TreeNode("Area No.3"))
					{
						ImGui::TreePop();
					}
		
				ImGui::TreePop();
				}

			ImGui::EndChild();	//�Ӵ��ڽ���
			ImGui::PopStyleColor();
			}
			ImGui::End(); // �����ڽ���
			ImGui::PopStyleColor();
		}
	}


	//�����������ݴ���
	void equipData()
	{
			ImGui::SetNextWindowSize(ImVec2(342, 576));				//���ó�ʼ���ڴ�С_�����Ժ󴰿ڴ�С���Ըı�
			ImGui::Begin("Equipment state",&isShowCurrentData, ImGuiWindowFlags_NoResize|
				ImGuiWindowFlags_NoScrollbar ); // ��������
			{
				ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(0.5f,0.5f,0.5f,0.8f));

				if (State_No1)
				{
					ImGui::Button("CNC_1");
				}
				else if (State_No2)
				{
					ImGui::Button("CNC_2");
				}
				else if (State_No3)
				{
					ImGui::Button("CNC_3");
				}
				else if (State_No4)
				{
					ImGui::Button("CNC_4");
				}
				else if (State_No5)
				{
					ImGui::Button("CNC_5");
				}
				else if (State_No6)
				{
					ImGui::Button("Car");
				}
				else
				{
					ImGui::Button("Equipment");
				}

				ImGui::SameLine();
				if (ImGui::Button("check"))
				{
				controlWindow=true;	
				}
				ImGui::PopStyleColor();
				ImGui::Separator();

				myCNCData.getcncData(cncCurrentData);
				myCNCData.currentData();

				ImGui::End(); // �����ڽ���
			}


	}



	// ��ͼ����
	void mapWindow()
	{
		//���ִ���
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::SetNextWindowPos(ImVec2(0, 601));					//���ó�ʼ����λ��_����֮�󴰿�λ�ò��ܵ���
		ImGui::SetNextWindowSize(ImVec2(342, 167));				//���ó�ʼ���ڴ�С_�����Ժ󴰿ڴ�С���Ըı�
		ImGui::Begin("smallMap",false,  ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoSavedSettings|ImGuiWindowFlags_NoScrollbar); // ��������

		{
			ImVec2 myWindowPosition=ImGui::GetWindowPos();
			ImVec2 myWindowSize=ImGui::GetWindowSize();

			myFactoryMap.drawSmallMap(camerPosiVec);


		}
		ImGui::End();
		ImGui::PopStyleColor();

	}


	//����������ĳ��ֵ�Ƿ����ı�
	bool isChange(bool tempBOOL)
	{
		if (this->isChangeNum=tempBOOL)
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	bool isControlWindow(bool tempBOOL)
	{
		if (this->isOpenControlWindow=tempBOOL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}



	//������ǰ���ݳ�ʼ��
	/*
	
	void initEquipData()
	{
		for (int i=0;i<10;i++)
		{
			cncCurrentData.push_back(0.0);

		}
	}
*/

	//���ô��ڳ�ʼ��
	void setOtherWindow()
	{
		myFactoryMap.loadMap();

	}

	//��ȡ�������
	void getCameraData(glm::mat4 &tempMate,glm::vec3 &tempVec)
	{

		this->camerMat=tempMate;
		this->camerPosiVec=tempVec;
	}


	

	//��ȡ��ǰ�ӹ�����
	void getCNCCurrentData(vector<float> &tempCurrentData)
	{
		this->cncCurrentData=tempCurrentData;
//		iData=iTempData;
	}


	//��ȡ����λ������
	void getPosCurrentData(dataStruct &tempdata)
	{
	//	myDataStruct=tempdata;
		this->cncCurrentData.clear();
		this->cncCurrentData.push_back(tempdata.tran_Move.x);
		this->cncCurrentData.push_back(tempdata.tran_Move.y);
		this->cncCurrentData.push_back(tempdata.tran_Move.z);
		this->cncCurrentData.push_back(tempdata.rota_Move.x);
		this->cncCurrentData.push_back(tempdata.rota_Move.y);


	}




private:
	/* ���崰�ڵ����ԣ��Դ�����ʽ�������� ��ȫ�֣� */
	void myWindowInit()
	{
		//������ʾģʽ(��ɫ����ɫ����͸��)
//		ImGui::StyleColorsLight();

		//���ô��ڷ��
		ImGuiStyle& style = ImGui::GetStyle();		//��ȡ���ڷ��
		ImVec4* colors = style.Colors;				//������ɫ
		style.WindowRounding=0.0f;					//���ڱ߽ǵ���
		style.WindowBorderSize=0.6f;				//���ڱ߿��С
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.0f,0.0f,0.0f,1.0f);	//���ڲ˵�����ɫ
		colors[ImGuiCol_TitleBg] = ImVec4(0.1f,0.1f,0.1f,1.0f);		//���ڱ�����ɫ
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.1f,0.1f,0.1f,1.0f);		//����ڱ�����ɫ
		colors[ImGuiCol_WindowBg] = ImVec4(0.1f,0.1f,0.1f,0.8f);	//���ڱ�����ɫ
		colors[ImGuiCol_ChildBg] = ImVec4(0.35f,0.35f,0.35f,0.8f);	//�Ӵ��ڱ�����ɫ
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3f,0.3f,0.3f,0.6f);	//���ƴ��ڱ�����ɫ
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.5f,0.5f,0.5f,1.0f);	//��ť��ɫ��ɫ
		colors[ImGuiCol_HeaderActive] = ImVec4(0.2f,0.2f,0.2f,0.6f);	//���ť��ɫ��ɫ
		/* ��������*/
	//	ImGuiIO& io = ImGui::GetIO();
		//ʹ������
	//	io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\simsun.ttc", 15.0f, NULL, io.Fonts->GetGlyphRangesChinese());
	}



private:
	//�˵���


	cncControlData controlData;
	cncControl myCncControlWindow;

	//��������
	cncData myCNCData;


	readFiles ncCodeReader;
	drawPart PartLine;
	factoryMap myFactoryMap;


	//��������
	dataStruct myDataStruct;

public:
		glm::mat4 camerMat;	 
		glm::vec3 camerPosiVec;
		//��ǰ�����������ݵ�����ѹ��10������
		vector<float> cncCurrentData;
	
		//��ǰ�������������ѹ��������
		float iData[10];
		float vData[10];
		
		//�ӹ�����
		float currentProgress;


		//��ȡNC����
		static bool readyToRead;
		static bool confirmReadNc;		
		static bool confirmClearNc;
		static bool clearNc;
		static bool readNCHelp;


		//����������ֵ�Ƿ�ı�
		bool isChangeNum;
		bool isOpenControlWindow;

		//�û�����
		static bool userhelp;
		//�ӹ����ͼ
		static bool openPartLine;
		//��������ͼ
		static bool	factoryMap;
		//���ƴ���
		static bool controlWindow;

		//����״̬ѡ���
		//�Ƿ���ʾ����״̬����
		bool isShowCurrentData;
		bool State_No1;
		bool State_No2;
		bool State_No3;
		bool State_No4;
		bool State_No5;
		bool State_No6;
		
		//ImGui::Checkbox("State", &State_No1);
};