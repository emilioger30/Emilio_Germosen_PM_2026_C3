#include <stdio.h>

/* Incrementa salarios.
   El programa incrementa el salario de los empleados de una empresa,
   actualiza el archivo correspondiente si sus ventas son superiores
   al millon de pesos anuales.
*/

typedef struct
{
    /* Declaracion de la estructura empleado. */
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *); /* Prototipo de funcion. */

void main(void)
{
    FILE *ar;

    /* El archivo se abre en la modalidad para leer y escribir. */
    if ((ar = fopen("ad5.dat", "r+")) != NULL)
        incrementa(ar);
    else
        printf("\nEl archivo no se puede abrir");

    /* La funcion rewind se utiliza para posicionarnos en el inicio
       del archivo cada vez que sea necesario. En este programa no
       tiene ninguna utilidad, solo se escribio para explicar su uso.
    */
    rewind(ar);

    fclose(ar);
}

void incrementa(FILE *ap)
/* Esta funcion se utiliza para incrementar el salario de todos
   aquellos empleados que hayan tenido ventas anuales por mas de
   $1,000,000. Actualiza ademas el archivo correspondiente.
*/
{
    int i, j, t;
    float sum;
    empleado emple;

    /* La funcion sizeof se utiliza para conocer el tamano
       de la estructura empleado.
    */
    t = sizeof(empleado);

    /* Se lee el primer registro del archivo. */
    fread(&emple, sizeof(empleado), 1, ap);

    while (!feof(ap))
    {
        /* La funcion ftell se utiliza para conocer la posicion
           de nuestro apuntador en el archivo. La variable i
           nos proporciona en este caso el tamano de todos los
           bloques que existen debajo de nuestra posicion.

           Si conocemos el tamano de cada bloque, entonces
           podemos obtener el numero de bloques que hay
           exactamente debajo de nuestra posicion.
        */
        i = ftell(ap) / t;

        sum = 0;

        /* Se calculan las ventas de cada vendedor. */
        for (j = 0; j < 12; j++)
            sum += emple.ventas[j];

        if (sum > 1000000)
        {
            /* Se incrementa el salario. */
            emple.salario = emple.salario * 1.10;

            /* Nos posicionamos para escribir el registro actualizado. */
            fseek(ap, (i - 1) * sizeof(empleado), 0);

            fwrite(&emple, sizeof(empleado), 1, ap);

            /* Nos posicionamos nuevamente para leer el siguiente
               registro. Esta instruccion no deberia ser necesaria,
               pero la funcion fwrite se comporta a veces de manera
               inestable en algunos compiladores de C.

               Para asegurarnos que siempre funcione correctamente,
               realizamos este nuevo reposicionamiento.
            */
            fseek(ap, i * sizeof(empleado), 0);
        }

        fread(&emple, sizeof(empleado), 1, ap);
    }
}
