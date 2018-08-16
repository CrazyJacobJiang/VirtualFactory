#pragma once
// GLM数学库
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//定义仿真系统的输入数据
struct  dataStruct
{

	//模型的位置
	glm::vec3 pos_Model;
	//模型的平移变换
	glm::vec3 tran_Move;
	//模型的旋转变换
	glm::vec2 rota_Move;

	//记录机床型号
	int modelNum;
	//设备中心位置
	glm::vec3 modelCenter;
	//设备尺寸
	float modelLenght;
	

};