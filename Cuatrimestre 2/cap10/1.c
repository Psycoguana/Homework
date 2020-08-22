// Construir un programa que se denomine POTENCIA.EXE y que se invoque desde línea de comandos
//     con dos argumentos enteros X e Y, y muestre en pantalla el valor de X elevado a la Y.

#include <stdio.h>
#include <stdlib.h>

int getPotencia(int, int);

int main(int argc, char const *argv[]) {
  printf("\n\n");

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  printf("%d^%d = %d", x, y, getPotencia(x, y));

  printf("\n\n");
  return 0;
}

int getPotencia(int X, int Y) { // No uso punteros porque también consumen 4 bytes de memoria
  int i;
  int aux = X;
  for (i = 1; i < Y; i++) {
    aux *= X;
  }
  return aux;
}
