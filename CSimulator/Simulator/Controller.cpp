#include "Controller.h"
#include "Memory.h"

Controller:: Controller(void): program_counter_(0){}
Controller::~Controller(void){}

void Controller::initial(void) {
	instruction_register_ = 0;
	setPC(0);
}

void Controller::fetch(Memory MEM) {
	instruction_register_ = MEM.loadByte(program_counter_++);
}

void Controller::decode(int& opcode, int& operand)
{
	opcode = instruction_register_ / 100;
	operand = instruction_register_ % 100;
}

void Controller::setPC(int num) {
	program_counter_ = num + 40;
}