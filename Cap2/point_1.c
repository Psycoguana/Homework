#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio, diametro, superficie, longitud_circunferencia;
    printf("Ingresar el radio de un circulo:");
    scanf("%f", &radio);

    diametro = radio * 2;
    superficie = 3.1416 * diametro;
    longitud_circunferencia = 2 * 3.1416 * radio;

    printf("Dado un radio de %f:\n", radio);
    printf("Longitud de la circunferencia: %f\n", longitud_circunferencia);
    printf("Superficie: %f\n", superficie);

    return 0;
}
