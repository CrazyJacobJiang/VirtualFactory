/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：eventdef.h
* 文件标识：根据配置管理计划书
* 摘    要：系统事件定义
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2010年3月18日
* 说    明：
*/

#ifndef __EVENT_DEF_H__
#define __EVENT_DEF_H__

#include "hncdatatype.h"

#define MAX_EVENT_NUM 512
#define MAX_RESERVE_DATA_LEN	128

typedef struct _EventElement
{
    Bit16 src;	 // 事件来源
    uBit16 code; // 事件代码
	Bit8 buf[MAX_RESERVE_DATA_LEN];
} SEventElement;

typedef struct _MSTInfo
{
	Bit16 num;
	Bit32 line;
}mstinfo;

#define _hncevent_get_size() sizeof(SEventElement)*(MAX_EVENT_NUM+8)


// 一. 定义事件来源
#define	EV_SRC_SYS	0x010		// 系统事件

#define	EV_SRC_CH0	0x100		// 通道0事件 0x100~0x10f

#define	EV_SRC_MDI	0x110		// MDI的事件 

#define EV_SRC_KBD	0x200		// 键盘事件

#define EV_SRC_AX0	0x300		// 轴事件

#define EV_SRC_NET	0x400		//网络事件

// 二. 定义事件代码
// 1. 定义键盘代码
//								0x  0	009
//								   ---	---
//						组号		|	|         子码
//						------------	--------------
//				0：单键组，标准ASCII码，目前包含两类，1）字符键，0x00yy
//														2）功能键, 0x01yy
//				1：ctrl组，组合键=0x1000+单键值
//				2：alt组，组合键=0x2000+单键值
//				3：shift组，组合键=0x3000+单键值
//				7：其他
//				暂不考虑三键组合键
//
						
#define kbNoKey		0x0000

// 00---字符键，标准ASCA码定义：'A'~'Z','0'~'9','*','!'......

#define kbSpace		0x0020
#define kbBack      0x0008
#define kbTab		0x0009
#define kbEnter		0x000d
// 01---功能键

#define kbShift		0x0110
#define kbCtrl		0x0111
#define kbAlt		0x0112
#define kbPause		0x0113
#define kbCapsLk	0x0114
#define kbEsc       0x011b

#define kbPgUp      0x0121
#define kbPgDn      0x0122
#define kbEnd       0x0123
#define kbHome      0x0124
#define kbLeft      0x0125
#define kbUp        0x0126
#define kbRight     0x0127
#define kbDown      0x0128
#define kbIns       0x012d
#define kbDel       0x012e

#define kbF1        0x0170
#define kbF2        0x0171
#define kbF3        0x0172
#define kbF4        0x0173
#define kbF5        0x0174
#define kbF6        0x0175
#define kbF7        0x0176
#define kbF8        0x0177
#define kbF9        0x0178
#define kbF10       0x0179
#define kbF11       0x017a
#define kbF12       0x017b

// ctrl组合键
#define CtrlBase	0x1000

#define	kbCtrlA		(CtrlBase+'A')
#define kbCtrlB     (CtrlBase+'B')
#define kbCtrlC     (CtrlBase+'C')
#define kbCtrlD     (CtrlBase+'D')
#define kbCtrlE     (CtrlBase+'E')
#define kbCtrlF     (CtrlBase+'F')
#define kbCtrlG     (CtrlBase+'G')
#define kbCtrlH     (CtrlBase+'H')
#define kbCtrlI     (CtrlBase+'I')
#define kbCtrlJ     (CtrlBase+'J')
#define kbCtrlK     (CtrlBase+'K')
#define kbCtrlL     (CtrlBase+'L')
#define kbCtrlM     (CtrlBase+'M')
#define kbCtrlN     (CtrlBase+'N')
#define kbCtrlO     (CtrlBase+'O')
#define kbCtrlP     (CtrlBase+'P')
#define kbCtrlQ     (CtrlBase+'Q')
#define kbCtrlR     (CtrlBase+'R')
#define kbCtrlS     (CtrlBase+'S')
#define kbCtrlT     (CtrlBase+'T')
#define kbCtrlU     (CtrlBase+'U')
#define kbCtrlV     (CtrlBase+'V')
#define kbCtrlW     (CtrlBase+'W')
#define kbCtrlX     (CtrlBase+'X')
#define kbCtrlY     (CtrlBase+'Y')
#define kbCtrlZ     (CtrlBase+'Z')

#define kbCtrlF1    (CtrlBase+kbF1)
#define kbCtrlF2    (CtrlBase+kbF2)
#define kbCtrlF3    (CtrlBase+kbF3)
#define kbCtrlF4    (CtrlBase+kbF4)
#define kbCtrlF5    (CtrlBase+kbF5)
#define kbCtrlF6    (CtrlBase+kbF6)
#define kbCtrlF7    (CtrlBase+kbF7)
#define kbCtrlF8    (CtrlBase+kbF8)
#define kbCtrlF9    (CtrlBase+kbF9)
#define kbCtrlF10   (CtrlBase+kbF10)
#define kbCtrlF11   (CtrlBase+kbF11)
#define kbCtrlF12   (CtrlBase+kbF12)

#define kbCtrlSpace	(CtrlBase+kbSpace)
#define kbCtrlPgUp  (CtrlBase+kbPgUp)
#define kbCtrlPgDn  (CtrlBase+kbPgDn)
#define kbCtrlEnd   (CtrlBase+kbEnd)
#define kbCtrlHome  (CtrlBase+kbHome)
#define kbCtrlLeft  (CtrlBase+kbLeft)
#define kbCtrlUp    (CtrlBase+kbUp)
#define kbCtrlRight (CtrlBase+kbRight)
#define kbCtrlDown  (CtrlBase+kbDown)
#define kbCtrlIns   (CtrlBase+kbIns)
#define kbCtrlDel   (CtrlBase+kbDel)

#define kbCtrlBack  (CtrlBase+kbBack)
#define kbCtrlEnter (CtrlBase+kbEnter)

// alt组合键
#define AltBase		0x2000

#define kbAltSpace  (AltBase+kbSpace)

#define kbAltA      (AltBase+'A')
#define kbAltB      (AltBase+'B')
#define kbAltC      (AltBase+'C')
#define kbAltD      (AltBase+'D')
#define kbAltE      (AltBase+'E')
#define kbAltF      (AltBase+'F')
#define kbAltG      (AltBase+'G')
#define kbAltH      (AltBase+'H')
#define kbAltI      (AltBase+'I')
#define kbAltJ      (AltBase+'J')
#define kbAltK      (AltBase+'K')
#define kbAltL      (AltBase+'L')
#define kbAltM      (AltBase+'M')
#define kbAltN      (AltBase+'N')
#define kbAltO      (AltBase+'O')
#define kbAltP      (AltBase+'P')
#define kbAltQ      (AltBase+'Q')
#define kbAltR      (AltBase+'R')
#define kbAltS      (AltBase+'S')
#define kbAltT      (AltBase+'T')
#define kbAltU      (AltBase+'U')
#define kbAltV      (AltBase+'V')
#define kbAltW      (AltBase+'W')
#define kbAltX      (AltBase+'X')
#define kbAltY      (AltBase+'Y')
#define kbAltZ      (AltBase+'Z')

#define kbAlt1      (AltBase+'1')
#define kbAlt2      (AltBase+'2')
#define kbAlt3      (AltBase+'3')
#define kbAlt4      (AltBase+'4')
#define kbAlt5      (AltBase+'5')
#define kbAlt6      (AltBase+'6')
#define kbAlt7      (AltBase+'7')
#define kbAlt8      (AltBase+'8')
#define kbAlt9      (AltBase+'9')
#define kbAlt0      (AltBase+'0')

#define kbAltF1     (AltBase+kbF1)
#define kbAltF2     (AltBase+kbF2)
#define kbAltF3     (AltBase+kbF3)
#define kbAltF4     (AltBase+kbF4)
#define kbAltF5     (AltBase+kbF5)
#define kbAltF6     (AltBase+kbF6)
#define kbAltF7     (AltBase+kbF7)
#define kbAltF8     (AltBase+kbF8)
#define kbAltF9     (AltBase+kbF9)
#define kbAltF10    (AltBase+kbF10)
#define kbAltF11    (AltBase+kbF11)
#define kbAltF12    (AltBase+kbF12)

#define kbAltMinus  (AltBase+'-')
#define kbAltEqual  (AltBase+'=')

#define kbAltUp		(AltBase+kbUp)
#define kbAltDown	(AltBase+kbDown)
#define kbAltLeft	(AltBase+kbLeft)
#define kbAltRight	(AltBase+kbRight)	

// shift组合键
#define ShiftBase	0x3000

#define kbShiftF1   (ShiftBase+kbF1)
#define kbShiftF2   (ShiftBase+kbF2)
#define kbShiftF3   (ShiftBase+kbF3)
#define kbShiftF4   (ShiftBase+kbF4)
#define kbShiftF5   (ShiftBase+kbF5)
#define kbShiftF6   (ShiftBase+kbF6)
#define kbShiftF7   (ShiftBase+kbF7)
#define kbShiftF8   (ShiftBase+kbF8)
#define kbShiftF9   (ShiftBase+kbF9)
#define kbShiftF10  (ShiftBase+kbF10)
#define kbShiftF11  (ShiftBase+kbF11)
#define kbShiftF12  (ShiftBase+kbF12)

#define kbShiftIns  (ShiftBase+kbIns)
#define kbShiftDel  (ShiftBase+kbDel)
#define kbShiftTab  (ShiftBase+kbTab)

#define kbIdle		(0x7fff)
#define kbRealRe	(0x7ffe)	// 只要系统查询事件队列无条件执行

#define kbReset		kbCtrlZ 	
#define kbReturn	kbF11	// 第二返回键

// 2. 定义通道事件
#define	ncEvtPrgStart	0xa001	// 程序启动
#define ncEvtPrgEnd		0xa002	// 程序结束
#define	ncEvtPrgHold	0xa003	// Hold完成	
#define	ncEvtPrgBreak	0xa004	// break完成	
#define	ncEvtG92Fin		0xa005	// G92完成
#define	ncEvtRstFin		0xa006	// 上电复位完成
#define	ncEvtRwndFin	0xa007	// 重运行完成
#define ncEvtMdiRdy		0xa008	// MDI准备好
#define	ncEvtMdiExit	0xa009	// MDI退出
#define	ncEvtMdiAck		0xa00a	// MDI行解释完成
#define	ncEvtRunStart	0xa00b	// 程序运行

#define	ncEvtRunRowAck	0xa00d	// 任意行请求应答
#define	ncEvtRunRowRdy	0xa00e	// 任意行准备好

#define ncEvtBpSaved	0xa011	// 断点保存完成
#define ncEvtBpResumed	0xa012	// 断点恢复完成
#define ncEvtIntvHold	0xa013	// 执行到M92等待用户干预
#define	ncEvtEstop		0xa014	// 外部急停
#define	ncEvtLoadOK		0xa015	// 程序加载完成

#define	ncEvtSyntax1	0xa016	// 第一类语法错【修改后可接着运行】
#define	ncEvtSyntax2	0xa017	// 第二类语法错【修改后从头运行】

#define	ncEvtGcodeSave	0xa018	// 程序中的数据保存指令
#define ncEvtLoadData	0xa019	// 程序中的数据加载指令
#define ncEvtChgTool	0xa01a	// G代码修改了刀具数据
#define ncEvtChgCrds	0xa01b	// G代码修改了坐标系数据
#define ncEvtChgAxes	0xa01c	// 通道轴组发生了改变
#define ncEvtChgVar	    0xa01d	// G代码修改变量

#define ncEvtNckNote	0xa01e	// 通道提示
#define ncEvtNckAlarm	0xa01f	// 通道报警
#define ncEvtStopAck	0xa020	// sys_stop_prog完成
// #define ncEvtMcode      0xa021
// #define ncEvtS0code     0xa022
// #define ncEvtS1code     0xa023
// #define ncEvtS2code     0xa024
// #define ncEvtS3code     0xa025
// #define ncEvtTcode      0xa026
#define ncEvtRandomRowFinish      0xa027 //任意行扫描完成
//#define ncEVtRandomRowRunFinish   0xa028 //任意行执行完成
#define ncEVtRandomRowRequestProg 0xa029 //任意行扫描模式请求程序管理器准备好程序
#define ncEvtFaultIrq	0xa030	// 故障中断
#define ncEvtPackFin	0xa040	// 数据打包完成

#define ncEvtAlarmChg	0xa055	// 报警产生或消除
#define ncEvtFileChg	0xa056	// 文件修改

#define ncEvtConnect	0xa060	// nc连接
#define ncEvtDisConnect	0xa061	// nc断开连接
#define ncEvtFileSend	0xa062	// 传送文件完毕


// 3. 定义轴事件
#define ncEvtMaxEncPos	0xa201	// 轴编码器初始位置过大
#define ncEvtMaxACC 	0xa202	// 轴加速度过大


// 4. 定义系统事件
#define ncEvtPoweroff	0xa800	// 系统断电
#define ncEvtSaveData	0xa801	// 保存系统数据
#define ncEvtSysExit	0xa802	// 系统退出

#define ncEvtUserStart	0xb000	// 用户自定义事件 保留100个

#define ncEvtUserFunc1  (ncEvtUserStart+100)	// event 100 对应用户按键调用指定程序
#define ncEvtUserFunc2  (ncEvtUserStart+101)	// event 100 对应用户按键调用指定程序
#define ncEvtHardRstFin	(ncEvtUserStart+102)	// 硬复位完成
#define ncEvtSaveRegB	(ncEvtUserStart+103)	// 保存B寄存器
#define ncEvtUserReqChn	(ncEvtUserStart+104)	// 请求切换通道
#define ncEvtUserReqMsk	(ncEvtUserStart+105)	// 请求屏蔽通道
#define ncEvtReserve0   (ncEvtUserStart+106)	// 用户保留PLC事件
#define ncEvtReserve1   (ncEvtUserStart+107)	// 用户保留PLC事件
#define ncEvtReserve2   (ncEvtUserStart+108)	// 用户保留PLC事件
#define ncEvtReserve3   (ncEvtUserStart+109)	// 用户保留PLC事件

#define ncEvtChFin0		(ncEvtUserStart+110)	// 通道0加工完成
#define ncEvtChFin1		(ncEvtUserStart+111)	// 通道1加工完成
#define ncEvtChFin2		(ncEvtUserStart+112)	// 通道2加工完成
#define ncEvtChFin3		(ncEvtUserStart+113)	// 通道3加工完成
#define ncEvtChFin		(ncEvtUserStart+114)	// 加工完成事件

#define ncEvtRstMsg		(ncEvtUserStart+120)	// 复位消息

#define ncEvtRigChg		(ncEvtUserStart+121)	// 钥匙锁切换权限消息

#define ncEvtRfidReadTag	(ncEvtUserStart+122)	// RFID读电子标签数据到CNC
#define ncEvtRfidWriteTag	(ncEvtUserStart+123)	// RFID写CNC数据到电子标签

#endif // __EVENT_DEF_H__
