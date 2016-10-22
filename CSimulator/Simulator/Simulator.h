#pragma once
#include "Input.h"
#include "Output.h"
#include "Controller.h"
#include "ArithmeticLogicUnit.h"
#include "Memory.h"

class Simulator
{
friend class Executor;
private:
	Controller controller_;
	Memory memory_;
	ArithmeticLogicUnit alu_;
	Input input_;
	Output output_;
	int operand_, opcode_;
public:
	Simulator(void);
	~Simulator(void);

	void runProgram(void); //done, simulate the computer run
	Memory& getMemory(); //in fact, this is not a good idea
	ArithmeticLogicUnit& getAlu();
};
