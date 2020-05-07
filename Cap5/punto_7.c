#include <stdio.h>
#include <stdlib.h>

int i;

int main(int argc, char const *argv[]) {
  printf("\n\n");
  int array_1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};
  int arraySize = sizeof(array_1) / sizeof(array_1[0]);
  int arrayCheck = arrayEquals(array_1, array_2, arraySize);

  if (arrayCheck == 1) {
    printf("Ambos arrays son iguales");
  } else if (arrayCheck == 0) {
    printf("Los arrays son diferentes");
  }

  printf("\n\n");
  return 0;
}

int arrayEquals(int array_1[], int array_2[], int arraySize) {
  for (i = 0; i < arraySize; i++) {
    if (array_1[i] != array_2[i]) {
      return 0;
    }
  }
  return 1;
}