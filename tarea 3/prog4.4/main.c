#include <stdio.h>
#include <stdlib.h>

int f1(void);
int f2(void);
int f3(void);
int f4(void);

int k=3;

void main(void)
{
int I;
for(I=1;I<=3;I++);
{
    printf("\nEl resultado de la funsion f1:%d",f1());
    printf("\nEl resultado de la funsion f2:%d",f2());
    printf("\nEl resultado de la funsion f3:%d",f3());
    printf("\nEl resultado de la funsion f4:%d",f4());
}
}
int f1(void)
{
    k+=k;
    return (k);
}
int f2(void)
{
    int k=1;
    k++;
    return(k);
}
int f3(void)
{
    static int k=8;
    k+=2;
    return(k);
}
int f4(void)
{
    int k=5;
    k=k+::k;
    return(k);
}
