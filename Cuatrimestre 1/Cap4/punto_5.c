#include <stdio.h>
#include <stdlib.h>

unsigned int isPrimo(unsigned int number);
showPrimes(unsigned int number_1, unsigned int number_2);

int main(int argc, char const *argv[]) {
  unsigned int number_1, number_2;

  printf("Ingrese dos números y vea los números primos entre ellos: ");
  scanf(" %d %d", &number_1, &number_2);
  
  // Para evitar errores se podría agregar un checkeo para nums > 1
  showPrimes(number_1, number_2);

  printf("\n\n");
  return 0;
}

showPrimes(unsigned int number_1, unsigned int number_2) {
  for (int i = number_1; i < number_2; i++) {
    if (isPrimo(i) == 0) {
      printf("%d es primo\n", i);
    }
  }
}

unsigned int isPrimo(unsigned int number) {
  // Checkeamos cada número mayor a 2 y menor a number.
  for (int i = 2; i < number; i++) {
    // Si el número de estos nums es 0, no sirve.
    if (number % i == 0) {
      return 1;
    }
  }
  // Si el programa llega hasta acá, el número tiene que ser primo.
  return 0;
}
