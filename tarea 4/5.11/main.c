#include <stdio.h>
#include <stdlib.h>

const int MAX=100;
void Lectura(int*,int);
int Binaria(int*,int,int);
void main(void)
{
int RES,ELE,TAM,VEC[MAX];
do
{
printf("Ingrese el tamano del arreglo:");
scanf("%d",&TAM);
}
while(TAM>MAX||TAM<1);
Lectura(VEC,TAM);
printf("\nIngrese el elemento a buscar:");
scanf("%d",&ELE);
RES=Binaria(VEC,TAM,ELE);
if(RES)
printf("\nEl elemento se encuentra en la posicion %d",RES);
else
printf("\nEl elemento no se encuentra en el arreglo");
}
void Lectura(int A[],int T)
{
int I;
for(I=0;I<T;I++)
{
printf("Ingrese el elemento %d:",I+1);
scanf("%d",&A[I]);
}
}
int Binaria(int A[],int T,int E)
{
int I=0,F=T-1,M,RES=0;
while(I<=F&&!RES)
{
M=(I+F)/2;
if(A[M]==E)
RES=M+1;
else if(E<A[M])
F=M-1;
else
I=M+1;
}
return RES;
}
