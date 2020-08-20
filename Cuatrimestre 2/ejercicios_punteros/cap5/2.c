// Ingrese 20 valores enteros y posteriormente un valor entero adicional al que llamaremos DIV.
// Indique cuantos componentes del vector son divisibles por DIV.

#include <stdio.h>
#include <stdlib.h>

const int N = 20;

inputData(int[], int *, int *);
showDiv(int[], int *, int *);

int main(int argc, char const *argv[]) {
  int numbers[N];
  int div;

  inputData(numbers, &N, &div);
  showDiv(numbers, &N, &div);

  printf("\n\n");
  return 0;
}

inputData(int array[], int *size, int *div) {
  int i;
  for (i = 0; i < *size; i++) {
    printf("Ingrese número #%d: ", i + 1);
    scanf("%d", array + i);
  }
  printf("Ahora ingrese el valor del divisor: ");
  scanf("%d", div);
}

showDiv(int array[], int *size, int *div) {
  int i;
  for (i = 0; i < *size; i++) {
    if ((*(array + i) % *div) == 0) {
      printf("%d es divisible por %d\n", *(array + i), *div);
    }
  }
}
