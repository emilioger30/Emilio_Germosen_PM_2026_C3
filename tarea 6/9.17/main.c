#include <stdio.h>
#include <string.h>

/* Reemplaza palabras.
   El programa lee cadenas de caracteres de un archivo y
   cada vez que encuentra la palabra Mexico escrita en forma
   incorrecta (la primera letra en minuscula), la reemplaza
   por su forma correcta y escribe la cadena en otro archivo.
*/

void cambia(FILE *, FILE *);
/* Prototipo de funcion. Se pasan dos archivos como parametros. */

void main(void)
{
    FILE *ar;
    FILE *ap;

    /* Se abre el archivo arc.txt para lectura. */
    ar = fopen("arc.txt", "r");

    /* Se abre el archivo arc1.txt para escritura. */
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);

        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }
}

void cambia(FILE *ap1, FILE *ap2)
{
    /* Esta funcion reemplaza en la cadena de caracteres
       la palabra mexico escrita con minuscula en la
       primera letra por su forma correcta y escribe
       la cadena de caracteres en un nuevo archivo.
    */

    int i, j, k;
    char cad[30], *cad1 = "", *cad2 = "", aux[30];

    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);

        strcpy(cad1, cad);

        /* Localiza la subcadena mexico en cad1. */
        cad2 = strstr(cad1, "mexico");

        while (cad2 != NULL)
        {
            /* Reemplaza la letra minuscula por la mayuscula. */
            cad2[0] = 'M';

            i = strlen(cad1);
            j = strlen(cad2);

            /* En k se almacena la diferencia de las longitudes
               de las cadenas cad1 y cad2.
            */
            k = i - j;

            if (k)
            {
                /* Se copia la subcadena de k caracteres de cad1
                   a aux, desde el inicio de cad1 hasta el caracter
                   anterior a mexico.
                */
                strncpy(aux, cad1, k);
                aux[k] = '\0';

                strcat(aux, cad2);
                strcpy(cad1, aux);
            }
            else
            {
                strcpy(cad1, cad2);
            }

            cad2 = strstr(cad1, "mexico");
        }

        /* Se escribe la cadena correcta en el archivo ap2. */
        fputs(cad1, ap2);
    }
}
