/*
* Copyright (c) 2013, 武汉华中数控股份有限公司
* All rights reserved.
* 
* 文件名称：hncparaman.h
* 文件标识：根据配置管理计划书
* 摘    要：参数管理
* 运行平台：Linux/Windows
* 
* 版    本：1.00
* 作    者：HNC-8 Team
* 日    期：2013年9月25日
* 说    明：
*/

#ifndef __HNC_PARA_MAN_H__
#define __HNC_PARA_MAN_H__

#include "hncdatatype.h"
#include "hncdatadef.h"

#define DATA_STRING_LEN (64)

// 返回值
#define	PARA_FILE_OPEN_FAIL		(-1)	// 文件打开失败
#define	PARA_FILE_SEEK_FAIL		(-2)	// 文件seek失败
#define	PARA_FILE_READ_FAIL		(-3)	// 文件读失败
#define	PARA_FILE_WRITE_FAIL	(-4)	// 文件写失败
#define	PARA_FILE_DATA_FAIL 	(-5)	// 文件数据错误
#define	PARA_POINT_NULL_ERR 	(-6)	// 空指针
#define PARA_FILENO_ERR			(-7)	// 参数类别错误
#define PARA_SUBNO_ERR			(-8)	// 子类号越界
#define PARA_ROWNO_ERR			(-9)	// 行号越界
#define PARA_ROWXNO_ERR			(-10)	// 总行号越界
#define PARA_INDEX_ERR			(-11)	// 索引越界
#define PARA_STRING_LIMIT		(-12)	// 字符串太长
#define PARA_PARMNO_ERR			(-13)	// 参数号越界
#define PARA_PARMANTYPE_ERR		(-14)	// 参数类型错误
#define PARM_MAPINDEX_ERR		(-15)	// 参数索引号错	
#define PARM_MAPROWNO_ERR		(-16)	// 参数行号错
#define PARM_SVWRITE_ERR        (-17)   // 写伺服参数失败
#define PARM_SVSAVE_ERR        (-18)    // 保存伺服参数失败
#define PAEM_SVSTATE_ERR       (-19)    // 总线通讯未准备好,无法写入伺服参数
#define PAEM_SVRESET_ERR       (-20)    // 总线未成功复位

// 参数属性类型
enum ParaPropType
{
	PARA_PROP_VALUE,	// 参数值 参数结构文件定义
	PARA_PROP_MAXVALUE,	// 最大值 参数结构文件定义
	PARA_PROP_MINVALUE,	// 最小值 参数结构文件定义
	PARA_PROP_DFVALUE,	// 缺省值 参数结构文件定义
	PARA_PROP_NAME,		// 名字  STRING
	PARA_PROP_ACCESS,	// 权限  INT
	PARA_PROP_ACT,		// 生效方式 INT
	PARA_PROP_STORE,	// 存储类型  INT
	PARA_PROP_ID,		// 参数编号 INT
	PARA_PROP_SIZE		// 大小 INT
};

// 参数生效方式枚举定义
enum ParaActType
{
	PARA_ACT_SAVE, // 保存生效
	PARA_ACT_NOW,  // 立即生效
	PARA_ACT_RST,  // 复位生效
	PARA_ACT_PWR,  // 重启生效
	PARA_ACT_HIDE  // 隐藏未启用
};


// 子类属性定义
enum ParaSubClassProp
{
	SUBCLASS_NAME,		// 子类名
	SUBCLASS_ROWNUM,	// 子类行数
	SUBCLASS_NUM,		// 子类数
	SUBCLASS_MAXNUM     //最大行数
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

// 参数文件头
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
//    功能：
//				参数管理器初始化
//
//    参数：
//			
//             
//
//    描述：
//
//	  返回：
//				返回0： 成功
//				返回-1：参数结构文件载入失败
//				返回-2：上次保存参数文件有异常,请核实参数数据
//				返回-3：参数载入失败，载入默认参数
//
/////////////////////////////////////////////////////////////////////////
extern Bit32  HNC_ParamanInit();

////////////////////////////////////////////////////////////////////////
//
//    void  HNC_ParamanExit()
//
//    功能：
//				参数管理器退出
//
//    参数：
//			
//             
//
//    描述：
//
//	  返回：
//				
//				
//
/////////////////////////////////////////////////////////////////////////
extern void  HNC_ParamanExit();

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo)
//
//    功能：
//            加载参数数据文件
//
//    参数：
//            fileName ：参数数据文件名；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanLoad(Bit8 *fileName, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSave(Bit16 clientNo)
//
//    功能：
//            保存参数数据文件
//
//    参数：
//            clientNo ：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSave(Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
//    Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo)
//
//    功能：
//				另存为参数数据文件
//
//    参数：
//			    lpFileName: 参数数据文件名            
//
//    描述：
//
//	  返回：
//				返回0： 成功
//		        返回<0：失败
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanSaveAs(Bit8* lpFileName, Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetParaProp(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo)
//
//    功能：
//            获取参数属性的值
//
//    参数：
//            parmId	 ：参数编号；
//            propType	 ：参数属性的类型；enum ParaPropType
//            propValue	 ：参数属性的值；
//            clientNo	 ：网络连接号；
//
//    描述：
//            参数编号说明：
//            详细说明参见《华中8型数控系统参数说明书》；
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetParaPropEx(Bit32 parmId, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSetParaProp(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo)
//
//    功能：
//            设置参数属性的值（包括参数值、最大值、最小值、缺省值、名称）
//
//    参数：
//            parmId	 ：参数编号；
//            propType	 ：参数属性的类型；enum ParaPropType
//            propValue	 ：参数属性的值；
//            clientNo	 ：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetParaPropEx(Bit32 parmId, Bit8 propType, const SDataProperty *propValue, Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
// Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
//							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0)
//
//    功能：
//				设置参数属性值,属性包括: 参数值、最大值、最小值、
//               缺省值、名称
//
//    参数：
//              ftype: 参数类别
//              subid: 子类号
//			    index: 索引偏移地址           
//              propType: 参数属性
//              propValue: 参数属性值 enum ParaPropType
//              clientNo: 网络连接号
//    描述：
//
//	  返回：			
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanSetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
							 Bit8 propType,const SDataProperty *propValue, Bit16 clientNo = 0);

////////////////////////////////////////////////////////////////////////
//
// Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
//							 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0)
//
//    功能：
//				获取参数属性值,属性包括: 参数值、最大值、最小值、
//               缺省值、名称、权限、生效方式、单位、内存大小
//
//    参数：
//              ftype: 参数类别
//              subid: 子类号
//			    index: 索引偏移地址           
//              propType: 参数属性
//              propValue: 参数属性值 enum ParaPropType
//              clientNo: 网络连接号
//    描述：
//
//	  返回：			
//
/////////////////////////////////////////////////////////////////////////
HNCAPI Bit32  HNC_ParamanGetParaProp(Bit32 filetype, Bit32 subid, Bit32 index,
									 Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo)
//
//    功能：
//            获取参数类别的名字
//
//    参数：
//            fileNo	：参数类别；
//            buf		：名字；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetFileName(Bit32 fileNo, Bit8 *buf, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetSubClassProp(Bit32 fileNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo)
//
//    功能：
//            获取参数子类属性的值
//
//    参数：
//            fileNo	：参数类别；
//            propType	：子类属性的类型；enum ParaSubClassProp
//            propValue ：子类属性的值；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetSubClassProp (Bit32 fileNo, Bit8 propType, SDataProperty *propValue, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo)
//
//    功能：
//            获取参数索引列表总显示行数
//
//    参数：
//            rowNum	：总行数；
//            clientNo	：网络连接号
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetTotalRowNum(Bit32 *rowNum, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransRow2Index(Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo)
//
//    功能：
//            通过参数类别、子类号、行号获取指定参数的索引值
//
//    参数：
//            fileNo	：参数类别；
//            subNo		：子类号；
//            rowNo		：子类行号；
//            index		：参数的索引值；
//            dupNum	：参数重复个数；
//            dupNo		：参数重复编号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransRow2Index (Bit32 fileNo, Bit32 subNo, Bit32 rowNo, Bit32 *index, Bit16 *dupNum, Bit16 *dupNo, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransRowx2Row(Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo)
//
//    功能：
//            通过参数行总索引号获取参数类别，子类号，以及子类行号
//
//    参数：
//            rowx		：总索引号
//            fileNo	：参数类别；
//            subNo		：子类号；
//            row		：子类行号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransRowx2Row (Bit32 rowx, Bit32 *fileNo, Bit32 *subNo, Bit32 *row, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32* rowx, Bit16 clientNo)
//
//    功能：
//            通过参数编号获取行总索引号
//
//    参数：
//            parmId	：参数编号；
//            rowx		：总索引号；
//            clientNo	：网络连接号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanTransId2Rowx(Bit32 parmId, Bit32 *rowx, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo)
//
//    功能：
//            加载参数子类的结构
//
//    参数：
//            fileNo	：参数类别;
//            subNo		：子类号；
//            clientNo	：网络索引号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanRewriteSubClass(Bit32 fileNo, Bit32 subNo, Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//    Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0)
//
//    功能：
//            保存参数结构文件
//
//    参数：
//            clientNo	：网络索引号；
//
//    描述：
//            
//
//    返回：
//            0：成功；非0：失败，参见返回值说明；
//
//////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSaveStrFile(Bit16 clientNo = 0);


///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0)
//
//    功能：
//				获取参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value: 返回参数整型值    
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0)
//
//    功能：
//				设置参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value: 参数整型值    
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetI32(Bit32 fileno, Bit32 subno, Bit32 index, Bit32 value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0)
//
//    功能：
//				获取参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value:  返回参数浮点值  
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0)
//
//    功能：
//				设置参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value:  参数浮点值  
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetFloat(Bit32 fileno, Bit32 subno, Bit32 index, fBit64 value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0)
//
//    功能：
//				获取参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value: 返回参数字符串   
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0)
//
//    功能：
//				设置参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value:  参数字符串   
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetStr(Bit32 fileno, Bit32 subno, Bit32 index, Bit8* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0)
//
//    功能：
//				获取参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value:  返回参数数据  
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanGetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

///////////////////////////////////////////////////////////////////////////////
//
//   Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0)
//
//    功能：
//				获取参数值
//
//    参数：
//              fileno: 参数类别
//              subno:  子类号  
//              index:  索引
//              value:  设置参数数据  
//              clientNo: 网络连接号          
//
//    描述：
//
//	  返回：
//				0  成功
//				返回<0：失败
//
//////////////////////////////////////////////////////////////////////////////////
HNCAPI Bit32 HNC_ParamanSetItem(Bit32 fileno, Bit32 subno, Bit32 index, SParamValue* value, Bit16 clientNo = 0);

#endif // __HNC_PARA_MAN_H__
