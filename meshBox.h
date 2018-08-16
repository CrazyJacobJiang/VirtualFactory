//mesh排序函数定义在类外部

#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include<algorithm>

//模型数据结
#include "modelStruct.h"


#include "Mesh.h"


//mesh包围盒最大值比较函数
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

