#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int decimal_number;
  int i;
  int number_binary[32];

  printf("Ingresa un número: ");
  scanf("%d", &decimal_number);

  for (i = 0; decimal_number > 0; i++) {
    number_binary[i] = decimal_number % 2;
    decimal_number = decimal_number / 2;
  }

  for (i = i - 1; i >= 0; i--) {
    printf("%d", number_binary[i]);
  }

  printf("\n\n");
  return 0;
}
