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

class Phs
{
public:
	//构造器
	Phs() :mShader("D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.vs", "D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.frag"),
		phs("D:/OpenGL lianxi/ProjectClient/Project1/Path/phs/phs.obj")
	{
	}

	void getview(glm::mat4 &mview)
	{
		this->view = mview;
	}

	//绘制物料站
	void draw_phs()
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
		model = glm::translate(model, tranPhs);
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//绘制静态物体
		phs.Draw(mShader);
	}

	static void cruise(float &menSwitch, Phs &phs, float &men_position, GLfloat deltaTime) {
		if (menSwitch == 1) {
			if (men_position >= 60.0f)
			{
				menSwitch = 2;
				return;
			}
			men_position += deltaTime;
			glm::vec3 temp = glm::vec3(men_position, 0.0f, 0.0f);
			phs.dataPhs(temp);
		}
		if (menSwitch == 2) {
			if (men_position <= 0.0f)
			{
				menSwitch = 1;
				return;
			}
			men_position -= deltaTime;
			glm::vec3 temp = glm::vec3(men_position, 0.0f, 0.0f);
			phs.dataPhs(temp);
		}
		return;
	}

	void dataPhs(glm::vec3 &tempdata)
	{
		tranPhs = tempdata;
	}

	void draw_All()
	{
		this->draw_phs();
	}
protected:
	//创建着色器以及机床部件对象
	glm::mat4 view;
	glm::vec3 tranPhs;
	Shader mShader;
public:
	Model phs;

};