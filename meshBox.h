//mesh���������������ⲿ

#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include<algorithm>

//ģ�����ݽ�
#include "modelStruct.h"


#include "Mesh.h"


//mesh��Χ�����ֵ�ȽϺ���
bool meshMaxX( Vertex &a,  Vertex &b)
{

	return a.Position.x>b.Position.x;

}

bool meshMaxY( Vertex&a, Vertex&b)
{

	return a.Position.y>b.Position.y;

}

bool meshMaxZ( Vertex&a, Vertex&b)
{

	return a.Position.z>b.Position.z;

}


bool meshMinX( Vertex&a, Vertex&b)
{

	return a.Position.x<b.Position.x;

}

bool meshMinY( Vertex&a, Vertex&b)
{

	return a.Position.y<b.Position.y;

}

bool meshMinZ( Vertex&a, Vertex&b)
{

	return a.Position.z<b.Position.z;

}

