/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
*
* 文件名称：hnccrds.h
* 文件标识：根据配置管理计划书
* 摘    要：通道数据接口
* 运行平台：Linux/Windows
*
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年7月17日
* 说    明：返回值说明：
*           0：成功；
*           -1：参数输入不正确；
*           -2：接口不提供该功能；
*/

#ifndef __HNC_CRDS_H__
#define __HNC_CRDS_H__

#include "hncdatatype.h"

// 坐标系数据类型
// 未标注类型的是Bit32
enum HncCRDS
{
	HNC_CRDS_CH_G5X_ZERO = 0, // 指定通道轴坐标系零点
	HNC_CRDS_CH_G5X_ID,       // 指定通道轴坐标系ID
	HNC_CRDS_CH_WCS_ZERO,     // 指定通道轴工件坐标系零点
	HNC_CRDS_CH_REL_ZERO,     // 指定通道轴相对坐标系零点
	HNC_CRDS_CH_FRAME_ZERO,   // 指定通道轴基架坐标系零点
	HNC_CRDS_G68_PNT1,        // 特性坐标系辅助点1坐标
	HNC_CRDS_G68_PNT2,        // 特性坐标系辅助点2坐标
	HNC_CRDS_G68_ZERO,        // 特性坐标系零点
	HNC_CRDS_G68_VCT,         // 特性坐标系向量 fBit64
	HNC_CRDS_CH_G5X_OFFSET_ZERO,  //指定通道轴坐标系偏置零点
	HNC_CRDS_TOTAL
};

//	取系统定义的各类坐标系数目
enum HncCrdsMaxNum
{
	G5EXT_MAX_NUM,		//	G54.X扩展坐标系的数目
	CHG_WCS_MAX_NUM,	//	进给保持时的临时工件坐标系数目
	TCS_MAX_NUM			//	TCS坐标系数目
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, void *value, Bit32 ch, Bit32 crds, Bit16 clientNo)
//
//    功能：
//            获取坐标系数据的值
//
//    参数：
//            type		：坐标系数据的类型；
//            ax		：轴号；
//            value		：坐标系数据的值；
//            ch		：通道号；
//            crds		：坐标系编号；
//            clientNo	：网络连接号；
//
//    描述：
//
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_CrdsGetValue(Bit32 type, Bit32 ax, void *value, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_CrdsSetValue(Bit32 type, Bit32 ax, void *val, Bit32 ch, Bit32 crds, Bit16 clientNo)
//
//    功能：
//            设置坐标系数据的值
//
//    参数：
//            type		：坐标系数据的类型；
//            ax		：轴号；
//            value		：坐标系数据的值；
//            ch		：通道号；
//            crds		：坐标系编号；
//            clientNo	：网络连接号；
//
//    描述：
//
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_CrdsSetValue(Bit32 type, Bit32 ax, void *val, Bit32 ch = -1, Bit32 crds = -1, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_CrdsGetMaxNum(HncCrdsMaxNum type)
//
//    功能：
//            取系统定义的各类坐标系数目
//
//    参数：
//
//    描述：
//
//    返回：
//            -1，错误；其他：返回type对应的坐标系数目
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_CrdsGetMaxNum(Bit32 type, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_CrdsLoad(void)
//
//    功能：
//            坐标系数据从文件加载
//
//    参数：
//
//    描述：
//            优先载入原文件，如果原文件损坏将载入备份文件
//
//    返回：
//            0：成功；-1：上次保存坐标系文件有异常,请核实坐标系数据；-2：载入失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_CrdsLoad(Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    void sys_crds_save(Bit16 clientNo)
//
//    功能：
//            坐标数据保存
//
//    参数：
//
//    描述：
//
//
//    返回：
//            0：成功；-1：失败；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_CrdsSave(Bit16 clientNo = 0);

#endif // __HNC_CRDS_H__
