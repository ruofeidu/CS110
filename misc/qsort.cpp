#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void quicksort(int l, int r, int a[]){
    int i=l, j=r, x=a[(l+r)>>1];
    do{
        while (a[i]<x) ++i;
        while (a[j]>x) --j;
        if (i<=j) swap(a[i++],a[j--]);
    } while (i<j);
    if (l<j) quicksort(l,j,a);
    if (i<r) quicksort(i,r,a);
}

int main(){
    int i,n;
    cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; ++i) cin>>a[i]; 
    quicksort(0,n,a);
    for (i = 0; i < n; ++i) cout<<a[i]<<' '; 
    system("pause");
    return 0;  
}
