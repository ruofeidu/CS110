/*
ID: starea1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int a[5001], b[5001], n;
int qsort(int l, int r, int a[5001])
{
    int i(l), j(r), k(a[(l + r) / 2]);
    do
    {
      while (i <= j && a[i] < k) i++;
      while (i <= j && a[j] > k) j--;
      if (i <= j)
      {
         a[0] = a[i]; a[i] = a[j]; a[j] = a[0];
         i++; j--;
      }
    } while (i <= j);
    if (l < j) qsort(l, j, a);
    if (i < r) qsort(i, r, a);
}
int main(void)
{
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");
    fin >> n;
    for (int i = 1; i <= n; i++)
      fin >> a[i] >> b[i];
    qsort(1,n,a);
    qsort(1,n,b);
    int l(a[1]), r(b[1]), point(1), ans1(0), ans2(0);
    do
    {
        while (point < n && a[point + 1] <= r) { point++; r = b[point];}
        if (r - l > ans1) ans1 = r - l;
        point++; 
        if (point <= n) {l = a[point]; if (l - r > ans2) ans2 = l - r; r = b[point];}
    } while (point <= n);
    fout << ans1 << " " << ans2 << endl;
    return 0;
}
