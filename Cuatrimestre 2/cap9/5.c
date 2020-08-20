// Ante la siguiente fracción de programa:
// int A, B, C, *P, *Q, *R;
// P = &A; R = &C;
// printf(“%p %p %p”, P, Q, R);
// Explique los resultados.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int A, B, C, *P, *Q, *R;
  P = &A; Q = &B; R = &C;
  printf("%p %p %p", P, Q, R);

  printf("\n\n");
  return 0;
}

// Los punteros de las variables son establecidos uno detrás del otro, por lo que su
// dirección en memoria es continua.
// Teniendo en cuenta que A es un int de 4 bytes, si su dirección en memoria fuese igual a 0,
//  entonces B = 4 y C = 8.
// A diferencia del ejercicio anterior, el puntero Q es establecido, por lo que la secuencialidad
// del establecimiento de direcciones de memoria para las variables es más fácil de ver.