#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;
#define row 8
#define column 8

int printMatrix(int matrix[][column], int arrayRow, int arrayColumn);
int randNumbGenerator(int max_rand, int seed);

int main(int argc, char const *argv[]) {
  int matriz[row][column] = {0};

  int randNumb1 = randNumbGenerator(7, time(0));
  sleep(1);  // Sorry, no sé como crear diferentes seeds sin esperar 1 sec.
  int randNumb2 = randNumbGenerator(7, time(0));

  // Darle el valor de 0 a toda la matriz

  // Cambiar dos posiciones aleatorias
  matriz[randNumb1][randNumb2] = 1;
  matriz[randNumb2][randNumb1] = 1;

  printMatrix(matriz, row, column);

  printf("\n\n");
  return 0;
}

int printMatrix(int matrix[][column], int arrayRow, int arrayColumn) {
  printf("Printeando valores de matrices...\n\n");
  for (i = 0; i < arrayRow; i++) {
    for (j = 0; j < arrayColumn; j++) {
      printf("Posición de matriz: [%d][%d]\nValor: %d\n\n", i, j, matrix[i][j]);
    }
  }
}

int randNumbGenerator(int max_rand, int seed) {
  srand(seed);
  return (rand() % max_rand) + 1;
}
