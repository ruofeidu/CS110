#include <iostream>
using namespace std;

void gcd( int a, int b, int &d, int &x, int &y ){
    if ( b == 0 ) {
        d = a; 
        x = 1; 
        y = 0;
        return; 
    }
    gcd( b, a % b, d, y, x );
    y -= x * ( a / b );
}

int main(){
    int d, x, y, a, b;
   // a = 1215;
    //b = 2755;
    
    a = 792 ;
    b = 13;
    
    do{
    cin >> a >> b;
    gcd( a, b, d, x, y ); 
    cout << d << ' ' << x << ' ' << y << endl; 
    
    system("pause"); 
    } while (true);
    return 0; 
}
