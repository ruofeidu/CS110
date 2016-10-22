#pragma once
class MachineCode;
class Memory;

class CodeLoader
{
public:
	CodeLoader(void);
	~CodeLoader(void);

	static void load(MachineCode, Memory&); // TO DO, load machine code from the MachineCode class to memory
};
