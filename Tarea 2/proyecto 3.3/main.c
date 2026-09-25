#include <stdio.h>
#include <stdlib.h>

void main(void)
{
float PAG,SPA;
SPA=0;
printf("Ingrese el primer pago:\t");
scanf("%f",&PAG);
while(PAG)
/*observa que la condicion es verdadera mientras el pago es diferente a cero*/
{
    SPA=SPA+PAG;
    printf("Ingrese el siguiente pago:\t");
    scanf("%f",&PAG);
    /*observa que la proposicion que modifica la condicion es una lectura*/

}
printf("\nEl total de pagos del mes es:%.2f",SPA);
}
