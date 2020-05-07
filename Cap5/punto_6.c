#include <stdio.h>
#include <stdlib.h>

unsigned int i;

// Prototipo
int isDescendiente(int array[], int arraySize);

int main(int argc, char const *argv[]) {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int isDesc = isDescendiente(array, sizeof(array) / sizeof(array[0]));

  if (isDesc == 0) {
    printf("NO esta ordenado de manera creciente");
  } else if (isDesc == 1) {
    printf("Esta ordenado de manera creciente");
  }

  printf("\n\n");
  return 0;
}

int isDescendiente(int array[], int arraySize) {
  int minVal = array[0];

  for (i = 1; i < arraySize; i++) {
    // Con cada loop, si el valor del array actual es mayor a minVal,
    // es creciente, por lo que se actualiza minVal y se continúa.
    if (array[i] > minVal) {
      minVal = array[i];
    } else {
      return 0;
    }
  }
  return 1;
}
