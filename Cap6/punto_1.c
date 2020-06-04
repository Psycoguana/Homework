/*
Realizar un programa que permita comprobar la diferencia
de comportamiento entre las funciones gets() y scanf().
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int amount = 20;
  char string_gets[amount], string_scanf[amount];

  // Idealmente se debería ingresar un string con espacios.
  
  printf("Leyendo input con gets(): ");
  gets(string_gets);
  printf("\n%s", string_gets);

  printf("\n\nLeyendo input con scanf(): ");
  scanf("%s", &string_scanf);
  printf("\n%s", string_scanf);

  printf("\n\n");
  return 0;
}
