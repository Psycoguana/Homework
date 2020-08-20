/*
Construya una función de comparación de strings similar a strcmp() que
contemple la existencia de las letras “ñ” y "Ñ".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// PROTOTYPE
char* myStrCmp(char* string_one, char* string_two);

int i;

int main(int argc, char const* argv[]) {
    printf("%d", myStrCmp("Ñ", "Ñ"));

  printf("\n\n");
  return 0;
}

char* myStrCmp(char* string_one, char* string_two) {
  
  // Si no son del mismo tamaño, no necesito checkear nada más, no son iguales.
  // Ademas evita SegFaults al comparar strings usando sus índices.
  if (strlen(string_one) != strlen(string_two)) {
    return 0;
  }

  // Si cualquier elemento del string no es igual, paro el programa.
  for (i = 0; i < strlen(string_one); i++) {
    if (string_one[i] != string_two[i]) {
        return 0;
    }
  }
  return 1;
}
