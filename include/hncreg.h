/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncreg.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ���Ĵ����ӿ�
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2013��6��20��
* ˵    ��������ֵ˵����
*           0���ɹ���
*           1���첽��ȡ�Ĵ�����δ��ȡ���Ĵ������ݣ�
*           -1���Ĵ������ʹ���
*           -2���Ĵ�����ų���������ƣ�
*           -3���Ĵ���λ�ų���������ƣ�
*           -4���Ĵ����������޸ģ�P�Ĵ�������
*           -5���Ĵ���ֵָ��Ϊ�գ�
*/

#ifndef __HNC_REG_H__
#define __HNC_REG_H__

#include "hncdatatype.h"

// �Ĵ�������
enum HncRegType
{
	REG_TYPE_X = 0,	// X�Ĵ��� Bit8
	REG_TYPE_Y,		// Y�Ĵ��� Bit8
	REG_TYPE_F,		// F�Ĵ��� Bit16
	REG_TYPE_G,		// G�Ĵ��� Bit16
	REG_TYPE_R,		// R�Ĵ��� Bit8
	REG_TYPE_W,		// W�Ĵ��� Bit16
	REG_TYPE_D,		// D�Ĵ��� Bit32
	REG_TYPE_B,		// B�Ĵ��� Bit32
	REG_TYPE_P,		// P�Ĵ��� Bit32
	REG_TYPE_TOTAL
};

// FG�Ĵ�������ַ
enum HncRegFGBaseType
{
	REG_FG_SYS_BASE = (REG_TYPE_TOTAL+1),	// ϵͳ���ݻ�ַ {Get(Bit32)}
	REG_FG_CHAN_BASE,		// ͨ�����ݻ�ַ {Get(Bit32)}
	REG_FG_AXIS_BASE,		// �����ݻ�ַ {Get(Bit32)}
	REG_FG_BASE_TYPE_TOTAL
};

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo);
//
//    ���ܣ�
//            ��ȡ�Ĵ�����ֵ
//
//    ������
//            type		���Ĵ������ͣ�enum HncRegType
//            index		���Ĵ�����ţ�
//            value		���Ĵ���ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo)
//
//    ���ܣ�
//            ���üĴ�����ֵ
//
//    ������
//            type		���Ĵ������ͣ�enum HncRegType
//            index		���Ĵ�����ţ�
//            value		���Ĵ���ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegSetValue(Bit32 type, Bit32 index, void *value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    ���ܣ�
//            ���üĴ������ݵ�һλ
//
//    ������
//            type		���Ĵ������ͣ�enum HncRegType
//            index		���Ĵ�����ţ�
//            bit		���Ĵ���λ�ţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegSetBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo)
//
//    ���ܣ�
//            ����Ĵ������ݵ�һλ
//
//    ������
//            type		���Ĵ������ͣ�enum HncRegType
//            index		���Ĵ�����ţ�
//            bit		���Ĵ���λ�ţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegClrBit(Bit32 type, Bit32 index, Bit32 bit, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ�Ĵ�����������
//
//    ������
//            type		���Ĵ������ͣ�enum HncRegType
//            num		���Ĵ���������
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetNum(Bit32 type, Bit32 *num, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡFG�Ĵ����Ļ�ַ
//
//    ������
//            baseType	����ַ���ͣ�enum HncRegFGBaseType
//            baseIndex	����ַ�Ĵ�����ţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_RegGetFGBase(Bit32 baseType, Bit32 *baseIndex, Bit16 clientNo = 0);

#endif // __HNC_REG_H__
