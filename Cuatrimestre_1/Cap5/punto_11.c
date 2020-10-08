#include <stdio.h>
#include <stdlib.h>

i;
const BUCEADORES_AMOUNT = 15;

int inputCaptura();
int showArray(int buceadores[], int arraySize);

int main(int argc, char const *argv[]) {
  int capturador = 0;
  // Menos mal que se pueden inicializar todos los valores con un solo número :'D
  int buceadores[15] = {0};

  while (capturador >= 0) {
    capturador = inputCaptura();
    // Usar -1 porque arrays
    buceadores[capturador - 1]++;
    showArray(buceadores, sizeof(buceadores) / sizeof(buceadores[0]));
  }

  printf("\n\n");
  return 0;
}

int inputCaptura() {
  int buceador;
  printf("Ingrese el número del buceador que capturó: ");
  scanf("%d", &buceador);
  return buceador;
}

int showArray(int buceadores[], int arraySize) {
  for (i = 0; i < arraySize; i++) {
    printf("Buceador #%d: %d\n", i + 1, buceadores[i]);
  }
}