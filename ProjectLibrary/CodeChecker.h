#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Completely Automated Public Turing test to tell Computers and Humans Apart
class CodeMachine{
private:
	string pic[10], code;		//记录图片，验证码 
	int pos[10][4][3];			//记录每个数字的图像信息
	int num[5];					//记录生成的数字
	char chr[5];				//验证码每一位信息

	int Random( int x );		//随机整数生成函数

public:
	CodeMachine();						//初始化
	void Generate( int x = 4 );		//产生随机数
	void ShowFigure( int x, int r );	//显示某位数字
	void ShowPic();						//显示整个验证码
	bool Check( string usercode );		//检查是否匹配
};
