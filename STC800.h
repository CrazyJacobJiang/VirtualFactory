#pragma once

//OpenGL头文件
#include <gl/glew.h>
#include <string.h> 
// GLM 数学库
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
//模型与着色器加载文件
#include "Shader.h"
#include "Model.h"
//输入数据结构体
#include "dataStruct.h"
#include"picking.h"


class STC800
{
public:
	//构造器
	STC800() :mShader("D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.vs", "D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.frag"),
				ke("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/ke.obj"),
				xAxis("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/Xaxis.obj"),
				yAxis("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/Yaxis.obj"),
				zAxis("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/Zaxis.obj"),
				aAxis("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/Aaxis.obj"),
				bAxis("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/Baxis.obj"),
				men("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/men.obj"),
				button1("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/button1.obj"),
				button2("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/button2.obj"),
				button3("D:/OpenGL lianxi/ProjectClient/Project1/Path/STC800/button3.obj")
			
	{
	}


	void getview(glm::mat4 &mview)
	{
		this->view=mview;
	}

	//获取模型驱动数据
	void getDatastruct(dataStruct& tempData)
	{
		this->trans_Vect=tempData.tran_Move;	//获取模型平移向量
		this->rota_Vect=tempData.rota_Move;	//获取模型旋转向量
		this->modelMove = tempData.pos_Model;
	}

	//绘制机床外壳以及静态部件
	void draw_Ke()
	{
		//使用着色器
		mShader.Use();

		// 投影矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//相机矩阵
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		model = glm::translate(model,modelMove);
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		ke.Draw(mShader);
	}

	//绘制机床门
	void draw_men()
	{
		//使用着色器
		mShader.Use();

		// 投影矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//相机矩阵
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, tranMen);	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		men.Draw(mShader);
	}

	//绘制按钮1 红色按钮
	void draw_button1()
	{
		//使用着色器
		mShader.Use();

		// 投影矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//相机矩阵
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		//model = glm::scale(model, tranButton1);	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		button1.Draw(mShader);
	}

	//绘制按钮2 黄色
	void draw_button2()
	{
		//使用着色器
		mShader.Use();

		// 投影矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//相机矩阵
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		button2.Draw(mShader);
	}

	//绘制按钮3 绿色
	void draw_button3()
	{
		//使用着色器
		mShader.Use();

		// 投影矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//相机矩阵
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		button3.Draw(mShader);
	}




	//绘制机床x轴
	void draw_Xaxis()
	{
		mShader.Use();
		// 矩阵、相机矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		// 模型矩阵
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model=glm::translate(model,glm::vec3(trans_Vect.x,0.0f,0.0f));
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制机床x轴
		xAxis.Draw(mShader);
	}

	//绘制机床y轴
	void draw_Yaxis()
	{
		mShader.Use();
		// 投影、视图矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型矩阵
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(trans_Vect.x,trans_Vect.y,0.0f)); 
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制机床y轴
		yAxis.Draw(mShader);
	}

	//绘制机床z轴
	void draw_Zaxis()
	{
		mShader.Use();
		// 投影、视图矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//模型变换
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(0.0f,0.0f,trans_Vect.z)); 
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制机床z轴
		zAxis.Draw(mShader);

	}

	//绘制机床A轴
	void draw_Aaxis()
	{
		mShader.Use();
		// 投影、视图矩阵
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		// 模型矩阵
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(trans_Vect.x, trans_Vect.y, 0.0f));
		model=glm::translate(model,glm::vec3(0.0f,3.85f,-0.85f));	//移动回坐标原点
		model=glm::rotate(model,rota_Vect.x,glm::vec3(1.0f,0.0f,0.0f));
		model=glm::translate(model,glm::vec3(0.0f,-3.85f,0.85f));
//		model=glm::translate(model,glm::vec3(trans_Vect.x,trans_Vect.y,0.0f));	//移动至变换后位置
		//model= glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制机床A轴
		aAxis.Draw(mShader);

	}

	//绘制机床B轴
	void draw_Baxis()
	{

		mShader.Use();
		// Transformation matrices
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);;
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		// Draw the loaded model
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, trans_Vect.z));
		model=glm::translate(model,glm::vec3(0.0f,-2.0f,0.0f));	//移动回坐标原点
		model=glm::rotate(model,rota_Vect.y,glm::vec3(0.0f,1.0f,0.0f));
		model=glm::translate(model,glm::vec3(0.0f,2.0f,0.0f));
	//	model=glm::translate(model,glm::vec3(0.0f,0.0f,trans_Vect.z));	//移动至变换后位置
	//  model= glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制机床B轴
		bAxis.Draw(mShader);

	}

	static void switch_men(float &menSwitch, STC800 &stc800, float &men_position, GLfloat deltaTime) {
		if (menSwitch == 2) {
			if (men_position >= 20.0f)
			{
				menSwitch = 3;
				return;
			}
			men_position += deltaTime;
			glm::vec3 temp = glm::vec3(0.0f, 0.0f, men_position / 20.0);
			stc800.dataMen(temp);
		}
		if (menSwitch == 4) {
			if (men_position <= 0.0f)
			{
				menSwitch = 1;
				return;
			}
			men_position -= deltaTime;
			glm::vec3 temp = glm::vec3(0.0f, 0.0f, men_position / 20.0);
			stc800.dataMen(temp);
		}
		return;
	}

	void dataMen(glm::vec3 &tempdata)
	{
		tranMen=tempdata;
	}

	void dataButton1(glm::vec3 &tempdata)
	{
		tranButton1=tempdata;
	}


	void draw_All()
	{


	this->draw_Ke();
	this->draw_men();
	this->draw_button1();
	this->draw_button2();
	this->draw_button3();


	this->draw_Xaxis();
	this->draw_Yaxis();
	this->draw_Zaxis();
	this->draw_Aaxis();
	this->draw_Baxis();


	}


protected:

	glm::mat4 view;	
	glm::vec3 modelCenter;
	glm::vec3 tmpcenter;
	glm::vec3 modelMove;

	glm::vec3 tranMen;
	glm::vec3 tranButton1;

	//模型平移向量
	glm::vec3 trans_Vect;
	//模型旋转角度
	glm::vec2 rota_Vect;


	//创建着色器以及机床部件对象
	Shader mShader;
public:
	Model ke;
	Model xAxis;
	Model yAxis;
	Model zAxis;
	Model aAxis;
	Model bAxis;
	Model men;
	Model button1;
	Model button2;
	Model button3;
};