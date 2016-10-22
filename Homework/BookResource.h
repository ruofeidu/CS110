#pragma once
#pragma once
#include "Book.h"

struct BookList
{
	Book data;
	BookList *next;
};

class BookResource
{
private:
	BookList *Head;
	int Total;

public:
	BookResource ( void ) { Head = new BookList; Head->next = NULL; }
	~BookResource () {};
	void readResource( char *filename );
	void writeResource( char *filename );
};

