#include "Reader.h"

reader::reader (int n, char *nm, char *d)
{
	No = n;
	strcpy( name, nm );
	strcpy( dept, d );
	borrowed = 0; 
	head = new List;
	head->data = 0;
	head->next = NULL;
}

void reader::Del( int x )
{
	List *p;
	p = head;
	while ( p->next != NULL )
	{
		if ( p->next->data == x )
			p->next = p->next->next;
		p = p->next;
	}
}

bool reader::Insert( int x, int index )
{
	List *p, *v;
	p = head;
	while (true)
	{
		if (index == 0)
		{
			v = new List;
			v->data = x;
			v->next = p->next;
			p->next = v;
			return true;
		}
		p = p->next;
		--index;
		if (p == NULL) return false;
	}
}

bool reader::Find( int x )
{
	List *p;
	p = head;
	if ( p == NULL ) return false;
	while ( p->next != NULL )
	{
		if ( p->next->data == x ) return true;
		p = p->next;
	}
	return false;
}

bool reader::bookBorrow( int id )
{
	if ( Find(id) ) return false;
	if ( borrowed == MAX ) return false; else 
	{
		Insert( id, 0 );
		++borrowed;
	}
	return true;
}

bool reader::bookReturn( int id )
{
	if ( Find( id ) )
	{
		Del( id );
		--borrowed;
		return true;
	} else return false;
}

void reader::show()
{
	List *p;
	p = head->next;
	cout << endl;
	cout << "您当前所借的" << borrowed << "本书ID分别为：" << endl; 
		
	p = head->next;
	while ( p != NULL )
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}


