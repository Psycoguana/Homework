#include <stdio.h>
#include <stdlib.h>

#define accountsSize 5
// Datos de cuenta, read-only
const int cuenta[accountsSize] = {458, 321, 744, 228, 349};
const char tipo[accountsSize] = {'B', 'A', 'C', 'C', 'A'};
const float saldo[accountsSize] = {458.32, 185, 90, 750.00, 250.00, 633.50};
int i;

// Prototypes
showGreatestFunds(int cuenta[], char type[], float saldo[], int arraySize);

int main(int argc, char const *argv[]) {
  showGreatestFunds(cuenta, tipo, saldo, accountsSize);

  printf("\n\n");
  return 0;
}

// This function is ugly as fuck
showGreatestFunds(int cuenta[], char type[], float saldo[], int arraySize) {
  int greatestFundsIndex = 0;

  for (i = 0; i < arraySize; i++) {
    if (saldo[i] > saldo[greatestFundsIndex]) {
      greatestFundsIndex = i;
    }
  }
  printf(
      "Datos de cuenta con con mayor saldo: \nCuenta nro: %d\nTipo: %c\nSaldo: "
      "$%.2f\n\n",
      cuenta[greatestFundsIndex], type[greatestFundsIndex],
      saldo[greatestFundsIndex]);
}