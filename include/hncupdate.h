#ifndef __HNC_UPDATE_H__
#define __HNC_UPDATE_H__

#include "hncdatatype.h"

#define SELECT_BASE (0x0000)
#define SELECT_BIN  (0x0001)
#define SELECT_BMP	(0x0002)
#define SELECT_DATA (0x0004)
#define SELECT_HLP  (0x0008)
#define SELECT_N    (0x0010)
#define SELECT_PARM (0x0020)
#define SELECT_PLC  (0x0040)
#define SELECT_PROG (0x0080)
#define SELECT_TMP  (0x0100)
#define SELECT_ALLBTF  (0x0200)

////////////////////////////////////////////////////////////////////////////////
//
//     Bit32 HNC_SysBackup(Bit32 flag,Bit8* PathName, Bit16 clientNo)
//     
//     ���ܣ�
//          ϵͳ����
// 
//	   ������	
//			������
//
//     ������
//          flag ��������
//          PathName �����ļ���
//			clientNo �������Ӻ�
//
//     ���أ�
//          ����ֵ -2: �ļ�����ʧ��
//          ����ֵ -1: tar�ļ�����!
//          ����ֵ 0: �ļ���������
//
///////////////////////////////
HNCAPI Bit32 HNC_SysBackup(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

////////////////////////////////////////////////////////////////////////////////
//
//     Bit32 HNC_SysUpdate(Bit32 flag,Bit8* PathName, Bit16 clientNo)
//     
//     ���ܣ�
//          ϵͳ����
// 
//	   ������	
//			������
//
//     ������
//          flag ��������
//          PathName �����ļ���
//			clientNo �������Ӻ�
//
//     ���أ�
//          ����ֵ -2: ����ʧ��!
//          ����ֵ -1: tar�ļ�����!
//          ����ֵ 0: �ļ������ɹ�
//
////////////////////////////////
HNCAPI Bit32 HNC_SysUpdate(Bit32 flag,Bit8* PathName, Bit16 clientNo=0);

#endif // __HNC_SYS_H__