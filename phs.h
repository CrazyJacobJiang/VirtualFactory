#pragma once

//OpenGLͷ�ļ�
#include <gl/glew.h>
#include <string.h> 
// GLM ��ѧ��
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
//ģ������ɫ�������ļ�
#include "Shader.h"
#include "Model.h"

class Phs
{
public:
	//������
	Phs() :mShader("D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.vs", "D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.frag"),
		phs("D:/OpenGL lianxi/ProjectClient/Project1/Path/phs/phs.obj")
	{
	}

	void getview(glm::mat4 &mview)
	{
		this->view = mview;
	}

	//��������վ
	void draw_phs()
	{
		//ʹ����ɫ��
		mShader.Use();

		// ͶӰ����
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		//�������
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//ģ�;���
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 20.0f));
		model = glm::translate(model, tranPhs);
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
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
	//������ɫ���Լ�������������
	glm::mat4 view;
	glm::vec3 tranPhs;
	Shader mShader;
public:
	Model phs;

};