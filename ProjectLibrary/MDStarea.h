/***************************************************
  文件: MDStarea.cpp
  引用：Login.cpp Input.cpp Output.cpp
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：MD5基础上改编的MDStarea
  构想：1024位加密
***************************************************/
#pragma once
#include <string>

typedef unsigned char    UINT1;
typedef unsigned char *  POINTER;
typedef unsigned short   UINT2;
typedef unsigned long    UINT4;


/* MD5 context */
typedef struct {
    UINT4    state[4];			// 状态 (ABCD)
    UINT4    count[2];			// 字长, 取模 2 ^ 64
    UINT1    buffer[64];        // 输入缓冲
} MD5_CTX;

void MD5Init(MD5_CTX*);							//初始化
void MD5Update(MD5_CTX *, UINT1 *,    UINT4);	//每轮次更新
void MD5Final(UINT1 [16], MD5_CTX *);			//合并
std::string MDSResult(UINT1 [16]);				//返回结果
std::string MDStarea(std::string source);		//MDStarea
std::string MD6(std::string source);			//MD6
