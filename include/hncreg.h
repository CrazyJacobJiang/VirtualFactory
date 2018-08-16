/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncreg.h
* 文件标识：根据配置管理计划书
* 摘    要：寄存器接口
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年6月20日
* 说    明：返回值说明：
*           0：成功；
*           1：异步获取寄存器，未获取到寄存器数据；
*           -1：寄存器类型错误；
*           -2：寄存器组号超过最大限制；
*           -3：寄存器位号超过最大限制；
*           -4：寄存器不允许修改（P寄存器）；
*           -5：寄存器值指针为空；
*/

#ifndef __HNC_REG_H__
#define __HNC_REG_H__

#include "hncdatatype.h"

// 寄存器类型
enum HncRegType
{
	REG_TYPE_X = 0,	// X寄存器 Bit8
	REG_TYPE_Y,		// Y寄存器 Bit8
	REG_TYPE_F,		// F寄存器 Bit16
	REG_TYPE_G,		// G寄存器 Bit16
	REG_TYPE_R,		// R寄存器 Bit8
	REG_TYPE_W,		// W寄存器 Bit16
	REG_TYPE_D,		// D寄存器 Bit32
	REG_TYPE_B,		// B寄存器 Bit32
	REG_TYPE_P,		// P寄存器 Bit32
	REG_TYPE_TOTAL
};

// FG寄存器基地址
enum HncRegFGBaseType
{
	REG_FG_SYS_BASE = (REG_TYPE_TOTAL+1),	// 系统数据基址 {Get(Bit32)}
	REG_FG_CHAN_BASE,		// 通道数据基址 {Get(Bit32)}
	REG_FG_AXIS_BASE,		// 轴数据基址 {Get(Bit32)}
	REG_FG_BASE_TYPE_TOTAL
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo);
//
//    功能：
//            获取寄存器的值
//
//    参数：
//            type		：寄存器类型；enum HncRegType
//            index		：寄存器组号；
//            value		：寄存器值；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo)
//
//    功能：
//            设置寄存器的值
//
//    参数：
//            type		：寄存器类型；enum HncRegType
//            index		：寄存器组号；
//            value		：寄存器值；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    功能：
//            设置寄存器数据的一位
//
//    参数：
//            type		：寄存器类型；enum HncRegType
//            index		：寄存器组号；
//            bit		：寄存器位号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    功能：
//            清除寄存器数据的一位
//
//    参数：
//            type		：寄存器类型；enum HncRegType
//            index		：寄存器组号；
//            bit		：寄存器位号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo)
//
//    功能：
//            获取寄存器的总组数
//
//    参数：
//            type		：寄存器类型；enum HncRegType
//            num		：寄存器组数；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo)
//
//    功能：
//            获取FG寄存器的基址
//
//    参数：
//            baseType	：基址类型；enum HncRegFGBaseType
//            baseIndex	：基址寄存器组号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo = 0);

#endif // __HNC_REG_H__
