// ComputerSystem.cpp : 定义控制台应用程序的入口点。
//

#include "Assembler.h"
#include "Simulator.h"
#include "CodeLoader.h"
#include "MachineCode.h" // can't move out
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Assembler assembler;
	Simulator simulator;
	
	assembler.loadSourceFile("example.txt");
	CodeLoader::load(assembler.convert(), simulator.getMemory());
	simulator.runProgram();

	for (int i=0; i<100; ++i)
		cout << simulator.getMemory().loadByte(i) << endl;
		cout << simulator.getAlu().getAccumulator() << endl;

	return 0;
}
