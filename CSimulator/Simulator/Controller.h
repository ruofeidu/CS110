#pragma once
class Memory;

class Controller
{
private:
	int program_counter_;
	int instruction_register_;
public:
	Controller(void);
	~Controller(void);
	void initial(void); //TO DO, initial everything you need to run a program, such as PC...
	void fetch(Memory); //TO DO, fetch instruction from memory to instruction register
	void decode(int&, int&); //TO DO, decode the instruction in the register, just get opcode and operand
	void setPC(int); //TO DO, set the program_counter
};
