#pragma once
#include "readFiles.h"

void readFiles::getFileContex()
{
	string path = getPath();
	this->fileName=pathTransform(path);
	readFilesInLine(fileName,this->fileContent);
	return ;
}
//��ȡ�ļ�·��
string readFiles::getPath()
{

	OPENFILENAME openFile;  
	WCHAR fileName[MAX_PATH]={0};//����ļ���  
	//��ʼ��  
	ZeroMemory(&openFile, sizeof(OPENFILENAME));  
	openFile.lStructSize = sizeof(OPENFILENAME);//�ṹ���С  
	openFile.hwndOwner = NULL;
	openFile.lpstrFile = fileName;  
	openFile.lpstrFile[0] = '\0';  
	openFile.nMaxFile = sizeof(fileName); 

	//���ù���  
	openFile.lpstrFilter = L"�ı��ļ�(*.txt)\0*.txt\0�����ļ�(*.*)\0*.*\0\0";  
	//Ĭ�Ϲ�����������Ϊ1  
	openFile.nFilterIndex = 1;  
	openFile.lpstrFileTitle = NULL; 
	openFile.nMaxFileTitle = 0; 
	//�ļ������ֶα����Ȱѵ�һ���ַ���Ϊ \0  
	openFile.lpstrInitialDir = NULL;  
	//���ñ�־λ�����Ŀ¼���ļ��Ƿ����  
	openFile.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;  
	//opfn.lpstrInitialDir = NULL;  
	// ��ʾ�Ի������û�ѡ���ļ� 

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
//���ж�ȡ�ı��ļ�
int readFiles::readFilesInLine(const string fileName, vector<string> &tempVec)
{
	// ����ifstream����inFile���󶨵����β�fileNameָ�����ļ�
	ifstream tempFile(fileName.c_str());
	if (!tempFile)  // ���ļ�ʧ��
	{
		//cout<<"���ļ�ʧ��"<<endl;
		return 1;
	}
	// ���ļ����ݶ��뵽string���͵�vector����
	// ÿһ�д洢Ϊ�����������һ��Ԫ��
	string ss;
	while (getline(tempFile, ss))
	{
		tempVec.push_back(ss);
	}
	tempFile.close();        // �ر��ļ�

	if (tempFile.eof())    // �����ļ�������
	{
		cout<<"�ļ�����"<<endl;
		return 0;
	}
	if (tempFile.bad())    // ����ϵͳ������
	{
		cout<<"ϵͳ����"<<endl;
		return 0;
	}
	if (tempFile.fail())    // ��������ʧ��
	{
		cout<<"���ݶ�ȡʧ��"<<endl;
		return 0;
	}
	return 0;
}
//����ļ�����
void readFiles::printfContex(vector<string> &tempVec)
{
	for (vector<string>::iterator iter = tempVec.begin(); iter != tempVec.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
//wcharת����string
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
//�����ֽ�wchar_t*ת��Ϊ���ֽ�char*  

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

//��·��ת��Ϊ����·�� ��б�ܱ�˫б��
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
