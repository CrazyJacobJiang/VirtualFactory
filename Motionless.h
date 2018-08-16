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


class Motionless
{
public:
	//������
	Motionless() :mShader("D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.vs", "D:/OpenGL lianxi/ProjectClient/Project1/Path/model_loading.frag"),
		chang("D:/OpenGL lianxi/ProjectClient/Project1/Path/chang/chang.obj"),
		wlz("D:/OpenGL lianxi/ProjectClient/Project1/Path/wlz/wlz.obj")
	{
	}


	void getview(glm::mat4 &mview)
	{
		 this->view = mview;
	}


	//���Ƴ�����
	void draw_Chang()
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
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		chang.Draw(mShader);
	}

	//��������վ
	void draw_wlz()
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
		model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		wlz.Draw(mShader);
	}

	void draw_All()
	{
		this->draw_Chang();
		this->draw_wlz();
	}
protected:
	//������ɫ���Լ�������������
	glm::mat4 view;
	Shader mShader;
public:
	Model chang;
	Model wlz;
	
};