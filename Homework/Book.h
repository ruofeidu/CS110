/***************************************************
  File:  Book.h
  Student Name:
  Project:
  Class:
  
  ... and any additional header info if necessary

***************************************************/

/*
 * This file contains code, originated from "C++ Primer, Fourth Edition".
 * Revised by Jermaine.
*/ 

#ifndef _BOOK_H        //Header defination Format: <PROJECT>_<PATH>_<FILE>_H
#define _BOOK_H        //Please modify it.

// Definition of Book class and related functions goes here

#include <iostream>
#include <string>
using namespace std;

class Book {
      // friend binary operator: must declare a parameter for each operand
      friend Book operator + (const Book&, const Book&); //addition on copy number
      friend bool operator == (const Book&, const Book&);
      friend bool operator < (const Book&, const Book&); //compare copy number
	  friend bool operator > (const Book&, const Book&);
	  friend bool operator <= (const Book&, const Book&);
	  friend bool operator >= (const Book&, const Book&);
      // iostream overload definition
      friend std::istream& operator>>(std::istream&, Book&);
      friend std::ostream& operator<<(std::ostream&, const Book&);
      // TO-DO other friend members as above
      
public:
    // added constructors to initialize from a string or an istream
    Book(): borrowed(0), copy(0), authornum(-1), id(0) { isbn[0] = '\0'; kind[0] = '\0'; title[0] = '\0'; }
    Book(std::istream &is) { is >> *this; }
    // TO-DO other constructors as above
    
public:
    // operations on Book objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Book & operator+=(const Book&);
	Book & operator++();
	Book operator++(int);
	Book & operator--();
	Book operator--(int);
	Book& operator = (const Book&);
    // TO-DO other members as above
    
public:
    // operations on Book objects
    bool same_isbn(const Book &rhs) const 
        { return strcmp(isbn, rhs.getIsbn()) == 0; }
        
    const char * getIsbn() const                //get isbn info
        { return isbn; }
    const int getCopy() const                   //get copy info
        { /*TO-DO*/ }
    const int getBorrowed() const               //get borrowed info
        { /*TO-DO*/ }
        
    void setIsbn(const char i[])                //set isbn info
        { /*TO-DO*/ }
    void setCopy(const int c)                   //set copy info
        { /*TO-DO*/ }
    void setBorrowed(const int b)               //set borrowed info
        { /*TO-DO*/ }
    // default constructor needed to initialize members of built-in type
    

private:
    // TO-DO private functions if necessary

private:
    static const int ISBN_LENGTH = 20;
	static const int TITLE_LENGTH = 20;
	static const int AUTHOR_LENGTH = 20;
	static const int KIND_LENGTH = 5;
	static const int AUTHOR_NUM = 5;
	
private:
    char isbn[ISBN_LENGTH + 1];         //isbn code for the book item
    char title[TITLE_LENGTH];
	char kind[KIND_LENGTH];
	char author[AUTHOR_NUM][AUTHOR_LENGTH];
	int borrowed;                       //the number of books borrowed
    int copy;                           //the number of copies of books remained
	int authornum;
	int id;
	
    // TO-DO other members as above

};

/* member function bodies below. */
inline 
bool operator==(const Book &a, const Book &b){
    // must be made a friend of Book
    return (a.isbn == b.isbn && a.id == b.id && a.title == b.title && a.copy == b.copy && a.borrowed == b.borrowed
		&& a.authornum == b.authornum && a.author == b.author && a.kind == b.kind);
}

inline
bool operator< (const Book &lhs, const Book &rhs) {
    return lhs.copy < rhs.copy;
}
bool operator> (const Book &lhs, const Book &rhs) {
    return lhs.copy > rhs.copy;
}
bool operator<= (const Book &lhs, const Book &rhs) {
    return lhs.copy <= rhs.copy;
}
bool operator>= (const Book &lhs, const Book &rhs) {
    return lhs.copy >= rhs.copy;
}

Book &Book::operator++()
{
	++copy;
	return *this;
}

Book Book::operator++(int x)
{
	Book tmp = *this;
	++copy;
	return tmp;
}

Book &Book::operator--()
{
	if (copy > 0) --copy; else std::cout << "复本数不能为负，操作无效！" << std::endl;
	return *this;
}

Book Book:: operator--(int x)
{
	Book tmp = *this;
	if (copy == 0) std::cout << "复本数不能为负，操作无效！" << std::endl; else --copy;
	return tmp;
}

// assumes that both objects refer to the same isbn
inline
Book& Book::operator += (const Book& rhs) {
	if ( strcmp(isbn, rhs.isbn) == 0 )
		copy += rhs.copy;
	else
		cout << "两本书ISBN不同，不能进行副本累加操作！" << endl;
	return *this;
}

// assumes that both objects refer to the same isbn
inline
Book operator + (const Book& lhs, const Book& rhs){
    Book ret;                        // define a local object that we'll return
    for(int i = 0; i < strlen(lhs.isbn) + 1; ++i)   // set isbn info
        ret.isbn[i] = lhs.isbn[i];            
    ret.copy = lhs.copy + rhs.copy;  // add the copy info of both books
    return ret;                      // return ret by value
}

inline
Book& Book::operator = (const Book& a)
{
	Book b;
	for (int i = 0; i < strlen(a.isbn); ++i)
		b.isbn[i] = a.isbn[i];
	for (int i = 0; i < strlen(a.title); ++i)
		b.title[i] = a.title[i];
	for (int i = 0; i < strlen(a.kind); ++i)
		b.kind[i] = a.kind[i];
	for (int i = 0; i < a.authornum; ++i)
		for (int j = 0; j < strlen(a.author[i]); ++j)
			b.author[i][j] = a.author[i][j];

	b.borrowed = a.borrowed;
	b.copy = a.copy;
	b.id = a.id;
	b.authornum = a.authornum;
	return b;
}

using std::istream; using std::ostream;

inline
istream& operator>>(istream& in, Book& s) {
    std::cout << "请输入ISBN(最大20字符长度)："; 
    in >> s.isbn;
    std::cout << "请输入复本数目：";
    in >> s.copy;
    // check that the inputs succeeded
    if (!in)
        s = Book();  // input failed: reset object to default state
    return in;
}

inline
ostream& operator<<(ostream& out, const Book& s) {
    out << "ISBN: " << s.isbn << "\t借出: " << s.borrowed << "\t剩余: " 
        << s.copy;
    return out;
}

#endif
