#pragma once
class MachineCode; // forward declaration

class Assembler
{
private:
	static const int MAX_INSTRUCTION_SIZE_ = 100;
	static const int MAX_INSTRUCTION_LENGTH_ = 20;
	char instructions_[MAX_INSTRUCTION_SIZE_][MAX_INSTRUCTION_LENGTH_];
	int size_;
public:
	Assembler(void);
	~Assembler(void);

	void loadSourceFile(char file_name[]); // TO DO, read file from disk
	MachineCode convert(void); // TO DO, convert to machine code, save it in MachineCode class
};
