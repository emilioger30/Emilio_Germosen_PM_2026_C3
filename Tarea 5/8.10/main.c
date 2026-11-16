#include <stdio.h>
#include <string.h>

/* Vendedores.
   El programa maneja informacion sobre las ventas que realizan los
   vendedores de articulos domesticos de una importante empresa
   de la Ciudad de Mexico.
*/

typedef struct
{
    char noba[10];   /* Nombre del banco */
    char nucu[10];   /* Numero de cuenta */
} banco;

typedef union
{
    banco che;      /* Cheque */
    banco nomi;     /* Nomina */
    char venta;     /* Ventanilla */
} fpago;

typedef struct
{
    char cnu[20];   /* Calle y numero */
    char col[20];   /* Colonia */
    char cp[5];     /* Codigo Postal */
    char ciu[15];   /* Ciudad */
} domicilio;

typedef struct
{
    int num;           /* Numero de vendedor */
    char nom[20];      /* Nombre del vendedor */
    float ven[12];     /* Ventas del ano */
    domicilio domi;
    float sal;         /* Salario mensual */
    fpago pago;
    int cla;           /* Clave forma de pago */
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

void main(void)
{
    vendedor VENDEDORES[100];
    int TAM;

    do
    {
        printf("Ingrese el numero de vendedores: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);

    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA");
}

void Lectura(vendedor A[], int T)
{
    int I, J;

    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d", I + 1);

        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);

        printf("Nombre del vendedor: ");
        fflush(stdin);
        gets(A[I].nom);

        printf("Ventas del ano:\n");

        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        printf("Domicilio del vendedor:\n");

        printf("\tCalle y numero: ");
        fflush(stdin);
        gets(A[I].domi.cnu);

        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].domi.col);

        printf("\tCodigo Postal: ");
        fflush(stdin);
        gets(A[I].domi.cp);

        printf("\tCiudad: ");
        fflush(stdin);
        gets(A[I].domi.ciu);

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (Banco-1 Nomina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);

        switch (A[I].cla)
        {
            case 1:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.che.noba);

                printf("\tNumero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.che.nucu);
                break;

            case 2:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.nomi.noba);

                printf("\tNumero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.nomi.nucu);
                break;

            case 3:
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVentas Totales de los Vendedores\n");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        printf("\nNumero de vendedor: %d", A[I].num);
        printf("\nVentas totales: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVendedores con Ventas > 1,500,000\n");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM > 1500000.00)
        {
            A[I].sal *= 1.05;

            printf("\nNumero de empleado: %d", A[I].num);
            printf("\nVentas: %.2f", SUM);
            printf("\nNuevo salario: %.2f\n", A[I].sal);
        }
    }
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVendedores con Ventas < 300,000\n");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM < 300000.00)
        {
            printf("\nNumero de empleado: %d", A[I].num);
            printf("\nNombre: %s", A[I].nom);
            printf("\nVentas: %.2f\n", SUM);
        }
    }
}

void F4(vendedor A[], int T)
{
    int I;

    printf("\n\t\tVendedores con Cuenta en el Banco\n");

    for (I = 0; I < T; I++)
    {
        if (A[I].cla == 1)
        {
            printf("\nNumero de vendedor: %d", A[I].num);
            printf("\nBanco: %s", A[I].pago.che.noba);
            printf("\nCuenta: %s\n", A[I].pago.che.nucu);
        }
    }
}
