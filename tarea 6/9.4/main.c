#include <stdio.h>

/* Archivos y cadenas de caracteres.
   El programa lee cadenas de caracteres de un archivo.
*/

void main(void)
{
    char cad[50];
    FILE *ap;

    /* Se abre el archivo para lectura y se verifica
       si se abrio correctamente.
    */
    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        /* Mientras no se detecte el fin de archivo
           se siguen leyendo cadenas de caracteres.
        */
        while (!feof(ap))
        {
            /* Observa que la instruccion para leer
               cadenas requiere de tres argumentos.
            */
            fgets(cad, 50, ap);

            /* Despliega la cadena en la pantalla. */
            puts(cad);
        }

        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
