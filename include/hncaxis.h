/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncaxis.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ����ӿڣ��߼��ᣩ
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

#ifndef __HNC_AXIS_H__
#define __HNC_AXIS_H__

#include "hncdatatype.h"

// ����������
// Get(Bit32)��ʾGet����ʱvoid *ΪBit32 *
enum HncAxis
{
	HNC_AXIS_NAME = 0,		// ���� {Get(Bit8[PARAM_STR_LEN])}
	HNC_AXIS_TYPE,			// ������ {Get(Bit32)}
	HNC_AXIS_CHAN,			// ��ȡͨ���� {Get(Bit32)}
	HNC_AXIS_CHAN_INDEX,	// ��ȡ��ͨ���е���� {Get(Bit32)}
	HNC_AXIS_CHAN_SINDEX,	// ��ȡ��ͨ���е������ {Get(Bit32)}
	HNC_AXIS_LEAD,			// ��ȡ������ {Get(Bit32)}
	HNC_AXIS_ACT_POS,		// ����ʵ��λ�� {Get(Bit32)}
	HNC_AXIS_ACT_POS2,		// ����ʵ��λ��2 {Get(Bit32)}
	HNC_AXIS_CMD_POS,		// ����ָ��λ�� {Get(Bit32)}
	HNC_AXIS_ACT_POS_WCS,	// ����ʵ��λ�� {Get(Bit32)}
	HNC_AXIS_CMD_POS_WCS,	// ����ָ��λ�� {Get(Bit32)}
	HNC_AXIS_ACT_POS_RCS,	// ���ʵ��λ�� {Get(Bit32)}
	HNC_AXIS_CMD_POS_RCS,	// ���ָ��λ�� {Get(Bit32)}
	HNC_AXIS_ACT_PULSE,		// ʵ������λ�� {Get(Bit32)}
	HNC_AXIS_CMD_PULSE,		// ָ������λ�� {Get(Bit32)}
	HNC_AXIS_PROG_POS,		// ���λ�� {Get(Bit32)}
	HNC_AXIS_ENC_CNTR,		// ���λ�� {Get(Bit32)}
	HNC_AXIS_CMD_VEL,		// ָ���ٶ� {Get(Bit32)}
	HNC_AXIS_ACT_VEL,		// ʵ���ٶ� {Get(fBit64)}
	HNC_AXIS_LEFT_TOGO,		// ʣ����� {Get(Bit32)}
	HNC_AXIS_WCS_ZERO,		// ������� {Get(Bit32)}
	HNC_AXIS_WHEEl_OFF,		// �����ж�ƫ���� {Get(Bit32)}
	HNC_AXIS_FOLLOW_ERR,	// ������� {Get(Bit32)}
	HNC_AXIS_SYN_ERR,		// ͬ�����	{Get(Bit32)}
	HNC_AXIS_COMP,			// �Ჹ��ֵ {Get(Bit32)}
	HNC_AXIS_ZSW_DIST,		// Z����ƫ�� {Get(Bit32)}
	HNC_AXIS_REAL_ZERO,		// ������ {Get(Bit32)}
	HNC_AXIS_MOTOR_REV,		// ���ת�� {Get(fBit64)}
	HNC_AXIS_DRIVE_CUR,		// ������Ԫ���� {Get(fBit64)}
	HNC_AXIS_LOAD_CUR,		// ���ص��� {Get(fBit64)}
	HNC_AXIS_RATED_CUR,		// ����� {Get(fBit64)}
	HNC_AXIS_IS_HOMEF,		// ������� {Get(Bit32)}
	HNC_AXIS_WAVE_FREQ,		// ����Ƶ�� {Get(fBit64)}
	HNC_AXIS_DRIVE_VER,     // �ŷ������汾 {Get(Bit8[32])}
	HNC_AXIS_MOTOR_TYPE,    // �ŷ����� {Get(Bit8[32])}
	HNC_AXIS_MOTOR_TYPE_FLAG,// �ŷ����ͳ����־ {Get(Bit32)}
	HNC_AXIS_TOTAL
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ�����ݵ�ֵ
//
//    ������
//            type		�������ݵ�����
//            ax		����ţ�
//            value		�������ݵ�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_AxisGetValue(Bit32 type, Bit32 ax, void *value, Bit16 clientNo = 0);

#endif // __HNC_AXIS_H__
