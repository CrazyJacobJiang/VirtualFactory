//model���������������ⲿ
#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include<algorithm>

#include "Mesh.h"

//model��Χ�бȽϺ���

bool modelMaxX(Mesh &a,Mesh &b)
{
	return a.meshMax.x>b.meshMax.x;


}

bool modelMaxY(Mesh &a,Mesh &b)
{
	return a.meshMax.y>b.meshMax.y;


}

bool modelMaxZ(Mesh &a,Mesh &b)
{
	return a.meshMax.z>b.meshMax.z;


}

bool modelMinX(Mesh &a,Mesh &b)
{
	return a.meshMin.x<b.meshMin.x;


}

bool modelMinY(Mesh &a,Mesh &b)
{

	return a.meshMin.y<b.meshMin.y;


}

bool modelMinZ(Mesh &a,Mesh &b)
{
	return a.meshMin.z<b.meshMin.z;


}