#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int key = 23645;
  int current_number = 0;

  printf("Ingresar clave númerica: ");
  while (current_number != key) {
    scanf("%d", &current_number);
  }

  printf("\n\n");
  return 0;
}
