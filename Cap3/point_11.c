#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
  int num_1 = 0;
  int num_2 = 0;
  int count = 0;
  bool stop_program = false;

  printf("Ingresar 10 números: ");
  while (count < 10 && !stop_program) {
    scanf("%d", &num_2);
    if (num_1 < num_2) {
      num_1 = num_2;
    } else {
        printf("No creciente");
        stop_program = true;
    }
    count ++;
  }

  printf("\n\n");
  return 0;
}
