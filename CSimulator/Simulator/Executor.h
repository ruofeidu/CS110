#pragma once
class Simulator;

class Executor
{
public:
	Executor(void);
	~Executor(void);
	static bool execute(Simulator&);
};
