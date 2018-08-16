/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncdatadef.h
* 文件标识：根据配置管理计划书
* 摘    要：基本数据定义
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年9月25日
* 说    明：参数、刀具、采样
*/

#ifndef __HNC_DATADEF_H__
#define __HNC_DATADEF_H__

#ifdef _HNC_80_

	#define SYS_CHAN_NUM	12
	#define SYS_AXES_NUM	64
	#define SYS_SPDL_NUM	16//主轴数
	#define SYS_NCBRD_NUM	8 //主控制设备数
	#define SYS_NCOBJ_NUM	120 //从设备控制对象（部件）数【轴数+RS232+LAN+USB+MCP+NCKB+I/O】
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   4	//通道最多主轴数
	#define MAX_SMC_AXES_NUM 32	//最多运控轴数

#else

	#define SYS_CHAN_NUM		(4)		// 系统最大通道数
	#define SYS_AXES_NUM		(24)	// 系统最大进给轴数
	#define SYS_SPDL_NUM		(8)		// 系统最大主轴数
	#define SYS_NCBRD_NUM		(4)		// 主控制设备数
	#define SYS_NCOBJ_NUM		(80)	// 从设备控制对象（部件）数
	#define CHAN_AXES_NUM		(9)		// 通道最大轴数
	#define CHAN_SPDL_NUM		(4)		// 通道最大主轴数
	#define MAX_SMC_AXES_NUM	(16)	// 最多运控轴数

#endif

#define TOTAL_AXES_NUM		(SYS_AXES_NUM+SYS_SPDL_NUM) // 系统最大逻辑轴数
#define SYS_PART_NUM		SYS_NCOBJ_NUM	// 	系统设备接口数

// 参数
// ID编号 
#define NCU_PARAM_ID_BASE	(0)
#define MAC_PARAM_ID_BASE	(10000)
#define CHAN_PARAM_ID_BASE	(40000)
#define AXIS_PARAM_ID_BASE	(100000)
#define COMP_PARAM_ID_BASE	(300000)
#define DEV_PARAM_ID_BASE	(500000)
#define TABLE_PARAM_ID_BASE (700000)  // 数据表参数

#define NCU_PARAM_ID_NUM	(1000)
#define MAC_PARAM_ID_NUM	(1000)
#define CHAN_PARAM_ID_NUM	(1000)
#define AXIS_PARAM_ID_NUM	(1000)
#define COMP_PARAM_ID_NUM	(1000)
#define DEV_PARAM_ID_NUM	(1000)
#define TABLE_PARAM_ID_NUM  (100000)  // 分配给数据表参数的ID数


// 参数管理器宏定义
// 参数类别
#define PARAMAN_FILE_NCU	(0)	// NC参数
#define PARAMAN_FILE_MAC	(1)	// 机床用户参数
#define PARAMAN_FILE_CHAN	(2)	// 通道参数
#define PARAMAN_FILE_AXIS	(3)	// 坐标轴参数
#define PARAMAN_FILE_ACMP	(4)	// 误差补偿参数
#define PARAMAN_FILE_CFG	(5)	// 设备接口参数
#define PARAMAN_FILE_TABLE	(6)	// 数据表参数
#define PARAMAN_FILE_BOARD	(7)	// 主站参数


#define PARAMAN_MAX_FILE_LIB		(7)		// 参数结构文件最大分类数
#define PARAMAN_MAX_PARM_PER_LIB	(1000)	// 各类参数最大条目数 
#define PARAMAN_MAX_PARM_EXTEND     (1000)	// 分支扩展参数最大条目数
#define PARAMAN_LIB_TITLE_SIZE		(16)	// 分类名字符串最大长度
#define PARAMAN_REC_TITLE_SIZE		(16)	// 子类名字符串最大长度
#define PARAMAN_ITEM_NAME_SIZE		(64)	// 参数条目字符串最大长度




// 参数相对基地址的偏移
// NC参数
enum 
{
	PAR_NCU_TYPE,			// NCU控制器类型
	PAR_NCU_CYCLE,			// 插补周期
	PAR_NCU_PLC2_CMDN,		// PLC2周期执行语句数

	PAR_NCU_ANG_RESOL = 5,	// 角度计算分辨率
	PAR_NCU_LEN_RESOL,		// 长度计算分辨率
	PAR_NCU_TIME_RESOL,		// 时间编程分辨率
	PAR_NCU_VEL_RESOL,		// 线速度编程分辨率
	PAR_NCU_SPDL_RESOL,		// 角速度编程分辨率
	PAR_NCU_ARC_PROFILE,	// 圆弧插补轮廓允许误差
	PAR_NCU_MAX_RAD_ERR,	// 圆弧编程端点半径允许偏差
	PAR_NCU_G43_SW_MODE,	// 刀具轴选择方式[0,固定z向;1,G17/18/19切换;2,G43指令轴切换]
	PAR_NCU_G41_G00_G01,	// G00插补使能
	PAR_NCU_G53_LEN_BACK,	// G53之后自动恢复刀具长度补偿[0,不恢复 1 恢复]
	PAR_NCU_CRDS_NUM,	    // 允许联动轴数
	PAR_NCU_LAN_EN,			// 局域网使能
	PAR_NCU_POWER_SAFE,		// 断电保护使能
	PAR_NCU_TIME_EN,		// 系统时间显示使能
	PAR_NCU_PSW_CHECK,		// 权限检查使能
	PAR_NCU_ALARM_POP,		// 报警窗口自动显示使能
	PAR_NCU_KBPLC_EN,       // 键盘PLC使能
	PAR_NCU_GRAPH_ERAS_EN,  // 图形自动擦除使能	
	PAR_NCU_FSPD_DISP,		// F进给速度显示方式	
	PAR_NCU_GLNO_DISP,		// G代码行号显示方式
	PAR_NCU_INCH_DISP,	    // 公制/英制选择
	PAR_NCU_DISP_DIGITS,	// 位置小数点后显示位数
	PAR_NCU_FEED_DIGITS,	// 速度小数点后显示位数
	PAR_NCU_SPINDLE_DIGITS,	// 转速小数点后显示位数
	PAR_NCU_LANGUAGE,		// 语言选择
	PAR_NCU_LCD_TIME,		// 进入屏保等待时间
	PAR_NCU_DISK_TYPE,		// 外置程序存储类型
	PAR_NCU_REFRE_INTERV,   // 界面刷新间隔时间
	PAR_NCU_SAVE_TYPE,      // 是否外接UPS
	PAR_NCU_OPERATE_NOTE,   // 操作提示使能[0位：重运行 1位：Tool->相对实际 2位：Tool->当前位置]
	PAR_NCU_SERVER_NAME,
	PAR_NCU_SERVER_IP1,
	PAR_NCU_SERVER_IP2,
	PAR_NCU_SERVER_IP3,
	PAR_NCU_SERVER_IP4,
	PAR_NCU_SERVER_PORT,    // 服务器端口号
	PAR_NCU_SERVER_LOGIN,   // 服务器访问用户名
	PAR_NCU_SERVER_PASSWD,  // 服务器访问密码

	PAR_NCU_NET_TYPE = 44,       // 网盘映射类型
	PAR_NCU_IP1,            // IP地址段1
	PAR_NCU_IP2,            // IP地址段2
	PAR_NCU_IP3,            // IP地址段3
	PAR_NCU_IP4,            // IP地址段4
	PAR_NCU_PORT,           // 本地端口号
	PAR_NCU_NET_START,		// 是否开启网络
	PAR_NCU_SERIAL_TYPE,	// 串口类型
	PAR_NCU_SERIAL_NO = 52,	// 串口号
	PAR_NCU_DATA_LEN,       // 收发数据长度
	PAR_NCU_STOP_BIT,       // 停止位
	PAR_NCU_VERIFY_BIT,     // 校验位
	PAR_NCU_BAUD_RATE,      // 波特率
	PAR_NCU_IP_TYPE,        // 静态IP/动态IP
	PAR_NCU_ARCS_INTERSECT, //圆弧交点允差
	PAR_NCU_TOOL_NUM = 60,	// 最大刀具数
	PAR_NCU_TOFF_DIGIT,     // 刀补有效位数
	PAR_NCU_MAGZ_NUM,		// 最大刀库数
	PAR_NCU_TOOL_LOCATION,	// 最大刀座数
	PAR_NCU_TABRA_ADD_EN,   // 刀具磨损累加使能
	PAR_NCU_TDIA_SHOW_EN,   // 车刀直径显示使能
	PAR_NCU_SUB_PROG_EN,    // 全局子程序调用使能
	PAR_NCU_TRANS_ORDER,	// 镜像缩放旋转嵌套次序
							// 【0 旋转->缩放->镜像 1 镜像->缩放->旋转 2 自由编程，自动整理成按镜像->缩放->旋转的次序实施变换 
							// 3 按照实际的编程次序实施变换； 0/1/2三种选择时，都会按照镜像->缩放->旋转的次序实施变换】
	PAR_NCU_CYCLE_OPT,		// 复合循环路径选项【0x00FF: 0 常规  1 退刀段效率优先 2 FANUC兼容  &0xFF00 = =  0x0000 : 45度退刀 0x0100: 径向退刀 
							// &0x0200 = =  0x0200时最后一刀直接退到循环起点，凹槽中有台阶时不要用此选项】
	PAR_NCU_HOLD_DECODE_EN,	// 进给保持后重新解释使能
	PAR_NCU_G28_LEN_BACK,	// G28后是否自动恢复刀长补
	PAR_NCU_SPEEDUP_EN,    // 内部调试用，加速使能

	PAR_NCU_LOG_SAVE_TYPE = 80, // 日志文件保存类型

	PAR_NCU_INTERNET_IP1,	// 网络平台服务器IP
	PAR_NCU_INTERNET_IP2,
	PAR_NCU_INTERNET_IP3,
	PAR_NCU_INTERNET_IP4,
	PAR_NCU_INTERNET_PORT,	//网络平台服务器端口
	PAR_NCU_GATEWAY1,		//本机网关
	PAR_NCU_GATEWAY2,
	PAR_NCU_GATEWAY3,
	PAR_NCU_GATEWAY4,

	PAR_NCU_HMI = 100,					// 界面设置参数基地址
	PAR_NCU_ISSU_EDITION = PAR_NCU_HMI,	// 发布版本号
	PAR_NCU_TEST_EDITION,				// 测试版本号
	PAR_NCU_SHOW_LIST,					// 示值列，40
	PAR_NCU_GRAPH = PAR_NCU_SHOW_LIST+40,	// 图形参数，90

	PAR_NCU_ALARM_LOG_NUM_LIMIT = 280,	//	日志条目限制
	PAR_NCU_WORKINFO_LOG_NUM_LIMIT,
	PAR_NCU_FILECHANGE_LOG_NUM_LIMIT,
	PAR_NCU_PANEL_LOG_NUM_LIMIT,
	PAR_NCU_DEFINE_LOG_NUM_LIMIT,
	PAR_NCU_EVENT_LOG_NUM_LIMIT,

	PAR_NCU_ALARM_LOG_TIME_LIMIT = 290,	//	日志时间限制
	PAR_NCU_WORKINFO_LOG_TIME_LIMIT,
	PAR_NCU_FILECHANGE_LOG_TIME_LIMIT,
	PAR_NCU_PANEL_LOG_TIME_LIMIT,
	PAR_NCU_DEFINE_LOG_TIME_LIMIT,
	PAR_NCU_EVENT_LOG_TIME_LIMIT,

	PAR_NCU_PROG_PATH = 300,	// 加工代码程序路径
	PAR_NCU_PLC_PATH,		// PLC程序路径
	PAR_NCU_PLC_NAME,		// PLC程序名
	PAR_NCU_DRV_PATH,		// 驱动程序路径
	PAR_NCU_DRV_NAME,		// 驱动程序名
	PAR_NCU_PARA_PATH,		// 参数文件路径
	PAR_NCU_PARA_NAME,		// 参数文件名
	PAR_NCU_SIMU_PATH,		// 仿真配置文件路径
	PAR_NCU_SIMU_NAME,		// 仿真配置文件名
	PAR_NCU_DLGP_PATH,		// 对话编程配置文件路径
	PAR_NCU_DLGP_NAME,		// 对话编程配置文件名
	PAR_NCU_VIDEO_DEV,      // 视频外设驱动
			
	PAR_NCU_SUB_DBG = 320,	// 宏程序单段使能【WIN】
	PAR_NCU_USER_LOGIN = 321,	// 	是否开启用户登录?
	PAR_NCU_G16_OPT = 350,	// G16的极点定义模式选择 0：FANUC模式 1：HNC-8模式
	PAR_NCU_GEDIT_FRAME = 351,	// 编辑界面框架选择 0：HNC-8模式 1：宁江专机模式
	PAR_NCU_FTP_MODE = 352,	// FTP连接方式 0：HNC-8模式 1：沈飞模式
	PAR_NCU_TCS = 353,//是否开启特性坐标系功能界面 0:不开启 1:开启
	PAR_NCU_HMI_TYPE,		// HMI类型，0：标准8型；1：沈飞专用；
	PAR_NCU_CHECK_SYSDISK_FREE,	// 系统盘剩余空间不足提示检测阈值
	PAR_NCU_MILL_FUN_TYPE,	// 铣床功能类型
	PAR_NCU_API_LOG_LEVEL,    // api日志记录级别
	PAR_NCU_EXIT_MDI_CLEAR,		// 退出mdi时是否清空mdi内容
	PAR_NCU_DEFAULT_RIGHT_LEVEL = 359, // 上电默认用户权限
	PAR_NCU_MCP_TYPE = 360, // 权限配置数据(360~377)
	PAR_NCU_TOTAL = 500		// NC参数总数
};



// 机床用户参数
enum 
{
	PAR_MAC_CHAN_NUM,	// 通道数：1~SYS_CHAN_NUM
	PAR_MAC_CHAN_TYPE,	// 机床通道加工类型【车、铣床、磨】
#ifdef _HNC_80_
	PAR_MAC_CHAN_FLAG = PAR_MAC_CHAN_TYPE+16,	// 通道选择标志
	//PAR_MAC_CHAN_AX_FLAG = PAR_MAC_CHAN_FLAG+12,	// 通道的轴显示标志，每个通道占用两个参数，共8*2 = 16个参数
	//PAR_MAC_CHAN_CUR_FLAG = PAR_MAC_CHAN_AX_FLAG+12,	// 通道的负载电流显示轴定制
#else
	PAR_MAC_CHAN_FLAG = PAR_MAC_CHAN_TYPE+8,	// 通道选择标志
	PAR_MAC_CHAN_AX_FLAG = PAR_MAC_CHAN_FLAG+8,	// 通道的轴显示标志，每个通道占用两个参数，共8*2 = 16个参数
	PAR_MAC_CHAN_CUR_FLAG = PAR_MAC_CHAN_AX_FLAG+16,	// 通道的负载电流显示轴定制
#endif
	PAR_MAC_SHOW_AXES = 41,		// 是否动态显示坐标轴
	PAR_MAC_CALIB_TYPE,			// 刀具测量仪类型
	PAR_MAC_ALARM_PAUSE,		// 开机自检警告暂停功能
	PAR_MAC_CC_CW_SPD_TYPE,		// 半径补偿圆弧速度处理策略
	PAR_MAC_CC_WEAR_TYPE,       //半径补偿=半径减/加磨损
	PAR_MAC_CC_CHECK_CTRL,      //半径补偿干涉控制，0：干涉报警 1：自动处理干涉
	PAR_MAC_CC_CHECK_NUM,         //半径补偿干涉检查段数
	
	PAR_MAC_HOME_BLOCK = 48,	// 机床是否安装回零挡块
	PAR_MAC_AXES_NUM,			// 机床总轴数
	PAR_MAC_SMX_AXIS_NUM,		// 运动控制通道轴数（耦合从轴+PMC轴）
	PAR_MAC_SMX_AXIS_IDX,		// PMC及耦合从轴编号，预留32个

    PAR_MAC_CYC_TYPE=83,      //钻攻中心固定循环类型
    PAR_MAC_T_CTRL_TYPE=89,         //T指令控制方式
    PAR_MAC_USR_VAR_WAIT,          //用户自定义宏变量是否执行G08等待
    PAR_MAC_USR_NEW_USR_VAR,      //兼容FANUC,三菱，#500~999断电保存。0，关闭断电保存功能；1，打开
	PAR_MAC_SP_POS_HOLD,		// C轴为速度模式时不刷新坐标

	PAR_MAC_TOOL = 100,	// 刀具处理参数预留
	
	PAR_MAC_FZONE_IN_MASK=110,	//机床保护区内部禁止掩码
	PAR_MAC_FZONE_EX_MASK,		//机床保护区外部禁止掩码
	PAR_MAC_FZONE_BND,		//机床保护区边界-x +x -y +y -z +z 6*6=36
	
	PAR_MAC_HOME_DWELL = 165,	// 回参考点延时时间，单位：ms
	PAR_MAC_PLCACK_CYCLE,		// PLC应答最长时间
	PAR_MAC_G32_HOLD_DX,		// 螺纹加工中止的退刀距离
	PAR_MAC_G32_HOLD_ANG,		// 螺纹加工中止的退刀角度
	PAR_MAC_G64_CORNER_CHK,		// G64拐角准停校验检查使能
	
	PAR_MAC_MCODE_FLAG = 170,	// M代码属性表
	
	PAR_MAC_CHAN_GMODE_SHOW = 220,	// 模态G指令显示定制，每个工位占用3个参数，共8*3 = 24个参数
	
	PAR_MAC_MEAS_SPD = 250,	// 测量速度
	PAR_MAC_MEAS_DIST,		// 测量最小行程
	
	PAR_MAC_IPSYNC_FUN = 260,	// 插补同步函数注册
	
	PAR_MAC_SPECIAL = 270,		// 专机预留参数起始地址
	
	PAR_MAC_CHECK_ENCRYPT = 298,	// 是否检查文件加密属性
	PAR_MAC_PROG_SKEY = 299,		// G代码文件密钥
	
	PAR_MAC_USER = 300,	// 用户参数基地址
    PAR_MAC_M2G = 360, //用户参数的G代码对应的M代码值
	
	PAR_MAC_TOTAL = 500	// 机床用户参数总数
};


// 通道参数
enum 
{
	PAR_CH_NAME = 0,	// 名称
	PAR_CH_XINDEX,		// X轴编号
	PAR_CH_YINDEX,		// Y轴编号
	PAR_CH_ZINDEX,		// Z轴编号
	PAR_CH_AINDEX,		// A轴编号
	PAR_CH_BINDEX,		// B轴编号
	PAR_CH_CINDEX,		// C轴编号
	PAR_CH_UINDEX,		// U轴编号
	PAR_CH_VINDEX,		// V轴编号
	PAR_CH_WINDEX,		// W轴编号
	PAR_CH_SPDL0,		// 主轴0编号
	PAR_CH_SPDL1,		// 主轴1编号
	PAR_CH_SPDL2,		// 主轴2编号
	PAR_CH_SPDL3,		// 主轴3编号
	PAR_CH_X_NAME,		// X轴名
	PAR_CH_Y_NAME,		// Y轴名
	PAR_CH_Z_NAME,		// Z轴名
	PAR_CH_A_NAME,		// A轴名
	PAR_CH_B_NAME,		// B轴名
	PAR_CH_C_NAME,		// C轴名
	PAR_CH_U_NAME,		// U轴名
	PAR_CH_V_NAME,		// V轴名
	PAR_CH_W_NAME,		// W轴名
	PAR_CH_S0_NAME,		// 主轴0名
	PAR_CH_S1_NAME,		// 主轴1名
	PAR_CH_S2_NAME,		// 主轴2名
	PAR_CH_S3_NAME,		// 主轴3名
	PAR_CH_SVEL_SHOW,	// 主轴转速显示方式
	PAR_CH_S_SHOW,		// 主轴显示定制
	
	PAR_CH_DEFAULT_F = 30,	// 通道的缺省进给速度
	PAR_CH_DRYRUN_SPD,		// 空运行进给速度
	PAR_CH_DIAPROG,			// 直径编程使能
	PAR_CH_UVW_INC_EN,		// UVW增量编程使能
	PAR_CH_CHAMFER_EN,		// 倒角使能
	PAR_CH_ANGLEP_EN,		// 角度编程使能
	PAR_CH_CYCLE_OPTION,	// 复合循环选项屏蔽字[位]：0x0001 粗加工圆弧转直线 0x0002：凹槽轴向余量报警屏蔽 0x0004: 无精加工
    PAR_CH_MPG_ACC_RATE,	// 手摇加速度系数
	PAR_CH_MPG_JK_RATE,		// 手摇捷度系数
    PAR_CH_MPG_WORK_RATE,   // 手摇加工系数

	PAR_CH_MAC_FRAME = 40,	// 机床结构类型【0, 一般直角系机床 1, 通用五轴机床；2+其它机床】
	PAR_CH_MACTURN,			// 车床横式立式类型【0, 横式 1, 立式】
    PAR_CH_ARC_SPEED_DOWN_R,     //圆弧降速半径
    PAR_CH_ARC_SPEED_DOWN_V,     //圆弧降速速度

	PAR_CH_FOLLOW_ROTATE_RAD = 60, //工具跟随的摆动半径
	PAR_CH_FOLLOW_CHORD_LEN, //弦线跟随的弦长
	PAR_CH_FOLLOW_TOOL_AX, //工具旋转的旋转轴号
	PAR_CH_FOLLOW_TABLE_AX, //工作台旋转的旋转轴号
	PAR_CH_FOLLOW_DX, //工具跟随旋转中心x偏移
	PAR_CH_FOLLOW_DY, //工具跟随旋转中心y偏移
	
	PAR_CH_VPLAN_MODE = 69,	// 速度规划模式0-9:曲面模式  10+高速模式【激光、木工】 
	
	PAR_CH_MICR_MAX_LEN,	// 微线段上限长度
	PAR_CH_CORNER_MAX_ANG,	// 拐角平滑最小角度
	PAR_CH_VEL_FILTER_LEN,	// 微线段速度滤波长度
	PAR_CH_PATH_TOLERANCE,	// 轨迹轮廓允差
	PAR_CH_CONER_DEC_FACTOR,// 拐角降速比例因子%
	PAR_CH_HSPL_MIN_LEN,	// 微线段下限长度
	PAR_CH_HSPL_MAX_ANG,	// 样条过渡夹角
	PAR_CH_HSPL_MAX_RAT,	// 样条平滑的相邻段最大长度比
	PAR_CH_HSPL_MAX_LEN,	// 样条平滑的最大线段长度
	PAR_CH_ARC2LINE,		// 圆弧离散为直线选择 79
	
	PAR_CH_LOOKAHEAD_NUM,	// 速度规划前瞻段数
	PAR_CH_CURVATURE_COEF,	// 曲率半径调整系数【0.3~100.0】
	PAR_CH_RECTIFY_NUM,		// 指令速度平滑周期数
	PAR_CH_JERK_TIMES,		// 合成捷度时间常数
	PAR_CH_MAX_ECEN_ACC,	// 向心加速度
	PAR_CH_MAX_TANG_ACC,	//切向加速度
    PAR_CH_FEED_ACC_COEF,	// 加速度系数	
	PAR_CH_FEED_JK_COEF,		// 捷度系数
	PAR_CH_PRE_SMOOTH_OFF,	//预处理平滑关闭

	PAR_CH_CYL_RAX = 90,	// 圆柱插补旋转轴号【缺省5、C轴】
	PAR_CH_CYL_LAX,			// 圆柱插补直线【轴向】轴号【缺省2、Z轴】
	PAR_CH_CYL_PAX,			// 圆柱插补平行【周向、纬线】轴号【缺省1、Y轴】
	
	PAR_CH_POLAR_LAX = 95,	// 极坐标插补的直线轴轴号
	PAR_CH_POLAR_RAX,		// 极坐标插补的旋转轴轴号
	PAR_CH_POLAR_VAX,		// 极坐标插补的假想轴轴号
	PAR_CH_POLAR_CX,		// 极坐标插补的旋转中心直线轴坐标
	PAR_CH_POLAR_CY,		// 极坐标插补假想轴偏心量
	
	PAR_CH_THREAD_TOL = 105,	// 螺纹起点允许偏差
	PAR_CH_THREAD_WAY,			// 螺纹加工方式


	PAR_CH_G61_DEFAULT,		// 系统上电时G61/G64模态设置
	PAR_CH_G00_DEFAULT,		// 系统上电时G00/G01模态设置
	PAR_CH_G90_DEFAULT,		// 系统上电时G90/G91模态设置
	PAR_CH_G28_ZTRAP_EN,	// G28搜索Z脉冲使能
	PAR_CH_G28_POS_EN,		// G28不寻Z脉冲时快移使能 【0 就进给速度定位 1 快移速度定位】
	PAR_CH_G28_ONE_SHOT,	// G29
	PAR_CH_SKIP_MODE,		// 任意行模式[0,非扫描 1，扫描，恢复单行轴移动模态 2扫描，恢复全部轴移动模态]
	PAR_CH_AXIS_RETURN_ORDER, //任意行轴返回顺序
	PAR_CH_M_GROUP1,             // M代码分组1
	// PAR_CH_G95_DEFAULT,		// 系统上电时G95/G94模态设置

	PAR_CH_MAG_START_NO = 125,	// 	起始刀库号
	PAR_CH_MAG_NUM,				// 	刀库数目
	PAR_CH_TOOL_START_NO,		// 	起始刀具号
	PAR_CH_TOOL_NUM,			// 	刀具数目
	PAR_CH_TOOL_OFF_START_NO,	//	起始刀补号
	PAR_CH_LIFE_ON,				// 	刀具寿命功能开启

	PAR_CH_TOFF_ON,				//限位与保护区时，刀补开启
	PAR_CH_TOFF_LIMIT,			//刀补开启时，Z轴刀尖与负限位的距离
	PAR_CH_LIFE_LOSE_NO,        //  T指令寿命管理忽略号	,例如T106，系统将其认为是T(106 - 100)
	PAR_CH_SYNC_RESET,			//复位是否清除同步

	//  = 140 第2套小线段参数
	PAR_CH_MICR_MAX_LEN2 = 140,	// 微线段上限长度
	PAR_CH_CORNER_MAX_ANG2,		// 工艺尖角最大夹角
	PAR_CH_VEL_FILTER_LEN2,		// 微线段速度滤波长度
	PAR_CH_PATH_TOLERANCE2,		// 轨迹轮廓允差
	PAR_CH_GEO_CNTR_NUM2,		// 微线段特征滤波段数
	PAR_CH_HSPL_MIN_LEN2,		// 微线段下限长度
	PAR_CH_HSPL_MAX_ANG2,		// 样条过渡夹角
	PAR_CH_HSPL_MAX_RAT2,		// 样条平滑的相邻段最大长度比
	PAR_CH_HSPL_MAX_LEN2,		// 样条平滑的最大线段长度
	PAR_CH_PATH_TYPE2,			// 切削轨迹类型
	PAR_CH_LOOKAHEAD_NUM2,		// 速度规划前瞻段数
	PAR_CH_CURVATURE_COEF2,		// 曲率半径调整系数【0.3~100.0】
	PAR_CH_RECTIFY_NUM2,		// 速度整定段数
	PAR_CH_POS_SMTH_NUM2,		// 位置平滑段数
	PAR_CH_FEED_ACC_COEF2=156,	// 加速度系数	
	PAR_CH_FEED_JK_COEF2,		// 捷度系数

	//  = 160 第3套小线段参数
	PAR_CH_MICR_MAX_LEN3 = 160,	// 微线段上限长度
	PAR_CH_CORNER_MAX_ANG3,		// 工艺尖角最大夹角
	PAR_CH_VEL_FILTER_LEN3,		// 微线段速度滤波长度
	PAR_CH_PATH_TOLERANCE3,		// 轨迹轮廓允差
	PAR_CH_GEO_CNTR_NUM3,		// 微线段特征滤波段数
	PAR_CH_HSPL_MIN_LEN3,		// 微线段下限长度
	PAR_CH_HSPL_MAX_ANG3,		// 样条过渡夹角
	PAR_CH_HSPL_MAX_RAT3,		// 样条平滑的相邻段最大长度比
	PAR_CH_HSPL_MAX_LEN3,		// 样条平滑的最大线段长度
	PAR_CH_PATH_TYPE3,			// 切削轨迹类型
	PAR_CH_LOOKAHEAD_NUM3,		// 速度规划前瞻段数
	PAR_CH_CURVATURE_COEF3,		// 曲率半径调整系数【0.3~100.0】
	PAR_CH_RECTIFY_NUM3,		// 速度整定段数
	PAR_CH_POS_SMTH_NUM3,		// 位置平滑段数
	PAR_CH_FEED_ACC_COEF3=176,	// 加速度系数	
	PAR_CH_FEED_JK_COEF3,		// 捷度系数

	//  = 180 第4套小线段参数
	PAR_CH_MICR_MAX_LEN4 = 180,	// 微线段上限长度
	PAR_CH_CORNER_MAX_ANG4,		// 工艺尖角最大夹角
	PAR_CH_VEL_FILTER_LEN4,		// 微线段速度滤波长度
	PAR_CH_PATH_TOLERANCE4,		// 轨迹轮廓允差
	PAR_CH_GEO_CNTR_NUM4,		// 微线段特征滤波段数
	PAR_CH_HSPL_MIN_LEN4,		// 微线段下限长度
	PAR_CH_HSPL_MAX_ANG4,		// 样条过渡夹角
	PAR_CH_HSPL_MAX_RAT4,		// 样条平滑的相邻段最大长度比
	PAR_CH_HSPL_MAX_LEN4,		// 样条平滑的最大线段长度
	PAR_CH_PATH_TYPE4,			// 切削轨迹类型
	PAR_CH_LOOKAHEAD_NUM4,		// 速度规划前瞻段数
	PAR_CH_CURVATURE_COEF4,		// 曲率半径调整系数【0.3~100.0】
	PAR_CH_RECTIFY_NUM4,		// 速度整定段数
	PAR_CH_POS_SMTH_NUM4,		// 位置平滑段数
	PAR_CH_FEED_ACC_COEF4=196,	// 加速度系数	
	PAR_CH_FEED_JK_COEF4,		// 捷度系数
	
	PAR_CH_ROBOT_PARA=200, //200~300机器人参数区
	//PAR_CH_WTZONE_NUM = 200,	// 工件及刀具保护区总个数0~10
	//PAR_CH_WTZONE_TYPE,			// 工件及刀具保护区类型
	//PAR_CH_WTZONE_FLAG,			// 工件及刀具保护区属性
	//PAR_CH_WTZONE_BND,			// 工件及刀具保护区边界
	
	PAR_CH_USER_AD_OFF = 300, // 用户模拟量输入点偏移量。x寄存器，单位字节
	PAR_CH_USER_DA_OFF = 301, // 用户模拟量输出点偏移量。y寄存器，单位字节

	//PAR_CH_RESONA_DAMP_AMP = 300, // 主轴转速避振波幅【百分比 0.05】
	//PAR_CH_RESONA_DAMP_PRD = 301, // 主轴转速避振周期【秒】

	PAR_CH_TAX_ENABLE = 310,	// 倾斜轴控制使能
	PAR_CH_TAX_ORTH_AX_INDEX,	// 正交轴轴号
	PAR_CH_TAX_TILT_AX_INDEX,	// 倾斜轴轴号
	PAR_CH_TAX_TILT_ANGLE,		// 倾斜角度

	PAR_CH_SYNC_MAIN_SPDL=314, //主动轴主轴号
	PAR_CH_SYNC_SUB_SPDL,      //从动轴主轴号
	PAR_CH_SYNC_MOLE,          //传动比分子
	PAR_CH_SYNC_DENO,          //传动比分母
	PAR_CH_SYNC_PHASE,         //同步相位差

	//五轴参数
	PAR_CH_RTCPARA_OFF=50,		//RTCP参数偏移值

	PAR_CH_TOOL_INIT_DIR_X=400,	//刀具初始方向(X)
	PAR_CH_TOOL_INIT_DIR_Y,		//刀具初始方向(Y)
	PAR_CH_TOOL_INIT_DIR_Z,		//刀具初始方向(Z)
	PAR_CH_ANG_OUTPUT_MODE=405,	//旋转轴角度输出判定方式
	PAR_CH_ANG_OUTPUT_ORDER,	//旋转轴角度输出判定顺序
	PAR_CH_POLE_TOLERANCE,		//极点角度范围
	
	PAR_CH_RTCP_SWIVEL_TYPE=410,	//摆头结构类型
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_X,	//摆头第1旋转轴方向(X)
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_Y,	//摆头第1旋转轴方向(Y)
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_Z,	//摆头第1旋转轴方向(Z)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_X,	//摆头第2旋转轴方向(X)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_Y,	//摆头第2旋转轴方向(Y)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_Z,	//摆头第2旋转轴方向(Z)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_X,	//摆头第1旋转轴偏移矢量(X)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_Y,	//摆头第1旋转轴偏移矢量(Y)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_Z,	//摆头第1旋转轴偏移矢量(Z)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_X,	//摆头第2旋转轴偏移矢量(X)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_Y,	//摆头第2旋转轴偏移矢量(Y)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_Z,	//摆头第2旋转轴偏移矢量(Z)

	PAR_CH_RTCP_TABLE_TYPE=425,		//转台结构类型
	PAR_CH_RTCP_TABLE_RAX1_DIR_X,	//转台第1旋转轴方向(X)
	PAR_CH_RTCP_TABLE_RAX1_DIR_Y,	//转台第1旋转轴方向(Y)
	PAR_CH_RTCP_TABLE_RAX1_DIR_Z,	//转台第1旋转轴方向(Z)
	PAR_CH_RTCP_TABLE_RAX2_DIR_X,	//转台第2旋转轴方向(X)
	PAR_CH_RTCP_TABLE_RAX2_DIR_Y,	//转台第2旋转轴方向(Y)
	PAR_CH_RTCP_TABLE_RAX2_DIR_Z,	//转台第2旋转轴方向(Z)
	PAR_CH_RTCP_TABLE_RAX1_OFF_X,	//转台第1旋转轴偏移矢量(X)
	PAR_CH_RTCP_TABLE_RAX1_OFF_Y,	//转台第1旋转轴偏移矢量(Y)
	PAR_CH_RTCP_TABLE_RAX1_OFF_Z,	//转台第1旋转轴偏移矢量(Z)
	PAR_CH_RTCP_TABLE_RAX2_OFF_X,	//转台第2旋转轴偏移矢量(X)
	PAR_CH_RTCP_TABLE_RAX2_OFF_Y,	//转台第2旋转轴偏移矢量(Y)
	PAR_CH_RTCP_TABLE_RAX2_OFF_Z,	//转台第2旋转轴偏移矢量(Z)

	PAR_CH_TOTAL = 500
};

// 坐标轴参数
#define SERVO_PARM_START_IDX 200 // 伺服参数起始参数号
#define SERVO_PARM_TOTAL_NUM 100//伺服参数个数
enum 
{
	PAR_AX_NAME = 0,	// 轴名[显示用]
	PAR_AX_TYPE,		// 轴类型[直线、摆动、回转、主轴]
	PAR_AX_INDEX,		// 轴编号 暂时预留
	PAR_AX_MODN,		// 设备号 暂时预留
	PAR_AX_DEV_I = PAR_AX_MODN,
	PAR_AX_PM_MUNIT,	// 电子齿轮比分子(位移量)[每转位移量nm]
	PAR_AX_PM_PULSE,	// 电子齿轮比分母(脉冲数)[每转指令脉冲数]
	PAR_AX_PLMT,		// 正软极限
	PAR_AX_NLMT,		// 负软极限
	PAR_AX_PLMT2,		// 第2正软极限
	PAR_AX_NLMT2,		// 第2负软极限

	PAR_AX_HOME_WAY = 10,	// 回参考点方式
	PAR_AX_HOME_DIR,		// 回参考点方向
	PAR_AX_ENC_OFF,			// 编码器反馈偏置量【手动零点、绝对式编码器】
	PAR_AX_HOME_OFF,		// 回参考点后的偏移量
	PAR_AX_HOME_MASK,		// Z脉冲屏蔽角度
	PAR_AX_HOME_HSPD,		// 回参考点高速
	PAR_AX_HOME_LSPD,		// 回参考点低速
	PAR_AX_HOME_CRDS,		// 参考点坐标值
	PAR_AX_HOME_CODSPACE,	// 距离码参考点间距
	PAR_AX_HOME_CODOFF,		// 间距编码偏差

	PAR_AX_HOME_RANGE = 20,	// 搜Z脉冲最大移动距离
	PAR_AX_HOME_CRDS2,		// 第2参考点坐标值
	PAR_AX_HOME_CRDS3,		// 第3参考点坐标值
	PAR_AX_HOME_CRDS4,		// 第4参考点坐标值
	PAR_AX_HOME_CRDS5,		// 第5参考点坐标值
	PAR_AX_REF_RANGE,		// 参考点范围偏差
	PAR_AX_HOME_CYCLE_OFF,	// 非整传动比回转轴偏差
	PAR_AX_ENC2_OFF,		// 第2编码器反馈偏置量【手动零点、绝对式编码器】
	PAR_AX_PM2_MUNIT,		// 第2编码器电子齿轮比分子(位移量)[每转位移量nm]
	PAR_AX_PM2_PULSE,		// 第2编码器电子齿轮比分母(脉冲数)[每转指令脉冲数]

	PAR_AX_G60_OFF = 30,	// 单向定位(G60)偏移量
	PAR_AX_ROT_RAD,			// 转动轴当量半径
	PAR_AX_JOG_LOWSPD,		// 慢速点动速度
	PAR_AX_JOG_FASTSPD,		// 快速点动速度
	PAR_AX_RAPID_SPD,		// 快移速度
	PAR_AX_FEED_SPD,		// 最高进给速度
	PAR_AX_RAPID_ACC,		// 快移加速度
	PAR_AX_RAPID_JK,		// 快移捷度
	PAR_AX_FEED_ACC,		// 进给加速度
	PAR_AX_FEED_JK,			// 进给捷度
	PAR_AX_THREAD_ACC,		// 螺纹加速度
	PAR_AX_THREAD_DEC,		// 螺纹减速度
	PAR_AX_MPG_UNIT_SPD,	// 手摇单位速度比例系数
	PAR_AX_MPG_RESOL,		// 手摇脉冲分辨率
	PAR_AX_MPG_INTE_RATE,	// 手摇缓冲系数
	PAR_AX_MPG_INTE_TIME,	// 手摇缓冲周期 [45]
	PAR_AX_MPG_OVER_RATE,	// 手摇过冲系数
	PAR_AX_MPG_VEL_GAIN,	// 手摇速度调节系数
	PAR_AX_RAPID_RATE,		// 超速报警系数

	PAR_AX_DEFAULT_S = 50,	// 主轴缺省转速
	PAR_SPDL_MAX_SPEED,		// 主轴最大转速
	PAR_SPDL_SPD_TOL,		// 主轴转速允许转速波动率
	PAR_SPDL_SPD_TIME,		// 主轴转速到达允许最大时间
	PAR_SPDL_THREAD_TOL,	// 螺纹加工时的转速允差
	PAR_AX_SP_ORI_POS,		// 进给主轴定向角度
	PAR_AX_SP_ZERO_TOL,		// 进给主轴零速允差【脉冲】
	PAR_AX_MAX_EXT_PINC,	// 外部指令最大周期叠加量

	PAR_AX_POS_TOL = 60,	// 定位允差
	PAR_AX_MAX_LAG,			// 最大跟随误差
	PAR_AX_LAG_CMP_EN,		// 龙门轴同步误差补偿使能
	PAR_AX_LAG_CMP_COEF,	// 跟随误差补偿调整系数
	PAR_AX_LAG_CMP_CNT,		// 动态补偿系数整定周期数
	
	PAR_AX_ATEETH = 65,	// 传动比分子[轴侧齿数]
	PAR_AX_MTEETH,		// 传动比分母[电机侧齿数]
	PAR_AX_MT_PPR,		// 电机每转脉冲数
	PAR_AX_PITCH,		// 丝杆导程
	PAR_AX_RACK_NUM,	// 齿条齿数
	PAR_AX_RACK_SPACE,	// 齿条齿间距
	PAR_AX_WORM_NUM,	// 蜗杆头数
	PAR_AX_WORM_SPACE,	// 蜗杆齿距
	PAR_RAX_VEL_RATE,   // 旋转轴速度系数
	PAR_AX_RATING_CUR,  // 额定电流
	PAR_AX_POWER_RATE,  // 功率系数
	PAR_AX_ENC2_PPR,	// 第2编码器每转脉冲数
	PAR_AX_INDEX_TYPE, //分度轴类型：1、鼠牙盘；2，分度轴
	PAR_AX_INDEX_POS,//分度起点
	PAR_AX_INDEX_DIVIDE, //分度间隔

	PAR_ZAX_LOCK_EN = 80,	// Z轴锁允许使能
	PAR_RAX_ROLL_EN,		// 旋转轴循环使能
	PAR_RAX_SHORTCUT,		// 旋转轴短路径选择使能
	PAR_RAX_CYCLE_RANGE,	// 旋转轴循环行程
	PAR_RAX_DISP_RANGE,		// 旋转轴显示角度范围
	PAR_LAX_PROG_UNIT,		// 直线轴编程指令最小单位
	PAR_RAX_PROG_UNIT,		// 旋转轴编程指令最小单位
	PAR_OVERLOAD_JUDGE,		// 轴过载判定百分比

	PAR_AX_ENC_MODE = 90,	// 编码器工作模式
// 0x000F：0,用第1编码器反馈 1,用第2编码器反馈  2,无反馈
// 0x00F0：0,用第1编码器指令 1,用第2编码器指令
// 0x0100：0,跟随误差由伺服驱动器反馈 1,跟踪误差由系统计算
// 0x1000：0,默认采用32位脉冲计数 1,采用64位脉冲计数 
#define AX_ENCODER_MASK	0x00FF
#define AX_NC_CMD_MASK  0x00F0
#define AX_NC_TRACK_ERR	0x0100
#define AX_NC_CYC64_MODE 0x1000

	PAR_AX_EC1_TYPE,		// 1号编码器类型【增量、距离码、绝对】
	PAR_AX_EC1_OUTP,		// 反馈电子齿轮比分子[输出脉冲数]
	PAR_AX_EC1_FBKP,		// 反馈电子齿轮比分母[反馈脉冲数]
	PAR_AX_EC1_BIT_N,		// 1号编码器计数位数【绝对式必填】
	PAR_AX_EC2_TYPE,		// 2号编码器类型【增量、距离码、绝对】
	PAR_AX_EC2_OUTP,		// 反馈电子齿轮比分子[输出脉冲数] 
	PAR_AX_EC2_FBKP,		// 反馈电子齿轮比分母[反馈脉冲数]
	PAR_AX_EC2_BIT_N,		// 2号编码器计数位数【绝对式必填】
	
	PAR_AX_SMX_TYPE = 100,	// 运动控制(MC)轴类型
	PAR_AX_SMX_LEAD_IDX,
	PAR_AX_COMPEN_LAG = 106,
	PAR_AX_ALARM_LAG,
	PAR_AX_ALARM_VDIFF,
	PAR_AX_ALARM_CDIFF,
	PAR_AX_SMX_PARA,		// MC轴运动系数，16

	PAR_AX_WCS_DISP=126,	//同步时，从轴工件坐标系显示方式
	PAR_AX_SYNC_MIRROR,		//是否镜像
	PAR_AX_COORD_DIR,		//主从轴坐标系的正方向
	PAR_AX_ZERO_OFFSET,		//同步轴机床零点偏差

	PAR_AX_COMP_MAX_COEF = 130,	// 最大误差补偿率
	PAR_AX_COMP_MAX_VALUE,		// 最大误差补偿值
	PAR_AX_CODOFF_VALUE,		// 轴反馈偏差


	PAR_AX_TANG_NO = 135,		//切线控制随动轴轴号0，1，2代表A，B，C轴，此参数有150移动到此
	PAR_AX_TANG_ANGLE,			//切线控制偏移角
	PAR_AX_TANG_OFFSET,			// 切线跟随偏差值

	//wangxu
	PAR_AX_ADJUST_COE=140,//蛙跳调节系数
	PAR_AX_FOL_COE,//随动比例增益
	PAR_AX_FOL_ADR,//随动模拟量地址
	PAR_AX_FOL_POS_DOWN,//随动位置下限
	PAR_AX_FOL_SPD,//随动最大转速
	PAR_AX_FOL_OFF,//随动到位信号误差范围
	PAR_AX_JUMP_HIGH,//蛙跳高度
	PAR_AX_FOL_POS_UP,//随动位置上限
	PAR_AX_JUMP_TO_FOL,//蛙跳切换到随动的高度
	PAR_AX_FOL_NONLINER,//随动电压非线性，需要先标定
	PAR_AX_DEM_SPACE,//标定的间距
	PAR_AX_DEM_VOL,//碰板电压
    
    PAR_AX_S_ACK=155,       //S指令需要响应
    PAR_AX_OUT_DA,          //主轴输出模拟量
    PAR_AX_MAX_MOTOR,       //主轴电机最大转速
    PAR_AX_SHIFT_NUM,       //主轴挡位数
    PAR_AX_LOW_SPEED1,      //主轴1档最低转速
    PAR_AX_HIGH_SPEED1,     //主轴1档最高转速
    PAR_AX_ATEETH1,      	//主轴1档传动比分子[轴侧齿数]
	PAR_AX_MTEETH1,	    	//主轴1档传动比分母[电机侧齿数]
    PAR_AX_EC_OUTP1,		//主轴1档反馈电子齿轮比分子[输出脉冲数]
	PAR_AX_EC_FBKP1,		//主轴1档反馈电子齿轮比分母[反馈脉冲数]
    PAR_AX_LOW_SPEED2,      //主轴2档最低转速
    PAR_AX_HIGH_SPEED2,     //主轴2档最高转速
    PAR_AX_ATEETH2,      	//主轴2档传动比分子[轴侧齿数]
    PAR_AX_MTEETH2,	    	//主轴2档传动比分母[电机侧齿数]
    PAR_AX_EC_OUTP2,		//主轴2档反馈电子齿轮比分子[输出脉冲数]
	PAR_AX_EC_FBKP2,		//主轴2档反馈电子齿轮比分母[反馈脉冲数]
    PAR_AX_LOW_SPEED3,      //主轴3档最低转速
    PAR_AX_HIGH_SPEED3,     //主轴3档最高转速
    PAR_AX_ATEETH3,      	//主轴3档传动比分子[轴侧齿数]
    PAR_AX_MTEETH3,	    	//主轴3档传动比分母[电机侧齿数]
    PAR_AX_EC_OUTP3,		//主轴3档反馈电子齿轮比分子[输出脉冲数]
	PAR_AX_EC_FBKP3,		//主轴3档反馈电子齿轮比分母[反馈脉冲数]
    PAR_AX_LOW_SPEED4,      //主轴4档最低转速
    PAR_AX_HIGH_SPEED4,     //主轴4档最高转速
    PAR_AX_ATEETH4,      	//主轴4档传动比分子[轴侧齿数]
    PAR_AX_MTEETH4,	    	//主轴4档传动比分母[电机侧齿数]
    PAR_AX_EC_OUTP4,		//主轴4档反馈电子齿轮比分子[输出脉冲数]
	PAR_AX_EC_FBKP4,		//主轴4档反馈电子齿轮比分母[反馈脉冲数]
    PAR_AX_SWITCH_SPEED,    //启用切换点转速
    PAR_AX_1S2_SPEED,       //档位一与档位二切换点转速
    PAR_AX_2S3_SPEED,       //档位二与档位三切换点转速
    PAR_AX_3S4_SPEED,       //档位三与档位四切换点转速
    PAR_AX_SHIGT_SPEED,     //主轴换挡时电机转速
    PAR_AX_SHIGT_HOME,      //主轴换挡后需要重新回零

	PAR_AX_ACT_PULSE_TOLERANCE = 196,	// 断电反馈脉冲位置允差
	PAR_AX_ENC_TOLERANCE = 197,	// 断电位置允差
	PAR_AX_OUT_ACTVEL = 198,	// 实际速度超速判断周期
	PAR_AX_INTEG_PRD = 199,		// 显示速度积分周期数
	

	// 伺服参数（进给轴，预留100个）
	PAR_SV_POSITION_GAIN = SERVO_PARM_START_IDX,	// 位置比例增益
	PAR_SV_POS_FF_GAIN,				// 位置前馈增益
	PAR_SV_SPEED_GAIN,				// 速度比例增益
	PAR_SV_SPEED_KI,				// 速度积分时间常数
	PAR_SV_SPEED_FB_FILTER,			// 速度反馈滤波因子
	PAR_SV_MOTOR_TYPE = 243,		// 驱动器电机类型代码
	PAR_SV_MOTOR_RATING_CUR = 286,	// 电机额定电流
	
	// 伺服参数（主轴，预留100个）
	PAR_SP_POSITION_GAIN = SERVO_PARM_START_IDX,	// 位置控制位置比例增益
	PAR_SP_MOTOR_RATING_CUR = 253,	// IM电机额定电流
	PAR_SP_MOTOR_TYPE = 259,		// 驱动器电机类型代码

	PAR_AX_TOTAL = 500
};




// 误差补偿参数
enum 
{
	PAR_CMP_BL_ENABLE = 0,		// 反向间隙补偿类型
	PAR_CMP_BL_VALUE,			// 反向间隙补偿值
	PAR_CMP_BL_RATE,			// 反向间隙补偿率
	PAR_CMP_BL_VALUE2,			// 第2反向间隙补偿值（快移反向间隙补偿值）

	PAR_CMP_HEAT_TYPE = 5,		// 热误差补偿类型
	PAR_CMP_HEAT_REFN,			// 热误差补偿参考点坐标
	PAR_CMP_HEAT_WARP_START,	// 热误差偏置表起始温度
	PAR_CMP_HEAT_WARP_NUM,		// 热误差偏置表温度点数
	PAR_CMP_HEAT_WARP_STEP,		// 热误差偏置表温度间隔
	PAR_CMP_HEAT_WARP_SENSOR,	// 热误差偏置表传感器编号
	PAR_CMP_HEAT_WARP_TABLE,	// 热误差偏置表起始参数号
	PAR_CMP_HEAT_SLOPE_START,	// 热误差斜率表起始温度
	PAR_CMP_HEAT_SLOPE_NUM,		// 热误差斜率表温度点数
	PAR_CMP_HEAT_SLOPE_STEP,	// 热误差斜率表温度间隔
	PAR_CMP_HEAT_SLOPE_SENSOR,	// 热误差斜率表传感器编号
	PAR_CMP_HEAT_SLOPE_TABLE,	// 热误差斜率表起始参数号
	PAR_CMP_HEAT_RATE,			// 热误差补偿率

	PAR_CMP_PITCH_TYPE = 20,	// 螺距误差补偿类型
	PAR_CMP_PITCH_START,		// 螺距误差补偿起点坐标
	PAR_CMP_PITCH_NUM,			// 螺距误差补偿点数
	PAR_CMP_PITCH_STEP,			// 螺距误差补偿点间距
	PAR_CMP_PITCH_MODULO,		// 螺距误差取模补偿使能
	PAR_CMP_PITCH_FACTOR,		// 螺距误差补偿倍率
	PAR_CMP_PITCH_TABLE,		// 螺距误差补偿表起始参数号

	PAR_CMP_SQU1_ENABLE = 30,	// 第1项垂直度补偿使能
	PAR_CMP_SQU1_INPUT_AX,	    // 第1项垂直度补偿基准轴号
	PAR_CMP_SQU1_REFN,	        // 第1项垂直度补偿基准点坐标
	PAR_CMP_SQU1_ANG,	        // 第1项垂直度补偿角度

	PAR_CMP_SQU2_ENABLE = 40,	// 第2项垂直度补偿使能
	PAR_CMP_SQU2_INPUT_AX,	    // 第2项垂直度补偿基准轴号
	PAR_CMP_SQU2_REFN,	        // 第2项垂直度补偿基准点坐标
	PAR_CMP_SQU2_ANG,	        // 第2项垂直度补偿角度

	PAR_CMP_STRA1_INPUT_AX = 50,	// 第1项直线度补偿基准轴号
	PAR_CMP_STRA1_TYPE,	        // 第1项直线度补偿类型
	PAR_CMP_STRA1_START,	    // 第1项直线度补偿起点坐标
	PAR_CMP_STRA1_NUM,	        // 第1项直线度补偿点数
	PAR_CMP_STRA1_STEP,	        // 第1项直线度补偿点间距
	PAR_CMP_STRA1_MODULO,	    // 第1项直线度取模补偿使能
	PAR_CMP_STRA1_FACTOR,	    // 第1项直线度补偿倍率
	PAR_CMP_STRA1_TABLE,	    // 第1项直线度补偿表起始参数号

	PAR_CMP_STRA2_INPUT_AX = 65,	// 第2项直线度补偿基准轴号
	PAR_CMP_STRA2_TYPE,	        // 第2项直线度补偿类型
	PAR_CMP_STRA2_START,	    // 第2项直线度补偿起点坐标
	PAR_CMP_STRA2_NUM,	        // 第2项直线度补偿点数
	PAR_CMP_STRA2_STEP,	        // 第2项直线度补偿点间距
	PAR_CMP_STRA2_MODULO,	    // 第2项直线度取模补偿使能
	PAR_CMP_STRA2_FACTOR,	    // 第2项直线度补偿倍率
	PAR_CMP_STRA2_TABLE,    	// 第2项直线度补偿表起始参数号

	PAR_CMP_ANG1_INPUT_AX = 80,	// 第1项角度补偿基准轴号
	PAR_CMP_ANG1_ASSO_AX,	    // 第1项角度补偿关联轴号
	PAR_CMP_ANG1_REFN,          // 第1项角度补偿参考点坐标
	PAR_CMP_ANG1_TYPE,	        // 第1项角度补偿类型
	PAR_CMP_ANG1_START,	        // 第1项角度补偿起点坐标
	PAR_CMP_ANG1_NUM,	        // 第1项角度补偿点数
	PAR_CMP_ANG1_STEP,	        // 第1项角度补偿点间距
	PAR_CMP_ANG1_MODULO,	    // 第1项角度取模补偿使能
	PAR_CMP_ANG1_FACTOR,	    // 第1项角度补偿倍率
	PAR_CMP_ANG1_TABLE,	        // 第1项角度补偿表起始参数号

	PAR_CMP_ANG2_INPUT_AX = 95,	// 第2项角度补偿基准轴号
	PAR_CMP_ANG2_ASSO_AX,	    // 第2项角度补偿关联轴号
	PAR_CMP_ANG2_REFN,          // 第2项角度补偿参考点坐标
	PAR_CMP_ANG2_TYPE,	        // 第2项角度补偿类型
	PAR_CMP_ANG2_START,	        // 第2项角度补偿起点坐标
	PAR_CMP_ANG2_NUM,	        // 第2项角度补偿点数
	PAR_CMP_ANG2_STEP,	        // 第2项角度补偿点间距
	PAR_CMP_ANG2_MODULO,	    // 第2项角度取模补偿使能
	PAR_CMP_ANG2_FACTOR,	    // 第2项角度补偿倍率
	PAR_CMP_ANG2_TABLE,	        // 第2项角度补偿表起始参数号

	PAR_CMP_ANG3_INPUT_AX = 110,	// 第3项角度补偿基准轴号
	PAR_CMP_ANG3_ASSO_AX,	    // 第3项角度补偿关联轴号
	PAR_CMP_ANG3_REFN,          // 第3项角度补偿参考点坐标
	PAR_CMP_ANG3_TYPE,	        // 第3项角度补偿类型
	PAR_CMP_ANG3_START,	        // 第3项角度补偿起点坐标
	PAR_CMP_ANG3_NUM,	        // 第3项角度补偿点数
	PAR_CMP_ANG3_STEP,	        // 第3项角度补偿点间距
	PAR_CMP_ANG3_MODULO,	    // 第3项角度取模补偿使能
	PAR_CMP_ANG3_FACTOR,	    // 第3项角度补偿倍率
	PAR_CMP_ANG3_TABLE,	        // 第3项角度补偿表起始参数号

	PAR_CMP_QUAD_ENABLE = 125,	// 过象限突跳补偿类型
	PAR_CMP_QUAD_VALUE,         // 过象限突跳补偿值
	PAR_CMP_QUAD_DELAY_T,		// 过象限突跳补偿延时时间，单位：ms
	PAR_CMP_QUAD_MIN_VEL,		// 过象限突跳补偿最低速度
	PAR_CMP_QUAD_MAX_VEL,		// 过象限突跳补偿最高速度
	PAR_CMP_QUAD_ACC_T,			// 过象限突跳补偿加速时间，单位：ms
	PAR_CMP_QUAD_DEC_T,			// 过象限突跳补偿减速时间，单位：ms
	PAR_CMP_QUAD_TRQ_VAL,		// 静摩擦补偿扭矩值，取值范围：-10000~10000
	PAR_CMP_QUAD_TRQ_VAL2,		// 静摩擦补偿扭矩值2，取值范围：-10000~10000
	PAR_CMP_QUAD_TRQ_MAX,		// 静摩擦补偿扭矩值补偿值，取值范围：-10000~10000

	PAR_CMP_MULHT_TYPE = 135,		// 多元线性补偿类型
	PAR_CMP_MULHT_REFN,				// 多元线性补偿参考点坐标
	PAR_CMP_MULHT_BASE_WARP,		// 主轴偏置模型常量
	PAR_CMP_MULHT_WARP_SEN_NUM,		// 主轴偏置模型传感器接入个数
	PAR_CMP_MULHT_WARP_SEN_LIST,    // 主轴偏置模型传感器编号序列
	PAR_CMP_MULHT_WARP_COEF_TABLE,  // 主轴偏置模型系数表起始参数号
	PAR_CMP_MULHT_BASE_SLOPE,       // 丝杆斜率模型常量
	PAR_CMP_MULHT_SLOPE_SEN_NUM,    // 丝杆斜率模型传感器接入个数
	PAR_CMP_MULHT_SLOPE_SEN_LIST,   // 丝杆斜率模型传感器编号序列
	PAR_CMP_MULHT_SLOPE_COEF_TABLE, // 丝杆斜率模型系数表起始参数号

	PAR_CMP_RATE_ENABLE = 150,		//机床反向的补偿率，在反向间隙与双向螺补时生效
	PAR_CMP_RATE_LOW,				//低速时的补偿率，半径100，F1000时的补偿率
	PAR_CMP_RATE_HIGH,				//高速时的补偿率，半径100，F5000时的补偿率
	PAR_CMP_RATE_MAX,				//最大补偿率

	PAR_CMP_FEEDFOR_ENABLE,			//前馈补偿
	PAR_CMP_FEEDFOR_VEL,			//前馈补偿速度系数
	PAR_CMP_FEEDFOR_ACC,			//前馈补偿加速度系数
	PAR_CMP_FEEDFOR_RATE,			//前馈补偿补偿系数

	PAR_CMP_SPECIAL = 160,	// 专机预留/扩展参数起始地址
	PAR_CMP_TOTAL = 200		// 轴补偿参数总个数
};

// 设备接口参数
enum
{
	PAR_DEV_NAME,				// 设备名称
	PAR_DEV_INDEX,				// 设备的系统序号，在系统全部设备中的序号
	PAR_DEV_TYPE,				// 设备类型
	PAR_DEV_GRP_IDX,			// 在同组设备中的序号
	PAR_DEV_ID,					// 设备ID[生产唯一]
	PAR_DEV_VENDOR,				// 生产商
	PAR_DEV_READONLY_NUM = 8,	// 保留
	PAR_DEV_MODE,				// 设备数据字长
	PAR_DEV_GNL_NUM				// [设备通用参数的个数]
};


// 设备--主站设备
enum 
{
	// 系统固化参数
	PAR_DEV_BRD_FPGA_VER = PAR_DEV_GNL_NUM,	// FPGA固件程序版本号
	PAR_DEV_BRD_CARD_VER, // 主站卡版本号

	PAR_DEV_BRD_SYS_OBJ_NUM = (PAR_DEV_GNL_NUM+10),	// 本地控制对象个数，保留+追加
	PAR_DEV_BRD_NET_OBJ_NUM,	// 总线从站控制对象个数
	PAR_DEV_BRD_OBJ_NUM,		// 控制对象总个数，本地+总线从站

	// 用户配置参数
	PAR_DEV_BRD_BUS_CYCLE = (PAR_DEV_GNL_NUM+40),	// 总线通讯周期
	PAR_DEV_BRD_BUS_REQ_TIMES,	// 总线通讯请求次数
	PAR_DEV_BRD_BUS_TOPO,		// 拓扑结构（保留）

	PAR_DEV_BRD_SP_ADD_NUM = (PAR_DEV_GNL_NUM+50),	// 追加模拟量主轴数

	PAR_DEV_BRD_RESV_TYPE = (PAR_DEV_GNL_NUM+60)	// 本地保留设备类型，预留10个，可扩展

};

// 设备--AX
enum 
{
	PAR_DEV_AX_MODE = PAR_DEV_GNL_NUM,	// 工作模式
	PAR_DEV_AX_IDX,			// 设备对应的逻辑轴号
	PAR_DEV_AX_ENCOD_DIR,	// 编码器反馈取反标志
	PAR_DEV_AX_CMD_TYPE,	// 主轴DA输出类型
	PAR_DEV_AX_CYC_EN,      // 反馈位置循环使能
	PAR_DEV_AX_MT_PPR,		// 反馈位置循环脉冲数
	PAR_DEV_AX_ENCOD_TYPE,  // 编码器类型
	PAR_DEV_AX_RESERVE1,	// 保留1
	PAR_DEV_AX_RESERVE2,	// 保留2
	PAR_DEV_AX_RESERVE3     // 保留3
};

// 设备--MPG
enum 
{
	PAR_DEV_MPG_TYPE = PAR_DEV_GNL_NUM,	// MPG类型
	PAR_DEV_MPG_IDX,					// MPG编号
	PAR_DEV_MPG_IN,						// 档位输入点组号
	PAR_DEV_MPG_DIR_FLAG,				// 各轴方向取反标志
	PAR_DEV_MPG_MULT_FACTOR,			// 倍率放大系数
	PAR_DEV_MPG_PAR_NUM					// MPG实际配置参数数目
};

// 设备--NCKB
enum 
{
	PAR_DEV_NCKB_TYPE = PAR_DEV_GNL_NUM,	// NCKB键盘类型
	PAR_DEV_NCKB_IDX,		// NCKB编号
	PAR_DEV_NCKB_CYCLE,		// NCKB扫描周期
	PAR_DEV_NCKB_PAR_NUM	// NCKB实际配置参数数目
};

// 设备--IO_LOC/IO_NET
enum 
{
	PAR_DEV_IO_WATCHDOG = PAR_DEV_GNL_NUM,	// 是否包含看门狗（保留）
	PAR_DEV_IO_AXIS_CTRL,	// 是否是轴控制板（保留）
	PAR_DEV_IN_X_BASE,		// 输入点X寄存器起始组号(PAR_DEV_GNL_NUM+2)
	PAR_DEV_IN_X_GRPN,		// 输入点组数
	PAR_DEV_OUT_Y_BASE,		// 输出点Y寄存器起始组号
	PAR_DEV_OUT_Y_GRPN,		// 输出点组数
	PAR_DEV_ENCOD1_TYPE,	// 编码器1类型
	PAR_DEV_ENCOD1_PPR,		// 编码器1每转脉冲数
	PAR_DEV_ENCOD2_TYPE,	// 编码器2类型
	PAR_DEV_ENCOD2_PPR,		// 编码器2每转脉冲数
};



// 设备--MCP_LOC/MCP_NET
enum
{
	PAR_DEV_MCP_TYPE = PAR_DEV_GNL_NUM,	// MCP类型：1-A / 2-B /3-C
	PAR_DEV_MCP_MPG_IDX,	// 手摇编号
	PAR_DEV_MCP_X_BASE,     // 输入点X寄存器起始组号(PAR_DEV_GNL_NUM+2)
	PAR_DEV_MCP_X_GRPN,     // 输入点占用X寄存器组数
	PAR_DEV_MCP_Y_BASE,     // 输出点寄存器起址
	PAR_DEV_MCP_Y_GRPN,     // 输出点占用Y寄存器组数
	PAR_DEV_MCP_MPG_DIR,    // 手摇方向取反标志
	PAR_DEV_MCP_MPG_MULT,   // 手摇倍率放大系数
	PAR_DEV_MCP_CODE_TYPE,  // 波段开关编码类型
	PAR_DEV_MCP_SPDL_NUM    // 追加模拟量主轴数（temp）
};

// 设备--SERIAL
enum 
{
	PAR_SERIAL_BIT_LEN = PAR_DEV_GNL_NUM,   // 收发数据位长度
	PAR_SERIAL_STOP,		// 停止位
	PAR_SERIAL_PARITY,		// 奇偶校验位
	PAR_SERIAL_BAUDRATE,	// 波特率
	PAR_SERIAL_PAR_NUM		// SERIAL实际配置参数数目
};

// 设备--LAN
enum 
{
	PAR_LAN_IP0 = PAR_DEV_GNL_NUM, // IP0
	// PAR_LAN_IP1,	// IP1
	// PAR_LAN_IP2,	// IP2
	// PAR_LAN_IP3,	// IP3
	PAR_LAN_GATE0,	// GATE0
	// PAR_LAN_GATE1,	// GATE1
	// PAR_LAN_GATE2,	// GATE2
	// PAR_LAN_GATE3,	// GATE3
	PAR_LAN_MASK0,	    // MASK0
	// PAR_LAN_MASK1,	// MASK1
	// PAR_LAN_MASK2,	// MASK2
	// PAR_LAN_MASK3,	// MASK3
	PAR_LAN_PAR_NUM     // LAN实际配置参数数目
};

// 设备--WCOM无线通讯接口
enum 
{
	PAR_WCOM_TYPE = PAR_DEV_GNL_NUM, // WCOM类型
	PAR_WCOM_RESERVE,	// 保留
	PAR_WCOM_PAR_NUM	// WCOM实际配置参数数目
};

// 设备--GATHER采集卡
enum
{
	PAR_GATHER_TYPE = PAR_DEV_GNL_NUM,	// 采集卡类型 1:KZM-6000
	PAR_GATHER_SERIAL_IDX,    // 串口设备号
	PAR_GATHER_SENSOR_NUM,    // 传感器数
	PAR_GATHER_IN_X_BASE,     // 输入点起始组号
	PAR_GATHER_PAR_NUM        // GATHER实际配置参数数目
};

// 数控设备控制对象应用类型定义，系统根据其类型和接口参数确定控制对象在系统中
// 的输入输出数据地址
enum DevNcobjType
{
	DEV_NCOBJ_NULL_LOC = 1000,	// 本地设备--非网络设备
	DEV_NCOBJ_SPDL_LOC,
	DEV_NCOBJ_AXIS_LOC,
	DEV_NCOBJ_IN_LOC,
	DEV_NCOBJ_OUT_LOC,
	DEV_NCOBJ_AD_LOC,
	DEV_NCOBJ_DA_LOC,
	DEV_NCOBJ_IOMD_LOC,		// NCUC总线的IO集成模块
	DEV_NCOBJ_MCP_LOC,
	DEV_NCOBJ_MPG_LOC,
	DEV_NCOBJ_NCKB_LOC,
	DEV_NCOBJ_SENSOR_LOC,	// 传感器设备
	DEV_NCOBJ_SERIAL_LOC,	// 串口设备
	DEV_NCOBJ_GATHER_LOC,	// 温度采集卡

	DEV_NCOBJ_NULL_NET = 2000,	// 网络设备--ncuc\ethercat\syqnet...
	DEV_NCOBJ_SPDL_NET,
	DEV_NCOBJ_AXIS_NET,
	DEV_NCOBJ_IN_NET,
	DEV_NCOBJ_OUT_NET,
	DEV_NCOBJ_AD_NET,
	DEV_NCOBJ_DA_NET,
	DEV_NCOBJ_IOMD_NET,		// NCUC总线的IO集成模块
	DEV_NCOBJ_MCP_NET,
	DEV_NCOBJ_MPG_NET,
	DEV_NCOBJ_NCKB_NET,
	DEV_NCOBJ_SENSOR_NET,	// 传感器
	DEV_NCOBJ_PIDC_NET,		// 位控板

	// 此处扩展新的类型
	DEV_NCOBJ_ENCOD_NET		// 编码器
};

// 	刀具参数
// 2.1 基本数据范围
#define MAX_GEO_PARA	(24)	// 刀具几何参数个数
#define MAX_WEAR_PARA	(24)	// 刀具磨损参数个数
#define MAX_TECH_PARA	(24)	// 刀具工艺相关参数个数
#define MAX_TOOL_EXPARA	(24)	// 刀具扩展参数个数
#define MAX_TOOL_MONITOR (24)	// 刀具监控参数个数
#define MAX_TOOL_MEASURE (24)	// 刀具测量参数个数
#define MAX_TOOL_BASE	(24)	// 刀具一般信息参数个数
#define MAX_TOOL_PARA	(200)	// 刀具基本参数个数 (24+24+24+24+24+24+24 = 168)
#define MAGZ_HEAD_SIZE	(16)	// 刀库数据表头大小

// 刀具参数索引
// INFTOOL_开头的为Bit32，其它为fBit64
enum ToolParaIndex
{
	// 刀具几何相关参数索引
	GTOOL_DIR = 0,	// 方向 
	GTOOL_LEN1,	// 长度1(铣：刀具长度；车：X偏置)
	GTOOL_LEN2,	// 长度2(车：Y偏置)
	GTOOL_LEN3,	// 长度3(车：Z偏置)
	GTOOL_LEN4,	// 长度4
	GTOOL_LEN5,	// 长度5
	GTOOL_RAD1,	// 半径1(铣：刀具半径；车：刀尖半径)
	GTOOL_RAD2,	// 半径2
	GTOOL_ANG1,	// 角度1
	GTOOL_ANG2,	// 角度2

	GTOOL_TOTAL,

	// 刀具磨损相关参数索引
	WTOOL_LEN1 = MAX_GEO_PARA, // (铣：长度磨损；车：Z磨损)
	WTOOL_LEN2,	// 长度2
	WTOOL_LEN3,	// 长度3
	WTOOL_LEN4,	// 长度4
	WTOOL_LEN5,	// 长度5
	WTOOL_RAD1,	// 半径1(铣：半径磨损；车：X磨损)
	WTOOL_RAD2,	// 半径2
	WTOOL_ANG1,	// 角度1
	WTOOL_ANG2,	// 角度2
	
	WTOOL_TOTAL,
	
	// 刀具工艺相关参数索引
	TETOOL_PARA0 = MAX_GEO_PARA+MAX_WEAR_PARA, // 工艺相关参数0～参数MAX_TECH_PARA_NUM-1
	TETOOL_PARA1,
	TETOOL_PARA2,
	TETOOL_PARA3,
	TETOOL_PARA4,
	TETOOL_PARA5,
	TETOOL_PARA6,
	TETOOL_PARA7,
	TETOOL_PARA8,
	TETOOL_PARA9,
	// 暂用10个，今后再加
	
	TETOOL_TOTAL,

	// 刀具扩展参数--刀具管理参数，各刀具类型通用
	EXTOOL_S_LIMIT = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA,    // S转速限制
	EXTOOL_F_LIMIT,    // F转速限制
	EXTOOL_LARGE_LEFT,		// 大刀具干涉左刀位
	EXTOOL_LARGE_RIGHT,		// 大刀具干涩右刀位

	EXTOOL_TOTAL,

	// 刀具监控参数
    MOTOOL_TYPE = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA+MAX_TOOL_EXPARA, // 刀具监控类型，按位有效，寿命/计件/磨损，可选多种监控方式同时监控
	MOTOOL_SEQU,		// 	优先级
	MOTOOL_MULTI,		// 	倍率

	MOTOOL_MAX_LIFE,	// 最大切削时间
	MOTOOL_ALM_LIFE,	// 预警切削时间
	MOTOOL_ACT_LIFE,	// 实际切削时间

	MOTOOL_MAX_COUNT,	// 最大安装次数
	MOTOOL_ALM_COUNT,	// 预警安装次数
	MOTOOL_ACT_COUNT,	// 实际安装次数

	MOTOOL_MAX_WEAR,	// 未使用
	MOTOOL_ALM_WEAR,	// 未使用
	MOTOOL_ACT_WEAR,	// 未使用

	MOTOOL_GROUP,       // 刀具所属分组号

	MOTOOL_TOTAL,

	// 刀具测量参数个数
	METOOL_PARA0 = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA+MAX_TOOL_EXPARA+MAX_TOOL_MONITOR,
	METOOL_PARA1,
	METOOL_PARA2,
	METOOL_PARA3,
	METOOL_PARA4,
	METOOL_PARA5,
	METOOL_PARA6,
	METOOL_PARA7,
	METOOL_PARA8,
	METOOL_PARA9,

	METOOL_TOTAL,

	// 	刀具一般信息
	INFTOOL_ID = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA+MAX_TOOL_EXPARA+MAX_TOOL_MONITOR+MAX_TOOL_BASE, // 刀具索引号
	INFTOOL_MAGZ,		// 	刀具所属刀库号
	INFTOOL_CH,			// 	刀具所属通道号
	INFTOOL_TYPE,		// 	刀具类型
	INFTOOL_STATE,		// 	刀具状态字
	INFTOOL_G64MODE,	//  刀具高速高精加工模式

	INFTOOL_TOTAL,

	TOOL_PARA_TOTAL // < MAX_TOOL_PARA
};

// 刀库表表头数据索引
enum MagzHeadIndex
{
	MAGZTAB_HEAD = 0,	// 刀库表起始偏移地址（刀具号段+刀位属性段）
	MAGZTAB_TOOL_NUM,	// 刀库表中刀具数
	MAGZTAB_CUR_TOOL,	// 当前刀具号
	MAGZTAB_CUR_POT,	// 当前刀位号
	MAGZTAB_REF_TOOL,	// 标刀号
	MAGZTAB_CHAN,		// 刀库所属通道号
	MAGZTAB_TYPE,		// 刀库类型
	SWAP_LEFT_TOOL,		// 机械手左刀位刀具号
	SWAP_RIGHT_TOOL,	// 机械手右刀位刀具号
	// 预留

	MAGZTAB_TOTAL
};

// 刀具参数具体化（兼容以前的刀具宏）
// 铣刀参数索引
#define MTOOL_RAD		GTOOL_RAD1	// 刀具半径
#define MTOOL_LEN		GTOOL_LEN1	// 刀具长度
#define MTOOL_RAD_WEAR	WTOOL_RAD1	// 铣刀:半径磨损补偿（径向）
#define MTOOL_LEN_WEAR	WTOOL_LEN1	// 铣刀:长度磨损补偿（轴向）

// 车刀参数索引
#define LTOOL_RAD		GTOOL_RAD1		// 刀尖半径
#define LTOOL_DIR		GTOOL_DIR		// 刀尖方向
#define LTOOL_RAD_WEAR	WTOOL_RAD1		// 车刀:刀具磨损值（径向）（相对值）
#define LTOOL_LEN_WEAR	WTOOL_LEN1		// 车刀:刀具磨损值（轴向）（相对值）
#define LTOOL_XOFF		GTOOL_LEN1		// 车刀：刀具偏置值（径向）（绝对值） =  试切时X值 - 试切直径/2
#define LTOOL_YOFF		GTOOL_LEN2
#define LTOOL_ZOFF		GTOOL_LEN3		// 车刀：刀具偏置值（轴向）（绝对值） =  试切时Z值 - 试切长度
#define LTOOL_XDONE		TETOOL_PARA0	// X试切标志
#define LTOOL_YDONE		TETOOL_PARA0
#define LTOOL_ZDONE		TETOOL_PARA1	// Z试切标志

#define SPDL_RESOLUTION	(1000)	// 主轴转速分辨率
#define MAX_SCAN_ROW_NUM_RANDOM 1000
#define GIVEN_ROW_IDLE				0
#define GIVEN_ROW_WAIT_PROG_OK		1     //等待任意行程序准备好
#define GIVEN_ROW_SCANING			2     //任意行扫描中
#define GIVEN_ROW_WAIT_SCAN_ACK		3     //任意行等待界面给出应答后再向后继续扫描
#define GIVEN_ROW_WAIT_SUBPROG_OK	4     //等待任意行子程序准备好
#define GIVEN_ROW_SUBPROG_OK		5     //任意行子程序准备好
#define GIVEN_ROW_SUBPROG_EXCUTING	6    //任意行子程序执行中
#define GIVEN_ROW_SCAN_ERR			7    //任意行扫描中发现语法错误
#define GIVEN_ROW_TYPE1_WAIT_Z_MOVE 8    //任意行扫描模式1，等待Z轴移动指令

// 采样
// 采样数据宏定义
#define SMPL_CHAN_NUM (16)		// 采样通道数
#define SMPL_DATA_NUM (10000)	// 每采样通道的采样点数

// 采样类型
enum HncSampleType
{
	SAMPL_NULL_TYPE = 0,// 空类型
	SAMPL_AXIS_CMD = 1,	// 轴的指令位置
	SAMPL_AXIS_ACT,		// 轴的实际位置
	SAMPL_FOLLOW_ERR,	// 轴的跟随误差
	SAMPL_CMD_INC,		// 轴的指令速度
	SAMPL_ACT_VEL,		// 轴的实际速度
	SAMPL_ACT_TRQ,		// 轴的负载电流
	SAMPL_CMD_POS,		// 指令电机位置
	SAMPL_CMD_PULSE,	// 指令脉冲位置
	SAMPL_ACT_POS,		// 实际电机位置
	SAMPL_ACT_PULSE,	// 实际脉冲位置
	SAMPL_TOL_COMP,		// 补偿值
	SAMPL_SYS_VAL = 101,	// 系统变量
	SAMPL_CHAN_VAL,		// 通道变量
	SAMPL_AXIS_VAL,		// 轴变量
	SAMPL_X_REG,		// X寄存器
	SAMPL_Y_REG,		// Y寄存器
	SAMPL_F_AXIS_REG,	// 轴F寄存器
	SAMPL_G_AXIS_REG,	// 轴G寄存器
	SAMPL_F_CHAN_REG,	// 通道F寄存器
	SAMPL_G_CHAN_REG,	// 通道G寄存器
	SAMPL_F_SYS_REG,	// 系统F寄存器
	SAMPL_G_SYS_REG,	// 系统G寄存器
	SAMPL_R_REG,		// R寄存器
	SAMPL_B_REG,		// B寄存器
	SAMPL_TOTAL
};
#define T_CTRL_CHANGE_DIRECT 0X1
#define T_CTRL_TOOL_MODE     0X2
#define VAR_WRITE_WAIT       0X1
#define VAR_READ_WAIT        0X2
#endif // __HNC_DATADEF_H__
