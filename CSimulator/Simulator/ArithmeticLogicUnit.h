#pragma once

class ArithmeticLogicUnit
{
	friend class Executor;
private:
	int accumulator_;
public:
	ArithmeticLogicUnit(void);
	~ArithmeticLogicUnit(void);
	void add(int);  // TO DO
	void sub(int); // TO DO
	void mul(int); // TO DO
	void div(int); // TO DO
	int getAccumulator(void); // TO DO
protected:
	void setAccumulator(int); // TO DO
};
