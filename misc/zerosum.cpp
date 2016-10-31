/*
ID: starea1
PROG: zerosum
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream fin ( "zerosum.in" );
ofstream fout ( "zerosum.out" );

const int maxlongint = 1000000000; 
const int MAXN = 10 + 1; 
int n, m, i, j, opn, sum; 
char f[MAXN];
char opt; 

void balance(){
    switch (opt) {
        case '+' : sum += opn; break; 
        case '-' : sum -= opn; break; 
    }
}

void RFS( int h ){
    int Ropt, Ropn, Rsum; 

    if ( h > n ) {
        balance();         
        if ( sum == 0 ){ 
            fout << 1; 
            for (int i = 2; i <= n; ++i )
                fout << f[i] << i;
            fout << endl; 
        }
        return; 
    }
    Ropt = opt; Ropn = opn; Rsum = sum;
    
    //CASE _
    opt = Ropt; opn = Ropn; sum = Rsum; 
    f[h] = ' ';
    if ( opt == ' ') sum = sum * 10 + h; else opn = opn * 10 + h; 
    RFS( h + 1 ); 
    
    //CASE +
    opt = Ropt; opn = Ropn; sum = Rsum;  
    balance();
    f[h] = '+'; opt = '+'; opn = h;
    RFS( h + 1 ); 
    
    //CASE -
    opt = Ropt; opn = Ropn; sum = Rsum; 
    balance(); 
    f[h] = '-'; opt = '-'; opn = h; 
    RFS( h + 1 ); 
    
    //Backup
    opt = Ropt; opn = Ropn; sum = Rsum;
}

int main(){   
    fin >> n; 
    for ( i = 0; i <= n; ++i ) f[i] = '_'; 
    sum = 1; opn = 1; opt = ' '; 
    RFS(2); 
    return 0;  
}
