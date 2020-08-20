// Declare varias variables locales.Estas se ubican en el área de memoria llamada “pila”,
// Determine en qué sentido crece la pila.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a, b, c, d;
  printf("%p\n", &a);
  printf("%p\n", &b);
  printf("%p\n", &c);
  printf("%p\n", &d);

  printf("\n\n");
  return 0;
}

// La pila se mueve en orden creciente de 4 en 4.
