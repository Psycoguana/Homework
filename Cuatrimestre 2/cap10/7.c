// Realizar un programa que reciba nombres como argumentos por línea de comandos y los muestre en pantalla
// ordenados alfabéticamente. Realizar el ordenamiento sin mover ni copiar los strings.
// Utilizar para ello el vector de punteros. Excluir del ordenamiento el nombre del programa ejecutable.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int showArray(char *[], int size);
int sortAddr(char *[], int);

int main(int argc, char *argv[]) {
  int i, j;
  char *aux;

  // Le sumo 1 a argv para saltearme el primer valor y resto 1 a argc porque tengo un elemento menos.
  sortAddr(argv + 1, argc - 1);
  showArray(argv + 1, argc - 1);

  printf("\n\n");
  return 0;
}

int sortAddr(char *pArray[], int size) {
  int i, j;
  char *aux;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {

      if (strcmp(*(pArray + j), *(pArray + j + 1)) > 0) {
        aux = *(pArray + j);
        *(pArray + j) = *(pArray + j + 1);
        *(pArray + j + 1) = aux;
      }
    }
  }
}

int showArray(char *array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%s\n", *(array + i), array + i);
  }
}