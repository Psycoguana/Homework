#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int num_1 = 0;
  int num_2 = 0;
  int count = 0;

  printf("Ingresar 10 números: ");
  while (count < 10) {
    scanf("%d", &num_2);
    if (num_1 < num_2) {
      num_1 = num_2;
    }
    count ++;
  }
  printf("El número más grande es %d", num_1);

  printf("\n\n");
  return 0;
}
