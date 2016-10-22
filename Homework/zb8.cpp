#include <iostream>
#include "Book.h"
using namespace std;

void Insert( Book x, int index );
void Print();

struct List
{
	Book data;
	List *next;
};

List *head;

bool insert( Book x, int index )
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
			return(true);
		}
		p = p->next;
		--index;
		if (p == NULL) return(false);
	}
}

void Print()
{
	List *p;
	p = head->next;
	while ( p != NULL )
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{
	int i, n, index;
	Book newbook;
	List *p, *v;

	v = head = new List;

	cout << "→请输入链表开始时有多少本书？";
	cin >> n;

	for ( i = 0; i < n; ++i )
	{
		cin >> newbook;
		p = new List;
		p->data = newbook;
		v->next = p;
		v = p;
	}
	v->next = NULL;

	cout << "→请输入您在第几本书后插入新书？";
	cin >> index;
	cout << "→请输入新书~";
	cin >> newbook;
	if (insert( newbook, index )) cout << "●新书插入成功！" << endl;
		else cout << "◎新书插入失败！可能是您输入的序号有误！" << endl;

	Print();
	
	system("pause");
	return(0);
}
