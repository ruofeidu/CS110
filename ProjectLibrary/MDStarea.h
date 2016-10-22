/***************************************************
  �ļ�: MDStarea.cpp
  ���ã�Login.cpp Input.cpp Output.cpp
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��MD5�����ϸı��MDStarea
  ���룺1024λ����
***************************************************/
#pragma once
#include <string>

typedef unsigned char    UINT1;
typedef unsigned char *  POINTER;
typedef unsigned short   UINT2;
typedef unsigned long    UINT4;


/* MD5 context */
typedef struct {
    UINT4    state[4];			// ״̬ (ABCD)
    UINT4    count[2];			// �ֳ�, ȡģ 2 ^ 64
    UINT1    buffer[64];        // ���뻺��
} MD5_CTX;

void MD5Init(MD5_CTX*);							//��ʼ��
void MD5Update(MD5_CTX *, UINT1 *,    UINT4);	//ÿ�ִθ���
void MD5Final(UINT1 [16], MD5_CTX *);			//�ϲ�
std::string MDSResult(UINT1 [16]);				//���ؽ��
std::string MDStarea(std::string source);		//MDStarea
std::string MD6(std::string source);			//MD6
