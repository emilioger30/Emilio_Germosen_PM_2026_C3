#include <stdio.h>
#include <stdlib.h>

void f1(void);
int k=5;

void main(void)
{
    int I;
    for(I=1;I<=3;I++)
        f1();
}
void f1(void)
{
    int k=2;
    k+=k;
    printf("\n\nEl valor de la variable local es:%d",k);
    ::k = ::k+k;
    printf("\nEl valor de la variable global es:%d",::k);
}
