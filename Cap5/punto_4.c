#include <stdio.h>
#include <stdlib.h>

// Prototipo
int randomInflator(int array[], int arrayLen);
int showArray(int array[], int arrayLen);

int i;

int main(int argc, char const *argv[]) {
  int array[20];
  int sizeArray = sizeof(array) / sizeof(array[0]);
  randomInflator(array, sizeArray);
  showArray(array, sizeArray);

  printf("\n\n");
  return 0;
}

int randomInflator(int array[], int arrayLen) {
  for (i = 0; i < arrayLen; i++) {
    /*
     Dado que la ejecución del programa es demasiado rápida
     time(0) retorna siempre el mismo valor.
     Si queremos random numbers debemos cambiar la seed con cada llamado.
     Estos números son aleatorios? No realmente, pero no sé como usar una
     funcion como random() especificando el rango.
     Por eso uso time() y le sumo i (cambia con cada llamado).
    */
    array[i] = randNumb(99, time(0) + i);
  }
  return 0;
}

int randNumb(int max_rand, int seed) {
  srand(seed);
  return (rand() % max_rand) - 1;
}

int showArray(int array[], int arrayLen) {
  for (i = 0; i < arrayLen; i++) {
    printf("Array #%d -> %d\n", i + 1, array[i]);
  }
  return 0;
}
