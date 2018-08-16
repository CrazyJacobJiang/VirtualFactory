#pragma once

// GLM ��ѧ��
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

//ģ�����ݽṹ��
//������Ϣ
struct Vertex {
	// ����
	glm::vec3 Position;
	// ����
	glm::vec3 Normal;
	// ����
	glm::vec2 TexCoords;
};

//������Ϣ
struct Texture {
	GLuint id;
	string type;
	aiString path;
};