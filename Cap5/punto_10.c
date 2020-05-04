#include <stdio.h>
#include <stdlib.h>

#define accountsSize 5
// Datos de cuenta, read-only
int cuenta[accountsSize] = {458, 321, 744, 228, 349};
char tipo[accountsSize] = {'B', 'A', 'C', 'C', 'A'};
float saldo[accountsSize] = {458.32, 185.10, 90.0, 750.00, 250.00, 633.50};
int i, j;

// Prototypes
int sortArrayDesc(int cuenta[], char type[], float saldo[], int arraySize);

int main(int argc, char const *argv[]) {
  sortArrayDesc(cuenta, tipo, saldo, accountsSize);

  printf("\n\n");
  return 0;
}

int sortArrayDesc(int cuenta[], char type[], float saldo[], int arraySize) {
  float auxFloat;
  char auxChar;
  int auxInt;

  for (i = 0; i < arraySize - 1; i++) {
    for (j = 0; j < arraySize - i - 1; j++) {
      if (saldo[j] > saldo[j + 1]) {
        auxFloat = saldo[j];
        saldo[j] = saldo[j + 1];
        saldo[j + 1] = auxFloat;

        auxChar = type[j];
        type[j] = type[j + 1];
        type[j + 1] = auxChar;

        auxInt = cuenta[j];
        cuenta[j] = cuenta[j + 1];
        cuenta[j + 1] = auxInt;
      }
    }
  }
  for (i = 0; i < arraySize; i++) {
    printf("%f\n", saldo[i]);
  }
}