/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncevent.h
* 文件标识：根据配置管理计划书
* 摘    要：事件接口
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年9月25日
* 说    明：
*/

#ifndef __HNC_EVENT_H__
#define __HNC_EVENT_H__

#include "eventdef.h"
#include "hncdatatype.h"


///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_EventGetSysEv(SEventElement *ev)
//
//    功能：
//            从消息队列中获取系统内部事件
//
//    参数：
//            ev ：输出参数，事件；
//
//    描述：
//            
//
//    返回：
//            0，成功；-1，失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_EventGetSysEv(SEventElement *ev);

///////////////////////////////////////////////////////////////////////////////
//
//    uBit16 HNC_EventGet(SEventElement *ev)
//
//    功能：
//            从消息队列中获取事件(系统内部事件+HNCGUI按键事件)
//
//    参数：
//            ev ：输出参数，事件；
//
//    描述：
//            
//
//    返回：
//            键值
//
//////////////////////////////////////////////////////////////////////////
extern uBit16 HNC_EventGet(SEventElement *ev);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_EventPut(SEventElement *ev, Bit16 clientNo)
//
//    功能：
//            将事件放入消息队列
//
//    参数：
//            ev ：事件；
//
//    描述：
//            
//
//    返回：
//            0：成功；-1：失败；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_EventPut(SEventElement *ev, Bit16 clientNo = 0);

#endif // __HNC_EVENT_H__
