#pragma once
#pragma execution_character_set("utf-8")
#include <string>
//IMGUI 界面库
#include <imgui/imgui.h>
#include "imgui_impl_glfw_gl3.h"

#include "readFiles.h"
#include "drawPart.h"
#include "loadTexture.h"
#include "factoryMap.h"
#include "cncControlData.h"
#include "cncData.h"

//用户界面
class myWindow
{
public:
	//初始化窗口
	myWindow()
	{

		this->myWindowInit();
		//初始化机床当前数据
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

//主菜单栏
	void mainMenubar()
	{
		/*  push/pop用于临时改变当前窗口的格式 */
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f,5.5f));	//压入菜单栏格式堆栈（菜单栏宽度设置） 
		ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
		// 主菜单
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
		ImGui::PopStyleVar();	//弹出格式堆栈
		ImGui::PopStyleColor();
	}

	

	//加工代码
	void ncCode()
	{
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::SetNextWindowPos(ImVec2(342, 601));					//设置初始窗口位置_设置之后窗口位置不能调节
		ImGui::SetNextWindowSize(ImVec2(1024, 167));				//设置初始窗口大小_设置以后窗口大小可以改变
		ImGui::Begin("",false,  ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoSavedSettings); // 窗口属性
		{
			ImGui::Text("Factory information");		//显示窗口文字
			ImGui::Separator();	//表格结束后应添加分割条
			//子窗口
			vector<string> NCcodeExanple;
			NCcodeExanple.push_back(" NC Code : ");
			NCcodeExanple.push_back(" Use the menu bar to load your NC code ");
			NCcodeExanple.push_back(" Be careful to Operate CNC");
			NCcodeExanple.push_back(" The .txt format would be avalable ");

			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.35f, 0.35f, 0.35f, 0.8f));
			ImGui::BeginChild("currentCode", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
			{
				//子窗口
				ImGui::Columns(1);	//表格起始位置，该函数确定表格的起点以及末点
				//绘制表格
				ImGui::Columns(2, "mycolumns"); // 2列
				ImGui::Separator();
				ImGui::Text("Factory State"); ImGui::NextColumn();
				ImGui::Text("Current Gcode"); ImGui::NextColumn();
				ImGui::Separator();
				//表格内容根据行，从上至下次进行排布显示，如有想切换至下一列表格，利用“ ImGui::NextColumn();”代替

				ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
				ImGui::Text(" This is the information of factory");		//显示窗口文字
				ImGui::PopStyleColor();

				ImGui::NextColumn();

				ImGui::PushStyleColor(ImGuiCol_Text,ImVec4(1.0f,0.0f,0.0f,1.0f));
				ImGui::Text(" NC Code");		//显示窗口文字
				ImGui::PopStyleColor();
				if (readNCHelp)
				{
					for (vector<string>::iterator iter = ncCodeReader.fileContent.begin(); iter != ncCodeReader.fileContent.end(); ++iter)
					{
						string str = *iter; 
						ImGui::Text(str.data());		//显示窗口文字
					}
				}
				else
				{
					for (vector<string>::iterator iter = NCcodeExanple.begin(); iter != NCcodeExanple.end(); ++iter)
					{
						string str = *iter; 
						ImGui::Text(str.data());		//显示窗口文字
					}
				}
				ImGui::Columns(1);	//表格终止始位置
				ImGui::Separator();	//表格结束后应添加分割条
			ImGui::EndChild();
			ImGui::PopStyleColor();
			}
			ImGui::End();
			ImGui::PopStyleColor();
		}
	}



	//其他弹出窗口
	void otherWindow()
	{
		//读取NC文件
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
			//读取进度
			float prossRead=0.0;
			ImGui::ProgressBar(prossRead, ImVec2(220.0f,0.0f));
			if (prossRead=1.0)
			{
				confirmReadNc=false;
			}
			ImGui::End();
		}

		//清除NC代码
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
		//刀具轨迹仿真窗口
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
			//控制窗口
			ImGui::SetNextWindowSize(ImVec2(340, 200));				//设置初始窗口大小_设置以后窗口大小可以改变
			ImGui::Begin("Control Plane",&controlWindow,ImGuiWindowFlags_NoScrollbar|ImGuiWindowFlags_NoResize);
			{
				if (ImGui::Button("Quit"))
				{
					controlWindow = false;
				}
				ImGui::Separator();	//表格结束后应添加分割条

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

		//加载纹理窗口
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
		//帮助窗口，按键说明
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
		ImGui::SetNextWindowPos(ImVec2(0, 25));					//设置初始窗口位置_设置之后窗口位置不能调节
		ImGui::SetNextWindowSize(ImVec2(342, 576));				//设置初始窗口大小_设置以后窗口大小可以改变

		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::Begin("windowTitle",false, ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoSavedSettings|ImGuiWindowFlags_NoFocusOnAppearing|ImGuiWindowFlags_NoScrollbar); // 窗口属性

		{
			ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(0.5f,0.5f,0.5f,0.8f));
			if (ImGui::Button("Equipment"))
			{
			}
			ImGui::PopStyleColor();
			ImGui::Separator();
			ImGui::Text("Condition", 123);
			{		
			//子窗口
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

			ImGui::EndChild();	//子窗口结束
			ImGui::PopStyleColor();
			}
			ImGui::End(); // 主窗口结束
			ImGui::PopStyleColor();
		}
	}


	//机床运行数据窗口
	void equipData()
	{
			ImGui::SetNextWindowSize(ImVec2(342, 576));				//设置初始窗口大小_设置以后窗口大小可以改变
			ImGui::Begin("Equipment state",&isShowCurrentData, ImGuiWindowFlags_NoResize|
				ImGuiWindowFlags_NoScrollbar ); // 窗口属性
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

				ImGui::End(); // 主窗口结束
			}


	}



	// 地图窗口
	void mapWindow()
	{
		//布局窗口
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 0.8f));
		ImGui::SetNextWindowPos(ImVec2(0, 601));					//设置初始窗口位置_设置之后窗口位置不能调节
		ImGui::SetNextWindowSize(ImVec2(342, 167));				//设置初始窗口大小_设置以后窗口大小可以改变
		ImGui::Begin("smallMap",false,  ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoSavedSettings|ImGuiWindowFlags_NoScrollbar); // 窗口属性

		{
			ImVec2 myWindowPosition=ImGui::GetWindowPos();
			ImVec2 myWindowSize=ImGui::GetWindowSize();

			myFactoryMap.drawSmallMap(camerPosiVec);


		}
		ImGui::End();
		ImGui::PopStyleColor();

	}


	//检测机床控制某个值是否发生改变
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



	//机床当前数据初始化
	/*
	
	void initEquipData()
	{
		for (int i=0;i<10;i++)
		{
			cncCurrentData.push_back(0.0);

		}
	}
*/

	//设置窗口初始化
	void setOtherWindow()
	{
		myFactoryMap.loadMap();

	}

	//获取相机数据
	void getCameraData(glm::mat4 &tempMate,glm::vec3 &tempVec)
	{

		this->camerMat=tempMate;
		this->camerPosiVec=tempVec;
	}


	

	//获取当前加工数据
	void getCNCCurrentData(vector<float> &tempCurrentData)
	{
		this->cncCurrentData=tempCurrentData;
//		iData=iTempData;
	}


	//获取机床位置数据
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
	/* 定义窗口的特性，对窗口样式进行设置 （全局） */
	void myWindowInit()
	{
		//窗口显示模式(白色、黑色、半透明)
//		ImGui::StyleColorsLight();

		//设置窗口风格
		ImGuiStyle& style = ImGui::GetStyle();		//获取窗口风格
		ImVec4* colors = style.Colors;				//窗口颜色
		style.WindowRounding=0.0f;					//窗口边角倒角
		style.WindowBorderSize=0.6f;				//窗口边框大小
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.0f,0.0f,0.0f,1.0f);	//窗口菜单栏颜色
		colors[ImGuiCol_TitleBg] = ImVec4(0.1f,0.1f,0.1f,1.0f);		//窗口标题颜色
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.1f,0.1f,0.1f,1.0f);		//激活窗口标题颜色
		colors[ImGuiCol_WindowBg] = ImVec4(0.1f,0.1f,0.1f,0.8f);	//窗口背景颜色
		colors[ImGuiCol_ChildBg] = ImVec4(0.35f,0.35f,0.35f,0.8f);	//子窗口背景颜色
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3f,0.3f,0.3f,0.6f);	//绘制窗口背景颜色
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.5f,0.5f,0.5f,1.0f);	//按钮颜色颜色
		colors[ImGuiCol_HeaderActive] = ImVec4(0.2f,0.2f,0.2f,0.6f);	//激活按钮颜色颜色
		/* 设置字体*/
	//	ImGuiIO& io = ImGui::GetIO();
		//使用宋体
	//	io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\simsun.ttc", 15.0f, NULL, io.Fonts->GetGlyphRangesChinese());
	}



private:
	//菜单栏


	cncControlData controlData;
	cncControl myCncControlWindow;

	//窗口文字
	cncData myCNCData;


	readFiles ncCodeReader;
	drawPart PartLine;
	factoryMap myFactoryMap;


	//机床数据
	dataStruct myDataStruct;

public:
		glm::mat4 camerMat;	 
		glm::vec3 camerPosiVec;
		//当前机床运行数据电流电压共10个数据
		vector<float> cncCurrentData;
	
		//当前机床主轴电流电压跳动数据
		float iData[10];
		float vData[10];
		
		//加工进度
		float currentProgress;


		//读取NC代码
		static bool readyToRead;
		static bool confirmReadNc;		
		static bool confirmClearNc;
		static bool clearNc;
		static bool readNCHelp;


		//检测机床控制值是否改变
		bool isChangeNum;
		bool isOpenControlWindow;

		//用户帮助
		static bool userhelp;
		//加工零件图
		static bool openPartLine;
		//厂房地形图
		static bool	factoryMap;
		//控制窗口
		static bool controlWindow;

		//机床状态选择框
		//是否显示运行状态窗口
		bool isShowCurrentData;
		bool State_No1;
		bool State_No2;
		bool State_No3;
		bool State_No4;
		bool State_No5;
		bool State_No6;
		
		//ImGui::Checkbox("State", &State_No1);
};