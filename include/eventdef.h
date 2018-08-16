/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�eventdef.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��ϵͳ�¼�����
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2010��3��18��
* ˵    ����
*/

#ifndef __EVENT_DEF_H__
#define __EVENT_DEF_H__

#include "hncdatatype.h"

#define MAX_EVENT_NUM 512
#define MAX_RESERVE_DATA_LEN	128

typedef struct _EventElement
{
    Bit16 src;	 // �¼���Դ
    uBit16 code; // �¼�����
	Bit8 buf[MAX_RESERVE_DATA_LEN];
} SEventElement;

typedef struct _MSTInfo
{
	Bit16 num;
	Bit32 line;
}mstinfo;

#define _hncevent_get_size() sizeof(SEventElement)*(MAX_EVENT_NUM+8)


// һ. �����¼���Դ
#define	EV_SRC_SYS	0x010		// ϵͳ�¼�

#define	EV_SRC_CH0	0x100		// ͨ��0�¼� 0x100~0x10f

#define	EV_SRC_MDI	0x110		// MDI���¼� 

#define EV_SRC_KBD	0x200		// �����¼�

#define EV_SRC_AX0	0x300		// ���¼�

#define EV_SRC_NET	0x400		//�����¼�

// ��. �����¼�����
// 1. ������̴���
//								0x  0	009
//								   ---	---
//						���		|	|         ����
//						------------	--------------
//				0�������飬��׼ASCII�룬Ŀǰ�������࣬1���ַ�����0x00yy
//														2�����ܼ�, 0x01yy
//				1��ctrl�飬��ϼ�=0x1000+����ֵ
//				2��alt�飬��ϼ�=0x2000+����ֵ
//				3��shift�飬��ϼ�=0x3000+����ֵ
//				7������
//				�ݲ�����������ϼ�
//
						
#define kbNoKey		0x0000

// 00---�ַ�������׼ASCA�붨�壺'A'~'Z','0'~'9','*','!'......

#define kbSpace		0x0020
#define kbBack      0x0008
#define kbTab		0x0009
#define kbEnter		0x000d
// 01---���ܼ�

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

// ctrl��ϼ�
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

// alt��ϼ�
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

// shift��ϼ�
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
#define kbRealRe	(0x7ffe)	// ֻҪϵͳ��ѯ�¼�����������ִ��

#define kbReset		kbCtrlZ 	
#define kbReturn	kbF11	// �ڶ����ؼ�

// 2. ����ͨ���¼�
#define	ncEvtPrgStart	0xa001	// ��������
#define ncEvtPrgEnd		0xa002	// �������
#define	ncEvtPrgHold	0xa003	// Hold���	
#define	ncEvtPrgBreak	0xa004	// break���	
#define	ncEvtG92Fin		0xa005	// G92���
#define	ncEvtRstFin		0xa006	// �ϵ縴λ���
#define	ncEvtRwndFin	0xa007	// ���������
#define ncEvtMdiRdy		0xa008	// MDI׼����
#define	ncEvtMdiExit	0xa009	// MDI�˳�
#define	ncEvtMdiAck		0xa00a	// MDI�н������
#define	ncEvtRunStart	0xa00b	// ��������

#define	ncEvtRunRowAck	0xa00d	// ����������Ӧ��
#define	ncEvtRunRowRdy	0xa00e	// ������׼����

#define ncEvtBpSaved	0xa011	// �ϵ㱣�����
#define ncEvtBpResumed	0xa012	// �ϵ�ָ����
#define ncEvtIntvHold	0xa013	// ִ�е�M92�ȴ��û���Ԥ
#define	ncEvtEstop		0xa014	// �ⲿ��ͣ
#define	ncEvtLoadOK		0xa015	// ����������

#define	ncEvtSyntax1	0xa016	// ��һ���﷨���޸ĺ�ɽ������С�
#define	ncEvtSyntax2	0xa017	// �ڶ����﷨���޸ĺ��ͷ���С�

#define	ncEvtGcodeSave	0xa018	// �����е����ݱ���ָ��
#define ncEvtLoadData	0xa019	// �����е����ݼ���ָ��
#define ncEvtChgTool	0xa01a	// G�����޸��˵�������
#define ncEvtChgCrds	0xa01b	// G�����޸�������ϵ����
#define ncEvtChgAxes	0xa01c	// ͨ�����鷢���˸ı�
#define ncEvtChgVar	    0xa01d	// G�����޸ı���

#define ncEvtNckNote	0xa01e	// ͨ����ʾ
#define ncEvtNckAlarm	0xa01f	// ͨ������
#define ncEvtStopAck	0xa020	// sys_stop_prog���
// #define ncEvtMcode      0xa021
// #define ncEvtS0code     0xa022
// #define ncEvtS1code     0xa023
// #define ncEvtS2code     0xa024
// #define ncEvtS3code     0xa025
// #define ncEvtTcode      0xa026
#define ncEvtRandomRowFinish      0xa027 //������ɨ�����
//#define ncEVtRandomRowRunFinish   0xa028 //������ִ�����
#define ncEVtRandomRowRequestProg 0xa029 //������ɨ��ģʽ������������׼���ó���
#define ncEvtFaultIrq	0xa030	// �����ж�
#define ncEvtPackFin	0xa040	// ���ݴ�����

#define ncEvtAlarmChg	0xa055	// ��������������
#define ncEvtFileChg	0xa056	// �ļ��޸�

#define ncEvtConnect	0xa060	// nc����
#define ncEvtDisConnect	0xa061	// nc�Ͽ�����
#define ncEvtFileSend	0xa062	// �����ļ����


// 3. �������¼�
#define ncEvtMaxEncPos	0xa201	// ���������ʼλ�ù���
#define ncEvtMaxACC 	0xa202	// ����ٶȹ���


// 4. ����ϵͳ�¼�
#define ncEvtPoweroff	0xa800	// ϵͳ�ϵ�
#define ncEvtSaveData	0xa801	// ����ϵͳ����
#define ncEvtSysExit	0xa802	// ϵͳ�˳�

#define ncEvtUserStart	0xb000	// �û��Զ����¼� ����100��

#define ncEvtUserFunc1  (ncEvtUserStart+100)	// event 100 ��Ӧ�û���������ָ������
#define ncEvtUserFunc2  (ncEvtUserStart+101)	// event 100 ��Ӧ�û���������ָ������
#define ncEvtHardRstFin	(ncEvtUserStart+102)	// Ӳ��λ���
#define ncEvtSaveRegB	(ncEvtUserStart+103)	// ����B�Ĵ���
#define ncEvtUserReqChn	(ncEvtUserStart+104)	// �����л�ͨ��
#define ncEvtUserReqMsk	(ncEvtUserStart+105)	// ��������ͨ��
#define ncEvtReserve0   (ncEvtUserStart+106)	// �û�����PLC�¼�
#define ncEvtReserve1   (ncEvtUserStart+107)	// �û�����PLC�¼�
#define ncEvtReserve2   (ncEvtUserStart+108)	// �û�����PLC�¼�
#define ncEvtReserve3   (ncEvtUserStart+109)	// �û�����PLC�¼�

#define ncEvtChFin0		(ncEvtUserStart+110)	// ͨ��0�ӹ����
#define ncEvtChFin1		(ncEvtUserStart+111)	// ͨ��1�ӹ����
#define ncEvtChFin2		(ncEvtUserStart+112)	// ͨ��2�ӹ����
#define ncEvtChFin3		(ncEvtUserStart+113)	// ͨ��3�ӹ����
#define ncEvtChFin		(ncEvtUserStart+114)	// �ӹ�����¼�

#define ncEvtRstMsg		(ncEvtUserStart+120)	// ��λ��Ϣ

#define ncEvtRigChg		(ncEvtUserStart+121)	// Կ�����л�Ȩ����Ϣ

#define ncEvtRfidReadTag	(ncEvtUserStart+122)	// RFID�����ӱ�ǩ���ݵ�CNC
#define ncEvtRfidWriteTag	(ncEvtUserStart+123)	// RFIDдCNC���ݵ����ӱ�ǩ

#endif // __EVENT_DEF_H__
