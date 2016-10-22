#include "CodeLoader.h"
#include "MachineCode.h"
#include "Memory.h"

CodeLoader:: CodeLoader(void){}
CodeLoader::~CodeLoader(void){}

void CodeLoader::load(MachineCode MKI, Memory& MEM) {
	for (int i = 0; i < MKI.getSize(); ++i) {
		MEM.storeByte(i + 40, MKI.nextInstruction() );
	}
}