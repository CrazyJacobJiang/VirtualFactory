/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncdatatype.h
* 文件标识：根据配置管理计划书
* 摘    要：NC数据类型
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年9月25日
* 说    明：
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

// 系统用全局变量、表达式运算的联合数据类型
typedef struct DATA_UNION
{
	Bit8 type;
	Bit8 g90;
	union 
	{
		Bit64 i;
		fBit64 f;
		uBit32 n;	// 变量偏移地址
		Bit8 s[8];
		Bit8 *pstr;	// 字符指针
	} v;
} SDataUnion;

// 参数：字符串类型长度
#define PARAM_STR_LEN	(8)

// 参数值
typedef	union _PARAM_VAL_UNION
{
	Bit32 i;
	fBit64 f;
	Bit8 s[PARAM_STR_LEN];
} SParamValue;


// 数据类型
#define DTYPE_NULL		(0)	// 空类型
#define DTYPE_INTEGER	(1)	// 整型
#define DTYPE_INT DTYPE_INTEGER
#define DTYPE_FLOAT		(2)	// 实型
#define DTYPE_EXPR		(3)	// 表达式
#define DTYPE_VAR		(4)	// 简单变量
#define DTYPE_STRING	(5)	// 字符串
#define DTYPE_UINT		(6) // 无符号整形
#define DTYPE_BOOL		(7) // 布尔型
#define DTYPE_FUNC		(8) // 函数表达式
#define DTYPE_ARR		(9) // 数组表达式
#define DTYPE_HEX4		(10) // 十六进制格式
#define DTYPE_BYTE		(11) // 十六进制格式
#define DTYPE_DOT	DTYPE_FLOAT

// 常量定义
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
