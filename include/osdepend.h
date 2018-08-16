/*
* Copyright (c) 2010, 武汉华中数控股份有限公司开发二部
* All rights reserved.
* 
* 文件名称：osdepend.h
* 文件标识：根据配置管理计划书
* 摘    要：为HMI提供时间、查找等系统调用的统一接口，满足跨平台的需要
* 运行平台：Linux/WinXP
* 
* 版    本：1.00
* 作    者：刘涛
* 日    期：2010年05月03日
* 说    明：
*/

#ifndef __OS_DEPEND_H__
#define __OS_DEPEND_H__

#ifdef _WINCE
	#include <winbase.h>
	#include <afx.h>
	#include <ceddk.h>
	#pragma comment(lib,"ceddk.lib")
#elif defined(_WIN32)
	#include <windows.h>
	#include <io.h>
#endif
#ifdef _LINUX
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include <sys/time.h>
#endif

#include "hncdatatype.h"

// [YYYY-MM-DD HH:MM]
#define date_format "%04d-%02d-%02d %02d:%02d"
#define FILE_DATE_LEN 18 // 文件日期字符串长度
#define FILE_SIZE_LEN 12 // 文件大小字符串长度

// windows定义的是260，但考虑到本系统内字符串一般定义为128，故加以限制
#define FILE_NAME_LEN 48  // 文件名（不含路径）长度
#define PATH_NAME_LEN 128 // 路径名（含文件名）长度

// FIND_ERR：没找到 FIND_OK：找到
enum FIND_TYPE {FIND_OVERFLOW = -2, FIND_ERR = -1, FIND_OK = 0};

#ifdef _WINCE
#define _A_SUBDIR	FILE_ATTRIBUTE_DIRECTORY
#define _A_NORMAL	FILE_ATTRIBUTE_NORMAL
#define rewind(fp)	fseek((fp), 0L, SEEK_SET)
#endif

#ifdef _LINUX
#define _stricmp	strcasecmp
#define stricmp		strcasecmp
#define _A_NORMAL	0x0
#define _A_SUBDIR	0x10
#endif

// 路径分隔符
#ifdef _LINUX
#define DIR_SEPARATOR '/'
#else
#define DIR_SEPARATOR '\\'
#endif

typedef struct _nctime_t
{
	int second;	// seconds - [0,59]
	int minute;	// minutes - [0,59]
	int hour;	// hours   - [0,23]
	int milliseconds; /* thousandths of seconds */

	int day;	// [1,31]
	int month;	// [0,11] (January = 0)
	int year;	// (current year minus 1900)
	int wday;	// Day of week, [0,6] (Sunday = 0)
} nctime_t;

// 文件结构
typedef struct _nc_fileinfo_t
{
	Bit8	reserved[21];
	uBit32	attrib;			// 文件属性
	uBit16	wr_time;
	uBit16	wr_date;
	Bit32	size;			// 文件大小
	Bit8	name[FILE_NAME_LEN];	// 文件名
} nc_finfo_t;

// 文件查找结构
typedef struct _ncfind_t
{
	nc_finfo_t info;
#ifdef _WINCE
	HANDLE handle;
#else
	Bit32 handle;
#endif
	Bit8 time[FILE_DATE_LEN]; // 修改时间[YYYY-MM-DD HH:MM]
} ncfind_t;

typedef struct _SDirInfo
{
#ifdef _LINUX
	Bit8 filedir[128];
	Bit8 filename[PATH_NAME_LEN];
	Bit16 fileattrib;
	DIR *dir;
#endif
}SDirInfo;

extern void nc_gettime(nctime_t *ptime);
extern void nc_settime(nctime_t *ptime);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 nc_findfirst(const Bit8 *filespec, ncfind_t *fileinfo, Bit16 attrib, SDirInfo *dir)
//
//    功能：  
//			查找磁盘文件（含目录）
//			 
//    参数：
//			filespec ：输入参数，文件查找路径（包含通配符）
//			fileinfo ：输出参数，文件信息结构
//			attrib ：  输入参数，文件属性
//			dir : 文件夹指针
//
//    描述：
//			 
//
//	  返回： 
//			enum FIND_TYPE类型；FIND_ERR：没找到，FIND_OK：找到
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 nc_findfirst(const Bit8 *filespec, ncfind_t *fileinfo, Bit16 attrib, SDirInfo *dir);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit8 nc_findnext(ncfind_t *fileinfo, SDirInfo *dir)
//
//    功能：  
//			继续nc_findfirst的文件(含目录)查找
//			 
//    参数：
//			fileinfo ：输入输出参数，文件信息结构
//			dir : 文件夹指针
//
//    描述：
//
//
//	  返回： 
//			enum FIND_TYPE类型；FIND_ERR：没找到，FIND_OK：找到
//
//////////////////////////////////////////////////////////////////////////
extern Bit8 nc_findnext(ncfind_t *fileinfo, SDirInfo *dir);

///////////////////////////////////////////////////////////////////////////////
//
//    void nc_findclose(ncfind_t *fileinfo, SDirInfo *dir)
//
//    功能：
//            关闭文件（含目录）查找
//
//    参数：
//            fileinfo ：文件信息；
//			  dir : 文件夹指针
//
//    描述：
//            关闭查找，释放相关资源
//
//    返回：
//            
//
//////////////////////////////////////////////////////////////////////////
extern void nc_findclose(ncfind_t *fileinfo, SDirInfo *dir);

#endif // __OS_DEPEND_H__
