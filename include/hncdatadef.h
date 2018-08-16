/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncdatadef.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ���������ݶ���
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2013��9��25��
* ˵    �������������ߡ�����
*/

#ifndef __HNC_DATADEF_H__
#define __HNC_DATADEF_H__

#ifdef _HNC_80_

	#define SYS_CHAN_NUM	12
	#define SYS_AXES_NUM	64
	#define SYS_SPDL_NUM	16//������
	#define SYS_NCBRD_NUM	8 //�������豸��
	#define SYS_NCOBJ_NUM	120 //���豸���ƶ��󣨲�������������+RS232+LAN+USB+MCP+NCKB+I/O��
	#define CHAN_AXES_NUM	9
	#define CHAN_SPDL_NUM   4	//ͨ�����������
	#define MAX_SMC_AXES_NUM 32	//����˿�����

#else

	#define SYS_CHAN_NUM		(4)		// ϵͳ���ͨ����
	#define SYS_AXES_NUM		(24)	// ϵͳ����������
	#define SYS_SPDL_NUM		(8)		// ϵͳ���������
	#define SYS_NCBRD_NUM		(4)		// �������豸��
	#define SYS_NCOBJ_NUM		(80)	// ���豸���ƶ��󣨲�������
	#define CHAN_AXES_NUM		(9)		// ͨ���������
	#define CHAN_SPDL_NUM		(4)		// ͨ�����������
	#define MAX_SMC_AXES_NUM	(16)	// ����˿�����

#endif

#define TOTAL_AXES_NUM		(SYS_AXES_NUM+SYS_SPDL_NUM) // ϵͳ����߼�����
#define SYS_PART_NUM		SYS_NCOBJ_NUM	// 	ϵͳ�豸�ӿ���

// ����
// ID��� 
#define NCU_PARAM_ID_BASE	(0)
#define MAC_PARAM_ID_BASE	(10000)
#define CHAN_PARAM_ID_BASE	(40000)
#define AXIS_PARAM_ID_BASE	(100000)
#define COMP_PARAM_ID_BASE	(300000)
#define DEV_PARAM_ID_BASE	(500000)
#define TABLE_PARAM_ID_BASE (700000)  // ���ݱ����

#define NCU_PARAM_ID_NUM	(1000)
#define MAC_PARAM_ID_NUM	(1000)
#define CHAN_PARAM_ID_NUM	(1000)
#define AXIS_PARAM_ID_NUM	(1000)
#define COMP_PARAM_ID_NUM	(1000)
#define DEV_PARAM_ID_NUM	(1000)
#define TABLE_PARAM_ID_NUM  (100000)  // ��������ݱ������ID��


// �����������궨��
// �������
#define PARAMAN_FILE_NCU	(0)	// NC����
#define PARAMAN_FILE_MAC	(1)	// �����û�����
#define PARAMAN_FILE_CHAN	(2)	// ͨ������
#define PARAMAN_FILE_AXIS	(3)	// ���������
#define PARAMAN_FILE_ACMP	(4)	// ��������
#define PARAMAN_FILE_CFG	(5)	// �豸�ӿڲ���
#define PARAMAN_FILE_TABLE	(6)	// ���ݱ����
#define PARAMAN_FILE_BOARD	(7)	// ��վ����


#define PARAMAN_MAX_FILE_LIB		(7)		// �����ṹ�ļ���������
#define PARAMAN_MAX_PARM_PER_LIB	(1000)	// ������������Ŀ�� 
#define PARAMAN_MAX_PARM_EXTEND     (1000)	// ��֧��չ���������Ŀ��
#define PARAMAN_LIB_TITLE_SIZE		(16)	// �������ַ�����󳤶�
#define PARAMAN_REC_TITLE_SIZE		(16)	// �������ַ�����󳤶�
#define PARAMAN_ITEM_NAME_SIZE		(64)	// ������Ŀ�ַ�����󳤶�




// ������Ի���ַ��ƫ��
// NC����
enum 
{
	PAR_NCU_TYPE,			// NCU����������
	PAR_NCU_CYCLE,			// �岹����
	PAR_NCU_PLC2_CMDN,		// PLC2����ִ�������

	PAR_NCU_ANG_RESOL = 5,	// �Ƕȼ���ֱ���
	PAR_NCU_LEN_RESOL,		// ���ȼ���ֱ���
	PAR_NCU_TIME_RESOL,		// ʱ���̷ֱ���
	PAR_NCU_VEL_RESOL,		// ���ٶȱ�̷ֱ���
	PAR_NCU_SPDL_RESOL,		// ���ٶȱ�̷ֱ���
	PAR_NCU_ARC_PROFILE,	// Բ���岹�����������
	PAR_NCU_MAX_RAD_ERR,	// Բ����̶˵�뾶����ƫ��
	PAR_NCU_G43_SW_MODE,	// ������ѡ��ʽ[0,�̶�z��;1,G17/18/19�л�;2,G43ָ�����л�]
	PAR_NCU_G41_G00_G01,	// G00�岹ʹ��
	PAR_NCU_G53_LEN_BACK,	// G53֮���Զ��ָ����߳��Ȳ���[0,���ָ� 1 �ָ�]
	PAR_NCU_CRDS_NUM,	    // ������������
	PAR_NCU_LAN_EN,			// ������ʹ��
	PAR_NCU_POWER_SAFE,		// �ϵ籣��ʹ��
	PAR_NCU_TIME_EN,		// ϵͳʱ����ʾʹ��
	PAR_NCU_PSW_CHECK,		// Ȩ�޼��ʹ��
	PAR_NCU_ALARM_POP,		// ���������Զ���ʾʹ��
	PAR_NCU_KBPLC_EN,       // ����PLCʹ��
	PAR_NCU_GRAPH_ERAS_EN,  // ͼ���Զ�����ʹ��	
	PAR_NCU_FSPD_DISP,		// F�����ٶ���ʾ��ʽ	
	PAR_NCU_GLNO_DISP,		// G�����к���ʾ��ʽ
	PAR_NCU_INCH_DISP,	    // ����/Ӣ��ѡ��
	PAR_NCU_DISP_DIGITS,	// λ��С�������ʾλ��
	PAR_NCU_FEED_DIGITS,	// �ٶ�С�������ʾλ��
	PAR_NCU_SPINDLE_DIGITS,	// ת��С�������ʾλ��
	PAR_NCU_LANGUAGE,		// ����ѡ��
	PAR_NCU_LCD_TIME,		// ���������ȴ�ʱ��
	PAR_NCU_DISK_TYPE,		// ���ó���洢����
	PAR_NCU_REFRE_INTERV,   // ����ˢ�¼��ʱ��
	PAR_NCU_SAVE_TYPE,      // �Ƿ����UPS
	PAR_NCU_OPERATE_NOTE,   // ������ʾʹ��[0λ�������� 1λ��Tool->���ʵ�� 2λ��Tool->��ǰλ��]
	PAR_NCU_SERVER_NAME,
	PAR_NCU_SERVER_IP1,
	PAR_NCU_SERVER_IP2,
	PAR_NCU_SERVER_IP3,
	PAR_NCU_SERVER_IP4,
	PAR_NCU_SERVER_PORT,    // �������˿ں�
	PAR_NCU_SERVER_LOGIN,   // �����������û���
	PAR_NCU_SERVER_PASSWD,  // ��������������

	PAR_NCU_NET_TYPE = 44,       // ����ӳ������
	PAR_NCU_IP1,            // IP��ַ��1
	PAR_NCU_IP2,            // IP��ַ��2
	PAR_NCU_IP3,            // IP��ַ��3
	PAR_NCU_IP4,            // IP��ַ��4
	PAR_NCU_PORT,           // ���ض˿ں�
	PAR_NCU_NET_START,		// �Ƿ�������
	PAR_NCU_SERIAL_TYPE,	// ��������
	PAR_NCU_SERIAL_NO = 52,	// ���ں�
	PAR_NCU_DATA_LEN,       // �շ����ݳ���
	PAR_NCU_STOP_BIT,       // ֹͣλ
	PAR_NCU_VERIFY_BIT,     // У��λ
	PAR_NCU_BAUD_RATE,      // ������
	PAR_NCU_IP_TYPE,        // ��̬IP/��̬IP
	PAR_NCU_ARCS_INTERSECT, //Բ�������ʲ�
	PAR_NCU_TOOL_NUM = 60,	// ��󵶾���
	PAR_NCU_TOFF_DIGIT,     // ������Чλ��
	PAR_NCU_MAGZ_NUM,		// ��󵶿���
	PAR_NCU_TOOL_LOCATION,	// �������
	PAR_NCU_TABRA_ADD_EN,   // ����ĥ���ۼ�ʹ��
	PAR_NCU_TDIA_SHOW_EN,   // ����ֱ����ʾʹ��
	PAR_NCU_SUB_PROG_EN,    // ȫ���ӳ������ʹ��
	PAR_NCU_TRANS_ORDER,	// ����������תǶ�״���
							// ��0 ��ת->����->���� 1 ����->����->��ת 2 ���ɱ�̣��Զ�����ɰ�����->����->��ת�Ĵ���ʵʩ�任 
							// 3 ����ʵ�ʵı�̴���ʵʩ�任�� 0/1/2����ѡ��ʱ�����ᰴ�վ���->����->��ת�Ĵ���ʵʩ�任��
	PAR_NCU_CYCLE_OPT,		// ����ѭ��·��ѡ�0x00FF: 0 ����  1 �˵���Ч������ 2 FANUC����  &0xFF00 = =  0x0000 : 45���˵� 0x0100: �����˵� 
							// &0x0200 = =  0x0200ʱ���һ��ֱ���˵�ѭ����㣬��������̨��ʱ��Ҫ�ô�ѡ�
	PAR_NCU_HOLD_DECODE_EN,	// �������ֺ����½���ʹ��
	PAR_NCU_G28_LEN_BACK,	// G28���Ƿ��Զ��ָ�������
	PAR_NCU_SPEEDUP_EN,    // �ڲ������ã�����ʹ��

	PAR_NCU_LOG_SAVE_TYPE = 80, // ��־�ļ���������

	PAR_NCU_INTERNET_IP1,	// ����ƽ̨������IP
	PAR_NCU_INTERNET_IP2,
	PAR_NCU_INTERNET_IP3,
	PAR_NCU_INTERNET_IP4,
	PAR_NCU_INTERNET_PORT,	//����ƽ̨�������˿�
	PAR_NCU_GATEWAY1,		//��������
	PAR_NCU_GATEWAY2,
	PAR_NCU_GATEWAY3,
	PAR_NCU_GATEWAY4,

	PAR_NCU_HMI = 100,					// �������ò�������ַ
	PAR_NCU_ISSU_EDITION = PAR_NCU_HMI,	// �����汾��
	PAR_NCU_TEST_EDITION,				// ���԰汾��
	PAR_NCU_SHOW_LIST,					// ʾֵ�У�40
	PAR_NCU_GRAPH = PAR_NCU_SHOW_LIST+40,	// ͼ�β�����90

	PAR_NCU_ALARM_LOG_NUM_LIMIT = 280,	//	��־��Ŀ����
	PAR_NCU_WORKINFO_LOG_NUM_LIMIT,
	PAR_NCU_FILECHANGE_LOG_NUM_LIMIT,
	PAR_NCU_PANEL_LOG_NUM_LIMIT,
	PAR_NCU_DEFINE_LOG_NUM_LIMIT,
	PAR_NCU_EVENT_LOG_NUM_LIMIT,

	PAR_NCU_ALARM_LOG_TIME_LIMIT = 290,	//	��־ʱ������
	PAR_NCU_WORKINFO_LOG_TIME_LIMIT,
	PAR_NCU_FILECHANGE_LOG_TIME_LIMIT,
	PAR_NCU_PANEL_LOG_TIME_LIMIT,
	PAR_NCU_DEFINE_LOG_TIME_LIMIT,
	PAR_NCU_EVENT_LOG_TIME_LIMIT,

	PAR_NCU_PROG_PATH = 300,	// �ӹ��������·��
	PAR_NCU_PLC_PATH,		// PLC����·��
	PAR_NCU_PLC_NAME,		// PLC������
	PAR_NCU_DRV_PATH,		// ��������·��
	PAR_NCU_DRV_NAME,		// ����������
	PAR_NCU_PARA_PATH,		// �����ļ�·��
	PAR_NCU_PARA_NAME,		// �����ļ���
	PAR_NCU_SIMU_PATH,		// ���������ļ�·��
	PAR_NCU_SIMU_NAME,		// ���������ļ���
	PAR_NCU_DLGP_PATH,		// �Ի���������ļ�·��
	PAR_NCU_DLGP_NAME,		// �Ի���������ļ���
	PAR_NCU_VIDEO_DEV,      // ��Ƶ��������
			
	PAR_NCU_SUB_DBG = 320,	// ����򵥶�ʹ�ܡ�WIN��
	PAR_NCU_USER_LOGIN = 321,	// 	�Ƿ����û���¼?
	PAR_NCU_G16_OPT = 350,	// G16�ļ��㶨��ģʽѡ�� 0��FANUCģʽ 1��HNC-8ģʽ
	PAR_NCU_GEDIT_FRAME = 351,	// �༭������ѡ�� 0��HNC-8ģʽ 1������ר��ģʽ
	PAR_NCU_FTP_MODE = 352,	// FTP���ӷ�ʽ 0��HNC-8ģʽ 1�����ģʽ
	PAR_NCU_TCS = 353,//�Ƿ�����������ϵ���ܽ��� 0:������ 1:����
	PAR_NCU_HMI_TYPE,		// HMI���ͣ�0����׼8�ͣ�1�����ר�ã�
	PAR_NCU_CHECK_SYSDISK_FREE,	// ϵͳ��ʣ��ռ䲻����ʾ�����ֵ
	PAR_NCU_MILL_FUN_TYPE,	// ϳ����������
	PAR_NCU_API_LOG_LEVEL,    // api��־��¼����
	PAR_NCU_EXIT_MDI_CLEAR,		// �˳�mdiʱ�Ƿ����mdi����
	PAR_NCU_DEFAULT_RIGHT_LEVEL = 359, // �ϵ�Ĭ���û�Ȩ��
	PAR_NCU_MCP_TYPE = 360, // Ȩ����������(360~377)
	PAR_NCU_TOTAL = 500		// NC��������
};



// �����û�����
enum 
{
	PAR_MAC_CHAN_NUM,	// ͨ������1~SYS_CHAN_NUM
	PAR_MAC_CHAN_TYPE,	// ����ͨ���ӹ����͡�����ϳ����ĥ��
#ifdef _HNC_80_
	PAR_MAC_CHAN_FLAG = PAR_MAC_CHAN_TYPE+16,	// ͨ��ѡ���־
	//PAR_MAC_CHAN_AX_FLAG = PAR_MAC_CHAN_FLAG+12,	// ͨ��������ʾ��־��ÿ��ͨ��ռ��������������8*2 = 16������
	//PAR_MAC_CHAN_CUR_FLAG = PAR_MAC_CHAN_AX_FLAG+12,	// ͨ���ĸ��ص�����ʾ�ᶨ��
#else
	PAR_MAC_CHAN_FLAG = PAR_MAC_CHAN_TYPE+8,	// ͨ��ѡ���־
	PAR_MAC_CHAN_AX_FLAG = PAR_MAC_CHAN_FLAG+8,	// ͨ��������ʾ��־��ÿ��ͨ��ռ��������������8*2 = 16������
	PAR_MAC_CHAN_CUR_FLAG = PAR_MAC_CHAN_AX_FLAG+16,	// ͨ���ĸ��ص�����ʾ�ᶨ��
#endif
	PAR_MAC_SHOW_AXES = 41,		// �Ƿ�̬��ʾ������
	PAR_MAC_CALIB_TYPE,			// ���߲���������
	PAR_MAC_ALARM_PAUSE,		// �����Լ쾯����ͣ����
	PAR_MAC_CC_CW_SPD_TYPE,		// �뾶����Բ���ٶȴ������
	PAR_MAC_CC_WEAR_TYPE,       //�뾶����=�뾶��/��ĥ��
	PAR_MAC_CC_CHECK_CTRL,      //�뾶����������ƣ�0�����汨�� 1���Զ��������
	PAR_MAC_CC_CHECK_NUM,         //�뾶�������������
	
	PAR_MAC_HOME_BLOCK = 48,	// �����Ƿ�װ���㵲��
	PAR_MAC_AXES_NUM,			// ����������
	PAR_MAC_SMX_AXIS_NUM,		// �˶�����ͨ����������ϴ���+PMC�ᣩ
	PAR_MAC_SMX_AXIS_IDX,		// PMC����ϴ����ţ�Ԥ��32��

    PAR_MAC_CYC_TYPE=83,      //�깥���Ĺ̶�ѭ������
    PAR_MAC_T_CTRL_TYPE=89,         //Tָ����Ʒ�ʽ
    PAR_MAC_USR_VAR_WAIT,          //�û��Զ��������Ƿ�ִ��G08�ȴ�
    PAR_MAC_USR_NEW_USR_VAR,      //����FANUC,���⣬#500~999�ϵ籣�档0���رնϵ籣�湦�ܣ�1����
	PAR_MAC_SP_POS_HOLD,		// C��Ϊ�ٶ�ģʽʱ��ˢ������

	PAR_MAC_TOOL = 100,	// ���ߴ������Ԥ��
	
	PAR_MAC_FZONE_IN_MASK=110,	//�����������ڲ���ֹ����
	PAR_MAC_FZONE_EX_MASK,		//�����������ⲿ��ֹ����
	PAR_MAC_FZONE_BND,		//�����������߽�-x +x -y +y -z +z 6*6=36
	
	PAR_MAC_HOME_DWELL = 165,	// �زο�����ʱʱ�䣬��λ��ms
	PAR_MAC_PLCACK_CYCLE,		// PLCӦ���ʱ��
	PAR_MAC_G32_HOLD_DX,		// ���Ƽӹ���ֹ���˵�����
	PAR_MAC_G32_HOLD_ANG,		// ���Ƽӹ���ֹ���˵��Ƕ�
	PAR_MAC_G64_CORNER_CHK,		// G64�ս�׼ͣУ����ʹ��
	
	PAR_MAC_MCODE_FLAG = 170,	// M�������Ա�
	
	PAR_MAC_CHAN_GMODE_SHOW = 220,	// ģ̬Gָ����ʾ���ƣ�ÿ����λռ��3����������8*3 = 24������
	
	PAR_MAC_MEAS_SPD = 250,	// �����ٶ�
	PAR_MAC_MEAS_DIST,		// ������С�г�
	
	PAR_MAC_IPSYNC_FUN = 260,	// �岹ͬ������ע��
	
	PAR_MAC_SPECIAL = 270,		// ר��Ԥ��������ʼ��ַ
	
	PAR_MAC_CHECK_ENCRYPT = 298,	// �Ƿ����ļ���������
	PAR_MAC_PROG_SKEY = 299,		// G�����ļ���Կ
	
	PAR_MAC_USER = 300,	// �û���������ַ
    PAR_MAC_M2G = 360, //�û�������G�����Ӧ��M����ֵ
	
	PAR_MAC_TOTAL = 500	// �����û���������
};


// ͨ������
enum 
{
	PAR_CH_NAME = 0,	// ����
	PAR_CH_XINDEX,		// X����
	PAR_CH_YINDEX,		// Y����
	PAR_CH_ZINDEX,		// Z����
	PAR_CH_AINDEX,		// A����
	PAR_CH_BINDEX,		// B����
	PAR_CH_CINDEX,		// C����
	PAR_CH_UINDEX,		// U����
	PAR_CH_VINDEX,		// V����
	PAR_CH_WINDEX,		// W����
	PAR_CH_SPDL0,		// ����0���
	PAR_CH_SPDL1,		// ����1���
	PAR_CH_SPDL2,		// ����2���
	PAR_CH_SPDL3,		// ����3���
	PAR_CH_X_NAME,		// X����
	PAR_CH_Y_NAME,		// Y����
	PAR_CH_Z_NAME,		// Z����
	PAR_CH_A_NAME,		// A����
	PAR_CH_B_NAME,		// B����
	PAR_CH_C_NAME,		// C����
	PAR_CH_U_NAME,		// U����
	PAR_CH_V_NAME,		// V����
	PAR_CH_W_NAME,		// W����
	PAR_CH_S0_NAME,		// ����0��
	PAR_CH_S1_NAME,		// ����1��
	PAR_CH_S2_NAME,		// ����2��
	PAR_CH_S3_NAME,		// ����3��
	PAR_CH_SVEL_SHOW,	// ����ת����ʾ��ʽ
	PAR_CH_S_SHOW,		// ������ʾ����
	
	PAR_CH_DEFAULT_F = 30,	// ͨ����ȱʡ�����ٶ�
	PAR_CH_DRYRUN_SPD,		// �����н����ٶ�
	PAR_CH_DIAPROG,			// ֱ�����ʹ��
	PAR_CH_UVW_INC_EN,		// UVW�������ʹ��
	PAR_CH_CHAMFER_EN,		// ����ʹ��
	PAR_CH_ANGLEP_EN,		// �Ƕȱ��ʹ��
	PAR_CH_CYCLE_OPTION,	// ����ѭ��ѡ��������[λ]��0x0001 �ּӹ�Բ��תֱ�� 0x0002���������������������� 0x0004: �޾��ӹ�
    PAR_CH_MPG_ACC_RATE,	// ��ҡ���ٶ�ϵ��
	PAR_CH_MPG_JK_RATE,		// ��ҡ�ݶ�ϵ��
    PAR_CH_MPG_WORK_RATE,   // ��ҡ�ӹ�ϵ��

	PAR_CH_MAC_FRAME = 40,	// �����ṹ���͡�0, һ��ֱ��ϵ���� 1, ͨ�����������2+����������
	PAR_CH_MACTURN,			// ������ʽ��ʽ���͡�0, ��ʽ 1, ��ʽ��
    PAR_CH_ARC_SPEED_DOWN_R,     //Բ�����ٰ뾶
    PAR_CH_ARC_SPEED_DOWN_V,     //Բ�������ٶ�

	PAR_CH_FOLLOW_ROTATE_RAD = 60, //���߸���İڶ��뾶
	PAR_CH_FOLLOW_CHORD_LEN, //���߸�����ҳ�
	PAR_CH_FOLLOW_TOOL_AX, //������ת����ת���
	PAR_CH_FOLLOW_TABLE_AX, //����̨��ת����ת���
	PAR_CH_FOLLOW_DX, //���߸�����ת����xƫ��
	PAR_CH_FOLLOW_DY, //���߸�����ת����yƫ��
	
	PAR_CH_VPLAN_MODE = 69,	// �ٶȹ滮ģʽ0-9:����ģʽ  10+����ģʽ�����⡢ľ���� 
	
	PAR_CH_MICR_MAX_LEN,	// ΢�߶����޳���
	PAR_CH_CORNER_MAX_ANG,	// �ս�ƽ����С�Ƕ�
	PAR_CH_VEL_FILTER_LEN,	// ΢�߶��ٶ��˲�����
	PAR_CH_PATH_TOLERANCE,	// �켣�����ʲ�
	PAR_CH_CONER_DEC_FACTOR,// �սǽ��ٱ�������%
	PAR_CH_HSPL_MIN_LEN,	// ΢�߶����޳���
	PAR_CH_HSPL_MAX_ANG,	// �������ɼн�
	PAR_CH_HSPL_MAX_RAT,	// ����ƽ�������ڶ���󳤶ȱ�
	PAR_CH_HSPL_MAX_LEN,	// ����ƽ��������߶γ���
	PAR_CH_ARC2LINE,		// Բ����ɢΪֱ��ѡ�� 79
	
	PAR_CH_LOOKAHEAD_NUM,	// �ٶȹ滮ǰհ����
	PAR_CH_CURVATURE_COEF,	// ���ʰ뾶����ϵ����0.3~100.0��
	PAR_CH_RECTIFY_NUM,		// ָ���ٶ�ƽ��������
	PAR_CH_JERK_TIMES,		// �ϳɽݶ�ʱ�䳣��
	PAR_CH_MAX_ECEN_ACC,	// ���ļ��ٶ�
	PAR_CH_MAX_TANG_ACC,	//������ٶ�
    PAR_CH_FEED_ACC_COEF,	// ���ٶ�ϵ��	
	PAR_CH_FEED_JK_COEF,		// �ݶ�ϵ��
	PAR_CH_PRE_SMOOTH_OFF,	//Ԥ����ƽ���ر�

	PAR_CH_CYL_RAX = 90,	// Բ���岹��ת��š�ȱʡ5��C�᡿
	PAR_CH_CYL_LAX,			// Բ���岹ֱ�ߡ�������š�ȱʡ2��Z�᡿
	PAR_CH_CYL_PAX,			// Բ���岹ƽ�С�����γ�ߡ���š�ȱʡ1��Y�᡿
	
	PAR_CH_POLAR_LAX = 95,	// ������岹��ֱ�������
	PAR_CH_POLAR_RAX,		// ������岹����ת�����
	PAR_CH_POLAR_VAX,		// ������岹�ļ��������
	PAR_CH_POLAR_CX,		// ������岹����ת����ֱ��������
	PAR_CH_POLAR_CY,		// ������岹������ƫ����
	
	PAR_CH_THREAD_TOL = 105,	// �����������ƫ��
	PAR_CH_THREAD_WAY,			// ���Ƽӹ���ʽ


	PAR_CH_G61_DEFAULT,		// ϵͳ�ϵ�ʱG61/G64ģ̬����
	PAR_CH_G00_DEFAULT,		// ϵͳ�ϵ�ʱG00/G01ģ̬����
	PAR_CH_G90_DEFAULT,		// ϵͳ�ϵ�ʱG90/G91ģ̬����
	PAR_CH_G28_ZTRAP_EN,	// G28����Z����ʹ��
	PAR_CH_G28_POS_EN,		// G28��ѰZ����ʱ����ʹ�� ��0 �ͽ����ٶȶ�λ 1 �����ٶȶ�λ��
	PAR_CH_G28_ONE_SHOT,	// G29
	PAR_CH_SKIP_MODE,		// ������ģʽ[0,��ɨ�� 1��ɨ�裬�ָ��������ƶ�ģ̬ 2ɨ�裬�ָ�ȫ�����ƶ�ģ̬]
	PAR_CH_AXIS_RETURN_ORDER, //�������᷵��˳��
	PAR_CH_M_GROUP1,             // M�������1
	// PAR_CH_G95_DEFAULT,		// ϵͳ�ϵ�ʱG95/G94ģ̬����

	PAR_CH_MAG_START_NO = 125,	// 	��ʼ�����
	PAR_CH_MAG_NUM,				// 	������Ŀ
	PAR_CH_TOOL_START_NO,		// 	��ʼ���ߺ�
	PAR_CH_TOOL_NUM,			// 	������Ŀ
	PAR_CH_TOOL_OFF_START_NO,	//	��ʼ������
	PAR_CH_LIFE_ON,				// 	�����������ܿ���

	PAR_CH_TOFF_ON,				//��λ�뱣����ʱ����������
	PAR_CH_TOFF_LIMIT,			//��������ʱ��Z�ᵶ���븺��λ�ľ���
	PAR_CH_LIFE_LOSE_NO,        //  Tָ������������Ժ�	,����T106��ϵͳ������Ϊ��T(106 - 100)
	PAR_CH_SYNC_RESET,			//��λ�Ƿ����ͬ��

	//  = 140 ��2��С�߶β���
	PAR_CH_MICR_MAX_LEN2 = 140,	// ΢�߶����޳���
	PAR_CH_CORNER_MAX_ANG2,		// ���ռ�����н�
	PAR_CH_VEL_FILTER_LEN2,		// ΢�߶��ٶ��˲�����
	PAR_CH_PATH_TOLERANCE2,		// �켣�����ʲ�
	PAR_CH_GEO_CNTR_NUM2,		// ΢�߶������˲�����
	PAR_CH_HSPL_MIN_LEN2,		// ΢�߶����޳���
	PAR_CH_HSPL_MAX_ANG2,		// �������ɼн�
	PAR_CH_HSPL_MAX_RAT2,		// ����ƽ�������ڶ���󳤶ȱ�
	PAR_CH_HSPL_MAX_LEN2,		// ����ƽ��������߶γ���
	PAR_CH_PATH_TYPE2,			// �����켣����
	PAR_CH_LOOKAHEAD_NUM2,		// �ٶȹ滮ǰհ����
	PAR_CH_CURVATURE_COEF2,		// ���ʰ뾶����ϵ����0.3~100.0��
	PAR_CH_RECTIFY_NUM2,		// �ٶ���������
	PAR_CH_POS_SMTH_NUM2,		// λ��ƽ������
	PAR_CH_FEED_ACC_COEF2=156,	// ���ٶ�ϵ��	
	PAR_CH_FEED_JK_COEF2,		// �ݶ�ϵ��

	//  = 160 ��3��С�߶β���
	PAR_CH_MICR_MAX_LEN3 = 160,	// ΢�߶����޳���
	PAR_CH_CORNER_MAX_ANG3,		// ���ռ�����н�
	PAR_CH_VEL_FILTER_LEN3,		// ΢�߶��ٶ��˲�����
	PAR_CH_PATH_TOLERANCE3,		// �켣�����ʲ�
	PAR_CH_GEO_CNTR_NUM3,		// ΢�߶������˲�����
	PAR_CH_HSPL_MIN_LEN3,		// ΢�߶����޳���
	PAR_CH_HSPL_MAX_ANG3,		// �������ɼн�
	PAR_CH_HSPL_MAX_RAT3,		// ����ƽ�������ڶ���󳤶ȱ�
	PAR_CH_HSPL_MAX_LEN3,		// ����ƽ��������߶γ���
	PAR_CH_PATH_TYPE3,			// �����켣����
	PAR_CH_LOOKAHEAD_NUM3,		// �ٶȹ滮ǰհ����
	PAR_CH_CURVATURE_COEF3,		// ���ʰ뾶����ϵ����0.3~100.0��
	PAR_CH_RECTIFY_NUM3,		// �ٶ���������
	PAR_CH_POS_SMTH_NUM3,		// λ��ƽ������
	PAR_CH_FEED_ACC_COEF3=176,	// ���ٶ�ϵ��	
	PAR_CH_FEED_JK_COEF3,		// �ݶ�ϵ��

	//  = 180 ��4��С�߶β���
	PAR_CH_MICR_MAX_LEN4 = 180,	// ΢�߶����޳���
	PAR_CH_CORNER_MAX_ANG4,		// ���ռ�����н�
	PAR_CH_VEL_FILTER_LEN4,		// ΢�߶��ٶ��˲�����
	PAR_CH_PATH_TOLERANCE4,		// �켣�����ʲ�
	PAR_CH_GEO_CNTR_NUM4,		// ΢�߶������˲�����
	PAR_CH_HSPL_MIN_LEN4,		// ΢�߶����޳���
	PAR_CH_HSPL_MAX_ANG4,		// �������ɼн�
	PAR_CH_HSPL_MAX_RAT4,		// ����ƽ�������ڶ���󳤶ȱ�
	PAR_CH_HSPL_MAX_LEN4,		// ����ƽ��������߶γ���
	PAR_CH_PATH_TYPE4,			// �����켣����
	PAR_CH_LOOKAHEAD_NUM4,		// �ٶȹ滮ǰհ����
	PAR_CH_CURVATURE_COEF4,		// ���ʰ뾶����ϵ����0.3~100.0��
	PAR_CH_RECTIFY_NUM4,		// �ٶ���������
	PAR_CH_POS_SMTH_NUM4,		// λ��ƽ������
	PAR_CH_FEED_ACC_COEF4=196,	// ���ٶ�ϵ��	
	PAR_CH_FEED_JK_COEF4,		// �ݶ�ϵ��
	
	PAR_CH_ROBOT_PARA=200, //200~300�����˲�����
	//PAR_CH_WTZONE_NUM = 200,	// ���������߱������ܸ���0~10
	//PAR_CH_WTZONE_TYPE,			// ���������߱���������
	//PAR_CH_WTZONE_FLAG,			// ���������߱���������
	//PAR_CH_WTZONE_BND,			// ���������߱������߽�
	
	PAR_CH_USER_AD_OFF = 300, // �û�ģ���������ƫ������x�Ĵ�������λ�ֽ�
	PAR_CH_USER_DA_OFF = 301, // �û�ģ���������ƫ������y�Ĵ�������λ�ֽ�

	//PAR_CH_RESONA_DAMP_AMP = 300, // ����ת�ٱ��񲨷����ٷֱ� 0.05��
	//PAR_CH_RESONA_DAMP_PRD = 301, // ����ת�ٱ������ڡ��롿

	PAR_CH_TAX_ENABLE = 310,	// ��б�����ʹ��
	PAR_CH_TAX_ORTH_AX_INDEX,	// ���������
	PAR_CH_TAX_TILT_AX_INDEX,	// ��б�����
	PAR_CH_TAX_TILT_ANGLE,		// ��б�Ƕ�

	PAR_CH_SYNC_MAIN_SPDL=314, //�����������
	PAR_CH_SYNC_SUB_SPDL,      //�Ӷ��������
	PAR_CH_SYNC_MOLE,          //�����ȷ���
	PAR_CH_SYNC_DENO,          //�����ȷ�ĸ
	PAR_CH_SYNC_PHASE,         //ͬ����λ��

	//�������
	PAR_CH_RTCPARA_OFF=50,		//RTCP����ƫ��ֵ

	PAR_CH_TOOL_INIT_DIR_X=400,	//���߳�ʼ����(X)
	PAR_CH_TOOL_INIT_DIR_Y,		//���߳�ʼ����(Y)
	PAR_CH_TOOL_INIT_DIR_Z,		//���߳�ʼ����(Z)
	PAR_CH_ANG_OUTPUT_MODE=405,	//��ת��Ƕ�����ж���ʽ
	PAR_CH_ANG_OUTPUT_ORDER,	//��ת��Ƕ�����ж�˳��
	PAR_CH_POLE_TOLERANCE,		//����Ƕȷ�Χ
	
	PAR_CH_RTCP_SWIVEL_TYPE=410,	//��ͷ�ṹ����
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_X,	//��ͷ��1��ת�᷽��(X)
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_Y,	//��ͷ��1��ת�᷽��(Y)
	PAR_CH_RTCP_SWIVEL_RAX1_DIR_Z,	//��ͷ��1��ת�᷽��(Z)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_X,	//��ͷ��2��ת�᷽��(X)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_Y,	//��ͷ��2��ת�᷽��(Y)
	PAR_CH_RTCP_SWIVEL_RAX2_DIR_Z,	//��ͷ��2��ת�᷽��(Z)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_X,	//��ͷ��1��ת��ƫ��ʸ��(X)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_Y,	//��ͷ��1��ת��ƫ��ʸ��(Y)
	PAR_CH_RTCP_SWIVEL_RAX1_OFF_Z,	//��ͷ��1��ת��ƫ��ʸ��(Z)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_X,	//��ͷ��2��ת��ƫ��ʸ��(X)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_Y,	//��ͷ��2��ת��ƫ��ʸ��(Y)
	PAR_CH_RTCP_SWIVEL_RAX2_OFF_Z,	//��ͷ��2��ת��ƫ��ʸ��(Z)

	PAR_CH_RTCP_TABLE_TYPE=425,		//ת̨�ṹ����
	PAR_CH_RTCP_TABLE_RAX1_DIR_X,	//ת̨��1��ת�᷽��(X)
	PAR_CH_RTCP_TABLE_RAX1_DIR_Y,	//ת̨��1��ת�᷽��(Y)
	PAR_CH_RTCP_TABLE_RAX1_DIR_Z,	//ת̨��1��ת�᷽��(Z)
	PAR_CH_RTCP_TABLE_RAX2_DIR_X,	//ת̨��2��ת�᷽��(X)
	PAR_CH_RTCP_TABLE_RAX2_DIR_Y,	//ת̨��2��ת�᷽��(Y)
	PAR_CH_RTCP_TABLE_RAX2_DIR_Z,	//ת̨��2��ת�᷽��(Z)
	PAR_CH_RTCP_TABLE_RAX1_OFF_X,	//ת̨��1��ת��ƫ��ʸ��(X)
	PAR_CH_RTCP_TABLE_RAX1_OFF_Y,	//ת̨��1��ת��ƫ��ʸ��(Y)
	PAR_CH_RTCP_TABLE_RAX1_OFF_Z,	//ת̨��1��ת��ƫ��ʸ��(Z)
	PAR_CH_RTCP_TABLE_RAX2_OFF_X,	//ת̨��2��ת��ƫ��ʸ��(X)
	PAR_CH_RTCP_TABLE_RAX2_OFF_Y,	//ת̨��2��ת��ƫ��ʸ��(Y)
	PAR_CH_RTCP_TABLE_RAX2_OFF_Z,	//ת̨��2��ת��ƫ��ʸ��(Z)

	PAR_CH_TOTAL = 500
};

// ���������
#define SERVO_PARM_START_IDX 200 // �ŷ�������ʼ������
#define SERVO_PARM_TOTAL_NUM 100//�ŷ���������
enum 
{
	PAR_AX_NAME = 0,	// ����[��ʾ��]
	PAR_AX_TYPE,		// ������[ֱ�ߡ��ڶ�����ת������]
	PAR_AX_INDEX,		// ���� ��ʱԤ��
	PAR_AX_MODN,		// �豸�� ��ʱԤ��
	PAR_AX_DEV_I = PAR_AX_MODN,
	PAR_AX_PM_MUNIT,	// ���ӳ��ֱȷ���(λ����)[ÿתλ����nm]
	PAR_AX_PM_PULSE,	// ���ӳ��ֱȷ�ĸ(������)[ÿתָ��������]
	PAR_AX_PLMT,		// ������
	PAR_AX_NLMT,		// ������
	PAR_AX_PLMT2,		// ��2������
	PAR_AX_NLMT2,		// ��2������

	PAR_AX_HOME_WAY = 10,	// �زο��㷽ʽ
	PAR_AX_HOME_DIR,		// �زο��㷽��
	PAR_AX_ENC_OFF,			// ����������ƫ�������ֶ���㡢����ʽ��������
	PAR_AX_HOME_OFF,		// �زο�����ƫ����
	PAR_AX_HOME_MASK,		// Z�������νǶ�
	PAR_AX_HOME_HSPD,		// �زο������
	PAR_AX_HOME_LSPD,		// �زο������
	PAR_AX_HOME_CRDS,		// �ο�������ֵ
	PAR_AX_HOME_CODSPACE,	// ������ο�����
	PAR_AX_HOME_CODOFF,		// ������ƫ��

	PAR_AX_HOME_RANGE = 20,	// ��Z��������ƶ�����
	PAR_AX_HOME_CRDS2,		// ��2�ο�������ֵ
	PAR_AX_HOME_CRDS3,		// ��3�ο�������ֵ
	PAR_AX_HOME_CRDS4,		// ��4�ο�������ֵ
	PAR_AX_HOME_CRDS5,		// ��5�ο�������ֵ
	PAR_AX_REF_RANGE,		// �ο��㷶Χƫ��
	PAR_AX_HOME_CYCLE_OFF,	// ���������Ȼ�ת��ƫ��
	PAR_AX_ENC2_OFF,		// ��2����������ƫ�������ֶ���㡢����ʽ��������
	PAR_AX_PM2_MUNIT,		// ��2���������ӳ��ֱȷ���(λ����)[ÿתλ����nm]
	PAR_AX_PM2_PULSE,		// ��2���������ӳ��ֱȷ�ĸ(������)[ÿתָ��������]

	PAR_AX_G60_OFF = 30,	// ����λ(G60)ƫ����
	PAR_AX_ROT_RAD,			// ת���ᵱ���뾶
	PAR_AX_JOG_LOWSPD,		// ���ٵ㶯�ٶ�
	PAR_AX_JOG_FASTSPD,		// ���ٵ㶯�ٶ�
	PAR_AX_RAPID_SPD,		// �����ٶ�
	PAR_AX_FEED_SPD,		// ��߽����ٶ�
	PAR_AX_RAPID_ACC,		// ���Ƽ��ٶ�
	PAR_AX_RAPID_JK,		// ���ƽݶ�
	PAR_AX_FEED_ACC,		// �������ٶ�
	PAR_AX_FEED_JK,			// �����ݶ�
	PAR_AX_THREAD_ACC,		// ���Ƽ��ٶ�
	PAR_AX_THREAD_DEC,		// ���Ƽ��ٶ�
	PAR_AX_MPG_UNIT_SPD,	// ��ҡ��λ�ٶȱ���ϵ��
	PAR_AX_MPG_RESOL,		// ��ҡ����ֱ���
	PAR_AX_MPG_INTE_RATE,	// ��ҡ����ϵ��
	PAR_AX_MPG_INTE_TIME,	// ��ҡ�������� [45]
	PAR_AX_MPG_OVER_RATE,	// ��ҡ����ϵ��
	PAR_AX_MPG_VEL_GAIN,	// ��ҡ�ٶȵ���ϵ��
	PAR_AX_RAPID_RATE,		// ���ٱ���ϵ��

	PAR_AX_DEFAULT_S = 50,	// ����ȱʡת��
	PAR_SPDL_MAX_SPEED,		// �������ת��
	PAR_SPDL_SPD_TOL,		// ����ת������ת�ٲ�����
	PAR_SPDL_SPD_TIME,		// ����ת�ٵ����������ʱ��
	PAR_SPDL_THREAD_TOL,	// ���Ƽӹ�ʱ��ת���ʲ�
	PAR_AX_SP_ORI_POS,		// �������ᶨ��Ƕ�
	PAR_AX_SP_ZERO_TOL,		// �������������ʲ���塿
	PAR_AX_MAX_EXT_PINC,	// �ⲿָ��������ڵ�����

	PAR_AX_POS_TOL = 60,	// ��λ�ʲ�
	PAR_AX_MAX_LAG,			// ���������
	PAR_AX_LAG_CMP_EN,		// ������ͬ������ʹ��
	PAR_AX_LAG_CMP_COEF,	// ������������ϵ��
	PAR_AX_LAG_CMP_CNT,		// ��̬����ϵ������������
	
	PAR_AX_ATEETH = 65,	// �����ȷ���[������]
	PAR_AX_MTEETH,		// �����ȷ�ĸ[��������]
	PAR_AX_MT_PPR,		// ���ÿת������
	PAR_AX_PITCH,		// ˿�˵���
	PAR_AX_RACK_NUM,	// ��������
	PAR_AX_RACK_SPACE,	// �����ݼ��
	PAR_AX_WORM_NUM,	// �ϸ�ͷ��
	PAR_AX_WORM_SPACE,	// �ϸ˳ݾ�
	PAR_RAX_VEL_RATE,   // ��ת���ٶ�ϵ��
	PAR_AX_RATING_CUR,  // �����
	PAR_AX_POWER_RATE,  // ����ϵ��
	PAR_AX_ENC2_PPR,	// ��2������ÿת������
	PAR_AX_INDEX_TYPE, //�ֶ������ͣ�1�������̣�2���ֶ���
	PAR_AX_INDEX_POS,//�ֶ����
	PAR_AX_INDEX_DIVIDE, //�ֶȼ��

	PAR_ZAX_LOCK_EN = 80,	// Z��������ʹ��
	PAR_RAX_ROLL_EN,		// ��ת��ѭ��ʹ��
	PAR_RAX_SHORTCUT,		// ��ת���·��ѡ��ʹ��
	PAR_RAX_CYCLE_RANGE,	// ��ת��ѭ���г�
	PAR_RAX_DISP_RANGE,		// ��ת����ʾ�Ƕȷ�Χ
	PAR_LAX_PROG_UNIT,		// ֱ������ָ����С��λ
	PAR_RAX_PROG_UNIT,		// ��ת����ָ����С��λ
	PAR_OVERLOAD_JUDGE,		// ������ж��ٷֱ�

	PAR_AX_ENC_MODE = 90,	// ����������ģʽ
// 0x000F��0,�õ�1���������� 1,�õ�2����������  2,�޷���
// 0x00F0��0,�õ�1������ָ�� 1,�õ�2������ָ��
// 0x0100��0,����������ŷ����������� 1,���������ϵͳ����
// 0x1000��0,Ĭ�ϲ���32λ������� 1,����64λ������� 
#define AX_ENCODER_MASK	0x00FF
#define AX_NC_CMD_MASK  0x00F0
#define AX_NC_TRACK_ERR	0x0100
#define AX_NC_CYC64_MODE 0x1000

	PAR_AX_EC1_TYPE,		// 1�ű��������͡������������롢���ԡ�
	PAR_AX_EC1_OUTP,		// �������ӳ��ֱȷ���[���������]
	PAR_AX_EC1_FBKP,		// �������ӳ��ֱȷ�ĸ[����������]
	PAR_AX_EC1_BIT_N,		// 1�ű���������λ��������ʽ���
	PAR_AX_EC2_TYPE,		// 2�ű��������͡������������롢���ԡ�
	PAR_AX_EC2_OUTP,		// �������ӳ��ֱȷ���[���������] 
	PAR_AX_EC2_FBKP,		// �������ӳ��ֱȷ�ĸ[����������]
	PAR_AX_EC2_BIT_N,		// 2�ű���������λ��������ʽ���
	
	PAR_AX_SMX_TYPE = 100,	// �˶�����(MC)������
	PAR_AX_SMX_LEAD_IDX,
	PAR_AX_COMPEN_LAG = 106,
	PAR_AX_ALARM_LAG,
	PAR_AX_ALARM_VDIFF,
	PAR_AX_ALARM_CDIFF,
	PAR_AX_SMX_PARA,		// MC���˶�ϵ����16

	PAR_AX_WCS_DISP=126,	//ͬ��ʱ�����Ṥ������ϵ��ʾ��ʽ
	PAR_AX_SYNC_MIRROR,		//�Ƿ���
	PAR_AX_COORD_DIR,		//����������ϵ��������
	PAR_AX_ZERO_OFFSET,		//ͬ����������ƫ��

	PAR_AX_COMP_MAX_COEF = 130,	// ���������
	PAR_AX_COMP_MAX_VALUE,		// �������ֵ
	PAR_AX_CODOFF_VALUE,		// �ᷴ��ƫ��


	PAR_AX_TANG_NO = 135,		//���߿����涯�����0��1��2����A��B��C�ᣬ�˲�����150�ƶ�����
	PAR_AX_TANG_ANGLE,			//���߿���ƫ�ƽ�
	PAR_AX_TANG_OFFSET,			// ���߸���ƫ��ֵ

	//wangxu
	PAR_AX_ADJUST_COE=140,//��������ϵ��
	PAR_AX_FOL_COE,//�涯��������
	PAR_AX_FOL_ADR,//�涯ģ������ַ
	PAR_AX_FOL_POS_DOWN,//�涯λ������
	PAR_AX_FOL_SPD,//�涯���ת��
	PAR_AX_FOL_OFF,//�涯��λ�ź���Χ
	PAR_AX_JUMP_HIGH,//�����߶�
	PAR_AX_FOL_POS_UP,//�涯λ������
	PAR_AX_JUMP_TO_FOL,//�����л����涯�ĸ߶�
	PAR_AX_FOL_NONLINER,//�涯��ѹ�����ԣ���Ҫ�ȱ궨
	PAR_AX_DEM_SPACE,//�궨�ļ��
	PAR_AX_DEM_VOL,//�����ѹ
    
    PAR_AX_S_ACK=155,       //Sָ����Ҫ��Ӧ
    PAR_AX_OUT_DA,          //�������ģ����
    PAR_AX_MAX_MOTOR,       //���������ת��
    PAR_AX_SHIFT_NUM,       //���ᵲλ��
    PAR_AX_LOW_SPEED1,      //����1�����ת��
    PAR_AX_HIGH_SPEED1,     //����1�����ת��
    PAR_AX_ATEETH1,      	//����1�������ȷ���[������]
	PAR_AX_MTEETH1,	    	//����1�������ȷ�ĸ[��������]
    PAR_AX_EC_OUTP1,		//����1���������ӳ��ֱȷ���[���������]
	PAR_AX_EC_FBKP1,		//����1���������ӳ��ֱȷ�ĸ[����������]
    PAR_AX_LOW_SPEED2,      //����2�����ת��
    PAR_AX_HIGH_SPEED2,     //����2�����ת��
    PAR_AX_ATEETH2,      	//����2�������ȷ���[������]
    PAR_AX_MTEETH2,	    	//����2�������ȷ�ĸ[��������]
    PAR_AX_EC_OUTP2,		//����2���������ӳ��ֱȷ���[���������]
	PAR_AX_EC_FBKP2,		//����2���������ӳ��ֱȷ�ĸ[����������]
    PAR_AX_LOW_SPEED3,      //����3�����ת��
    PAR_AX_HIGH_SPEED3,     //����3�����ת��
    PAR_AX_ATEETH3,      	//����3�������ȷ���[������]
    PAR_AX_MTEETH3,	    	//����3�������ȷ�ĸ[��������]
    PAR_AX_EC_OUTP3,		//����3���������ӳ��ֱȷ���[���������]
	PAR_AX_EC_FBKP3,		//����3���������ӳ��ֱȷ�ĸ[����������]
    PAR_AX_LOW_SPEED4,      //����4�����ת��
    PAR_AX_HIGH_SPEED4,     //����4�����ת��
    PAR_AX_ATEETH4,      	//����4�������ȷ���[������]
    PAR_AX_MTEETH4,	    	//����4�������ȷ�ĸ[��������]
    PAR_AX_EC_OUTP4,		//����4���������ӳ��ֱȷ���[���������]
	PAR_AX_EC_FBKP4,		//����4���������ӳ��ֱȷ�ĸ[����������]
    PAR_AX_SWITCH_SPEED,    //�����л���ת��
    PAR_AX_1S2_SPEED,       //��λһ�뵵λ���л���ת��
    PAR_AX_2S3_SPEED,       //��λ���뵵λ���л���ת��
    PAR_AX_3S4_SPEED,       //��λ���뵵λ���л���ת��
    PAR_AX_SHIGT_SPEED,     //���ỻ��ʱ���ת��
    PAR_AX_SHIGT_HOME,      //���ỻ������Ҫ���»���

	PAR_AX_ACT_PULSE_TOLERANCE = 196,	// �ϵ練������λ���ʲ�
	PAR_AX_ENC_TOLERANCE = 197,	// �ϵ�λ���ʲ�
	PAR_AX_OUT_ACTVEL = 198,	// ʵ���ٶȳ����ж�����
	PAR_AX_INTEG_PRD = 199,		// ��ʾ�ٶȻ���������
	

	// �ŷ������������ᣬԤ��100����
	PAR_SV_POSITION_GAIN = SERVO_PARM_START_IDX,	// λ�ñ�������
	PAR_SV_POS_FF_GAIN,				// λ��ǰ������
	PAR_SV_SPEED_GAIN,				// �ٶȱ�������
	PAR_SV_SPEED_KI,				// �ٶȻ���ʱ�䳣��
	PAR_SV_SPEED_FB_FILTER,			// �ٶȷ����˲�����
	PAR_SV_MOTOR_TYPE = 243,		// ������������ʹ���
	PAR_SV_MOTOR_RATING_CUR = 286,	// ��������
	
	// �ŷ����������ᣬԤ��100����
	PAR_SP_POSITION_GAIN = SERVO_PARM_START_IDX,	// λ�ÿ���λ�ñ�������
	PAR_SP_MOTOR_RATING_CUR = 253,	// IM��������
	PAR_SP_MOTOR_TYPE = 259,		// ������������ʹ���

	PAR_AX_TOTAL = 500
};




// ��������
enum 
{
	PAR_CMP_BL_ENABLE = 0,		// �����϶��������
	PAR_CMP_BL_VALUE,			// �����϶����ֵ
	PAR_CMP_BL_RATE,			// �����϶������
	PAR_CMP_BL_VALUE2,			// ��2�����϶����ֵ�����Ʒ����϶����ֵ��

	PAR_CMP_HEAT_TYPE = 5,		// ����������
	PAR_CMP_HEAT_REFN,			// �������ο�������
	PAR_CMP_HEAT_WARP_START,	// �����ƫ�ñ���ʼ�¶�
	PAR_CMP_HEAT_WARP_NUM,		// �����ƫ�ñ��¶ȵ���
	PAR_CMP_HEAT_WARP_STEP,		// �����ƫ�ñ��¶ȼ��
	PAR_CMP_HEAT_WARP_SENSOR,	// �����ƫ�ñ��������
	PAR_CMP_HEAT_WARP_TABLE,	// �����ƫ�ñ���ʼ������
	PAR_CMP_HEAT_SLOPE_START,	// �����б�ʱ���ʼ�¶�
	PAR_CMP_HEAT_SLOPE_NUM,		// �����б�ʱ��¶ȵ���
	PAR_CMP_HEAT_SLOPE_STEP,	// �����б�ʱ��¶ȼ��
	PAR_CMP_HEAT_SLOPE_SENSOR,	// �����б�ʱ��������
	PAR_CMP_HEAT_SLOPE_TABLE,	// �����б�ʱ���ʼ������
	PAR_CMP_HEAT_RATE,			// ��������

	PAR_CMP_PITCH_TYPE = 20,	// �ݾ���������
	PAR_CMP_PITCH_START,		// �ݾ������������
	PAR_CMP_PITCH_NUM,			// �ݾ���������
	PAR_CMP_PITCH_STEP,			// �ݾ���������
	PAR_CMP_PITCH_MODULO,		// �ݾ����ȡģ����ʹ��
	PAR_CMP_PITCH_FACTOR,		// �ݾ���������
	PAR_CMP_PITCH_TABLE,		// �ݾ���������ʼ������

	PAR_CMP_SQU1_ENABLE = 30,	// ��1�ֱ�Ȳ���ʹ��
	PAR_CMP_SQU1_INPUT_AX,	    // ��1�ֱ�Ȳ�����׼���
	PAR_CMP_SQU1_REFN,	        // ��1�ֱ�Ȳ�����׼������
	PAR_CMP_SQU1_ANG,	        // ��1�ֱ�Ȳ����Ƕ�

	PAR_CMP_SQU2_ENABLE = 40,	// ��2�ֱ�Ȳ���ʹ��
	PAR_CMP_SQU2_INPUT_AX,	    // ��2�ֱ�Ȳ�����׼���
	PAR_CMP_SQU2_REFN,	        // ��2�ֱ�Ȳ�����׼������
	PAR_CMP_SQU2_ANG,	        // ��2�ֱ�Ȳ����Ƕ�

	PAR_CMP_STRA1_INPUT_AX = 50,	// ��1��ֱ�߶Ȳ�����׼���
	PAR_CMP_STRA1_TYPE,	        // ��1��ֱ�߶Ȳ�������
	PAR_CMP_STRA1_START,	    // ��1��ֱ�߶Ȳ����������
	PAR_CMP_STRA1_NUM,	        // ��1��ֱ�߶Ȳ�������
	PAR_CMP_STRA1_STEP,	        // ��1��ֱ�߶Ȳ�������
	PAR_CMP_STRA1_MODULO,	    // ��1��ֱ�߶�ȡģ����ʹ��
	PAR_CMP_STRA1_FACTOR,	    // ��1��ֱ�߶Ȳ�������
	PAR_CMP_STRA1_TABLE,	    // ��1��ֱ�߶Ȳ�������ʼ������

	PAR_CMP_STRA2_INPUT_AX = 65,	// ��2��ֱ�߶Ȳ�����׼���
	PAR_CMP_STRA2_TYPE,	        // ��2��ֱ�߶Ȳ�������
	PAR_CMP_STRA2_START,	    // ��2��ֱ�߶Ȳ����������
	PAR_CMP_STRA2_NUM,	        // ��2��ֱ�߶Ȳ�������
	PAR_CMP_STRA2_STEP,	        // ��2��ֱ�߶Ȳ�������
	PAR_CMP_STRA2_MODULO,	    // ��2��ֱ�߶�ȡģ����ʹ��
	PAR_CMP_STRA2_FACTOR,	    // ��2��ֱ�߶Ȳ�������
	PAR_CMP_STRA2_TABLE,    	// ��2��ֱ�߶Ȳ�������ʼ������

	PAR_CMP_ANG1_INPUT_AX = 80,	// ��1��ǶȲ�����׼���
	PAR_CMP_ANG1_ASSO_AX,	    // ��1��ǶȲ����������
	PAR_CMP_ANG1_REFN,          // ��1��ǶȲ����ο�������
	PAR_CMP_ANG1_TYPE,	        // ��1��ǶȲ�������
	PAR_CMP_ANG1_START,	        // ��1��ǶȲ����������
	PAR_CMP_ANG1_NUM,	        // ��1��ǶȲ�������
	PAR_CMP_ANG1_STEP,	        // ��1��ǶȲ�������
	PAR_CMP_ANG1_MODULO,	    // ��1��Ƕ�ȡģ����ʹ��
	PAR_CMP_ANG1_FACTOR,	    // ��1��ǶȲ�������
	PAR_CMP_ANG1_TABLE,	        // ��1��ǶȲ�������ʼ������

	PAR_CMP_ANG2_INPUT_AX = 95,	// ��2��ǶȲ�����׼���
	PAR_CMP_ANG2_ASSO_AX,	    // ��2��ǶȲ����������
	PAR_CMP_ANG2_REFN,          // ��2��ǶȲ����ο�������
	PAR_CMP_ANG2_TYPE,	        // ��2��ǶȲ�������
	PAR_CMP_ANG2_START,	        // ��2��ǶȲ����������
	PAR_CMP_ANG2_NUM,	        // ��2��ǶȲ�������
	PAR_CMP_ANG2_STEP,	        // ��2��ǶȲ�������
	PAR_CMP_ANG2_MODULO,	    // ��2��Ƕ�ȡģ����ʹ��
	PAR_CMP_ANG2_FACTOR,	    // ��2��ǶȲ�������
	PAR_CMP_ANG2_TABLE,	        // ��2��ǶȲ�������ʼ������

	PAR_CMP_ANG3_INPUT_AX = 110,	// ��3��ǶȲ�����׼���
	PAR_CMP_ANG3_ASSO_AX,	    // ��3��ǶȲ����������
	PAR_CMP_ANG3_REFN,          // ��3��ǶȲ����ο�������
	PAR_CMP_ANG3_TYPE,	        // ��3��ǶȲ�������
	PAR_CMP_ANG3_START,	        // ��3��ǶȲ����������
	PAR_CMP_ANG3_NUM,	        // ��3��ǶȲ�������
	PAR_CMP_ANG3_STEP,	        // ��3��ǶȲ�������
	PAR_CMP_ANG3_MODULO,	    // ��3��Ƕ�ȡģ����ʹ��
	PAR_CMP_ANG3_FACTOR,	    // ��3��ǶȲ�������
	PAR_CMP_ANG3_TABLE,	        // ��3��ǶȲ�������ʼ������

	PAR_CMP_QUAD_ENABLE = 125,	// ������ͻ����������
	PAR_CMP_QUAD_VALUE,         // ������ͻ������ֵ
	PAR_CMP_QUAD_DELAY_T,		// ������ͻ��������ʱʱ�䣬��λ��ms
	PAR_CMP_QUAD_MIN_VEL,		// ������ͻ����������ٶ�
	PAR_CMP_QUAD_MAX_VEL,		// ������ͻ����������ٶ�
	PAR_CMP_QUAD_ACC_T,			// ������ͻ����������ʱ�䣬��λ��ms
	PAR_CMP_QUAD_DEC_T,			// ������ͻ����������ʱ�䣬��λ��ms
	PAR_CMP_QUAD_TRQ_VAL,		// ��Ħ������Ť��ֵ��ȡֵ��Χ��-10000~10000
	PAR_CMP_QUAD_TRQ_VAL2,		// ��Ħ������Ť��ֵ2��ȡֵ��Χ��-10000~10000
	PAR_CMP_QUAD_TRQ_MAX,		// ��Ħ������Ť��ֵ����ֵ��ȡֵ��Χ��-10000~10000

	PAR_CMP_MULHT_TYPE = 135,		// ��Ԫ���Բ�������
	PAR_CMP_MULHT_REFN,				// ��Ԫ���Բ����ο�������
	PAR_CMP_MULHT_BASE_WARP,		// ����ƫ��ģ�ͳ���
	PAR_CMP_MULHT_WARP_SEN_NUM,		// ����ƫ��ģ�ʹ������������
	PAR_CMP_MULHT_WARP_SEN_LIST,    // ����ƫ��ģ�ʹ������������
	PAR_CMP_MULHT_WARP_COEF_TABLE,  // ����ƫ��ģ��ϵ������ʼ������
	PAR_CMP_MULHT_BASE_SLOPE,       // ˿��б��ģ�ͳ���
	PAR_CMP_MULHT_SLOPE_SEN_NUM,    // ˿��б��ģ�ʹ������������
	PAR_CMP_MULHT_SLOPE_SEN_LIST,   // ˿��б��ģ�ʹ������������
	PAR_CMP_MULHT_SLOPE_COEF_TABLE, // ˿��б��ģ��ϵ������ʼ������

	PAR_CMP_RATE_ENABLE = 150,		//��������Ĳ����ʣ��ڷ����϶��˫���ݲ�ʱ��Ч
	PAR_CMP_RATE_LOW,				//����ʱ�Ĳ����ʣ��뾶100��F1000ʱ�Ĳ�����
	PAR_CMP_RATE_HIGH,				//����ʱ�Ĳ����ʣ��뾶100��F5000ʱ�Ĳ�����
	PAR_CMP_RATE_MAX,				//��󲹳���

	PAR_CMP_FEEDFOR_ENABLE,			//ǰ������
	PAR_CMP_FEEDFOR_VEL,			//ǰ�������ٶ�ϵ��
	PAR_CMP_FEEDFOR_ACC,			//ǰ���������ٶ�ϵ��
	PAR_CMP_FEEDFOR_RATE,			//ǰ����������ϵ��

	PAR_CMP_SPECIAL = 160,	// ר��Ԥ��/��չ������ʼ��ַ
	PAR_CMP_TOTAL = 200		// �Ჹ�������ܸ���
};

// �豸�ӿڲ���
enum
{
	PAR_DEV_NAME,				// �豸����
	PAR_DEV_INDEX,				// �豸��ϵͳ��ţ���ϵͳȫ���豸�е����
	PAR_DEV_TYPE,				// �豸����
	PAR_DEV_GRP_IDX,			// ��ͬ���豸�е����
	PAR_DEV_ID,					// �豸ID[����Ψһ]
	PAR_DEV_VENDOR,				// ������
	PAR_DEV_READONLY_NUM = 8,	// ����
	PAR_DEV_MODE,				// �豸�����ֳ�
	PAR_DEV_GNL_NUM				// [�豸ͨ�ò����ĸ���]
};


// �豸--��վ�豸
enum 
{
	// ϵͳ�̻�����
	PAR_DEV_BRD_FPGA_VER = PAR_DEV_GNL_NUM,	// FPGA�̼�����汾��
	PAR_DEV_BRD_CARD_VER, // ��վ���汾��

	PAR_DEV_BRD_SYS_OBJ_NUM = (PAR_DEV_GNL_NUM+10),	// ���ؿ��ƶ������������+׷��
	PAR_DEV_BRD_NET_OBJ_NUM,	// ���ߴ�վ���ƶ������
	PAR_DEV_BRD_OBJ_NUM,		// ���ƶ����ܸ���������+���ߴ�վ

	// �û����ò���
	PAR_DEV_BRD_BUS_CYCLE = (PAR_DEV_GNL_NUM+40),	// ����ͨѶ����
	PAR_DEV_BRD_BUS_REQ_TIMES,	// ����ͨѶ�������
	PAR_DEV_BRD_BUS_TOPO,		// ���˽ṹ��������

	PAR_DEV_BRD_SP_ADD_NUM = (PAR_DEV_GNL_NUM+50),	// ׷��ģ����������

	PAR_DEV_BRD_RESV_TYPE = (PAR_DEV_GNL_NUM+60)	// ���ر����豸���ͣ�Ԥ��10��������չ

};

// �豸--AX
enum 
{
	PAR_DEV_AX_MODE = PAR_DEV_GNL_NUM,	// ����ģʽ
	PAR_DEV_AX_IDX,			// �豸��Ӧ���߼����
	PAR_DEV_AX_ENCOD_DIR,	// ����������ȡ����־
	PAR_DEV_AX_CMD_TYPE,	// ����DA�������
	PAR_DEV_AX_CYC_EN,      // ����λ��ѭ��ʹ��
	PAR_DEV_AX_MT_PPR,		// ����λ��ѭ��������
	PAR_DEV_AX_ENCOD_TYPE,  // ����������
	PAR_DEV_AX_RESERVE1,	// ����1
	PAR_DEV_AX_RESERVE2,	// ����2
	PAR_DEV_AX_RESERVE3     // ����3
};

// �豸--MPG
enum 
{
	PAR_DEV_MPG_TYPE = PAR_DEV_GNL_NUM,	// MPG����
	PAR_DEV_MPG_IDX,					// MPG���
	PAR_DEV_MPG_IN,						// ��λ��������
	PAR_DEV_MPG_DIR_FLAG,				// ���᷽��ȡ����־
	PAR_DEV_MPG_MULT_FACTOR,			// ���ʷŴ�ϵ��
	PAR_DEV_MPG_PAR_NUM					// MPGʵ�����ò�����Ŀ
};

// �豸--NCKB
enum 
{
	PAR_DEV_NCKB_TYPE = PAR_DEV_GNL_NUM,	// NCKB��������
	PAR_DEV_NCKB_IDX,		// NCKB���
	PAR_DEV_NCKB_CYCLE,		// NCKBɨ������
	PAR_DEV_NCKB_PAR_NUM	// NCKBʵ�����ò�����Ŀ
};

// �豸--IO_LOC/IO_NET
enum 
{
	PAR_DEV_IO_WATCHDOG = PAR_DEV_GNL_NUM,	// �Ƿ�������Ź���������
	PAR_DEV_IO_AXIS_CTRL,	// �Ƿ�������ư壨������
	PAR_DEV_IN_X_BASE,		// �����X�Ĵ�����ʼ���(PAR_DEV_GNL_NUM+2)
	PAR_DEV_IN_X_GRPN,		// ���������
	PAR_DEV_OUT_Y_BASE,		// �����Y�Ĵ�����ʼ���
	PAR_DEV_OUT_Y_GRPN,		// ���������
	PAR_DEV_ENCOD1_TYPE,	// ������1����
	PAR_DEV_ENCOD1_PPR,		// ������1ÿת������
	PAR_DEV_ENCOD2_TYPE,	// ������2����
	PAR_DEV_ENCOD2_PPR,		// ������2ÿת������
};



// �豸--MCP_LOC/MCP_NET
enum
{
	PAR_DEV_MCP_TYPE = PAR_DEV_GNL_NUM,	// MCP���ͣ�1-A / 2-B /3-C
	PAR_DEV_MCP_MPG_IDX,	// ��ҡ���
	PAR_DEV_MCP_X_BASE,     // �����X�Ĵ�����ʼ���(PAR_DEV_GNL_NUM+2)
	PAR_DEV_MCP_X_GRPN,     // �����ռ��X�Ĵ�������
	PAR_DEV_MCP_Y_BASE,     // �����Ĵ�����ַ
	PAR_DEV_MCP_Y_GRPN,     // �����ռ��Y�Ĵ�������
	PAR_DEV_MCP_MPG_DIR,    // ��ҡ����ȡ����־
	PAR_DEV_MCP_MPG_MULT,   // ��ҡ���ʷŴ�ϵ��
	PAR_DEV_MCP_CODE_TYPE,  // ���ο��ر�������
	PAR_DEV_MCP_SPDL_NUM    // ׷��ģ������������temp��
};

// �豸--SERIAL
enum 
{
	PAR_SERIAL_BIT_LEN = PAR_DEV_GNL_NUM,   // �շ�����λ����
	PAR_SERIAL_STOP,		// ֹͣλ
	PAR_SERIAL_PARITY,		// ��żУ��λ
	PAR_SERIAL_BAUDRATE,	// ������
	PAR_SERIAL_PAR_NUM		// SERIALʵ�����ò�����Ŀ
};

// �豸--LAN
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
	PAR_LAN_PAR_NUM     // LANʵ�����ò�����Ŀ
};

// �豸--WCOM����ͨѶ�ӿ�
enum 
{
	PAR_WCOM_TYPE = PAR_DEV_GNL_NUM, // WCOM����
	PAR_WCOM_RESERVE,	// ����
	PAR_WCOM_PAR_NUM	// WCOMʵ�����ò�����Ŀ
};

// �豸--GATHER�ɼ���
enum
{
	PAR_GATHER_TYPE = PAR_DEV_GNL_NUM,	// �ɼ������� 1:KZM-6000
	PAR_GATHER_SERIAL_IDX,    // �����豸��
	PAR_GATHER_SENSOR_NUM,    // ��������
	PAR_GATHER_IN_X_BASE,     // �������ʼ���
	PAR_GATHER_PAR_NUM        // GATHERʵ�����ò�����Ŀ
};

// �����豸���ƶ���Ӧ�����Ͷ��壬ϵͳ���������ͺͽӿڲ���ȷ�����ƶ�����ϵͳ��
// ������������ݵ�ַ
enum DevNcobjType
{
	DEV_NCOBJ_NULL_LOC = 1000,	// �����豸--�������豸
	DEV_NCOBJ_SPDL_LOC,
	DEV_NCOBJ_AXIS_LOC,
	DEV_NCOBJ_IN_LOC,
	DEV_NCOBJ_OUT_LOC,
	DEV_NCOBJ_AD_LOC,
	DEV_NCOBJ_DA_LOC,
	DEV_NCOBJ_IOMD_LOC,		// NCUC���ߵ�IO����ģ��
	DEV_NCOBJ_MCP_LOC,
	DEV_NCOBJ_MPG_LOC,
	DEV_NCOBJ_NCKB_LOC,
	DEV_NCOBJ_SENSOR_LOC,	// �������豸
	DEV_NCOBJ_SERIAL_LOC,	// �����豸
	DEV_NCOBJ_GATHER_LOC,	// �¶Ȳɼ���

	DEV_NCOBJ_NULL_NET = 2000,	// �����豸--ncuc\ethercat\syqnet...
	DEV_NCOBJ_SPDL_NET,
	DEV_NCOBJ_AXIS_NET,
	DEV_NCOBJ_IN_NET,
	DEV_NCOBJ_OUT_NET,
	DEV_NCOBJ_AD_NET,
	DEV_NCOBJ_DA_NET,
	DEV_NCOBJ_IOMD_NET,		// NCUC���ߵ�IO����ģ��
	DEV_NCOBJ_MCP_NET,
	DEV_NCOBJ_MPG_NET,
	DEV_NCOBJ_NCKB_NET,
	DEV_NCOBJ_SENSOR_NET,	// ������
	DEV_NCOBJ_PIDC_NET,		// λ�ذ�

	// �˴���չ�µ�����
	DEV_NCOBJ_ENCOD_NET		// ������
};

// 	���߲���
// 2.1 �������ݷ�Χ
#define MAX_GEO_PARA	(24)	// ���߼��β�������
#define MAX_WEAR_PARA	(24)	// ����ĥ���������
#define MAX_TECH_PARA	(24)	// ���߹�����ز�������
#define MAX_TOOL_EXPARA	(24)	// ������չ��������
#define MAX_TOOL_MONITOR (24)	// ���߼�ز�������
#define MAX_TOOL_MEASURE (24)	// ���߲�����������
#define MAX_TOOL_BASE	(24)	// ����һ����Ϣ��������
#define MAX_TOOL_PARA	(200)	// ���߻����������� (24+24+24+24+24+24+24 = 168)
#define MAGZ_HEAD_SIZE	(16)	// �������ݱ�ͷ��С

// ���߲�������
// INFTOOL_��ͷ��ΪBit32������ΪfBit64
enum ToolParaIndex
{
	// ���߼�����ز�������
	GTOOL_DIR = 0,	// ���� 
	GTOOL_LEN1,	// ����1(ϳ�����߳��ȣ�����Xƫ��)
	GTOOL_LEN2,	// ����2(����Yƫ��)
	GTOOL_LEN3,	// ����3(����Zƫ��)
	GTOOL_LEN4,	// ����4
	GTOOL_LEN5,	// ����5
	GTOOL_RAD1,	// �뾶1(ϳ�����߰뾶����������뾶)
	GTOOL_RAD2,	// �뾶2
	GTOOL_ANG1,	// �Ƕ�1
	GTOOL_ANG2,	// �Ƕ�2

	GTOOL_TOTAL,

	// ����ĥ����ز�������
	WTOOL_LEN1 = MAX_GEO_PARA, // (ϳ������ĥ�𣻳���Zĥ��)
	WTOOL_LEN2,	// ����2
	WTOOL_LEN3,	// ����3
	WTOOL_LEN4,	// ����4
	WTOOL_LEN5,	// ����5
	WTOOL_RAD1,	// �뾶1(ϳ���뾶ĥ�𣻳���Xĥ��)
	WTOOL_RAD2,	// �뾶2
	WTOOL_ANG1,	// �Ƕ�1
	WTOOL_ANG2,	// �Ƕ�2
	
	WTOOL_TOTAL,
	
	// ���߹�����ز�������
	TETOOL_PARA0 = MAX_GEO_PARA+MAX_WEAR_PARA, // ������ز���0������MAX_TECH_PARA_NUM-1
	TETOOL_PARA1,
	TETOOL_PARA2,
	TETOOL_PARA3,
	TETOOL_PARA4,
	TETOOL_PARA5,
	TETOOL_PARA6,
	TETOOL_PARA7,
	TETOOL_PARA8,
	TETOOL_PARA9,
	// ����10��������ټ�
	
	TETOOL_TOTAL,

	// ������չ����--���߹������������������ͨ��
	EXTOOL_S_LIMIT = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA,    // Sת������
	EXTOOL_F_LIMIT,    // Fת������
	EXTOOL_LARGE_LEFT,		// �󵶾߸�����λ
	EXTOOL_LARGE_RIGHT,		// �󵶾߸�ɬ�ҵ�λ

	EXTOOL_TOTAL,

	// ���߼�ز���
    MOTOOL_TYPE = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA+MAX_TOOL_EXPARA, // ���߼�����ͣ���λ��Ч������/�Ƽ�/ĥ�𣬿�ѡ���ּ�ط�ʽͬʱ���
	MOTOOL_SEQU,		// 	���ȼ�
	MOTOOL_MULTI,		// 	����

	MOTOOL_MAX_LIFE,	// �������ʱ��
	MOTOOL_ALM_LIFE,	// Ԥ������ʱ��
	MOTOOL_ACT_LIFE,	// ʵ������ʱ��

	MOTOOL_MAX_COUNT,	// ���װ����
	MOTOOL_ALM_COUNT,	// Ԥ����װ����
	MOTOOL_ACT_COUNT,	// ʵ�ʰ�װ����

	MOTOOL_MAX_WEAR,	// δʹ��
	MOTOOL_ALM_WEAR,	// δʹ��
	MOTOOL_ACT_WEAR,	// δʹ��

	MOTOOL_GROUP,       // �������������

	MOTOOL_TOTAL,

	// ���߲�����������
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

	// 	����һ����Ϣ
	INFTOOL_ID = MAX_GEO_PARA+MAX_WEAR_PARA+MAX_TECH_PARA+MAX_TOOL_EXPARA+MAX_TOOL_MONITOR+MAX_TOOL_BASE, // ����������
	INFTOOL_MAGZ,		// 	�������������
	INFTOOL_CH,			// 	��������ͨ����
	INFTOOL_TYPE,		// 	��������
	INFTOOL_STATE,		// 	����״̬��
	INFTOOL_G64MODE,	//  ���߸��ٸ߾��ӹ�ģʽ

	INFTOOL_TOTAL,

	TOOL_PARA_TOTAL // < MAX_TOOL_PARA
};

// ������ͷ��������
enum MagzHeadIndex
{
	MAGZTAB_HEAD = 0,	// �������ʼƫ�Ƶ�ַ�����ߺŶ�+��λ���ԶΣ�
	MAGZTAB_TOOL_NUM,	// ������е�����
	MAGZTAB_CUR_TOOL,	// ��ǰ���ߺ�
	MAGZTAB_CUR_POT,	// ��ǰ��λ��
	MAGZTAB_REF_TOOL,	// �굶��
	MAGZTAB_CHAN,		// ��������ͨ����
	MAGZTAB_TYPE,		// ��������
	SWAP_LEFT_TOOL,		// ��е����λ���ߺ�
	SWAP_RIGHT_TOOL,	// ��е���ҵ�λ���ߺ�
	// Ԥ��

	MAGZTAB_TOTAL
};

// ���߲������廯��������ǰ�ĵ��ߺ꣩
// ϳ����������
#define MTOOL_RAD		GTOOL_RAD1	// ���߰뾶
#define MTOOL_LEN		GTOOL_LEN1	// ���߳���
#define MTOOL_RAD_WEAR	WTOOL_RAD1	// ϳ��:�뾶ĥ�𲹳�������
#define MTOOL_LEN_WEAR	WTOOL_LEN1	// ϳ��:����ĥ�𲹳�������

// ������������
#define LTOOL_RAD		GTOOL_RAD1		// ����뾶
#define LTOOL_DIR		GTOOL_DIR		// ���ⷽ��
#define LTOOL_RAD_WEAR	WTOOL_RAD1		// ����:����ĥ��ֵ�����򣩣����ֵ��
#define LTOOL_LEN_WEAR	WTOOL_LEN1		// ����:����ĥ��ֵ�����򣩣����ֵ��
#define LTOOL_XOFF		GTOOL_LEN1		// ����������ƫ��ֵ�����򣩣�����ֵ�� =  ����ʱXֵ - ����ֱ��/2
#define LTOOL_YOFF		GTOOL_LEN2
#define LTOOL_ZOFF		GTOOL_LEN3		// ����������ƫ��ֵ�����򣩣�����ֵ�� =  ����ʱZֵ - ���г���
#define LTOOL_XDONE		TETOOL_PARA0	// X���б�־
#define LTOOL_YDONE		TETOOL_PARA0
#define LTOOL_ZDONE		TETOOL_PARA1	// Z���б�־

#define SPDL_RESOLUTION	(1000)	// ����ת�ٷֱ���
#define MAX_SCAN_ROW_NUM_RANDOM 1000
#define GIVEN_ROW_IDLE				0
#define GIVEN_ROW_WAIT_PROG_OK		1     //�ȴ������г���׼����
#define GIVEN_ROW_SCANING			2     //������ɨ����
#define GIVEN_ROW_WAIT_SCAN_ACK		3     //�����еȴ��������Ӧ�����������ɨ��
#define GIVEN_ROW_WAIT_SUBPROG_OK	4     //�ȴ��������ӳ���׼����
#define GIVEN_ROW_SUBPROG_OK		5     //�������ӳ���׼����
#define GIVEN_ROW_SUBPROG_EXCUTING	6    //�������ӳ���ִ����
#define GIVEN_ROW_SCAN_ERR			7    //������ɨ���з����﷨����
#define GIVEN_ROW_TYPE1_WAIT_Z_MOVE 8    //������ɨ��ģʽ1���ȴ�Z���ƶ�ָ��

// ����
// �������ݺ궨��
#define SMPL_CHAN_NUM (16)		// ����ͨ����
#define SMPL_DATA_NUM (10000)	// ÿ����ͨ���Ĳ�������

// ��������
enum HncSampleType
{
	SAMPL_NULL_TYPE = 0,// ������
	SAMPL_AXIS_CMD = 1,	// ���ָ��λ��
	SAMPL_AXIS_ACT,		// ���ʵ��λ��
	SAMPL_FOLLOW_ERR,	// ��ĸ������
	SAMPL_CMD_INC,		// ���ָ���ٶ�
	SAMPL_ACT_VEL,		// ���ʵ���ٶ�
	SAMPL_ACT_TRQ,		// ��ĸ��ص���
	SAMPL_CMD_POS,		// ָ����λ��
	SAMPL_CMD_PULSE,	// ָ������λ��
	SAMPL_ACT_POS,		// ʵ�ʵ��λ��
	SAMPL_ACT_PULSE,	// ʵ������λ��
	SAMPL_TOL_COMP,		// ����ֵ
	SAMPL_SYS_VAL = 101,	// ϵͳ����
	SAMPL_CHAN_VAL,		// ͨ������
	SAMPL_AXIS_VAL,		// �����
	SAMPL_X_REG,		// X�Ĵ���
	SAMPL_Y_REG,		// Y�Ĵ���
	SAMPL_F_AXIS_REG,	// ��F�Ĵ���
	SAMPL_G_AXIS_REG,	// ��G�Ĵ���
	SAMPL_F_CHAN_REG,	// ͨ��F�Ĵ���
	SAMPL_G_CHAN_REG,	// ͨ��G�Ĵ���
	SAMPL_F_SYS_REG,	// ϵͳF�Ĵ���
	SAMPL_G_SYS_REG,	// ϵͳG�Ĵ���
	SAMPL_R_REG,		// R�Ĵ���
	SAMPL_B_REG,		// B�Ĵ���
	SAMPL_TOTAL
};
#define T_CTRL_CHANGE_DIRECT 0X1
#define T_CTRL_TOOL_MODE     0X2
#define VAR_WRITE_WAIT       0X1
#define VAR_READ_WAIT        0X2
#endif // __HNC_DATADEF_H__
