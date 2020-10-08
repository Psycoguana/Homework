#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float superficie, radio;
    
    printf("Ingresar la superficie de un circulo: ");
    scanf("%f", &superficie);

    radio = sqrt(superficie / 3.1416);
    float diametro = radio * 2;
    
    printf("El área del circulo es %f \n", diametro);

    return 0;
}