/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncsys.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��ϵͳ���ݽӿ�
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2013��6��20��
* ˵    ��������ֵ˵����
*           0���ɹ���
*           -1���������벻��ȷ��
*           -2���ӿڲ��ṩ�ù��ܣ�
*/

#ifndef __HNC_SYS_H__
#define __HNC_SYS_H__

#include "hncdatatype.h"

// ϵͳ��������
// Get(Bit32)��ʾGet����ʱvoid *ΪBit32 *
// Set(NULL)��ʾ����ΪNULL�Ŀ�������
enum HncSystem
{
	HNC_SYS_CHAN_NUM = 0,		// ��ȡϵͳͨ���� {Get(Bit32)}
	HNC_SYS_MOVE_UNIT,			// ���ȷֱ��� {Get(Bit32)}
	HNC_SYS_TURN_UNIT,			// �Ƕȷֱ��� {Get(Bit32)}
	HNC_SYS_METRIC_DISP,		// ��Ӣ�� {Get(Bit32)}
	HNC_SYS_SHOW_TIME,			// ��ʾʱ�� {Get(Bit32)}
	HNC_SYS_POP_ALARM,			// �����Զ���ʾ {Get(Bit32)}
	HNC_SYS_GRAPH_ERASE,		// ͼ���Զ����� {Get(Bit32)}
	HNC_SYS_MAC_TYPE,			// ��������
	HNC_SYS_PREC,				// ����ϵ���� {Get(Bit32)}
	HNC_SYS_F_PREC,				// F���� {Get(Bit32)}
	HNC_SYS_S_PREC,				// S���� {Get(Bit32)}
	HNC_SYS_NCK_VER,			// NCK�汾 {Get(Bit8[32])}
	HNC_SYS_DRV_VER,			// DRV�汾 {Get(Bit8[32])}
	HNC_SYS_PLC_VER,			// PLC�汾 {Get(Bit8[32])}
	HNC_SYS_CNC_VER,			// CNC�汾 {Get(Bit32) Set(Bit32)}
	HNC_SYS_MCP_KEY,			// MCP���Կ�׿��� {Get(Bit32)}
	HNC_SYS_ACTIVE_CHAN,		// �ͨ�� {Get(Bit32) Set(Bit32)}
	HNC_SYS_REQUEST_CHAN,		// ����ͨ�� {Get(Bit32)}
	HNC_SYS_MDI_CHAN,			// MDI����ͨ�� {Get(Bit32)}
	HNC_SYS_REQUEST_CHAN_MASK,	// �����ͨ�������� {Get(Bit32)}
	HNC_SYS_CHAN_MASK,			// ͨ�������� {Set(Bit32)}
	HNC_SYS_PLC_STOP,			// plcֹͣ {Set(NULL)}
	HNC_SYS_POWEROFF_ACT,		// �ϵ�Ӧ�� {Set(NULL)}
	HNC_SYS_IS_HOLD_REDECODE,	// �������ֺ��Ƿ����½��� {Get(Bit32)}
	HNC_SYS_NC_VER,             // NC�汾 {Get(Bit8[32])}
	HNC_SYS_SN_NUM,             // CF��SN�� {Get(Bit8[32]) Set(Bit8[32])}
	HNC_SYS_MACHINE_TYPE,		//�����ͺ� {Get(Bit8[48]) Set(Bit8[48])}
	HNC_SYS_MACHINE_INFO,		//������Ϣ {Get(Bit8[48]) Set(Bit8[48])}
	HNC_SYS_MACFAC_INFO,		//��������Ϣ {Get(Bit8[48]) Set(Bit8[48])}
	HNC_SYS_USER_INFO,			//�û���Ϣ {Get(Bit8[48]) Set(Bit8[48])}
	HNC_SYS_MACHINE_NUM,		//������� {Get(Bit8[48]) Set(Bit8[48])}
	HNC_SYS_EXFACTORY_DATE,     //����ʱ�� {Get(Bit8[32])}
	HNC_SYS_ACCESS_LEVEL,		//Ȩ�޵ȼ� {Get(Bit32)}
	HNC_SYS_MUL_CHAN_RESET,		// ��ͨ����λ����������� {Set(Bit32)[0/1]}
	HNC_SYS_RIGHTS_KEY,			// Ȩ��Կ���� {Get(Bit32)}
	HNC_SYS_TOTAL
};

#define MAX_SYS_STR_LEN		(64)

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_SystemGetValue(Bit32 type, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡϵͳ���ݵ�ֵ
//
//    ������
//            type		��ϵͳ���ݵ����ͣ�
//            value		��ϵͳ���ݵ�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_SystemGetValue(Bit32 type, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_SystemSetValue(Bit32 type, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ����ϵͳ���ݵ�ֵ
//
//    ������
//            type		��ϵͳ���ݵ����ͣ�
//            value		��ϵͳ���ݵ�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_SystemSetValue(Bit32 type, void *value = NULL, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_SystemGetUserRealTimeData(Bit8 *value, Bit16 clientNo)
//
//    ���ܣ�
//				��ȡ�û�ʵʱ����
//
//    ������
//              value:ϵͳ���ݵ�ֵ������6400
//              clientNo: �������Ӻ�
//
//    ������
//
//	  ���أ�
//				0: �ɹ�
//				-1:��ָ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_SystemGetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_SystemSetUserRealTimeData(Bit8 *value, Bit16 clientNo)
//
//    ���ܣ�
//				�����û�ʵʱ����
//
//    ������
//              value: ϵͳ���ݵ�ֵ������6400
//              clientNo: �������Ӻ�
//
//    ������
//
//	  ���أ�
//				0: �ɹ�
//				-1:��ָ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_SystemSetUserRealTimeData(Bit8 *value, Bit16 clientNo = 0);




#endif // __HNC_SYS_H__
