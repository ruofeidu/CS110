#pragma once

class Memory
{
private:
	static const int CONTENT_SIZE_ = 100;
	int content_[CONTENT_SIZE_];
public:
	Memory(void);
	~Memory(void);
	int loadByte(int address); // TO DO
	void storeByte(int address, int data); // TO DO
};
