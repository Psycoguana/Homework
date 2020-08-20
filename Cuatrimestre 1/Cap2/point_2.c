#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NUMBER_1, NUMBER_2, NUMBER_3, promedio;

    printf("Ingresar 3 números enteros:");

    scanf("%d", &NUMBER_1);
    scanf("%d", &NUMBER_2);
    scanf("%d", &NUMBER_3);

    printf("Promedio es %d", (NUMBER_1 + NUMBER_2 + NUMBER_3) / 3);
    return 0;
}
