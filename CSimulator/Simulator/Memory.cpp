#include <iostream>
#include "Memory.h"

Memory:: Memory(void) { memset(content_,0,sizeof(content_)); }
Memory::~Memory(void) { }

int Memory::loadByte(int address) {
	return(content_[address]);	
}

void Memory::storeByte(int address, int data) {
	content_[address] = data;	
}
