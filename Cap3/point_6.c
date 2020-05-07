#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int sum = 0;
  int number;
  printf("Ingrese un numero: ");
  scanf("%d", &number);

  for (int i = 1; i < number; i++) {
    if (number % i == 0) {
      sum += i;
    }
  }

  if (sum == number) {
    printf("El número %d es perfecto", number);
  } else {
    printf("El número %d NO es perfecto", number);
  }

  printf("\n\n");
  return 0;
}
