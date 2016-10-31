/*
ID: starea1
PROG: ttwo
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "ttwo.in" );
ofstream fout ( "ttwo.out" );

const int WARN = 10000000; 
const int MAXN = 11; 
const int n = 10; 
const int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; 
int i, j, cy, cx, cd, fy, fx, fd, ans; 
bool g[MAXN][MAXN];
string s; 

int main(){   
    memset( g, false, sizeof(g) ); 
    for ( i = 1; i <= n; ++i ){
        fin >> s; 
        for ( j = 1; j <= n; ++j ){
            switch (s[j-1]) {
                case '*': g[i][j] = false; break;
                case '.': g[i][j] = true; break; 
                case 'C': g[i][j] = true; cy = i; cx = j; cd = 0; break; 
                case 'F': g[i][j] = true; fy = i; fx = j; fd = 0; break; 
            }
        }
    }
    
    ans = 0; 
    while ((cy != fy) || (cx != fx)) { 
        ++ans; 
        if (g[cy+d[cd][0]][cx+d[cd][1]]){
            cy += d[cd][0]; 
            cx += d[cd][1]; 
        } else {
            cd = (cd + 1) % 4; 
        }
        if (g[fy+d[fd][0]][fx+d[fd][1]]){
            fy += d[fd][0]; 
            fx += d[fd][1]; 
        } else {
            fd = (fd + 1) % 4; 
        }
        if (ans > WARN){
            ans = 1; 
            break; 
        }
    } 
    
    fout << ans-1 << endl; 
    return 0;  
}
