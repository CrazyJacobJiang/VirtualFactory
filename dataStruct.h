#pragma once
// GLM��ѧ��
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//�������ϵͳ����������
struct  dataStruct
{

	//ģ�͵�λ��
	glm::vec3 pos_Model;
	//ģ�͵�ƽ�Ʊ任
	glm::vec3 tran_Move;
	//ģ�͵���ת�任
	glm::vec2 rota_Move;

	//��¼�����ͺ�
	int modelNum;
	//�豸����λ��
	glm::vec3 modelCenter;
	//�豸�ߴ�
	float modelLenght;
	

};