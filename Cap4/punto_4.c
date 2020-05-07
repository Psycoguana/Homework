#include <stdio.h>
#include <stdlib.h>

unsigned int isPrimo(unsigned int number);

int main(int argc, char const *argv[]) {
  unsigned int number;

  printf("Ingrese un número y vea si es primo: ");
  scanf(" %d", &number);

  if (isPrimo(number) == 0) {
    printf("%d es primo", number);
  } else {
    printf("%d no es primo", number);
  }

  printf("\n\n");
  return 0;
}

unsigned int isPrimo(unsigned int number) {
  // Checkeamos cada número mayor a 2 y menor a number.
  int i;
  for (i = 2; i < number; i++) {
    // Si el número de estos nums es 0, no sirve.
    if (number % i == 0) {
      return 1;
    }
  }
  // Si el programa llega hasta acá, el número tiene que ser primo.
  return 0;
}
