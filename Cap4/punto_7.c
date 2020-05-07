#include <stdio.h>
#include <stdlib.h>

// PROTOTIPO
int isPerfect(unsigned int number);

int main(int argc, char const *argv[]) {
  long unsigned sum = 0;
  int counter = 0;
  long unsigned int current_number = 4;

  while (counter < 5) {
    // Dado que los números perfectos son pares,
    // contemos de 2 en 2 reduciendo tiempo.
    current_number += 2;

    if (isPerfect(current_number)) {
      printf("\nEl número %lu es perfecto", current_number);
      counter++;
    } else {
      //   Uncomment to debug:
      //   printf("\n%lu no es perfecto", current_number);
    }
  }

  printf("\n\n");
  return 0;
}

int isPerfect(unsigned int number) {
  // Se checkea que el número termine en 6 u 8.
  int sum = 0;

  if ((number % 10) == 6 || (number % 10) == 8) {
    for (int i = 1; i < number; i++) {
      if (number % i == 0) {
        sum += i;
      }
    }
  }

  if (sum == number) {
    return 1;
  } else {
    return 0;
  }
}
