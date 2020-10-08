#include <stdio.h>
#include <stdlib.h>

#define accountsSize 5
// Datos de cuenta, read-only
int cuenta[accountsSize] = {458, 321, 744, 228, 349};
char tipo[accountsSize] = {'B', 'A', 'C', 'C', 'A'};
float saldo[accountsSize] = {458.32, 185.10, 90.0, 750.00, 250.00};
int i, j;

// Prototypes
int sortArrayDesc(int cuenta[], char type[], float saldo[], int arraySize);
int printBiggerThan(float moneyAmount, float saldo[], int arraySize);

int main(int argc, char const *argv[]) {
  int sortedArray = sortArrayDesc(cuenta, tipo, saldo, accountsSize);
  
  if (sortedArray == 0) {
    printf("Los saldos mayores a %d son: \n", 500);
    printBiggerThan((float)500, saldo, accountsSize);
  }

  printf("\n\n");
  return 0;
}

int sortArrayDesc(int cuenta[], char type[], float saldo[], int arraySize) {
  float auxFloat;
  char auxChar;
  int auxInt;

  for (i = arraySize - 1; i > 0; i--) {
    for (j = i; j >= 0; j--) {
      if (saldo[j] < saldo[j + 1]) {
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
  return 0;
}

int printBiggerThan(float moneyAmount, float saldo[], int arraySize) {
  for (i = 0; i < arraySize; i++) {
    if (saldo[i] >= moneyAmount) {
      printf("%.2f\n", saldo[i]);
    }
  }
  return 0;
}