#include "ArithmeticLogicUnit.h"

ArithmeticLogicUnit::ArithmeticLogicUnit(void){ accumulator_ = 0; }
ArithmeticLogicUnit::~ArithmeticLogicUnit(void){ }

void ArithmeticLogicUnit::add(int x){
	accumulator_ += x;
}

void ArithmeticLogicUnit::sub(int x){
	accumulator_ -= x;
}


void ArithmeticLogicUnit::mul(int x){
	accumulator_ *= x;
}

void ArithmeticLogicUnit::div(int x){
	accumulator_ /= x;
}

int ArithmeticLogicUnit::getAccumulator(){
	return accumulator_;
}

void ArithmeticLogicUnit::setAccumulator(int num){
	accumulator_  = num; 
}