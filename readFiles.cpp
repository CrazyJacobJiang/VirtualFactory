#pragma once
#include "readFiles.h"

void readFiles::getFileContex()
{
	string path = getPath();
	this->fileName=pathTransform(path);
	readFilesInLine(fileName,this->fileContent);
	return ;
}
//获取文件路径
string readFiles::getPath()
{

	OPENFILENAME openFile;  
	WCHAR fileName[MAX_PATH]={0};//存放文件名  
	//初始化  
	ZeroMemory(&openFile, sizeof(OPENFILENAME));  
	openFile.lStructSize = sizeof(OPENFILENAME);//结构体大小  
	openFile.hwndOwner = NULL;
	openFile.lpstrFile = fileName;  
	openFile.lpstrFile[0] = '\0';  
	openFile.nMaxFile = sizeof(fileName); 

	//设置过滤  
	openFile.lpstrFilter = L"文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";  
	//默认过滤器索引设为1  
	openFile.nFilterIndex = 1;  
	openFile.lpstrFileTitle = NULL; 
	openFile.nMaxFileTitle = 0; 
	//文件名的字段必须先把第一个字符设为 \0  
	openFile.lpstrInitialDir = NULL;  
	//设置标志位，检查目录或文件是否存在  
	openFile.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;  
	//opfn.lpstrInitialDir = NULL;  
	// 显示对话框让用户选择文件 

	if ( GetOpenFileName(&openFile) )    
	{    
		string tempPath=wcharToString(fileName);  
		return tempPath;
	} 
	else
	{
		string tempPath2="Path\OpenFiles.txt";
		return tempPath2;
	}

}
//按行读取文本文件
int readFiles::readFilesInLine(const string fileName, vector<string> &tempVec)
{
	// 创建ifstream对象inFile并绑定到由形参fileName指定的文件
	ifstream tempFile(fileName.c_str());
	if (!tempFile)  // 打开文件失败
	{
		//cout<<"打开文件失败"<<endl;
		return 1;
	}
	// 将文件内容读入到string类型的vector容器
	// 每一行存储为该容器对象的一个元素
	string ss;
	while (getline(tempFile, ss))
	{
		tempVec.push_back(ss);
	}
	tempFile.close();        // 关闭文件

	if (tempFile.eof())    // 遇到文件结束符
	{
		cout<<"文件结束"<<endl;
		return 0;
	}
	if (tempFile.bad())    // 发生系统级故障
	{
		cout<<"系统错误"<<endl;
		return 0;
	}
	if (tempFile.fail())    // 读入数据失败
	{
		cout<<"数据读取失败"<<endl;
		return 0;
	}
	return 0;
}
//输出文件内容
void readFiles::printfContex(vector<string> &tempVec)
{
	for (vector<string>::iterator iter = tempVec.begin(); iter != tempVec.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
//wchar转换成string
string readFiles::wcharToString(LPCWSTR tempWchar)
{
	int tempLenght= WideCharToMultiByte(CP_ACP, 0, tempWchar, -1, NULL, 0, NULL, NULL);

	if (tempLenght<= 0) 
		return string("");

	char* tempMyWords = new char[tempLenght];
	if (NULL == tempMyWords) return std::string("");

	WideCharToMultiByte(CP_ACP, 0, tempWchar, -1, tempMyWords, tempLenght, NULL, NULL);
	tempMyWords[tempLenght -1] = 0;

	string tempString(tempMyWords);
	delete [] tempMyWords;

	return tempString;
}
//将宽字节wchar_t*转化为单字节char*  

inline char*readFiles:: unicodeToAnsi( const wchar_t* tempWchar )  
{  
	int tempLenght = WideCharToMultiByte( CP_ACP, 0, tempWchar, -1, NULL, 0, NULL, NULL );  
	if (tempLenght== 0)  
	{  
		return NULL;  
	}  
	char* tempChar = new char[tempLenght];  
	WideCharToMultiByte( CP_ACP, 0, tempWchar, -1, tempChar, tempLenght, NULL, NULL );  
	return tempChar;  
}  

//将路径转换为绝对路径 单斜杠变双斜杠
string readFiles::pathTransform( string &tempString)
{
	for(string::iterator tempNum=tempString.begin();tempNum!=tempString.end();++tempNum)
	{
		if(*tempNum=='\\')
		{
			tempNum=tempString.insert(tempNum,'\\');
			++tempNum;
		}
	}
	return tempString;
}
