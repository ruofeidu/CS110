#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Completely Automated Public Turing test to tell Computers and Humans Apart
class CodeMachine{
private:
	string pic[10], code;		//��¼ͼƬ����֤�� 
	int pos[10][4][3];			//��¼ÿ�����ֵ�ͼ����Ϣ
	int num[5];					//��¼���ɵ�����
	char chr[5];				//��֤��ÿһλ��Ϣ

	int Random( int x );		//����������ɺ���

public:
	CodeMachine();						//��ʼ��
	void Generate( int x = 4 );		//���������
	void ShowFigure( int x, int r );	//��ʾĳλ����
	void ShowPic();						//��ʾ������֤��
	bool Check( string usercode );		//����Ƿ�ƥ��
};
