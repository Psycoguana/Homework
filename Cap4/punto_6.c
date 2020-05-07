#include <stdio.h>
#include <stdlib.h>

int i;

unsigned int isPrimo(unsigned int number);
showPrimes(unsigned int number_1, unsigned int number_2);

int main(int argc, char const *argv[]) {

  printf("#### Encontrando números primos entre 1000 y 2000 ####\n");
  showPrimes(1000, 2000);

  printf("\n#### Encontrando números primos entre 2000 y 3000 ###\n");
  showPrimes(2000, 3000);

  printf("\n#### Encontrando números primos entre 3000 y 4000 ####\n");
  showPrimes(3000, 4000);

  printf("\n\n");
  return 0;
}

showPrimes(unsigned int number_1, unsigned int number_2) {
  for (i = number_1; i < number_2; i++) {
    if (isPrimo(i) == 0) {
      printf("%d es primo\n", i);
    }
  }
}

unsigned int isPrimo(unsigned int number) {
  // Checkeamos cada número mayor a 2 y menor a number.
  for (i = 2; i < number; i++) {
    // Si el número de estos nums es 0, no sirve.
    if (number % i == 0) {
      return 1;
    }
  }
  // Si el programa llega hasta acá, el número tiene que ser primo.
  return 0;
}
