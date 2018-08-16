/*
* Copyright (c) 2010, �人�������عɷ����޹�˾��������
* All rights reserved.
* 
* �ļ����ƣ�osdepend.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ��ΪHMI�ṩʱ�䡢���ҵ�ϵͳ���õ�ͳһ�ӿڣ������ƽ̨����Ҫ
* ����ƽ̨��Linux/WinXP
* 
* ��    ����1.00
* ��    �ߣ�����
* ��    �ڣ�2010��05��03��
* ˵    ����
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
#define FILE_DATE_LEN 18 // �ļ������ַ�������
#define FILE_SIZE_LEN 12 // �ļ���С�ַ�������

// windows�������260�������ǵ���ϵͳ���ַ���һ�㶨��Ϊ128���ʼ�������
#define FILE_NAME_LEN 48  // �ļ���������·��������
#define PATH_NAME_LEN 128 // ·���������ļ���������

// FIND_ERR��û�ҵ� FIND_OK���ҵ�
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

// ·���ָ���
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

// �ļ��ṹ
typedef struct _nc_fileinfo_t
{
	Bit8	reserved[21];
	uBit32	attrib;			// �ļ�����
	uBit16	wr_time;
	uBit16	wr_date;
	Bit32	size;			// �ļ���С
	Bit8	name[FILE_NAME_LEN];	// �ļ���
} nc_finfo_t;

// �ļ����ҽṹ
typedef struct _ncfind_t
{
	nc_finfo_t info;
#ifdef _WINCE
	HANDLE handle;
#else
	Bit32 handle;
#endif
	Bit8 time[FILE_DATE_LEN]; // �޸�ʱ��[YYYY-MM-DD HH:MM]
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
//    ���ܣ�  
//			���Ҵ����ļ�����Ŀ¼��
//			 
//    ������
//			filespec ������������ļ�����·��������ͨ�����
//			fileinfo ������������ļ���Ϣ�ṹ
//			attrib ��  ����������ļ�����
//			dir : �ļ���ָ��
//
//    ������
//			 
//
//	  ���أ� 
//			enum FIND_TYPE���ͣ�FIND_ERR��û�ҵ���FIND_OK���ҵ�
//
//////////////////////////////////////////////////////////////////////////
extern Bit32 nc_findfirst(const Bit8 *filespec, ncfind_t *fileinfo, Bit16 attrib, SDirInfo *dir);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit8 nc_findnext(ncfind_t *fileinfo, SDirInfo *dir)
//
//    ���ܣ�  
//			����nc_findfirst���ļ�(��Ŀ¼)����
//			 
//    ������
//			fileinfo ����������������ļ���Ϣ�ṹ
//			dir : �ļ���ָ��
//
//    ������
//
//
//	  ���أ� 
//			enum FIND_TYPE���ͣ�FIND_ERR��û�ҵ���FIND_OK���ҵ�
//
//////////////////////////////////////////////////////////////////////////
extern Bit8 nc_findnext(ncfind_t *fileinfo, SDirInfo *dir);

///////////////////////////////////////////////////////////////////////////////
//
//    void nc_findclose(ncfind_t *fileinfo, SDirInfo *dir)
//
//    ���ܣ�
//            �ر��ļ�����Ŀ¼������
//
//    ������
//            fileinfo ���ļ���Ϣ��
//			  dir : �ļ���ָ��
//
//    ������
//            �رղ��ң��ͷ������Դ
//
//    ���أ�
//            
//
//////////////////////////////////////////////////////////////////////////
extern void nc_findclose(ncfind_t *fileinfo, SDirInfo *dir);

#endif // __OS_DEPEND_H__
