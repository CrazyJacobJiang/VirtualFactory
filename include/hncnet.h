/*
* Copyright (c) 2013, 武汉华中数控股份有限公司软件开发部
* All rights reserved.
*
* 文件名称：hncnet.h
* 文件标识：根据配置管理计划书
* 摘    要：
* 运行平台：linux/winxp
*
* 版    本：1.10.01
* 作    者：江哲夫
* 日    期：2013年8月23日
* 说    明：
*/

#ifndef _HNCNET_H_
#define _HNCNET_H_

#include "hncdatatype.h"
#include "osdepend.h"

#define VERSION_LEN  32

// 时间周期类型
enum TimePeriod
{
	HEARTBEAT_TIME = 0,	           // 心跳周期
	HEARTBEAT_TIMEOUT_COUNT,	   // 心跳超时周期
	API_TIMEOUT_TIME,              // 默认接口超时时间
	PARMSAVE_TIMEOUT_TIME,         // 参数保存超时时间
	PARMSAVEAS_TIMEOUT_TIME,       // 参数另存为超时时间
	BACKUP_TIMEOUT_TIME,           // 备份超时时间
	UPDATE_TIMEOUT_TIME,           // 升级超时时间
	FILE_CHECK_TIMEOUT_TIME,       // 文件校验超时时间
};

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit16 HNC_NetInit(const Bit8 *ip, uBit16 port)
//
//    功能：
//            网络初始化
//
//    参数：
//             ip：本机IP
//			   port：本机端口
//
//    描述：
//
//
//    返回：
//            -3： windows打开socket失败
//			  -1： socket初始化失败
//			   1： 读取IP配置文件失败
//			   0： 成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit16 HNC_NetInit(const Bit8 *ip, uBit16 port);

///////////////////////////////////////////////////////////////////////////
//
//    extern void HNC_NetExit(void)
//
//    功能：
//            网络退出
//
//    参数：
//
//
//    描述：
//
//
//    返回：
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI void HNC_NetExit(void);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit16 HNC_NetIsThreadStartup(void)
//
//    功能：
//            获取网络线程开启状态
//
//    参数：
//
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			    0：网络线程未开启
//				1：网络线程已开启
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit16 HNC_NetIsThreadStartup(void);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetSetIpaddr(const Bit8 *ip, uBit16 port, Bit16 clientNo)
//
//    功能：
//            设置目标机器IP和端口号
//
//    参数：
//            ip ：		目标机器IP
//            port ：	目标机器端口号
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			  -11：clientNo索引号越界
//			    0：设置成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetSetIpaddr(const Bit8 *ip, uBit16 port, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetGetIpaddr(const Bit8 *ip, uBit16 port, Bit16 clientNo)
//
//    功能：
//            获取目标机器IP和端口号
//
//    参数：
//            ip ：		目标机器IP
//            port ：	目标机器端口号
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			  -11：clientNo索引号越界
//			    0：设置成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetGetIpaddr(Bit8 *ip, uBit16 *port, Bit16 clientNo);

HNCAPI Bit32 HNC_NetAddIpaddr(const Bit8 *ip, uBit16 port, Bit16 clientNo);

HNCAPI Bit32 HNC_NetDelIpaddr(Bit16 clientNo);

HNCAPI Bit32 HNC_NetGetClientNo(const Bit8 *ip, uBit16 port, Bit16 *clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetFileSend(const Bit8 *localname, const Bit8 *dstname, Bit16 index)
//
//    功能：
//            向目标机器发送文件
//
//    参数：
//            localname ：本地待发送文件路径
//            dstname ：目标机器接收文件后，文件保存路径
//            index ：目标机器索引号
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			  -11：clientNo索引号越界
//			   -2：本地文件打开失败
//			   -3：网络文件已被打开
//			   -4：网络文件打开失败
//			   -5：本地文件读取失败
//			   -7：文件校验出错
//				0：发送成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetFileSend(const Bit8 *localname, const Bit8 *dstname, Bit16 index);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetFileGet(const Bit8 *localname, const Bit8 *dstname, Bit16 index)
//
//    功能：
//            获取目标机器文件
//
//    参数：
//            localname ：获取目标机器文件后，本地保存路径
//            dstname ：目标机器文件路径
//            index ：目标机器索引号
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			  -11：clientNo索引号越界
//			   -2：本地文件打开失败
//			   -3：网络文件已被打开
//			   -4：网络文件打开失败
//			   -5：本地文件读取失败
//			   -7：文件校验出错
//			   -8：已有文件传输任务
//				0：获取成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetFileGet(const Bit8 *localname, const Bit8 *dstname, Bit16 index);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetFileGetDirInfo(const Bit8 *dirname, ncfind_t *info, Bit16 clientNo)
//
//    功能：
//            获取目标机器指定文件夹的信息，包括文件夹中包含的文件和子文件夹信息
//
//    参数：
//            dirname ：目标机器待获取信息的文件夹路径
//            info ：获取到的信息
//            index ：目标机器索引号
//
//    描述：
//
//
//    返回：
//            -10：网络未初始化
//			  -11：clientNo索引号越界
//			   =0：目标文件夹不存在，或者目标文件夹中没有文件和文件夹
//			   >0：获取成功
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetFileGetDirInfo(const Bit8 *dirname, ncfind_t *info, uBit16 &num, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetProgLoad(const Bit8 *filename, Bit16 ch, Bit16 clientNo)
//
//    功能：
//            从网络加载G代码
//
//    参数：
//            filename ：待加载的G代码文件路径
//            ch ：通道号
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//
//
//////////////////////////////////////////////////////////////////////////
//HNCAPI Bit32 HNC_NetProgLoad(const Bit8 *filename, Bit16 ch, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit16 HNC_NetConnect(const Bit8 *ip, uBit16 port)
//
//    功能：
//            连接目标机器，如果成功则自动分配一个clientNo
//
//    参数：
//            ip ：目标ip
//            port ：目标端口
//
//    描述：
//
//
//    返回：
//            0~255：连接成功，返回值为自动分配的clientNo
//			  其他：连接失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit16 HNC_NetConnect(const Bit8 *ip, uBit16 port);

///////////////////////////////////////////////////////////////////////////
//
//    extern uBit16 HNC_NetIsConnect(Bit16 clientNo)
//
//    功能：
//            测试目标机器是否已连接
//
//    参数：
//            clientNo ：目标机器客户号
//
//    描述：
//
//
//    返回：
//            0：已连接
//			  其他：未连接，返回错误号
//
//////////////////////////////////////////////////////////////////////////
HNCAPI uBit16 HNC_NetIsConnect(Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetFileCheck(const Bit8 *localname, const Bit8 *dstname, Bit16 clientNo)
//
//    功能：
//            比较上、下位机文件是否一致
//
//    参数：
//            localname ：获取目标机器文件后，本地保存路径
//            dstname ：目标机器文件路径
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//           0 : 成功
//           非0 ：失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetFileCheck(const Bit8 *localName, const Bit8 *dstName, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetFileRemove(const Bit8 *dstName, Bit16 clientNo)
//
//    功能：
//            删除文件
//
//    参数：
//            dstname ：目标文件名。可使用*.*删除目录下所有文件。
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//           0 : 成功
//           非0 ：失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetFileRemove(const Bit8 *dstName, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_NetMakeDir(const Bit8 *dir, Bit16 clientNo)
//
//    功能：
//            新建文件夹
//
//    参数：
//            dstname ：目标文件夹路径
//            clientNo ：目标机器索引号
//
//    描述：
//            
//
//    返回：
//           0 : 成功
//           非0 ：失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetMakeDir(const Bit8 *dir, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_NetRemoveDir(const Bit8 *dir, Bit16 clientNo)
//
//    功能：
//            删除文件夹
//
//    参数：
//            dir ：目标文件夹路径
//            clientNo ：目标机器索引号
//
//    描述：
//
//
//    返回：
//           0 : 成功
//           非0 ：失败
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetRemoveDir(const Bit8 *dir, Bit16 clientNo);

///////////////////////////////////////////////////////////////////////////
//
//    extern void HNC_NetGetDllVer(Bit8* dllVer);
//
//    功能：
//            获取DLL版本
//
//    参数：
//            dllVer ：DLL版本
//
//
//    描述：
//
//
//    返回：
//
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetGetDllVer(Bit8* dllVer);

///////////////////////////////////////////////////////////////////////////
//
//    extern void HNC_NetGetSDKVer(Bit8* dllSDKVer);
//
//    功能：
//            获取SDK版本
//
//    参数：
//            dllSDKVer : SDK版本
//
//
//    描述：
//
//
//    返回：
//
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetGetSDKVer(Bit8* dllSDKVer);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetGetPeriod(Bit32 type,Bit32* value);
//
//    功能：
//            获取目标机器网络时间设置
//
//    参数：
//            type ：网络时间周期类型
//            value: 时间周期的值
//
//
//    描述：
//
//
//    返回：
//
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetGetPeriod(Bit32 type,Bit32* value);

///////////////////////////////////////////////////////////////////////////
//
//    extern Bit32 HNC_NetSetPeriod(Bit32 type,Bit32 value);
//
//    功能：
//            获取目标机器文件
//
//    参数：
//            type ：网络时间周期类型
//            value: 时间周期的值
//
//    描述：
//
//
//    返回：
//
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetSetPeriod(Bit32 type,Bit32 value);


extern Bit32 HNC_NetEventPutFileChgLog(Bit8 *content);
#endif