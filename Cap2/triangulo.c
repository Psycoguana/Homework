#include <stdio.h>
#include <stdlib.h>

int main() {
    float triangulo_base, triangulo_altura, triangulo_superficie;
    
    printf("Por favor, ingrese la base del triangulo: ");
    scanf("%f", &triangulo_base);

    printf("Ahora ingrese la altura: ");
    scanf("%f", &triangulo_altura);

    triangulo_superficie = triangulo_base * (triangulo_altura / 2);
    printf("La superficie del triangulo es %.2f\n\n", triangulo_superficie);

    return 0;
}