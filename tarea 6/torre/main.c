#include <stdio.h>

void hanoi(int n, char origen, char auxiliar, char destino)
{
    if (n == 1)
    {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }

    hanoi(n - 1, origen, destino, auxiliar);

    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    hanoi(n - 1, auxiliar, origen, destino);
}

int main(void)
{
    int discos;

    printf("Ingrese el numero de discos: ");
    scanf("%d", &discos);

    printf("\nMovimientos necesarios:\n\n");
    hanoi(discos, 'A', 'B', 'C');

    return 0;
}
