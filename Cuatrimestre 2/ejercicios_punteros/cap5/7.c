// Implementar una función que reciba dos vectores de enteros del mismo tamaño y su longitud,
// y retorne 1 si ambos vectores son iguales (identicos contenidos en idénticas posiciones),
// y 0 en caso contrario.

#include <stdio.h>
#include <stdlib.h>

isEqual(int[], int[], int *);

int main(int argc, char const *argv[]) {
  int size = 5;
  int numbers1[] = {1, 2, 3, 4, 5};
  // Returns 1
  int numbers2[] = {1, 2, 3, 4, 5};
  //Returns 0
//   int numbers2[] = {2, 3, 4, 1, 5};

  int result = isEqual(numbers1, numbers2, &size);
  printf("%d", result);

  printf("\n\n");
  return 0;
}

isEqual(int array1[], int array2[], int *size) {
  int i;
  for (i = 0; i < *size; i++) {
    if (*(array1 + i) != *(array2 + i)) {
      return 0;
    }
  }
  return 1;
}
