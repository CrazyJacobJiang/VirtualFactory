/*
* Copyright (c) 2013, 武汉华中数控股份有限公司开发二部
* All rights reserved.
*
* 文件名称：hncverify.h
* 文件标识：根据配置管理计划书
* 摘    要：提供校验图形绘制部分接口函数，校验时，直接根据指令计算出轨迹
			然后绘出。


* 运行平台：linux/winxp
*
* 版    本：
* 作    者：吴烜辉
* 日    期：2013年9月6日
* 说    明：


*/

#ifndef __VERIFY_H__
#define __VERIFY_H__
#include "hncdatatype.h"
#include "hncdatadef.h"
enum TCURVETYPE
{
	TCURVE_TYPE_NONE,	//没有曲线类型
	TCURVE_TYPE_LINE,	//直线
	TCURVE_TYPE_CYCLE,		//圆弧
	TCURVE_TYPE_THREAD,        //螺纹
};
///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurveType(Bit32 ch, Bit32* curtype, Bit16 clientNo = 0);
//
//    功能：
//            获取曲线类型
//
//    参数：
//            ch ：通道号；
//            curtype : 曲线类型 enum TCURVETYPE
//            clientNo: 网络连接号
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveType(Bit32 ch, Bit32* curtype, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_VerifyGetCurveSpos(Bit32 ch,Bit32 ax, Bit64* spos, Bit16 clientNo = 0);
//
//    功能：
//            获取曲线起点
//
//    参数：
//            ch ：通道号；
//			  ax ：轴号
//            spos: 起点
//            clientNo: 网络连接号
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveSpos(Bit32 ch,Bit32 ax, Bit64* spos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurveEpos(Bit32 ch,Bit32 ax, Bit64* epos, Bit16 clientNo = 0);
//
//    功能：
//            获取曲线终点
//
//    参数：
//            ch ：通道号；
//			  ax ：轴号
//            epos:曲线终点
//            clientNo: 网络连接号
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveEpos(Bit32 ch,Bit32 ax, Bit64* epos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetLinePos(Bit32 ch, Bit32 pos[], Bit32* flag, Bit16 clientNo = 0);
//
//    功能：
//            获取直线校验中间点
//
//    参数：
//            ch ：通道号；
//            flag : 校验标志 0：单段直线校验完成 1：单段直线校验未完成
//            clientNo: 网络连接号
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetLinePos(Bit32 ch, Bit32 pos[CHAN_AXES_NUM], Bit32* flag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyClearCurve(Bit32 ch, Bit16 clientNo = 0);
//
//    功能：
//            曲线校验完毕
//
//    参数：
//            ch ：通道号；
//            clientNo: 网络连接号
//
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyClearCurve(Bit32 ch, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurvePoint(Bit32 ch,Bit32 pos[3], Bit32* vflag, Bit16 clientNo = 0);
//
//    功能：
//           圆弧曲线校验中间点
//
//    参数：
//            ch ：通道号；
//			  pos[3] ：中间点
//            vflag:校验标志 0：单段圆弧校验完成 1：单段圆弧校验未完成
//            clientNo: 网络连接号
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurvePoint(Bit32 ch,Bit32 pos[3], Bit32* vflag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyCalcuCyclePara(Bit32 ch ,Bit8* vflag, Bit16 clientNo = 0);
//
//    功能：
//           计算圆弧参数
//
//    参数：
//            ch ：通道号；
//            vflag:0,1
//            clientNo: 网络连接号
//
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyCalcuCyclePara(Bit32 ch, Bit8* vflag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifySetChCmdPos(Bit32 ch,Bit32 ax,Bit64 pos, Bit16 clientNo = 0);
//
//    功能：
//          设置通道指令点
//
//    参数：
//            ch ：通道号；
//			  ax ： 轴号
//			  pos：中间点
//            clientNo: 网络连接号
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifySetChCmdPos(Bit32 ch,Bit32 ax,Bit64 pos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCmdPos(Bit32 ax,Bit64* pos, Bit16 clientNo = 0);
//
//    功能：
//          获取通道指令点
//
//    参数：
//            ax ：轴号；
//            pos: 位置
//            clientNo: 网络连接号
//
//    描述：
//
//
//    返回：
//            0:成功
//           -1:失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCmdPos(Bit32 ax, Bit64* pos, Bit16 clientNo = 0);


#endif