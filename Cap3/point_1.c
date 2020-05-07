#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int current_numer = 0;
    printf("Por favor ingrese números positivos: ");

    while (current_numer >= 0)
    {
        scanf("%d", &current_numer);
        if ((current_numer % 2) != 0)
        {
            printf("%d es impar\n", current_numer);
        }
        else
        {
            printf("%d es par\n", current_numer);
        }
    }
    printf("No se permiten números negativos");

    printf("\n\n");
    return 0;
}
