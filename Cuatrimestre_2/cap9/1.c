// Realice un programa que esté compuesto por diversas funciones(propias y de librerías)
// Indique en que dirección del segmento de código comienza cada una, incluyendo el main.

#include <stdio.h>
#include <stdlib.h>

int myFunc();

int main(int argc, char const *argv[]) {
  printf("Main: %p\n", &main);
  printf("myFunc: %p\n", &myFunc);
  printf("scanf: %p\n", &scanf);
  printf("printf: %p\n", &printf);
  

  printf("\n\n");
  return 0;
}

int myFunc() {
    printf("This should not be printed...");
}
