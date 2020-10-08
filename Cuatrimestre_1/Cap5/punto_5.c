#include <stdio.h>
#include <stdlib.h>

int i;
const throwAmount = 1000;

int throwDice(int seed);

int main(int argc, char const *argv[]) {
  for (i = 0; i < throwAmount; i++) {
    throwDice(time(0) + i);
  }

  printf("\n\n");
  return 0;
}

int throwDice(int seed) {
  srand(seed);
  // Creo que esto esta mal y podría tirar un 7 u 8, pero no lo hace.
  printf("%d\n" ,(rand() % 6) + 1);
  return 0;
}
