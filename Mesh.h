/*
网格加载类，OBJ文件内单个设备部件记作一个网格，网格数据由此类加载。
mesh类将获取的模型部件数据存储到模型数据内，并在最后计算单个mesh类包围盒数据
*/

#pragma once
//标准头文件
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// OpenGL库
#include <GL/glew.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//模型数据结构体
#include "modelStruct.h"

//包围盒计算
#include "meshBox.h"




class Mesh {
public:
	/*  网格数据结构  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	//包围盒数据
	glm::vec3 meshMax;
	glm::vec3 meshMin;
	
	/*  功能  */
	// 构造网格
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
	{
		//获取模型数据
		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;

		// 设置网格
		this->setupMesh();

		//网格初始化完成后调用排序函数，必须在mesh初始化的同时完成包围盒的计算。
		this->getmeshMax();
		this->getmeshMin();

	}


	// 绘制网格
	void Draw(Shader shader) 
	{
		// 绑定纹理
		GLuint diffuseNr = 1;
		GLuint specularNr = 1;
		for(GLuint i = 0; i < this->textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i); // 激活纹理
			// 查询纹理
			stringstream ss;
			string number;
			string name = this->textures[i].type;
			if(name == "texture_diffuse")
				ss << diffuseNr++; 
			else if(name == "texture_specular")
				ss << specularNr++; 
			number = ss.str(); 
			// 设置采样器
			glUniform1i(glGetUniformLocation(shader.Program, (name + number).c_str()), i);
			// 绑定纹理
			glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
		}

		// 设置属性默认值
		glUniform1f(glGetUniformLocation(shader.Program, "material.shininess"), 16.0f);

		// 绘制纹理
		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// 切换默认状态
		for (GLuint i = 0; i < this->textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}


private:
	/*  渲染数据  */
	GLuint VAO, VBO, EBO;

	/*  功能    */
	// 初始化缓冲对象
	void setupMesh()
	{
		// 创建对象
		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glGenBuffers(1, &this->EBO);

		glBindVertexArray(this->VAO);
		// 加载数据到定点缓冲区
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		
		//数据转换
		glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);  

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

		
		// V定点位置
		glEnableVertexAttribArray(0);	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		// 定点法线
		glEnableVertexAttribArray(1);	
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
		// 纹理坐标
		glEnableVertexAttribArray(2);	
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

		glBindVertexArray(0);
	}


	//mesh包围盒计算函数
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



