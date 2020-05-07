#include <stdio.h>
#include <stdlib.h>

int i;

int main(int argc, char const *argv[]) {
  int array[20];

  printf("Ingrese 20 enteros: \n\n");
  // Se divide el sizeof array en 4 (cada int ocupa 4 bytes),
  // para que el código sea menos hardcoded.
  for (i = 0; i < sizeof(array) / 4; i++) {
    printf("Ingrese #%d: ", i + 1);
    scanf(" %d", &array[i]);
  }

  printf("\nMostrando números en el orden de ingreso...\n");
  for (i = 0; i < sizeof(array) / 4; i++) {
    printf("Valor #%d: %d\n", i + 1, array[i]);
  }

  printf("\nMostrando números en orden de ingreso invertido...\n");
  // se le resta 1 al sizeof(array) ya que indexes start at zero bruh
  for (i = (sizeof(array) / 4) - 1; i >= 0; i--) {
    printf("Valor #%d: %d\n", i + 1, array[i]);
  }

  printf("\n\n");
  return 0;
}
