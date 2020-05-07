#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int counter = 0;
  int current_number = 0;
  int pares = 0;
  int impares = 0;

  printf("Por favor ingrese 100 números: ");
  while (counter < 100) {
    scanf("%d", &current_number);
    printf("\n");

    if ((current_number % 2) != 0) {
      impares++;
    } else {
      pares++;
    }

    counter++;
  }

  printf("Pares: %d\n", pares);
  printf("Impares: %d\n", impares);

  printf("\n\n");
  return 0;
}
