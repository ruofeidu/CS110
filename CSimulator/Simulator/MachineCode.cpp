#include <iostream>
#include "MachineCode.h"

MachineCode:: MachineCode(void):size_(0), next_instruction_(0) {
	memset(instructions_,0,sizeof(instructions_));
}
MachineCode::~MachineCode(void) {}

void MachineCode::putInstruction(int instruction) {
	instructions_[size_++] = instruction;
}


int MachineCode::nextInstruction() {
	return instructions_[ next_instruction_++ ] ;
}

int MachineCode::getSize() {
	return size_;
}
