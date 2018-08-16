/*
* Copyright (c) 2013, �人�������عɷ����޹�˾��������
* All rights reserved.
*
* �ļ����ƣ�hncverify.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ���ṩУ��ͼ�λ��Ʋ��ֽӿں�����У��ʱ��ֱ�Ӹ���ָ�������켣
			Ȼ������


* ����ƽ̨��linux/winxp
*
* ��    ����
* ��    �ߣ���@��
* ��    �ڣ�2013��9��6��
* ˵    ����


*/

#ifndef __VERIFY_H__
#define __VERIFY_H__
#include "hncdatatype.h"
#include "hncdatadef.h"
enum TCURVETYPE
{
	TCURVE_TYPE_NONE,	//û����������
	TCURVE_TYPE_LINE,	//ֱ��
	TCURVE_TYPE_CYCLE,		//Բ��
	TCURVE_TYPE_THREAD,        //����
};
///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurveType(Bit32 ch, Bit32* curtype, Bit16 clientNo = 0);
//
//    ���ܣ�
//            ��ȡ��������
//
//    ������
//            ch ��ͨ���ţ�
//            curtype : �������� enum TCURVETYPE
//            clientNo: �������Ӻ�
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveType(Bit32 ch, Bit32* curtype, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_VerifyGetCurveSpos(Bit32 ch,Bit32 ax, Bit64* spos, Bit16 clientNo = 0);
//
//    ���ܣ�
//            ��ȡ�������
//
//    ������
//            ch ��ͨ���ţ�
//			  ax �����
//            spos: ���
//            clientNo: �������Ӻ�
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveSpos(Bit32 ch,Bit32 ax, Bit64* spos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurveEpos(Bit32 ch,Bit32 ax, Bit64* epos, Bit16 clientNo = 0);
//
//    ���ܣ�
//            ��ȡ�����յ�
//
//    ������
//            ch ��ͨ���ţ�
//			  ax �����
//            epos:�����յ�
//            clientNo: �������Ӻ�
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurveEpos(Bit32 ch,Bit32 ax, Bit64* epos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetLinePos(Bit32 ch, Bit32 pos[], Bit32* flag, Bit16 clientNo = 0);
//
//    ���ܣ�
//            ��ȡֱ��У���м��
//
//    ������
//            ch ��ͨ���ţ�
//            flag : У���־ 0������ֱ��У����� 1������ֱ��У��δ���
//            clientNo: �������Ӻ�
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetLinePos(Bit32 ch, Bit32 pos[CHAN_AXES_NUM], Bit32* flag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyClearCurve(Bit32 ch, Bit16 clientNo = 0);
//
//    ���ܣ�
//            ����У�����
//
//    ������
//            ch ��ͨ���ţ�
//            clientNo: �������Ӻ�
//
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyClearCurve(Bit32 ch, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCurvePoint(Bit32 ch,Bit32 pos[3], Bit32* vflag, Bit16 clientNo = 0);
//
//    ���ܣ�
//           Բ������У���м��
//
//    ������
//            ch ��ͨ���ţ�
//			  pos[3] ���м��
//            vflag:У���־ 0������Բ��У����� 1������Բ��У��δ���
//            clientNo: �������Ӻ�
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCurvePoint(Bit32 ch,Bit32 pos[3], Bit32* vflag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyCalcuCyclePara(Bit32 ch ,Bit8* vflag, Bit16 clientNo = 0);
//
//    ���ܣ�
//           ����Բ������
//
//    ������
//            ch ��ͨ���ţ�
//            vflag:0,1
//            clientNo: �������Ӻ�
//
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyCalcuCyclePara(Bit32 ch, Bit8* vflag, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifySetChCmdPos(Bit32 ch,Bit32 ax,Bit64 pos, Bit16 clientNo = 0);
//
//    ���ܣ�
//          ����ͨ��ָ���
//
//    ������
//            ch ��ͨ���ţ�
//			  ax �� ���
//			  pos���м��
//            clientNo: �������Ӻ�
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifySetChCmdPos(Bit32 ch,Bit32 ax,Bit64 pos, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_VerifyGetCmdPos(Bit32 ax,Bit64* pos, Bit16 clientNo = 0);
//
//    ���ܣ�
//          ��ȡͨ��ָ���
//
//    ������
//            ax ����ţ�
//            pos: λ��
//            clientNo: �������Ӻ�
//
//    ������
//
//
//    ���أ�
//            0:�ɹ�
//           -1:ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_VerifyGetCmdPos(Bit32 ax, Bit64* pos, Bit16 clientNo = 0);


#endif