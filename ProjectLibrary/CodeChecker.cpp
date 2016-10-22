#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "CodeChecker.h"
using namespace std;

//随机整数生成函数
int CodeMachine::Random( int x ){
	return ( rand() * x / (RAND_MAX + 1) );
}


CodeMachine::CodeMachine (){
	srand( time(NULL) );

	//每个像素点图片
	pic[0] = "┌┍┎┏┌┍┎┏";
	pic[1] = "┐┑┒┓┐┑┒┓";
	pic[2] = "└┕┖┗└┕┖┗";
	pic[3] = "┘┙┚┛┘┙┚┛";
	pic[4] = "│┃┆┇┋┊│┃";
	pic[5] = "─━┄┅┈┉─━";
	pic[6] = "├┝┞┟┠┡┢┣";
	pic[7] = "┤┥┦┧┨┩┪┫";
	pic[8] = "                ";

	//每个数字对应“图片”
	pos[0][0][0] = 0; pos[0][0][1] = 1;
	pos[0][1][0] = 4; pos[0][1][1] = 4;
	pos[0][2][0] = 2; pos[0][2][1] = 3;

	pos[1][0][0] = 8; pos[1][0][1] = 4;
	pos[1][1][0] = 8; pos[1][1][1] = 4;
	pos[1][2][0] = 8; pos[1][2][1] = 4;

	pos[2][0][0] = 5; pos[2][0][1] = 1;
	pos[2][1][0] = 0; pos[2][1][1] = 3;
	pos[2][2][0] = 2; pos[2][2][1] = 5;

	pos[3][0][0] = 5; pos[3][0][1] = 1;
	pos[3][1][0] = 5; pos[3][1][1] = 7;
	pos[3][2][0] = 5; pos[3][2][1] = 3;

	pos[4][0][0] = 4; pos[4][0][1] = 4;
	pos[4][1][0] = 2; pos[4][1][1] = 7;
	pos[4][2][0] = 8; pos[4][2][1] = 4;

	pos[5][0][0] = 0; pos[5][0][1] = 5;
	pos[5][1][0] = 2; pos[5][1][1] = 1;
	pos[5][2][0] = 5; pos[5][2][1] = 3;

	pos[6][0][0] = 0; pos[6][0][1] = 5;
	pos[6][1][0] = 6; pos[6][1][1] = 1;
	pos[6][2][0] = 2; pos[6][2][1] = 3;

	pos[7][0][0] = 5; pos[7][0][1] = 1;
	pos[7][1][0] = 8; pos[7][1][1] = 4;
	pos[7][2][0] = 8; pos[7][2][1] = 4;

	pos[8][0][0] = 0; pos[8][0][1] = 1;
	pos[8][1][0] = 6; pos[8][1][1] = 7;
	pos[8][2][0] = 2; pos[8][2][1] = 3;

	pos[9][0][0] = 0; pos[9][0][1] = 1;
	pos[9][1][0] = 2; pos[9][1][1] = 7;
	pos[9][2][0] = 5; pos[9][2][1] = 3;
}

//产生验证码
void CodeMachine::Generate( int x ){
	code = "";
	
	for ( int i = 0; i < x; ++i ){
		num[i] = Random(10);
		chr[i] = '0' + num[i]; 
		code = code + chr[i];
	}
	
	//Debug:
	//num[0] = num[1] = num[2] = num[3] = 0;
	//code = "0000";
}

//显示数字
void CodeMachine::ShowFigure( int x, int r ){
	int i = Random( 8 );
	cout << pic[ pos[x][r][0] ].substr ( i * 2, 2 ) << pic[ pos[x][r][1] ].substr ( i * 2, 2 );

}

//显示图像
void CodeMachine::ShowPic(){
	//Debug: for ( int i = 0; i < 4; ++i ) cout << num[i]; cout << endl;

	for ( int r = 0; r < 3; ++r ){
		cout << "☆ ";
		for ( int i = 0; i < 4; ++i ) {
			ShowFigure( num[i], r );
		}
		cout << endl;
	}	
}

bool CodeMachine::Check( string usercode ){
	
	if ( code == usercode )
		return true;	
	else 
		return false;
}