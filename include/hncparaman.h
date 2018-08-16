/*
* Copyright (c) 2013, �人�������عɷ����޹�˾
* All rights reserved.
* 
* �ļ����ƣ�hncparaman.h
* �ļ���ʶ���������ù���ƻ���
* ժ    Ҫ����������
* ����ƽ̨��Linux/Windows
* 
* ��    ����1.00
* ��    �ߣ�HNC-8 Team
* ��    �ڣ�2013��9��25��
* ˵    ����
*/

#ifndef __HNC_PARA_MAN_H__
#define __HNC_PARA_MAN_H__

#include "hncdatatype.h"
#include "hncdatadef.h"

#define DATA_STRING_LEN (64)

// ����ֵ
#define	PARA_FILE_OPEN_FAIL		(-1)	// �ļ���ʧ��
#define	PARA_FILE_SEEK_FAIL		(-2)	// �ļ�seekʧ��
#define	PARA_FILE_READ_FAIL		(-3)	// �ļ���ʧ��
#define	PARA_FILE_WRITE_FAIL	(-4)	// �ļ�дʧ��
#define	PARA_FILE_DATA_FAIL 	(-5)	// �ļ����ݴ���
#define	PARA_POINT_NULL_ERR 	(-6)	// ��ָ��
#define PARA_FILENO_ERR			(-7)	// ����������
#define PARA_SUBNO_ERR			(-8)	// �����Խ��
#define PARA_ROWNO_ERR			(-9)	// �к�Խ��
#define PARA_ROWXNO_ERR			(-10)	// ���к�Խ��
#define PARA_INDEX_ERR			(-11)	// ����Խ��
#define PARA_STRING_LIMIT		(-12)	// �ַ���̫��
#define PARA_PARMNO_ERR			(-13)	// ������Խ��
#define PARA_PARMANTYPE_ERR		(-14)	// �������ʹ���
#define PARM_MAPINDEX_ERR		(-15)	// ���������Ŵ�	
#define PARM_MAPROWNO_ERR		(-16)	// �����кŴ�
#define PARM_SVWRITE_ERR        (-17)   // д�ŷ�����ʧ��
#define PARM_SVSAVE_ERR        (-18)    // �����ŷ�����ʧ��
#define PAEM_SVSTATE_ERR       (-19)    // ����ͨѶδ׼����,�޷�д���ŷ�����
#define PAEM_SVRESET_ERR       (-20)    // ����δ�ɹ���λ

// ������������
enum ParaPropType
{
	PARA_PROP_VALUE,	// ����ֵ �����ṹ�ļ�����
	PARA_PROP_MAXVALUE,	// ���ֵ �����ṹ�ļ�����
	PARA_PROP_MINVALUE,	// ��Сֵ �����ṹ�ļ�����
	PARA_PROP_DFVALUE,	// ȱʡֵ �����ṹ�ļ�����
	PARA_PROP_NAME,		// ����  STRING
	PARA_PROP_ACCESS,	// Ȩ��  INT
	PARA_PROP_ACT,		// ��Ч��ʽ INT
	PARA_PROP_STORE,	// �洢����  INT
	PARA_PROP_ID,		// ������� INT
	PARA_PROP_SIZE		// ��С INT
};

// ������Ч��ʽö�ٶ���
enum ParaActType
{
	PARA_ACT_SAVE, // ������Ч
	PARA_ACT_NOW,  // ������Ч
	PARA_ACT_RST,  // ��λ��Ч
	PARA_ACT_PWR,  // ������Ч
	PARA_ACT_HIDE  // ����δ����
};


// �������Զ���
enum ParaSubClassProp
{
	SUBCLASS_NAME,		// ������
	SUBCLASS_ROWNUM,	// ��������
	SUBCLASS_NUM,		// ������
	SUBCLASS_MAXNUM     //�������
};

typedef struct 
{
	Bit8 type;
	union 
	{
		fBit64 val_real;
		uBit32 val_uint;
		Bit32  val_int;
		Bit8   val_string[DATA_STRING_LEN];
		Bit8   val_bool;
		Bit32  val_hex4;
		Bit8   val_byte[PARAM_STR_LEN];
	} value;
} SDataProperty;

// �����ļ�ͷ
typedef struct
{
	uBit32 HeadInfoSize;
	uBit32 MajorVersion;
	uBit32 MinorVersion; 
	uBit32 DataSize;
	uBit32 Chksum;
	uBit32 Reserved[3];
} ParmFileHead;

////////////////////////////////////////////////////////////////////////
//
//    Bit32  HNC_ParamanInit()
//
//    ���ܣ�
//				������������ʼ��
//
//    ������
//			
//             
//
//    ������
//
//	  ���أ�
//				����0�� �ɹ�
//				����-1�������ṹ�ļ�����ʧ��
//				����-2���ϴα�������ļ����쳣,���ʵ��������
//				����-3����������ʧ�ܣ�����Ĭ�ϲ���
//
/////////////////////////////////////////////////////////////////////////
extern Bit32  HNC_ParamanInit();

////////////////////////////////////////////////////////////////////////
//
//    void  HNC_ParamanExit()
//
//    ���ܣ�
//				�����������˳�
//
//    ������
//			
//             
//
//    ������
//
//	  ���أ�
//				
//				
//
/////////////////////////////////////////////////////////////////////////
extern void  HNC_ParamanExit();

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo)
//
//    ���ܣ�
//            ���ز��������ļ�
//
//    ������
//            fileName �����������ļ�����
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSave(Bit16 clientNo)
//
//    ���ܣ�
//            ������������ļ�
//
//    ������
//            clientNo ���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSave(Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
//    Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo)
//
//    ���ܣ�
//				���Ϊ���������ļ�
//
//    ������
//			    lpFileName: ���������ļ���            
//
//    ������
//
//	  ���أ�
//				����0�� �ɹ�
//		        ����<0��ʧ��
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetParaProp(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ�������Ե�ֵ
//
//    ������
//            parmId	 ��������ţ�
//            propType	 ���������Ե����ͣ�enum ParaPropType
//            propValue	 ���������Ե�ֵ��
//            clientNo	 ���������Ӻţ�
//
//    ������
//            �������˵����
//            ��ϸ˵���μ�������8������ϵͳ����˵���顷��
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetParaPropEx(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSetParaProp(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo)
//
//    ���ܣ�
//            ���ò������Ե�ֵ����������ֵ�����ֵ����Сֵ��ȱʡֵ�����ƣ�
//
//    ������
//            parmId	 ��������ţ�
//            propType	 ���������Ե����ͣ�enum ParaPropType
//            propValue	 ���������Ե�ֵ��
//            clientNo	 ���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetParaPropEx(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
// Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
//							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0)
//
//    ���ܣ�
//				���ò�������ֵ,���԰���: ����ֵ�����ֵ����Сֵ��
//               ȱʡֵ������
//
//    ������
//              ftype: �������
//              subid: �����
//			    index: ����ƫ�Ƶ�ַ           
//              propType: ��������
//              propValue: ��������ֵ enum ParaPropType
//              clientNo: �������Ӻ�
//    ������
//
//	  ���أ�			
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
// Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
//							 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ��������ֵ,���԰���: ����ֵ�����ֵ����Сֵ��
//               ȱʡֵ�����ơ�Ȩ�ޡ���Ч��ʽ����λ���ڴ��С
//
//    ������
//              ftype: �������
//              subid: �����
//			    index: ����ƫ�Ƶ�ַ           
//              propType: ��������
//              propValue: ��������ֵ enum ParaPropType
//              clientNo: �������Ӻ�
//    ������
//
//	  ���أ�			
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
									 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ������������
//
//    ������
//            fileNo	���������
//            buf		�����֣�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetSubClassProp(Bit32 fileNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ�����������Ե�ֵ
//
//    ������
//            fileNo	���������
//            propType	���������Ե����ͣ�enum ParaSubClassProp
//            propValue ���������Ե�ֵ��
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetSubClassProp (Bit32 fileNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo)
//
//    ���ܣ�
//            ��ȡ���������б�����ʾ����
//
//    ������
//            rowNum	����������
//            clientNo	���������Ӻ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransRow2Index(Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo)
//
//    ���ܣ�
//            ͨ�������������š��кŻ�ȡָ������������ֵ
//
//    ������
//            fileNo	���������
//            subNo		������ţ�
//            rowNo		�������кţ�
//            index		������������ֵ��
//            dupNum	�������ظ�������
//            dupNo		�������ظ���ţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransRow2Index (Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransRowx2Row(Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo)
//
//    ���ܣ�
//            ͨ���������������Ż�ȡ�����������ţ��Լ������к�
//
//    ������
//            rowx		����������
//            fileNo	���������
//            subNo		������ţ�
//            row		�������кţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransRowx2Row (Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32* rowx, Bit16 clientNo)
//
//    ���ܣ�
//            ͨ��������Ż�ȡ����������
//
//    ������
//            parmId	��������ţ�
//            rowx		���������ţ�
//            clientNo	���������Ӻţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32 *rowx, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo)
//
//    ���ܣ�
//            ���ز�������Ľṹ
//
//    ������
//            fileNo	���������;
//            subNo		������ţ�
//            clientNo	�����������ţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0)
//
//    ���ܣ�
//            ��������ṹ�ļ�
//
//    ������
//            clientNo	�����������ţ�
//
//    ������
//            
//
//    ���أ�
//            0���ɹ�����0��ʧ�ܣ��μ�����ֵ˵����
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ����ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value: ���ز�������ֵ    
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				���ò���ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value: ��������ֵ    
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ����ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value:  ���ز�������ֵ  
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				���ò���ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value:  ��������ֵ  
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ����ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value: ���ز����ַ���   
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				���ò���ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value:  �����ַ���   
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ����ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value:  ���ز�������  
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0)
//
//    ���ܣ�
//				��ȡ����ֵ
//
//    ������
//              fileno: �������
//              subno:  �����  
//              index:  ����
//              value:  ���ò�������  
//              clientNo: �������Ӻ�          
//
//    ������
//
//	  ���أ�
//				0  �ɹ�
//				����<0��ʧ��
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

#endif // __HNC_PARA_MAN_H__
