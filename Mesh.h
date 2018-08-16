/*
��������࣬OBJ�ļ��ڵ����豸��������һ���������������ɴ�����ء�
mesh�ཫ��ȡ��ģ�Ͳ������ݴ洢��ģ�������ڣ����������㵥��mesh���Χ������
*/

#pragma once
//��׼ͷ�ļ�
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// OpenGL��
#include <GL/glew.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//ģ�����ݽṹ��
#include "modelStruct.h"

//��Χ�м���
#include "meshBox.h"




class Mesh {
public:
	/*  �������ݽṹ  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	//��Χ������
	glm::vec3 meshMax;
	glm::vec3 meshMin;
	
	/*  ����  */
	// ��������
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
	{
		//��ȡģ������
		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;

		// ��������
		this->setupMesh();

		//�����ʼ����ɺ������������������mesh��ʼ����ͬʱ��ɰ�Χ�еļ��㡣
		this->getmeshMax();
		this->getmeshMin();

	}


	// ��������
	void Draw(Shader shader) 
	{
		// ������
		GLuint diffuseNr = 1;
		GLuint specularNr = 1;
		for(GLuint i = 0; i < this->textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i); // ��������
			// ��ѯ����
			stringstream ss;
			string number;
			string name = this->textures[i].type;
			if(name == "texture_diffuse")
				ss << diffuseNr++; 
			else if(name == "texture_specular")
				ss << specularNr++; 
			number = ss.str(); 
			// ���ò�����
			glUniform1i(glGetUniformLocation(shader.Program, (name + number).c_str()), i);
			// ������
			glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
		}

		// ��������Ĭ��ֵ
		glUniform1f(glGetUniformLocation(shader.Program, "material.shininess"), 16.0f);

		// ��������
		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// �л�Ĭ��״̬
		for (GLuint i = 0; i < this->textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}


private:
	/*  ��Ⱦ����  */
	GLuint VAO, VBO, EBO;

	/*  ����    */
	// ��ʼ���������
	void setupMesh()
	{
		// ��������
		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glGenBuffers(1, &this->EBO);

		glBindVertexArray(this->VAO);
		// �������ݵ����㻺����
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		
		//����ת��
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);  

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

		
		// V����λ��
		glEnableVertexAttribArray(0);	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		// ���㷨��
		glEnableVertexAttribArray(1);	
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
		// ��������
		glEnableVertexAttribArray(2);	
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

		glBindVertexArray(0);
	}


	//mesh��Χ�м��㺯��
	void getmeshMax()
	{

		sort(vertices.begin(),vertices.end(),meshMaxX);
		this->meshMax.x=vertices[0].Position.x;

		sort(vertices.begin(),vertices.end(),meshMaxY);
		this->meshMax.y=vertices[0].Position.y;

		sort(vertices.begin(),vertices.end(),meshMaxZ);
		this->meshMax.z=vertices[0].Position.z;

	}

	void getmeshMin()
	{

		sort(vertices.begin(),vertices.end(),meshMinX);
		this->meshMin.x=vertices[0].Position.x;

		sort(vertices.begin(),vertices.end(),meshMinY);
		this->meshMin.y=vertices[0].Position.y;

		sort(vertices.begin(),vertices.end(),meshMinZ);
		this->meshMin.z=vertices[0].Position.z;

	}

};



