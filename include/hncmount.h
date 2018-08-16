/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
*
* 文件名称：hncmount.h
* 文件标识：根据配置管理计划书
* 摘    要：系统数据接口
* 运行平台：Linux/Windows
*
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2014年7月15日
* 说    明：返回值说明：
*           0：成功；
*           -1：参数输入不正确；
*/

#ifndef __HNC_MOUNT_H__
#define __HNC_MOUNT_H__
#include "hncdatatype.h"



#define IP_LEN (16)
#define NAME_LEN (32)     //网盘用户名长度
#define PROGADDR_LEN (32) //网盘文件夹名长度
#define PASS_LEN    (9) // 最大密码字符数为9



//////////////////////////////////////////////////////////////////////////////
//
//    Bit16 HNC_NetDiskMount(Bit8* ip, Bit8* prog_addr)
//
//    功能：
//				挂载网盘
//
//    参数：ip 网盘地址16位
//          prog_addr G代码地址 32位
//
//    描述：
//
//    返回：
//				返回0：挂载成功
//				返回非0：挂载失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetDiskMount( Bit8* ip, Bit8* progAddr, Bit8* uname = "", Bit8* uPassword = "", Bit16 clientNo = 0);

#endif // __HNC_MOUNT_H__

