// 标准头文件 头文件的顺序不能乱
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#include <windows.h>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// GLM数学库
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// 多媒体库
#include <SOIL.h>
// GL 类
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "stc800.h"
#include "Motionless.h"
#include "phs.h"
//用户界面
#include"myWindow.h"
  
//kafka库，顺序必须在华中头文件之上
#include <cppkafka/producer.h>
#include "cppkafka/consumer.h"

//用户界面

using namespace std;

//错误回掉函数
static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error %d: %s\n", error, description);
}
// 窗口设置
GLuint screenWidth = 1366, screenHeight = 768;

// 交互功能
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void Do_Movement();
//机床侧门状态标签，1-门已关、2-正在开门、3-门已开、4-正在关门
float menSwitch = 1;
//phs小车状态标签
float phsSwitch = 1;
//图像加载
GLuint loadTexture(GLchar* path);
GLuint loadCubemap(vector<const GLchar*> faces);

// 摄像机
Camera camera(glm::vec3(0.0f, 3.0f, 15.0f));
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;
//将物体包围盒定义为全局变量，在回调函数中使用
glm::vec3 ke_modelMax;
glm::vec3 ke_modelMin;
glm::vec3 button1_modelMax;
glm::vec3 button1_modelMin;
glm::vec3 button2_modelMax;
glm::vec3 button2_modelMin;
glm::vec3 button3_modelMax;
glm::vec3 button3_modelMin;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

// myWindow myMenu;
myWindow myMenu;

//定义各轴移动距离
float Xaxis = 0.0f;
float Yaxis = 0.0f;
float Lmen=0.0f;
float Rmen=0.0f;

//定义kafak标志位
bool Gcode = false;
bool Start = false;

//键盘功能
ImGuiIO& keyIo = ImGui::GetIO();
void keyboardFunction();

void glfw_mouse_click_callback( GLFWwindow *window, int button,
								int action, int mods ) {
	if(GLFW_PRESS == action){
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		glm::vec3 ray_origin = camera.Position;
		glm::vec3 ray_direction;
		glm::mat4 view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		picking::ScreenPosToWorldRay(
			xpos, ypos,
			screenWidth, screenHeight, 
			view, 
			projection, 
			ray_direction
		);
		float intersection_distance; 
		//机床外壳中心坐标
		glm::vec3 sphere_centre_wor(-1.1f, 4.26f, 1.54f);
		//机床外壳半径
		float sphere_radius = 6.0f;
		glm::mat4 model;
		if(picking::TestRayOBBIntersection( ray_origin, ray_direction, button1_modelMin, 
								button1_modelMax, model, intersection_distance )){
			if(menSwitch == 1){
				std::cout<<"===================" << std::endl;
				std::cout<< "正打开侧门，请稍等" << std::endl;
				menSwitch = 2;
				return ;
			}if(menSwitch == 3){
				std::cout<<"===================" << std::endl;
				std::cout<< "正关闭侧门，请稍等" << std::endl;
				menSwitch = 4;
				return ;
			}
		}else if(picking::TestRayOBBIntersection( ray_origin, ray_direction, button2_modelMin, 
			button2_modelMax, model, intersection_distance ))
		{
			std::cout<<"===================" << std::endl;
			std::cout<<"button2,发送加工文件"<<std::endl;
			Gcode = true;
			return;

		}else if(picking::TestRayOBBIntersection( ray_origin, ray_direction, button3_modelMin, 
			button3_modelMax, model, intersection_distance ))
		{
			std::cout<<"===================" << std::endl;
			std::cout<<"button3，开始加工"<<std::endl;
			Start = true;
			return;
		}
	}
}
bool myWindow::readyToRead = false;
bool myWindow::confirmReadNc = false;
bool myWindow::clearNc = false;
bool myWindow::confirmClearNc = false;
bool myWindow::readNCHelp = false;
bool myWindow::userhelp = false;
bool myWindow::openPartLine = false;
bool myWindow::factoryMap = false;
bool myWindow::controlWindow = false;

// 主程序
int main(int argc,char* argv[])
{
	//初始化窗口
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return 1;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


	//创建窗口
	GLFWwindow* window = glfwCreateWindow(1366, 768, "Interactive System", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	// 垂直同步
//	glfwSwapInterval(1); 
	//初始化GLEW
//	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
		return -1;
	}
	//设置视口大小
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(342, 167, 1024, 576);

	// 交互功能
	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetMouseButtonCallback(window, glfw_mouse_click_callback );
	

	// 其他选项将鼠标锁定至屏幕中心
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//绑定ImGUi
	ImGui_ImplGlfwGL3_Init(window, true);
	

	// 设置深度缓存
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//生成驱动数据结构体
//	struct dataStruct tempData;
	struct dataStruct tempData[3];
	//创建机床位置数据

	tempData[0].pos_Model = glm::vec3(-30.0f, 0.0f, 0.0f);
	tempData[1].pos_Model = glm::vec3(0.0f, 0.0f, 0.0f);
	tempData[2].pos_Model = glm::vec3(30.0f, 0.0f, 0.0f);

	//创建模型
	//获取数据
	STC800 stc800;
	Motionless motionless;
	Phs phs;
	myMenu.setOtherWindow();
	ke_modelMax = stc800.ke.modelMax;
	ke_modelMin = stc800.ke.modelMin;
	button1_modelMax = stc800.button1.modelMax;
	button1_modelMin = stc800.button1.modelMin;
	button2_modelMax = stc800.button2.modelMax;
	button2_modelMin = stc800.button2.modelMin;
	button3_modelMax = stc800.button3.modelMax;
	button3_modelMin = stc800.button3.modelMin;

#pragma endregion

	// 以线条模式绘图
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	float men_position = 0;//侧门状态标识符
	float phsPosition = 0;

	//配置kafka消息中间件,生产者负责发送命令							
	cppkafka::Configuration config = {
		{ "metadata.broker.list", "192.168.1.199:9092" }
	};
	cppkafka::Producer producer(config);

	//配置kafka消息中间件,消费者负责接收数据	
	string csm_brokers = "192.168.1.199:9092";
	string csm_topic_name = "Data";
	string csm_group_id = "0";
	string min = "1";
	string time = "10";

	cppkafka::Configuration csm_config = {
		{ "metadata.broker.list", csm_brokers },
		{ "group.id", csm_group_id },
		{ "enable.auto.commit", true },
		{"fetch.min.bytes",min},
		{"fetch.wait.max.ms",time}
	};
	
	cppkafka::Consumer consumer(csm_config);
	consumer.subscribe({ csm_topic_name });
	cout << "Consuming messages from topic " << csm_topic_name << endl;
	cppkafka::Message csm_msg;
	

	chrono::milliseconds mytime(1);
	double xPos = 0.0;
	double yPos = 0.0;
	double zPos = 0.0;

	// 启动循环
	while(!glfwWindowShouldClose(window))
	{
	//std::vector<Message> poll_batch(size_t max_batch_size, std::chrono::milliseconds timeout);

	//poll中的参数对性能的影响很大
		
		csm_msg = consumer.poll(mytime);
		
		if (csm_msg) {
			//cout << csm_msg.get_payload() << endl;
			istringstream istr = (istringstream)csm_msg.get_payload();
			istr >> xPos; istr >> yPos; istr >> zPos;
		//	cout << xPos << " " << yPos << " " << zPos << " " << endl;
		}
		
		// 设置帧周期
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		//cout << deltaTime << endl;
		lastFrame = currentFrame;

		//更新数据结构体
		for (int i = 0; i < 3; i++)
		{
			tempData[i].tran_Move = glm::vec3(20 * xPos*0.01, 20 * yPos*0.01, 20 * zPos*0.01);
			tempData[i].rota_Move = glm::vec2(20 * xPos*0.01 + 0.8, 20 * yPos*0.01);
		}
		vector<float> tempCurrentData = {500*(float)xPos, 400*(float)yPos, 300*(float)zPos
										,90*(float)xPos, 90*(float)yPos, (float)0.0 
										,(float)0.0, (float)0.0, (float)0.0, (float)0.0};
		myMenu.getCNCCurrentData(tempCurrentData);
		// 压入堆栈
		glfwPollEvents();
		// 清除背景颜色
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 mview = camera.GetViewMatrix();
		stc800.getview(mview);

		for (int i = 0; i < 3; i++)
		{
			stc800.getDatastruct(tempData[i]);
			stc800.draw_All();
		}

		motionless.getview(mview);
		phs.getview(mview);

		motionless.draw_All();
		phs.draw_All();
	
		STC800::switch_men(menSwitch, stc800, men_position, deltaTime);
		Phs::cruise(phsSwitch, phs, phsPosition, deltaTime);

	
		if (ImGui::IsMouseClicked(0, false)) {
				double xpos, ypos;
				glfwGetCursorPos(window, &xpos, &ypos);
				xpos = xpos - 342;
				ypos = ypos - 25;
				glm::vec3 ray_origin = camera.Position;
				glm::vec3 ray_direction;
				glm::mat4 view = camera.GetViewMatrix();
				glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
				picking::ScreenPosToWorldRay(
					xpos, ypos,
					1024, 576,
					view,
					projection,
					ray_direction
				);
				float intersection_distance;
				//机床外壳中心坐标
				glm::vec3 sphere_centre_wor(-1.1f, 4.26f, 1.54f);
				//机床外壳半径
				float sphere_radius = 6.0f;
				glm::mat4 model;
				if (picking::TestRayOBBIntersection(ray_origin, ray_direction, button1_modelMin,
					button1_modelMax, model, intersection_distance)) {
					if (menSwitch == 1) {
						std::cout << "===================" << std::endl;
						std::cout << "open the gate, wait a minute" << std::endl;
						menSwitch = 2;
						
					}if (menSwitch == 3) {
						std::cout << "===================" << std::endl;
						std::cout << "close the gate, wait a minute" << std::endl;
						menSwitch = 4;
					}
				}
				else if (picking::TestRayOBBIntersection(ray_origin, ray_direction, button2_modelMin,
					button2_modelMax, model, intersection_distance))
				{
					std::cout << "===================" << std::endl;
					std::cout << "button2,sending Gcode" << std::endl;
					Gcode = true;
				}
				else if (picking::TestRayOBBIntersection(ray_origin, ray_direction, button3_modelMin,
					button3_modelMax, model, intersection_distance))
				{
					std::cout << "===================" << std::endl;
					std::cout << "button3,start" << std::endl;
					Start = true;
				}
		}
		
	
		/* 原界面的展示绘制 2018年6月6日 Jacob注释
		ImGui_ImplGlfwGL3_NewFrame();	
		myMenu.mainMenubar();
		myMenu.cncContorl();
		myMenu.drawMap();
		myMenu.ncCode();
		ImGui::Render();
		*/


		//绘制界面
		ImGui_ImplGlfwGL3_NewFrame();
		//获取界面数据
		
		glm::mat4 tempMate = camera.GetViewMatrix();
		myMenu.getCameraData(tempMate, camera.Position);
		//	myMenu.getPosCurrentData(modelData);
		//菜单栏	
		myMenu.otherWindow();
		myMenu.mainMenubar();
		//信息窗口
		myMenu.currentEquip();
		//地图窗口
		myMenu.mapWindow();
		//加工代码
		myMenu.ncCode();
		//imgui窗口结束之后必须调；

		ImGui::Render();

		//imgui功能
		keyboardFunction();


		//键盘交互
//		keyboardFunction();
		// 交换缓冲
		glfwSwapBuffers(window);
		if (Gcode)
		{
			string message = "GcodeLoad";
			producer.produce(cppkafka::MessageBuilder("test").partition(0).payload(message));
			Gcode = false;
		}
		if (Start)
		{
			string message = "CycleStart";
			producer.produce(cppkafka::MessageBuilder("test").partition(0).payload(message));
			Start = false;
		}


	}
	glfwTerminate();
	return 0;
}



//函数定义
#pragma region "用户输入"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if(action == GLFW_PRESS)
		keys[key] = true;
	else if(action == GLFW_RELEASE)
		keys[key] = false;	
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

/*
void keyboardFunction()
{
	if(keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if(keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if(keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if(keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if(keys[GLFW_KEY_LEFT])
		camera.ProcessMouseMovement(1.0f, 0.0f);
	if(keys[GLFW_KEY_RIGHT])
		camera.ProcessMouseMovement(-1.0f, 0.0f);
}
*/

void keyboardFunction()
{
	if (keyIo.KeysDown[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (keyIo.KeysDown[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (keyIo.KeysDown[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (keyIo.KeysDown[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);

	if (keyIo.KeysDown[GLFW_KEY_LEFT])
		camera.ProcessMouseMovement(1.0f, 0.0f);
	if (keyIo.KeysDown[GLFW_KEY_RIGHT])
		camera.ProcessMouseMovement(-1.0f, 0.0f);
}
#pragma endregion
