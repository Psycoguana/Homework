#include <stdio.h>
#include <stdlib.h>

int main() {
    float diagonal_1, diagonal_2;

    printf("Ingresar el valor de las diagonales de un rombo:\n");
    scanf("%f", &diagonal_1);
    scanf("%f", &diagonal_2);

    float superficie = (diagonal_1 * diagonal_2) / 2;
    printf("Teniendo en cuenta un rombo con una diagonal de %f y una diagonal de %f:\n", diagonal_1, diagonal_2);
    printf("Su superficie es igual a -> %f", superficie);

    printf("\n");
    return 0;
}