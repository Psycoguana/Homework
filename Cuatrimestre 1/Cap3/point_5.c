#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int key = 23645;
  int tries = 0;
  int current_number = 0;
  bool stop_program = false;

  printf("Ingresar clave númerica: ");

  while (!stop_program && (current_number != key)) {
    if (tries == 3) {
      printf("Se han realizado demasiados intentos.");
      stop_program = true;
    } else {
      scanf("%d", &current_number);
      tries++;
    }
  }

  printf("\n\n");
  return 0;
}
