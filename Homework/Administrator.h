#pragma once
#include <string>
#include "Reader.h"

class Administrator : public Teacher
{
private:
	string Password;

public:
	Administrator( int n, char *nm, char *d ): Teacher(n, nm, d) { MAX = 10; }
	void ModifyPW( string x );

};
