#pragma once

class MachineCode
{
	static const int MAX_SIZE_ = 100;
	int instructions_[MAX_SIZE_];
	int size_, next_instruction_;
public:
	MachineCode(void);
	~MachineCode(void);

	void putInstruction(int); // TO DO
	int nextInstruction(void); // TO DO
	int getSize(void); // TO DO
};
