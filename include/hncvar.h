/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncvar.h
* 文件标识：根据配置管理计划书
* 摘    要：变量接口
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年6月20日
* 说    明：返回值说明：
*           0：成功；
*           1：异步获取变量，未获取到数据；
*           -1：函数与变量类型不匹配；
*           -2：轴号超过限制；
*           -3：通道号超过限制；
*           -4：轴变量索引号超过限制；
*           -5：通道变量索引号超过限制；
*           -6：系统变量索引号超过限制；
*           -7：变量位号超过限制；
*           -8：变量值指针为空；
*/

#ifndef __HNC_VAR_H__
#define __HNC_VAR_H__

#include "hncdatatype.h"

// 变量类型
enum HncVarType
{
	VAR_TYPE_AXIS = 0,	// 轴变量 {Get(Bit32), Set(Bit32)}
	VAR_TYPE_CHANNEL,	// 通道变量 {Get(Bit32), Set(Bit32)}
	VAR_TYPE_SYSTEM,	// 系统变量 {Get(Bit32), Set(Bit32)}
	VAR_TYPE_SYSTEM_F,	// 浮点类型的系统变量 {Get(fBit64), Set(fBit64)}
	VAR_TYPE_TOTAL
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, void *value, Bit16 clientNo)
//
//    功能：
//            获取变量的值
//
//    参数：
//            type		：变量类型；enum HncVarType
//            no		：轴号或者通道号；
//            index		：索引号；
//            value		：变量值；
//            clientNo	：网络连接号；
//
//    描述：
//            no：轴变量填轴号；通道变量填通道号；系统变量填0；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VarGetValue(Bit32 type, Bit32 no, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, void *value, Bit16 clientNo)
//
//    功能：
//            设置变量的值
//
//    参数：
//            type		：变量类型；enum HncVarType
//            no		：轴号或者通道号；
//            index		：索引号；
//            value		：变量值；
//            clientNo	：网络连接号；
//
//    描述：
//            no：轴变量填轴号；通道变量填通道号；系统变量填0；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VarSetValue(Bit32 type, Bit32 no, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VarSetBit(Bit32 type, Bit32 no, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    功能：
//            设置变量数据的一位
//
//    参数：
//            type		：变量类型；enum HncVarType
//            no		：轴号或者通道号；
//            index		：索引号；
//            bit		：变量位号；
//            clientNo	：网络连接号；
//
//    描述：
//            no：轴变量填轴号；通道变量填通道号；系统变量填0；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VarSetBit(Bit32 type, Bit32 no, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VarClrBit(Bit32 type, Bit32 no, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    功能：
//            清除变量数据的一位
//
//    参数：
//            type		：变量类型；enum HncVarType
//            no		：轴号或者通道号；
//            index		：索引号；
//            bit		：变量位号；
//            clientNo	：网络连接号；
//
//    描述：
//            no：轴变量填轴号；通道变量填通道号；系统变量填0；
//
//    返回： 
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VarClrBit(Bit32 type, Bit32 no, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_MacroVarGetValue(Bit32 no, SDataUnion *var, Bit16 clientNo)
//
//    功能：
//            获取宏变量的值
//
//    参数：
//            no		：变量编号；
//            var		：变量值；
//            clientNo	：网络连接号；
//
//    描述：
//            变量编号说明：
//            [0, 2999]：通道变量；
//            [40000, 59999]：系统变量；其中，[50000, 54999]：用户自定义变量；
//            [60000, 69999]：轴变量；
//            [70000, 99999]：刀具变量；
//            详细说明参见《华中8型数控系统用户说明书》的用户宏程序；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_MacroVarGetValue(Bit32 no, SDataUnion *var, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_MacroVarSetValue(Bit32 no, SDataUnion *var, Bit16 clientNo)
//
//    功能：
//            设置宏变量的值
//
//    参数：
//            no		：变量编号；
//            var		：变量值；
//            clientNo	：网络连接号；
//
//    描述：
//            设置用户自定义变量[50000, 54999]；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_MacroVarSetValue(Bit32 no, SDataUnion *var, Bit16 clientNo = 0);

#endif // __HNC_VAR_H__
