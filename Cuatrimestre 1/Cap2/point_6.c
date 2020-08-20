#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b, c, d, e;

    printf("Por favor, ingrese una palabra de 5 letras: ");
    scanf("%c%c%c%c%c", &a, &b, &c, &d, &e);

    printf("%c", a + 5);
    printf("%c", b + 5);
    printf("%c", c + 5);
    printf("%c", d + 5);
    printf("%c", e + 5);

    printf("\n\n");
    return 0;
}