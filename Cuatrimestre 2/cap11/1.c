// Desarrolle un programa que lea un número de teclado, que indica a su vez cuántos números enteros ingresará
// el usuario a continuación. Crear el vector para almacenar el tamaño exacto de los datos y leer los enteros
// que serán guardados en el vector "dinámico". Informar el promedio de los datos ingresados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int writeData(int[], int);
int readData(int[], int);

fail() { exit(1); }

int main(int argc, char const *argv[]) {
  int size, i;
  printf("Cuantos enteros vas a ingresar? ");
  scanf("%d", &size);

  // Asigno memoria.
  int *vec = malloc(size * sizeof(int));

  // Checkeo que la memoria fue obtenida.
  if (vec == NULL) {
    fail();
  }

  // Pido y escribo los datos en el array.
  writeData(vec, size);
  
  // Obtengo el total de los datos ingresados.
  int total = readData(vec, size);
  
  // Libero la memoria que ya no necesito.
  free(vec);

  printf("El promedio de los %d enteros ingresados es: %.2f", size, total / size);

  printf("\n\n");
  return 0;
}

int writeData(int array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Ingresar #%d: ", i + 1);
    scanf("%d", array + i);
  }
  printf("\n");
}

int readData(int array[], int size) {
  int i, total = 0;
  for (i = 0; i < size; i++) {
    total += *(array + i);
  }
  return total;
}
