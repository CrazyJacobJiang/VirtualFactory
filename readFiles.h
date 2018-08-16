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
	//��ȡ�ļ�·��
	string getPath();
	//���ж�ȡ�ı��ļ�
	int readFilesInLine(const string fileName, vector<string> &tempVec);
	//����ļ�����
	void printfContex(vector<string> &tempVec);
	//wcharת����string
	string wcharToString(LPCWSTR tempWchar);	//�����ֽ�wchar_t*ת��Ϊ���ֽ�char*  

	inline char* unicodeToAnsi( const wchar_t* tempWchar ); 

	//��·��ת��Ϊ����·�� ��б�ܱ�˫б��
	string pathTransform( string &tempString);
};

