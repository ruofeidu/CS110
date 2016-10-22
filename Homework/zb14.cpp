#include <iostream>
using namespace std;

int DIV( int x, int y) {
	if ( y == 0 ) throw y; 
	return x / y;
}

int main(){
	try {
		cout << DIV(6,3) << endl;
		cout << DIV(10,0) << endl;
		cout << DIV(5,2) << endl;
	}

	catch ( int ) {
		cout << "divide by zero" << endl;
	}
	cout << "It's over!" << endl;

	system("pause");
	return 0;
}
