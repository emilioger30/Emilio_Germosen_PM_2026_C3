#include <stdio.h>
#include <stdlib.h>

const int TAM=10;

void lectura(int [][TAM],int);
void imprime(int [][TAM],int);

void main(void)
{
    int MAT[TAM][TAM];
    lectura(MAT,TAM);
    imprime(MAT,TAM);
}
void lectura(int A[][TAM],int F)
{
    int I,J;
    for(I=0;I<F;I++)
        for(J=0;J<F;J++)
    {
        printf("Ingrese el elemento %d %d:",I+1,J+1);
        scanf("%d",&A[1][J]);
    }
}
void imprime(int A[][TAM],int F)
{
    int I,J;
    for(I=0;I<F;I++)
        for(J=0;J<TAM;J++)
        if(I==J)
        printf("\nDiagonal%d %d",I,J,A[I][J]);
}
