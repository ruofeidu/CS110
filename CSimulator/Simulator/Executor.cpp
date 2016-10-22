#include "Executor.h"
#include "Simulator.h"

Executor:: Executor(void)
{
}

Executor::~Executor(void)
{
}


bool Executor::execute(Simulator& SIM)
{
	switch(SIM.opcode_) {
	case 10:	SIM.memory_.storeByte( SIM.operand_, SIM.input_.readInt() ); break;
	case 11:	SIM.output_.writeInt( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 20:	SIM.alu_.setAccumulator( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 21:	SIM.memory_.storeByte( SIM.operand_, SIM.alu_.getAccumulator() ); break;
	case 30:	SIM.alu_.add( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 31:	SIM.alu_.sub( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 32:	SIM.alu_.mul( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 33:	SIM.alu_.div( SIM.memory_.loadByte( SIM.operand_ ) ); break;
	case 40:	SIM.controller_.setPC( SIM.operand_ ); break;
	case 41:	if ( SIM.alu_.getAccumulator() != 0 ) SIM.controller_.setPC( SIM.operand_ ); break;
	case 42:	if ( SIM.alu_.getAccumulator() == 0 ) SIM.controller_.setPC( SIM.operand_ ); break;
	case 43:	return true; break;
	}
	return(false);
}