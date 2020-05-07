#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  long unsigned sum = 0;
  int counter = 0;
  long unsigned int current_number = 4;

  while (counter < 5) {
    // Dado que los números perfectos son pares,
    // contemos de 2 en 2 reduciendo tiempo.
    current_number += 2;

    // Se checkea que el número termine en 6 u 8.
    if ((current_number % 10) == 6 || (current_number % 10) == 8) {
      for (int i = 1; i < current_number; i++) {
        if (current_number % i == 0) {
          sum += i;
        }
      }
    }

    if (sum == current_number) {
      printf("\nEl número %lu es perfecto", current_number);
      counter++;
    } else {
      printf("\n%lu no es perfecto", current_number);
    }
    sum = 0;
  }

  printf("\n\n");
  return 0;
}