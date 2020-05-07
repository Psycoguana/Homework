#include <stdio.h>
#include <stdlib.h>

// Prototipo
float arrayPromedio(int array[], int longitudArray);

int i;

int main(int argc, char const *argv[]) {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};
  float promedio = arrayPromedio(array, sizeof(array) / sizeof(array[0]));

  printf("Promedio: %.2f", promedio);

  printf("\n\n");
  return 0;
}

float arrayPromedio(int array[], int longitudArray) {
  int sum = 0;

  for (i = 0; i < longitudArray; i++) {
    sum += array[i];
  }

  return (float) sum / longitudArray;
}
