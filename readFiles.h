#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <commdlg.h> 
using namespace std;
class readFiles
{
public:
	string fileName;
	vector<string> fileContent;
	void getFileContex();
	//获取文件路径
	string getPath();
	//按行读取文本文件
	int readFilesInLine(const string fileName, vector<string> &tempVec);
	//输出文件内容
	void printfContex(vector<string> &tempVec);
	//wchar转换成string
	string wcharToString(LPCWSTR tempWchar);	//将宽字节wchar_t*转化为单字节char*  

	inline char* unicodeToAnsi( const wchar_t* tempWchar ); 

	//将路径转换为绝对路径 单斜杠变双斜杠
	string pathTransform( string &tempString);
};

