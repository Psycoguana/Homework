#include <stdio.h>
#include <stdlib.h>

int i;

int main(int argc, char const *argv[]) {
  int array[20];
  int DIV;

  printf("Ingrese 20 enteros: \n\n");
  // Se divide el sizeof(array) por el sizeof de su primer elemento.
  // En este caso, dividimos por int (4 bytes) incluso sin saber que es un int.
  // Esto nos da el tamaño del array.
  for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    printf("Ingrese #%d: ", i + 1);
    scanf(" %d", &array[i]);
  }
  printf("Ahora ingrese un divisor: ");
  scanf(" %d", &DIV);

  // This is horrifying, como debería hacer esto sin que el index=1?
  for (i = 1; i < sizeof(array) / sizeof(array[0]); i++) {
    if (array[i] % DIV == 0) {
      printf("%d es divisible por %d\n", array[i], DIV);
    }
  }

  printf("\n\n");
  return 0;
}
