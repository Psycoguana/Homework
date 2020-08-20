// Realizar una función que reciba un vector de enteros y su longitud,
// y retorne el promedio de sus valores.

// 99.4

#include <stdio.h>
#include <stdlib.h>

const int N = 5;

float getPromedio(int[], int *);

int main(int argc, char const *argv[]) {
  int numbers[] = {1, 50, 6, 7, 433};

  float prom = getPromedio(numbers, &N);
  printf("El promedio es %.2f", prom);

  printf("\n\n");
  return 0;
}

float getPromedio(int array[], int *size) {
  int i, max = 0;

  for (i = 0; i < *size; i++) {
    max += *(array + i);
  }

  return ((float)max / *size);
}
