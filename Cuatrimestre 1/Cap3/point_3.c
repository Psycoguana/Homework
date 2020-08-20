#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int key = 235;
  int current_number = 0;
  int counter_23 = 0;

  while (current_number != key) {
    scanf("%d", &current_number);
    
    // Se asume que se puede hacer esta comprobación ya que
    // si (current_numer != key), el programa sigue normalmente.
    if (current_number == 23) {
      counter_23++;
    }
  }

  printf("El 23 fue ingresado %d vez", counter_23);

  printf("\n\n");
  return 0;
}
