// Ingrese 20 valores enteros y muéstrelos en pantalla en una línea, en el orden de ingreso,
// y en la línea siguiente, en orden inverso al de ingreso.

#include <stdio.h>
#include <stdlib.h>

const int N = 20;

inputData(int[], int);
inputData2(int[], int);
showData(int[], int);

int main(int argc, char const *argv[]) {
  int numbers[N];
  inputData(numbers, N);
  showData(numbers, N);
  printf("\n");
  showDataInverse(numbers, N);

  printf("\n\n");
  return 0;
}


// Ambas son correctas en un parcial?

inputData(int array[], int size) {
  int *p;
  for (p = array; p < array + size; p++) {
    printf("\nIngrese número #%d: ", (p - array) + 1);

    scanf("%d", p);
  }
}

inputData2(int array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("\nIngrese número #%d: ", i);

    scanf("%d", (array + i));
  }
}

showData(int array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("\n%d", *(array + i));
  }
}

showDataInverse(int array[], int size) {
  int *i;
  for (i = (array + size) - 1; i >= array; i--) {
    printf("\n%d", *(i));
  }
}
