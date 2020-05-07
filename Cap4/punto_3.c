#include <stdio.h>
#include <stdlib.h>

// PROTOTIPO
long unsigned int potencia(int number, int potencia);

int main(int argc, char const *argv[]) {
  printf("%lu", potencia(2, 63));

  printf("\n\n");
  return 0;
}

long unsigned int potencia(int number, int potencia) {
  long unsigned int new_number = number;

  int i;
  for (i = 0; i < potencia - 1; i++) {
    new_number = new_number * number;
  }

  return new_number;
}