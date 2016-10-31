/*
ID: starea1
PROG: sort3
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

ifstream fin ( "sort3.in" );
ofstream fout ( "sort3.out" );

const int maxlongint = 10000000; 
const int MAXN = 1000 + 1;   
int x,y,z,xy,yx,xz,zx,yz,zy,i,n,ans;
int a[MAXN]; 

int main(){   
    fin >> n; 
    for ( i = 0; i < n; ++i ) {
        fin >> a[i];
        if (a[i]==1) ++x; else if(a[i]==2) ++y; else ++z; 
    }
    
    for ( i = 0; i < x; ++i )   if (a[i]==2) ++xy; else if (a[i]==3) ++xz; 
    for ( i = x; i < x+y; ++i ) if (a[i]==1) ++yx; else if (a[i]==3) ++yz; 
    for ( i = x+y; i < n; ++i ) if (a[i]==1) ++zx; else if (a[i]==2) ++zy; 
    
    ans = min(xy, yx) + min(xz, zx) + min(yz, zy); 
    xy = abs(xy-yx); 
    xz = abs(xz-zx);
    yz = abs(yz-zy); 
    ans += 2*min(xy, min(xz, yz));  
    
    fout << ans << endl; 
    return 0;  
}
