#include <iostream>
#include "Output.h"

Output:: Output(void) {}
Output::~Output(void) {}

void Output::writeInt(int ans)
{
	std::cout << ans << std::endl;
}