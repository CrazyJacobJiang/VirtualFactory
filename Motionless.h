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


class Motionless
{
public:
	//构造器
	Motionless() :mShader("D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.vs", "D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.frag"),
		chang("D:/OpenGL lianxi/ProjectClient/Project1/Path/chang/chang.obj"),
		wlz("D:/OpenGL lianxi/ProjectClient/Project1/Path/wlz/wlz.obj")
	{
	}


	void getview(glm::mat4 &mview)
	{
		 this->view = mview;
	}


	//绘制厂房壳
	void draw_Chang()
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
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		chang.Draw(mShader);
	}

	//绘制物料站
	void draw_wlz()
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
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 20.0f));
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		wlz.Draw(mShader);
	}

	void draw_All()
	{
		this->draw_Chang();
		this->draw_wlz();
	}
protected:
	//创建着色器以及机床部件对象
	glm::mat4 view;
	Shader mShader;
public:
	Model chang;
	Model wlz;
	
};