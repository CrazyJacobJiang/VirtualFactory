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
//�������ݽṹ��
#include "dataStruct.h"
#include"picking.h"


class STC800
{
public:
	//������
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

	//��ȡģ����������
	void getDatastruct(dataStruct& tempData)
	{
		this->trans_Vect=tempData.tran_Move;	//��ȡģ��ƽ������
		this->rota_Vect=tempData.rota_Move;	//��ȡģ����ת����
		this->modelMove = tempData.pos_Model;
	}

	//���ƻ�������Լ���̬����
	void draw_Ke()
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
		model = glm::translate(model,modelMove);
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		ke.Draw(mShader);
	}

	//���ƻ�����
	void draw_men()
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
		model = glm::translate(model, modelMove);
		model = glm::translate(model, tranMen);	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		men.Draw(mShader);
	}

	//���ư�ť1 ��ɫ��ť
	void draw_button1()
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
		//model = glm::scale(model, tranButton1);	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		button1.Draw(mShader);
	}

	//���ư�ť2 ��ɫ
	void draw_button2()
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
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		button2.Draw(mShader);
	}

	//���ư�ť3 ��ɫ
	void draw_button3()
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
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƾ�̬����
		button3.Draw(mShader);
	}




	//���ƻ���x��
	void draw_Xaxis()
	{
		mShader.Use();
		// �����������
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		// ģ�;���
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model=glm::translate(model,glm::vec3(trans_Vect.x,0.0f,0.0f));
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƻ���x��
		xAxis.Draw(mShader);
	}

	//���ƻ���y��
	void draw_Yaxis()
	{
		mShader.Use();
		// ͶӰ����ͼ����
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//ģ�;���
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(trans_Vect.x,trans_Vect.y,0.0f)); 
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƻ���y��
		yAxis.Draw(mShader);
	}

	//���ƻ���z��
	void draw_Zaxis()
	{
		mShader.Use();
		// ͶӰ����ͼ����
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		//ģ�ͱ任
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(0.0f,0.0f,trans_Vect.z)); 
		//model = glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƻ���z��
		zAxis.Draw(mShader);

	}

	//���ƻ���A��
	void draw_Aaxis()
	{
		mShader.Use();
		// ͶӰ����ͼ����
		glm::mat4 projection = glm::perspective(45.0f, 1.7777778f, 0.1f, 200.0f);
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		// ģ�;���
		glm::mat4 model;
		model = glm::translate(model, modelMove);
		model = glm::translate(model, glm::vec3(trans_Vect.x, trans_Vect.y, 0.0f));
		model=glm::translate(model,glm::vec3(0.0f,3.85f,-0.85f));	//�ƶ�������ԭ��
		model=glm::rotate(model,rota_Vect.x,glm::vec3(1.0f,0.0f,0.0f));
		model=glm::translate(model,glm::vec3(0.0f,-3.85f,0.85f));
//		model=glm::translate(model,glm::vec3(trans_Vect.x,trans_Vect.y,0.0f));	//�ƶ����任��λ��
		//model= glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));	
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƻ���A��
		aAxis.Draw(mShader);

	}

	//���ƻ���B��
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
		model=glm::translate(model,glm::vec3(0.0f,-2.0f,0.0f));	//�ƶ�������ԭ��
		model=glm::rotate(model,rota_Vect.y,glm::vec3(0.0f,1.0f,0.0f));
		model=glm::translate(model,glm::vec3(0.0f,2.0f,0.0f));
	//	model=glm::translate(model,glm::vec3(0.0f,0.0f,trans_Vect.z));	//�ƶ����任��λ��
	//  model= glm::scale(model, glm::vec3(0.002f, 0.002f, 0.002f));
		glUniformMatrix4fv(glGetUniformLocation(mShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//���ƻ���B��
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

	//ģ��ƽ������
	glm::vec3 trans_Vect;
	//ģ����ת�Ƕ�
	glm::vec2 rota_Vect;


	//������ɫ���Լ�������������
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