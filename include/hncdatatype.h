/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncdatatype.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��NC��������
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2013��9��25��
* ˵    ����
*/

#ifndef __HNC_DATATYPE_H__
#define __HNC_DATATYPE_H__

#define _TRUE_64_

#undef _TRUE_64_


#ifdef _LINUX_
	#ifdef _TRUE_64_
		typedef long long  Bit64; 
		#define B64LEN	(4)
		#define B64DWD	(2)
	#else
		typedef long  Bit64; 
		#define B64LEN	(2)
		#define B64DWD	(1)
	#endif
	typedef long long  iBit64;
#else
	#ifdef _TRUE_64_
		typedef _int64  Bit64; 
		#define B64LEN	(4)
		#define B64DWD	(2)
	#else
		typedef long  Bit64; 
		#define B64LEN	(2)
		#define B64DWD	(1)
	#endif
	typedef _int64  iBit64;
#endif

typedef double  fBit64; 
typedef float  fBit32; 
typedef unsigned long  uBit32; 
typedef long Bit32;  
typedef short unsigned int  uBit16;
typedef short int Bit16;  
typedef unsigned char uBit8;
typedef char Bit8; 

#ifndef __KERNEL__
		#pragma pack (4)
#endif

#ifdef _WIN32
#pragma warning(disable : 4103)
#pragma warning(disable : 4996)
#pragma warning(disable : 4121)
#endif

// ϵͳ��ȫ�ֱ��������ʽ�����������������
typedef struct DATA_UNION
{
	Bit8 type;
	Bit8 g90;
	union 
	{
		Bit64 i;
		fBit64 f;
		uBit32 n;	// ����ƫ�Ƶ�ַ
		Bit8 s[8];
		Bit8 *pstr;	// �ַ�ָ��
	} v;
} SDataUnion;

// �������ַ������ͳ���
#define PARAM_STR_LEN	(8)

// ����ֵ
typedef	union _PARAM_VAL_UNION
{
	Bit32 i;
	fBit64 f;
	Bit8 s[PARAM_STR_LEN];
} SParamValue;


// ��������
#define DTYPE_NULL		(0)	// ������
#define DTYPE_INTEGER	(1)	// ����
#define DTYPE_INT DTYPE_INTEGER
#define DTYPE_FLOAT		(2)	// ʵ��
#define DTYPE_EXPR		(3)	// ���ʽ
#define DTYPE_VAR		(4)	// �򵥱���
#define DTYPE_STRING	(5)	// �ַ���
#define DTYPE_UINT		(6) // �޷�������
#define DTYPE_BOOL		(7) // ������
#define DTYPE_FUNC		(8) // �������ʽ
#define DTYPE_ARR		(9) // ������ʽ
#define DTYPE_HEX4		(10) // ʮ�����Ƹ�ʽ
#define DTYPE_BYTE		(11) // ʮ�����Ƹ�ʽ
#define DTYPE_DOT	DTYPE_FLOAT

// ��������
#ifndef PI
#define PI	(3.14159265358979312)
#endif

#ifndef EE
#define EE	(2.71828182845924523)
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL	(0)
#else
#define NULL    ((void *)0)
#endif
#endif

#define UNREFERENCED_PARAM(P) { (P) = (P); } 

#if defined _HNC_DLL_
	#ifdef __cplusplus
	#define HNCAPI extern "C" __declspec(dllexport)
	#else
	#define HNCAPI __declspec(dllexport)
	#endif
#elif defined _HNC_DLL_IMP_
	#ifdef __cplusplus
	#define HNCAPI extern "C" __declspec(dllimport)
	#else
	#define HNCAPI __declspec(dllimport)
	#endif
#else
	#define HNCAPI extern
#endif

#endif //  __HNC_DATATYPE_H__
