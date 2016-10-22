#include "Simulator.h"
#include "Executor.h"
#include <iostream>
using namespace std;

Simulator::Simulator(void)
{
}

Simulator::~Simulator(void)
{
}

void Simulator::runProgram(void) {
	controller_.initial();
	bool halt = false;
	while (!halt) { // every program should end with the HALT command
		controller_.fetch(memory_);
		controller_.decode(opcode_, operand_);
		halt = Executor::execute(*this);
	}
}

Memory& Simulator::getMemory(void) {
	return memory_;
}

ArithmeticLogicUnit& Simulator::getAlu(void) {
	return alu_;
}
