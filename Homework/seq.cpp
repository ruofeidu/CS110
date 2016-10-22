#include <iostream>
#include "seq.h"
using namespace std;

const int maxl = 1000;
char label[maxl] = "lable";
int index = 0;

void SetLabel( const char* str)
{
	strcpy(label, str);
}

void SetInitNumber( int num )
{
	index = num;
}

char * GetNextLabel()
{
	char *str = new char[strlen(label) + 20];
	sprintf(str, "%s%d", label, index);
	++index;
	return str;
}
