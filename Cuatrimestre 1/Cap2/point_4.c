#include <stdio.h>
#include <stdlib.h>

int main() {
    float temp_input, temp_c, temp_f, temp_k;
    char ESCALA;
    printf("Cual es su escala de temperatura? (C,F,K)\n");
    scanf("%c", &ESCALA);

    if (ESCALA != 'C' || ESCALA != 'F' || ESCALA != 'K') {
        printf("Escala de temperatura incorrecta");
        return 1;
    }

    printf("Cual es la temperatura?\n");
    scanf("%f", &temp_input);

    if (ESCALA == 'C') {
        temp_c = temp_input;
        temp_f = (temp_c * 9/5) + 32;
        temp_k = temp_c + 273.15;
    } else if (ESCALA == 'F') {
        temp_f = temp_input;
        temp_c = (temp_f - 32) * 5/9;
        temp_k = temp_c + 273.15;
    } else if (ESCALA == 'K') {
        temp_k = temp_input;
        temp_c = temp_k - 273.15;
        temp_f = temp_c * 9/5 + 32;
    }

    printf("C°: %f\n", temp_c);
    printf("F°: %f\n", temp_f);
    printf("K°: %f\n", temp_k);

    printf("\n");
    return 0;
}