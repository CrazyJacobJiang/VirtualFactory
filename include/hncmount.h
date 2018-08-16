/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
*
* �ļ����ƣ�hncmount.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��ϵͳ���ݽӿ�
* ����ƽ̨��Linux/Windows
*
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2014��7��15��
* ˵    ��������ֵ˵����
*           0���ɹ���
*           -1���������벻��ȷ��
*/

#ifndef __HNC_MOUNT_H__
#define __HNC_MOUNT_H__
#include "hncdatatype.h"



#define IP_LEN (16)
#define NAME_LEN (32)     //�����û�������
#define PROGADDR_LEN (32) //�����ļ���������
#define PASS_LEN    (9) // ��������ַ���Ϊ9



//////////////////////////////////////////////////////////////////////////////
//
//    Bit16 HNC_NetDiskMount(Bit8* ip, Bit8* prog_addr)
//
//    ���ܣ�
//				��������
//
//    ������ip ���̵�ַ16λ
//          prog_addr G�����ַ 32λ
//
//    ������
//
//    ���أ�
//				����0�����سɹ�
//				���ط�0������ʧ��
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_NetDiskMount( Bit8* ip, Bit8* progAddr, Bit8* uname = "", Bit8* uPassword = "", Bit16 clientNo = 0);

#endif // __HNC_MOUNT_H__

