#pragma once
#include <iostream>
#include <Windows.h>
// GLM ��ѧ��
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>


//���ݽṹ��
#include "dataStruct.h"


//���������
int setRand()
{
	int mrote=0;
	int i=(1+rand()%3);
	if (i>2)
		mrote=mrote+1;

	else
		mrote=mrote-1;

	return mrote;
}





