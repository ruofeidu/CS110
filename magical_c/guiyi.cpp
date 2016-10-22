#include <iostream>
#include <stdio.h>
 
int main()
{
    int a[5]={1,2,3,4,5};
 
    int *ptr=(int *)(&a+1);
    printf("%d\n",*(ptr-1));

    system("pause"); 
    return 0;
}
