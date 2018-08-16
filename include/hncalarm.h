/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncalarm.h
* 文件标识：根据配置管理计划书
* 摘    要：报警管理：报警统一编号和管理
*           1) 报警类型共计9种，分别是系统、通道、轴、伺服、PLC、设备、语法、用户PLC、HMI；
*           2) 报警级别共计2级，分别是报警和提示；
*           3) 报警号共计9位，
*              通道、语法：(1位报警类型)+(1位报警级别)+(3位通道号)+(4位报警内容编号)；
*              轴、伺服  ：(1位报警类型)+(1位报警级别)+(3位轴号)  +(4位报警内容编号)；
*              其它      ：(1位报警类型)+(1位报警级别)+(7位报警内容编号)；
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年9月25日
* 说    明：HMI开发无需调用Init/Exit；
*/

#ifndef __HNC_ALARM_H__
#define __HNC_ALARM_H__

#include "hncdatatype.h"
#include "osdepend.h"

#define EHNC_INVAL (-101) // 无效的参数
#define EHNC_FUNC  (-102) // 功能无法执行

#define ALARM_TXT_LEN (64) // 报警内容文本长度

#define ALARM_HISTORY_MAX_NUM (512) // 最大报警历史数

#define ALARM_HISTORY_FILE_NAME "ALM_LOG.DAT"

#define ALARM_PLC_USER		"PMESSAGE.TXT"
#define ALARM_SYTAX_USER	"USR_SYTAX.TXT"

//	报警错误类型
enum AlarmType
{
	ALARM_SY = 0,	//	系统报警（System）
	ALARM_CH,		//	通道报警（Channel）
	ALARM_AX,		//	轴报警（Axis）
	ALARM_SV,		//	伺服报警（Servo）
	ALARM_PC,		//	PLC报警（PLC）
	ALARM_DV,		//	设备报警（Dev）
	ALARM_PS,		//	语法报警（Program Syntax）
	ALARM_UP,		//	用户PLC报警（User PLC）
	ALARM_HM,		//	HMI报警（HMI）
	ALARM_TYPE_ALL
};

//	报警级别
enum AlarmLevel
{
	ALARM_ERR = 0,	//	错误（Error）
	ALARM_MSG,		//	提示（Message）	
	ALARM_LEVEL_ALL
};

// 报警历史记录数据
typedef struct _AlarmHistoryData
{
	Bit32 alarmNo; // 报警编号
	nctime_t timeBegin;	// 报警时间
	nctime_t timeEnd;	// 报警消除时间
	Bit8 text[ALARM_TXT_LEN]; // 报警文本
} AlarmHisData;

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmInit(void)
//
//    功能：
//            报警初始化
//
//    参数：
//            
//
//    描述：
//            
//
//    返回：
//            0，成功；-1，初始化失败；-2，语法报警文本打开失败；-3，系统报警文本打开失败；
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmInit(void);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmExit(void)
//
//    功能：
//            报警模块退出
//
//    参数：
//            
//
//    描述：
//            
//
//    返回：
//            0，成功；-1，失败；
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmExit(void);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmRefresh(Bit16 clientNo = 0)
//
//    功能：
//            报警信息刷新
//
//    参数：
//            
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmRefresh(Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmGetNum(Bit32 type, Bit32 level, Bit32 *num, Bit16 clientNo)
//
//    功能：
//           获取当前报警的数目
//
//    参数：	
//           type     ：报警类型；enum AlarmType
//           level    ：报警级别；enum AlarmLevel
//           num [out]：报警数目；
//           clientNo ：网络连接号；
//
//    描述：
//           
//
//    返回：
//           0：成功；非0：失败，参见返回值说明；
//				
///////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmGetNum(Bit32 type, Bit32 level, Bit32 *num, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmGetData(Bit32 type, Bit32 level, Bit32 index, Bit32 *alarmNo, Bit8 *alarmText, Bit16 clientNo)
//
//    功能：
//           获取当前报警的数目
//
//    参数：	
//           type     ：报警类型；enum AlarmType
//           level    ：报警级别；enum AlarmLevel
//           index    ：当前报警的索引号；
//           alarmNo [out]：输出报警号；
//           alarmText [out]：输出报警文本；(最少字符串长度为64，由调用者保证)
//           clientNo：网络连接号；
//
//    描述：
//            
//
//    返回：
//           0：成功；非0：失败，参见返回值说明；
//				
///////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmGetData(Bit32 type, Bit32 level, Bit32 index, Bit32 *alarmNo, Bit8 *alarmText, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmGetHistoryNum(Bit32 *num, Bit16 clientNo)
//
//    功能：
//            获取报警历史数
//
//    参数：
//            num [out]：报警历史的数目；
//            clientNo ：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmGetHistoryNum(Bit32 *num, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmGetHistoryData(Bit32 index, Bit32 *count, AlarmHisData *data, Bit16 clientNo)
//
//    功能：
//            获取报警历史的数据
//
//    参数：
//            index        ：报警历史的索引号；
//            count [in/out] ：[in]需要获取的报警历史的数目，[out]实际获取的数目；
//            data [out]   ：报警历史的数据；
//            clientNo     ：网络连接号；
//
//    描述：
//            获取从index开始的num条报警历史数据
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmGetHistoryData(Bit32 index, Bit32 *count, AlarmHisData *data, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmSaveHistory(Bit16 clientNo)
//
//    功能：
//            保存报警历史
//
//    参数：
//            clientNo ：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmSaveHistory(Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmClrHistory(Bit16 clientNo)
//
//    功能：
//            清空报警历史
//
//    参数：
//            clientNo ：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmClrHistory(Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmGetHistoryRecordLevel(Bit32 *level)
//
//    功能：
//            获取报警历史的记录级别
//
//    参数：
//            level    ：报警级别；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmGetHistoryRecordLevel(Bit32 *level);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmSetHistoryRecordLevel(Bit32 level)
//
//    功能：
//            设置报警历史的记录级别
//
//    参数：
//            level    ：报警级别；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmSetHistoryRecordLevel(Bit32 level);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmTransAlarmNoToStr(const Bit32 alarmNo, Bit8 *str)
//
//    功能：
//            获取报警号对应的字符串格式
//
//    参数：
//            alarmNo ：报警号；
//            str ：字符串；长度>12；
//
//    描述：
//            字符串格式：AX_ERR_00001
//
//    返回：
//            0：成功；-1：失败；
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmTransAlarmNoToStr(const Bit32 alarmNo, Bit8 *str);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmClr(Bit32 type, Bit32 level)
//
//    功能：
//            清除无效报警
//
//    参数：
//            type ：报警类型
//            level ：报警级别
//
//    描述：
//			  一些报警在报警源清除后，报警状态还没有消除，调用本接口可以将报警源已经解除的报警消除
//
//    返回：
//            
//			  0：成功；-1：失败；
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AlarmClr(Bit32 type, Bit32 level, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmAddAlarm(Bit32 type, Bit32 level, Bit32 sub, Bit32 alarmNo)
//
//    功能：
//            当前报警增加指定的报警
//
//    参数：
//            type ：报警类型；enum AlarmType
//            level ：报警级别；enum AlarmLevel
//            sub ：报警类型为：通道、语法，则为通道号；报警类型为：轴、伺服，则为轴号；其他类型：为0
//            alarmNo ：报警编号
//
//    描述：
//            暂时只支持：HMI报警（所有）、轴报警（关键参数齿轮比/编码器偏置未设置）、轴报警（电机位置丢失）
//
//    返回：
//            0：成功；-1：失败
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmAddAlarm(Bit32 type, Bit32 level, Bit32 sub, Bit32 alarmNo);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AlarmDelAlarm(Bit32 type, Bit32 level, Bit32 sub, Bit32 alarmNo)
//
//    功能：
//            当前报警删除指定的报警
//
//    参数：
//            type ：报警类型；enum AlarmType
//            level ：报警级别；enum AlarmLevel
//            sub ：报警类型为：通道、语法，则为通道号；报警类型为：轴、伺服，则为轴号；其他类型：为0
//            alarmNo ：报警编号
//
//    描述：
//            暂时只支持：HMI报警（所有）、轴报警（关键参数齿轮比/编码器偏置未设置）、轴报警（电机位置丢失）
//
//    返回：
//            0：成功；-1：失败
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 HNC_AlarmDelAlarm(Bit32 type, Bit32 level, Bit32 sub, Bit32 alarmNo);

#endif // __HNC_ALARM_H__
