// Generar y mostrar una matriz de 8 x 8 enteros cuyos elementos valgan 0,
//     excepto 2 de ellos que valdrán 1 y estarán ubicados en posiciones aleatorias de la matriz.
//     Mostrar dicha matriz en pantalla.

#include <stdio.h>
#include <stdlib.h>

inflateMatrix(int[][8], const int *size);
printMatrix(int[][8], const int *size);
getRandNumb();

const int size = 8;
#define N 9;

int main(int argc, char const *argv[]) {

  int matrix[size][size];
  inflateMatrix(matrix, &size);
  printMatrix(matrix, &size);

  printf("\n\n");
  return 0;
}

inflateMatrix(int matrix[][8], const int *size) {
  int i, j;
  int rand1 = getRandNumb(*size - 1);
  int rand2 = getRandNumb(*size - 1);

  for (i = 0; i < *size; i++) {
    for (j = 0; j < *size; j++) {
      *(*(matrix + i) + j) = 0;
    }
  }
  printf("Changing value in matrix[%d][%d]...\n", rand1, rand2);
  *(*(matrix + rand1) + rand2) = 1;
}

printMatrix(int matrix[][8], const int *size) {
  int i, j;
  for (i = 0; i < *size; i++) {
    for (j = 0; j < *size; j++) {
      printf("{");
      printf("%d", *(*(matrix + i) + j));
      printf("}");
    }
    printf("\n");
  }
}

getRandNumb(int max) {
  srand(time(0));
  return rand() % max;
}
