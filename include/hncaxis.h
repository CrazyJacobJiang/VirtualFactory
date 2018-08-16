/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncaxis.h
* 文件标识：根据配置管理计划书
* 摘    要：轴接口（逻辑轴）
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年6月20日
* 说    明：返回值说明：
*           0：成功；
*           -1：参数输入不正确；
*           -2：接口不提供该功能；
*/

#ifndef __HNC_AXIS_H__
#define __HNC_AXIS_H__

#include "hncdatatype.h"

// 轴数据类型
// Get(Bit32)表示Get数据时void *为Bit32 *
enum HncAxis
{
	HNC_AXIS_NAME = 0,		// 轴名 {Get(Bit8[PARAM_STR_LEN])}
	HNC_AXIS_TYPE,			// 轴类型 {Get(Bit32)}
	HNC_AXIS_CHAN,			// 获取通道号 {Get(Bit32)}
	HNC_AXIS_CHAN_INDEX,	// 获取在通道中的轴号 {Get(Bit32)}
	HNC_AXIS_CHAN_SINDEX,	// 获取在通道中的主轴号 {Get(Bit32)}
	HNC_AXIS_LEAD,			// 获取引导轴 {Get(Bit32)}
	HNC_AXIS_ACT_POS,		// 机床实际位置 {Get(Bit32)}
	HNC_AXIS_ACT_POS2,		// 机床实际位置2 {Get(Bit32)}
	HNC_AXIS_CMD_POS,		// 机床指令位置 {Get(Bit32)}
	HNC_AXIS_ACT_POS_WCS,	// 工件实际位置 {Get(Bit32)}
	HNC_AXIS_CMD_POS_WCS,	// 工件指令位置 {Get(Bit32)}
	HNC_AXIS_ACT_POS_RCS,	// 相对实际位置 {Get(Bit32)}
	HNC_AXIS_CMD_POS_RCS,	// 相对指令位置 {Get(Bit32)}
	HNC_AXIS_ACT_PULSE,		// 实际脉冲位置 {Get(Bit32)}
	HNC_AXIS_CMD_PULSE,		// 指令脉冲位置 {Get(Bit32)}
	HNC_AXIS_PROG_POS,		// 编程位置 {Get(Bit32)}
	HNC_AXIS_ENC_CNTR,		// 电机位置 {Get(Bit32)}
	HNC_AXIS_CMD_VEL,		// 指令速度 {Get(Bit32)}
	HNC_AXIS_ACT_VEL,		// 实际速度 {Get(fBit64)}
	HNC_AXIS_LEFT_TOGO,		// 剩余进给 {Get(Bit32)}
	HNC_AXIS_WCS_ZERO,		// 工件零点 {Get(Bit32)}
	HNC_AXIS_WHEEl_OFF,		// 手轮中断偏移量 {Get(Bit32)}
	HNC_AXIS_FOLLOW_ERR,	// 跟踪误差 {Get(Bit32)}
	HNC_AXIS_SYN_ERR,		// 同步误差	{Get(Bit32)}
	HNC_AXIS_COMP,			// 轴补偿值 {Get(Bit32)}
	HNC_AXIS_ZSW_DIST,		// Z脉冲偏移 {Get(Bit32)}
	HNC_AXIS_REAL_ZERO,		// 相对零点 {Get(Bit32)}
	HNC_AXIS_MOTOR_REV,		// 电机转速 {Get(fBit64)}
	HNC_AXIS_DRIVE_CUR,		// 驱动单元电流 {Get(fBit64)}
	HNC_AXIS_LOAD_CUR,		// 负载电流 {Get(fBit64)}
	HNC_AXIS_RATED_CUR,		// 额定电流 {Get(fBit64)}
	HNC_AXIS_IS_HOMEF,		// 回零完成 {Get(Bit32)}
	HNC_AXIS_WAVE_FREQ,		// 波形频率 {Get(fBit64)}
	HNC_AXIS_DRIVE_VER,     // 伺服驱动版本 {Get(Bit8[32])}
	HNC_AXIS_MOTOR_TYPE,    // 伺服类型 {Get(Bit8[32])}
	HNC_AXIS_MOTOR_TYPE_FLAG,// 伺服类型出错标志 {Get(Bit32)}
	HNC_AXIS_TOTAL
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo)
//
//    功能：
//            获取轴数据的值
//
//    参数：
//            type		：轴数据的类型
//            ax		：轴号；
//            value		：轴数据的值；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo = 0);

#endif // __HNC_AXIS_H__
