#include <fstream>
#include <iostream>
#include "Assembler.h"
#include "MachineCode.h"

Assembler:: Assembler(void) : size_(0) {
	memset(instructions_,0,sizeof(instructions_));
}

Assembler::~Assembler(void) {}

void Assembler::loadSourceFile(char file_name[])
{
	std::ifstream fin ( file_name );

	while (fin.peek() != EOF) {	
		fin.getline(instructions_[size_++],30);
	}

	fin.close ();
}

MachineCode Assembler::convert(void)
{
	MachineCode MKI;
	int opcode = 0, operand = 0, pos = 0;

	for (int i = 0; i < size_; ++i) {
		if (instructions_[i][0] == 'r'){	//read
			opcode = 1000;
			pos = 5;
		} else
		if (instructions_[i][0] == 'w'){		//write	
			opcode = 1100;
			pos = 6;
		} else
		if (instructions_[i][0] == 'l'){		//load
			opcode = 2000;
			pos = 5;
		} else
		if (instructions_[i][0] == 's' && instructions_[i][1] == 't'){	//store
			opcode = 2100;
			pos = 6;
		} else
		if (instructions_[i][0] == 'a'){ //add
			opcode = 3000;
			pos = 4;
		} else
		if (instructions_[i][0] == 's' && instructions_[i][1] == 'u'){	//sub
			opcode = 3100;
			pos = 4;
		} else
		if (instructions_[i][0] == 'm'){ // mul
			opcode = 3200;
			pos = 4;
		} else
		if  (instructions_[i][0] == 'd'){ // div
			opcode = 3300;
			pos = 4;
		} else
		if (instructions_[i][0] == 'b'  && instructions_[i][2] == ' ') { // br
			opcode = 4000;
			pos = 3;
		} else
			if (instructions_[i][0] == 'b'  && instructions_[i][2] == 'n') { // brn
			opcode = 4100;
			pos = 4;
		} else
		if (instructions_[i][0] == 'b'  && instructions_[i][2] == 'z') { // brz
			opcode = 4200;
			pos = 4;
		} else { //halt
			opcode = 4300;
		}; 

		if (opcode != 4300)
			operand = (instructions_[i][pos] - '0') * 10 + (instructions_[i][pos + 1] - '0');
		else
			operand = 0;
		
		MKI.putInstruction( opcode + operand );
	}
	return(MKI);
}
