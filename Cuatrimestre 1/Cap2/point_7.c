#include <stdio.h>
#include <stdlib.h>

int main() {
  int cateto_number;

  printf("Porfavor ingresar un número para el tamaño de los catetos: ");
  scanf("%d", &cateto_number);

  char symbol = '*';
  for (int i = 0; i < cateto_number; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("%c ", symbol);
    }
    printf("\n");
  }

  printf("\n\n");
  return 0;
}
