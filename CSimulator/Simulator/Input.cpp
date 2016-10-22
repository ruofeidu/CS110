#include <iostream>
#include "Input.h"

Input:: Input(void) {}
Input::~Input(void) {}

int Input::readInt() {
	int x;
	std::cin >> x;
	return x;
}