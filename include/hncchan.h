/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncchan.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��ͨ�����ݽӿ�
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

#ifndef __HNC_CHANNEL_H__
#define __HNC_CHANNEL_H__

#include "hncdatatype.h"

// ͨ����������
// Get(Bit32)��ʾGet����ʱvoid *ΪBit32 *
// Set(NULL)��ʾ����ΪNULL�Ŀ�������
enum HncChannel
{
	HNC_CHAN_IS_EXIST = 0,		// ͨ���Ƿ���� {Get(Bit32)}
	HNC_CHAN_MAC_TYPE,			// ͨ���Ļ������� {Get(Bit32)}
	HNC_CHAN_AXES_MASK,			// ������ {Get(Bit32)}
	HNC_CHAN_AXES_MASK1,		// ������1 {Get(Bit32)}
	HNC_CHAN_NAME,				// ͨ���� {Get(Bit8[PARAM_STR_LEN])}
	HNC_CHAN_CMD_TYPE,			// ��ȡ��ǰG����ı�־ {Get(Bit32)}
	HNC_CHAN_CMD_FEEDRATE,		// ָ������ٶ� {Get(fBit64)}
	HNC_CHAN_ACT_FEEDRATE,		// ʵ�ʽ����ٶ� {Get(fBit64)}
	HNC_CHAN_PROG_FEEDRATE,		// ���ָ���ٶ� {Get(fBit64)}
	HNC_CHAN_FEED_OVERRIDE,		// �����޵� {Get(Bit32)}
	HNC_CHAN_RAPID_OVERRIDE,	// �����޵� {Get(Bit32)}
	HNC_CHAN_MCODE,             // ͨ����Mָ�� {Get(Bit32)}
	HNC_CHAN_TCODE,				// ͨ����Tָ�� {Get(Bit32)}
	HNC_CHAN_TOFFS,				// ͨ���еĵ�ƫ�� {Get(Bit32)}
	HNC_CHAN_TOOL_USE,			// ��ǰ���� {Get(Bit32)}
	HNC_CHAN_TOOL_RDY,			// ׼���ý����ĵ��� {Get(Bit32)}
	HNC_CHAN_MODE,				// ģʽ(����ֵ���ݶ��������) {Get(Bit32)}
	HNC_CHAN_IS_MDI,			// MDI {Get(Bit32)}
	HNC_CHAN_CYCLE,				// ѭ������ {Get(Bit32), Set(NULL)}
	HNC_CHAN_HOLD,				// �������� {Get(Bit32), Set(NULL)}
	HNC_CHAN_IS_PROGSEL,		// ��ѡ���� {Get(Bit32)}
	HNC_CHAN_IS_PROGEND,		// ����������� {Get(Bit32)}
	HNC_CHAN_IS_THREADING,		// ���Ƽӹ� {Get(Bit32)}
	HNC_CHAN_IS_RIGID,			// ���Թ�˿ {Get(Bit32)}
	HNC_CHAN_IS_REWINDED,		// �����и�λ״̬ {Get(Bit32)}
	HNC_CHAN_IS_ESTOP,			// ��ͣ {Get(Bit32)}
	HNC_CHAN_IS_RESETTING,		// ��λ {Get(Bit32)}
	HNC_CHAN_IS_RUNNING,		// ������ {Get(Bit32)}
	HNC_CHAN_IS_HOMING,			// ������ {Get(Bit32)}
	HNC_CHAN_IS_MOVING,			// ���ƶ��� {Get(Bit32)}
	HNC_CHAN_DIAMETER,			// ֱ�뾶��� {Get(Bit32)}
	HNC_CHAN_VERIFY,			// У�� {Get(Bit32), Set(Bit32)}
	HNC_CHAN_RUN_ROW,			// ������ {Get(Bit32)}
	HNC_CHAN_DCD_ROW,			// ������ {Get(Bit32)}
	HNC_CHAN_SEL_PROG,			// ѡ�����ı�� {Get(Bit32)}
	HNC_CHAN_RUN_PROG,			// ���г���ı�� {Get(Bit32)}
	HNC_CHAN_PART_CNTR,			// �ӹ����� {Get(Bit32), Set(Bit32)}
	HNC_CHAN_PART_STATI,		// �������� {Get(Bit32), Set(Bit32)}
	HNC_CHAN_HMI_RESET,			// HMI��λ {Set(NULL)}
	HNC_CHAN_CHG_PROG,			// �����޸ı�־ {Set(NULL)}

	HNC_CHAN_PERIOD_TOTAL,		// ���������ݽ��������������ݲ���Ϊ���������ϴ�

	HNC_CHAN_LAX,				// ͨ�����Ӧ���߼���� {Get(Bit32)}
	HNC_CHAN_AXIS_NAME,			// ������� {Get(Bit8[PARAM_STR_LEN])}
	HNC_CHAN_SPDL_NAME,			// ��������� {Get(Bit8[PARAM_STR_LEN])}
	HNC_CHAN_MODAL,				// ͨ��ģ̬ ��80�� {Get(Bit32)}
	HNC_CHAN_SPDL_LAX,			// ͨ�������Ӧ���߼���ţ���̬ {Get(Bit32)}
	HNC_CHAN_SPDL_PARA_LAX,		// ͨ�������Ӧ���߼���ţ���̬ {Get(Bit32)}
	HNC_CHAN_CMD_SPDL_SPEED,	// ����ָ���ٶ� {Get(fBit64)}
	HNC_CHAN_ACT_SPDL_SPEED,	// ����ʵ���ٶ� {Get(fBit64)}
	HNC_CHAN_SPDL_OVERRIDE,		// �����޵� {Get(Bit32)}
	HNC_CHAN_DO_HOLD,			// ���ý������� 
	HNC_CHAN_BP_POS,			// �ϵ�λ�� {Get(Bit32)}
	HNC_CHAN_PROG_FLOW,			// ���ڵ����ֶ��ӳ��� {Get(Bit32)}
	HNC_CHAN_H_OFF,				// ��ǰʹ�õ��߳��Ȳ����� {Get(Bit32)}
	HNC_CHAN_D_OFF,				// ��ǰʹ�õ��߰뾶������ {Get(Bit32)}
	HNC_CHAN_TOTAL
};

#define HNC_CHAN_PACK_NUM	(HNC_CHAN_PERIOD_TOTAL)

// HNC_CHAN_MODE���ܷ���ֵ
#define	CHAN_MODE_RESET	(0)
#define	CHAN_MODE_AUTO	(1)
#define	CHAN_MODE_JOG	(2)
#define	CHAN_MODE_STEP	(3)
#define	CHAN_MODE_MPG	(4)
#define	CHAN_MODE_HOME	(5)
#define	CHAN_MODE_PMC	(6)
#define CHAN_MODE_SBL	(7)

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡͨ�����ݵ�ֵ
//
//    ������
//            type		��ͨ�����ݵ����ͣ�
//            ch		��ͨ���ţ�
//            index		��ͨ�����/ͨ������ţ�
//            value		��ͨ�����ݵ�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ChannelGetValue(Bit32 type, Bit32 ch, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ChannelSetValue(Bit32 type, Bit32 ch, Bit32 index, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ����ͨ�����ݵ�ֵ
//
//    ������
//            type		��ͨ�����ݵ����ͣ�
//            ch		��ͨ���ţ�
//            index		��ͨ�����/ͨ������ţ�
//            value		��ͨ�����ݵ�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ChannelSetValue(Bit32 type, Bit32 ch, Bit32 index = 0, void *value = NULL, Bit16 clientNo = 0);

#endif // __HNC_CHANNEL_H__
