// Crear una función que reciba un vector de enteros y su longitud,
// y cargue sus variables con valores aleatorios comprendidos entre 0 y 99 (utilizar la función rand).

#include <stdio.h>
#include <stdlib.h>

inflateArray(int[], int *);
showArray(int[], int *);

int main(int argc, char const *argv[]) {
  int size = 20;
  int numbers[size];
  inflateArray(numbers, &size);
  showArray(numbers, &size);

  printf("\n\n");
  return 0;
}

inflateArray(int array[], int *size) {
  srand(time(0));

  int i;
  for (i = 0; i < *size; i++) {
    *(array + i) = (rand() % 100);
  }
}

showArray(int array[], int *size) {
  int i;
  for (i = 0; i < *size; i++) {
    printf("Element #%d: %d\n", i + 1, *(array + i));
  }
}
