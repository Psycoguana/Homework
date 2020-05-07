#include <stdio.h>
#include <stdlib.h>

int main() {
  int cateto_number;

  printf("Porfavor ingresar un número para el tamaño de los catetos: ");
  scanf("%d", &cateto_number);
  int spaces = cateto_number + 50;

  printf("\n");
  // filas
  for (int i = 0; i < cateto_number; i++) {
    // spaces
    for (int k = 0; k < spaces; k++) {
      printf("%c", ' ');
    }
    spaces -= 2;
    // columnas
    for (int j = 0; j < i + 1; j++) {
      printf("%c ", '*');
    }
    printf("\n");
  }

  printf("\n\n");
  return 0;
}