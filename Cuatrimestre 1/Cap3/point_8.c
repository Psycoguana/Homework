#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int intentos = 10;
  srand(time(0));

  for (int i = 0; i < intentos; i++) {
    int result = (rand() % 9) + 1;

    if (result < 6) {
      printf("Seca\n");
    } else {
      printf("Cara\n");
    }
  }

  printf("\n\n");
  return 0;
}
