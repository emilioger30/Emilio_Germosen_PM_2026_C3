#include <stdio.h>
#include <string.h>

/* Escuela.
   El programa genera informacion importante de los alumnos de una escuela.
*/

typedef struct
{
    char mat[20];   /* Materia */
    int pro;        /* Promedio */
} matpro;

typedef struct
{
    int matri;      /* Matricula */
    char nom[20];   /* Nombre del alumno */
    matpro cal[5];  /* Arreglo de estructuras matpro */
} alumno;

void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int);
void F3(alumno *, int);

void main(void)
{
    alumno ALU[50];
    int TAM;

    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1);

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
}

void Lectura(alumno A[], int T)
{
    int I, J;

    for (I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);

        printf("\nMatricula: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);

        printf("Nombre: ");
        gets(A[I].nom);

        for (J = 0; J < 5; J++)
        {
            printf("Materia %d: ", J + 1);
            gets(A[I].cal[J].mat);

            printf("Promedio de %s: ", A[I].cal[J].mat);
            scanf("%d", &A[I].cal[J].pro);
            fflush(stdin);
        }
    }
}

void F1(alumno A[], int T)
{
    int I, J;
    float SUM, PRO;

    printf("\n\nPromedio de cada alumno");

    for (I = 0; I < T; I++)
    {
        SUM = 0;

        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;

        PRO = SUM / 5;

        printf("\nMatricula: %d\tPromedio: %.2f",
               A[I].matri, PRO);
    }
}

void F2(alumno A[], int T)
{
    int I, J;
    float SUM, PRO;

    printf("\n\nAlumnos con promedio mayor a 9");

    for (I = 0; I < T; I++)
    {
        SUM = 0;

        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;

        PRO = SUM / 5;

        if (PRO > 9)
            printf("\nMatricula del alumno: %d",
                   A[I].matri);
    }
}

void F3(alumno A[], int T)
{
    int I;
    float SUM = 0.0;

    for (I = 0; I < T; I++)
        SUM += A[I].cal[3].pro;

    SUM = SUM / T;

    printf("\n\nPromedio de la cuarta materia: %.2f", SUM);
}
