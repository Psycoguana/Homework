// Realice un programa que utilice variables globales y locales.
// Determine en qué lugar de la memoria se ubican. ¿Qué conclusión obtiene?

#include <stdio.h>
#include <stdlib.h>

// Prototypes
int testVars(int, int *);

int main(int argc, char const *argv[]) {
  int test = 5;
  testVars(test, &test);

  printf("\n\n");
  return 0;
}

int testVars(int num, int *p_num) {
    printf("El valor de test es %d y su dirección de memoria es %p\n", num, &num);
    printf("El valor de test es %d y su dirección de memoria es %p\n", *p_num, p_num);
}