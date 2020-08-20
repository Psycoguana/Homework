// Ingreso datos y los ordeno con burbujeo.

#include <stdio.h>
#include <stdlib.h>

#define arraySize 5

// Prototypes
int inputData();
int getMin(int[], int);
int sortData(int[], int);
int showNames(int[]);

int main(int argc, char const *argv[]) {
  int num[] = {3, 2, -555, 6, 7};

  // inputData(num, arraySize);
  showData(num);
  sortData(num, arraySize);
  // getMin(num, arraySize);
  printf("\n\n");
  showData(num);

  printf("\n\n");
  return 0;
}

int sortData(int num[], int size) {
  int *p, j, aux, i;

  for (num, i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (*(num + j) > *(num + j + 1)) {
        swap(num, j);
      }
    }
  }
}

void swap(int *a, int b) {
  int *aux;
  aux = *(a + b);
  *(a + b) = *(a + b + 1);
  *(a + b + 1) = aux;
}

int inputData(int num[], int size) {
  int *p;
  for (p = num; p < num + size; p++) {
    printf("Input number #%d: ", (p - num) + 1);
    scanf("%d", p);
  }
}

int getMin(int num[], int size) {
  int *p, *p_min;

  for (p = p_min = num; p < num + size; p++) {
    if (*p < *p_min) {
      p_min = p;
    }
  }
  printf("El valor mínimo es: %d", *p_min);
}

int showData(int num[]) {
  int *p;

  for (p = num; p < num + arraySize; p++) {
    printf("%p  %d\n", p, *p);
  }
}