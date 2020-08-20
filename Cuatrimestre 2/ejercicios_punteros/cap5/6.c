// Realizar una función que reciba un vector de enteros y su longitud,
// y retorne 1 si el vector esta ordenado en forma creciente, y 0 en caso contrario.

#include <stdio.h>
#include <stdlib.h>

analyzeOrder(int[], int *);

int main(int argc, char const *argv[]) {
  int numbers[] = {1, 2, 3, 4, 5};
  int size = 5;
  int result = analyzeOrder(numbers, &size);
  printf("%d", result);

  printf("\n\n");
  return 0;
}

analyzeOrder(int array[], int *size) {
  int prev = *array, i;

  for (i = 0; i < *size; i++) {
    if (*(array + i) < prev) {
      return 0;
    }
    prev = *(array + i);
  }
  return 1;
}
