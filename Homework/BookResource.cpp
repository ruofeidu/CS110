#include <fstream>
#include "BookResource.h"
using namespace std;

void BookResource::readResource( char *filename )
{
	BookList *v;

	ifstream fin ( filename );
	fin >> Total;

	for ( int i = 0; i < Total; ++i )
	{
		v = new BookList;
		fin >> v->data;
		v->next = Head->next;
		Head->next = v;
	}
	fin.close ();
}

void BookResource::writeResource( char *filename )
{
	BookList *p;

	ofstream fout ( filename );
	p = Head->next;
	while ( p != NULL )
	{
		fout << p->data << endl;
		p = p->next;
	}
	fout << endl;
	fout.close ();
}