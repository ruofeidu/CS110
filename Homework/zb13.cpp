#include "BookResource.h"

int main()
{
	BookResource BR;
	BR.readResource ( "input.txt" );
	BR.writeResource ( "output.txt" );
	//system("pause");
	return 0; 
}