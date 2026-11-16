#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *archivo;
    char *texto;
    int capacidad = 100;
    int longitud = 0;
    int c;

    archivo = fopen("texto.txt", "r");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    /* Reserva memoria inicial */
    texto = (char *)malloc(capacidad * sizeof(char));

    if (texto == NULL)
    {
        printf("Error al reservar memoria.\n");
        fclose(archivo);
        return 1;
    }

    /* Lectura caracter por caracter */
    while ((c = fgetc(archivo)) != EOF)
    {
        /* Si se llena la memoria, se duplica */
        if (longitud >= capacidad - 1)
        {
            capacidad *= 2;

            texto = (char *)realloc(texto, capacidad * sizeof(char));

            if (texto == NULL)
            {
                printf("Error al redimensionar memoria.\n");
                fclose(archivo);
                return 1;
            }
        }

        texto[longitud++] = (char)c;
    }

    texto[longitud] = '\0';

    fclose(archivo);

    printf("Contenido del archivo:\n\n%s\n", texto);
    printf("\nCaracteres leidos: %d\n", longitud);

    free(texto);

    return 0;
}
