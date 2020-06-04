/*
El programa que sigue permite el ingreso de 2 strings por teclado y luego los
muestra en pantalla. 

Explique la diferencia de comportamiento cuando los datos
cargados son “PEPE” y “LOLA”, y cuando son “CARLOS”y “MAGNO”.
*/

#include <stdio.h>
int main()
{
    char VEC[2][5] , I;
    for(I=0;I<2;I++)
        gets(VEC[I]);
    printf("\n\n\n");
    for(I=0;I<2;I++)
        puts(VEC[I]);
}

/*
Al declarar char VEC[2][5], decimos que solo podemos tener 2 strings de 4 caracteres (el 5to espacio es ocupado por "\0").
Entonces, "PEPE" y "LOLA" van a ser ingresados normalmente, pero "CARLOS"...........idk
*/
