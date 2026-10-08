#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define POTENCIA 5
#define RAIZCUADRADA 6
#define ERR_OK 0
#define ERR_SYNTAX 1
#define ERR_DivByZero 555

// Declaración de funciones
int suma(double s1, double s2, double *r);
int divicion(double dividendo, double divisor, double *r);
int multiplicacion(double multiplicando, double multiplicador, double *r);
int resta(double minuendo, double sustraendo, double *r);
int potencia(double base, int exponente, double *r);
int raiz_cuadrada(double radicando, double *r);
int main()
{
    int menu = -1;
    double n1 = 0.0, n2 = 0.0, result = 0.0;
    int err = ERR_OK;

    printf("\nCALCULADORA V1.0");
    do
    {
        printf("\n0-SALIR\n1-SUMAR\n2-RESTAR\n3-MULTIPLICAR\n4-DIVIDIR\n5-POTENCIA\n6-RAIZ_CUADRADA\n");
        scanf("%i", &menu);

        if(menu == SUMAR)
            {
            printf("\nSUMA");
            printf("\nEscriba el primer numero: ");
            scanf("%lf", &n1);
            printf("\nEscriba el segundo numero: ");
            scanf("%lf", &n2);
            err = suma(n1, n2, &result);
            if(err == ERR_OK)
            {
                printf("\nResultado: %lf + %lf = %lf", n1, n2, result);
            }
        }

        if(menu == RESTAR)
            {
            printf("\nRESTA");
            printf("\nEscriba el minuendo: ");
            scanf("%lf", &n1);
            printf("\nEscriba el sustraendo: ");
            scanf("%lf", &n2);
            err = resta(n1, n2, &result);
            if(err == ERR_OK)
            {
                printf("\nResultado: %lf - %lf = %lf", n1, n2, result);
            }
        }

        if(menu == MULTIPLICAR)
            {
            printf("\nMULTIPLICACION");
            printf("\nEscriba el multiplicando: ");
            scanf("%lf", &n1);
            printf("\nEscriba el multiplicador: ");
            scanf("%lf", &n2);
            err = multiplicacion(n1, n2, &result);
            if(err == ERR_OK)
            {
                printf("\nResultado: %lf * %lf = %lf", n1, n2, result);
            }
        }

        if(menu == POTENCIA)
            {
            printf("\nPOTENCIA");
            printf("\nEscriba la base: ");
            scanf("%lf", &n1);
            printf("\nEscriba el exponente: ");
            scanf("%lf", &n2);
            err = potencia(n1, (int)n2, &result);
            if(err == ERR_OK)
            {
                printf("\nResultado: %lf ^ %lf = %lf", n1, n2, result);
            }
        }
        if(menu==RAIZCUADRADA)
        {
            printf("\nRAIZ_CUADRADA");
            printf("\nEscriba el radicando:");
            scanf("%lf",&n1);
            err=raiz_cuadrada(n1,&result);
            if(err==ERR_OK)
            {
                printf("\nResultado:%lf^*(1/2)=%lf",n1,result);
            }
        }

        if(menu == DIVIDIR)
            {
            printf("\nDIVISION");
            printf("\nEscriba el dividendo: ");
            scanf("%lf", &n1);
            printf("\nEscriba el divisor: ");
            scanf("%lf", &n2);
            err = divicion(n1, n2, &result);
            if(err == ERR_OK)
            {
                printf("\nResultado: %lf / %lf = %lf", n1, n2, result);
            } else if(err == ERR_DivByZero)
            {
                printf("\nError: No se puede dividir entre cero");
            }
        }

    }
    while(menu != SALIR);

    return 0;
}
int suma(double s1, double s2, double *r)
{
    *r = s1 + s2;
    return ERR_OK;
}

int divicion(double dividendo, double divisor, double *r)
{
    if(divisor != 0)
        {
        *r = dividendo / divisor;
        return ERR_OK;
    }
    else
    {
        return ERR_DivByZero;
    }
}

int resta(double minuendo, double sustraendo, double *r)
{
    *r = minuendo - sustraendo;
    return ERR_OK;
}

int multiplicacion(double multiplicando, double multiplicador, double *r)
{
    *r = multiplicando * multiplicador;
    return ERR_OK;
}

int potencia(double base, int exponente, double *r)
{
    double resultado = 1.0;

    if(exponente > 0)
        {
        for(int i = 0; i < exponente; i++)
        {
            resultado *= base;
        }
    }
    else
        if(exponente < 0)
    {
        for(int i = 0; i < -exponente; i++)
         {
            resultado *= base;
        }
        resultado = 1.0 / resultado;
    }
    else
        { // exponente == 0
        resultado = 1.0;
    }

    *r = resultado;
    return ERR_OK;
}
int raiz_cuadrada(double radicando, double *r)
{
    if(radicando < 0) {
        return ERR_SYNTAX;
    }
    double x = radicando;
    double aprox = radicando / 2.0;
    for(int i = 0; i < 20; i++) {
        aprox = 0.5 * (aprox + x / aprox);
    }
    *r = aprox;
    return ERR_OK;
}
