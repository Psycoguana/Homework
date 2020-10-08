#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char bin_number;
  int dec = 0;

  printf("Ingrese un número binario (1111011): ");

  while (bin_number != '\n') {
    scanf("%c", &bin_number);
    if (bin_number == '1') {
      dec = (dec * 2) + 1;
    } else if (bin_number == '0') {
      dec *= 2;
    }
  }
  printf("%d", dec);

  printf("\n\n");
  return 0;
}
