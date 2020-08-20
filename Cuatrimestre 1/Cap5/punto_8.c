#include <stdio.h>
#include <stdlib.h>

#define accountsSize 5
int i;

// Prototypes
showAccountType(char desiredType, int cuenta[], char type[], float saldo[],
                  int arraySize);

int main(int argc, char const *argv[]) {
  int cuenta[accountsSize] = {458, 321, 744, 228, 349};
  char tipo[accountsSize] = {'B', 'A', 'C', 'C', 'A'};
  float saldo[accountsSize] = {458.32, 185, 90, 750.00, 250.00, 633.50};

  showAccountType('A', cuenta, tipo, saldo, accountsSize);

  printf("\n\n");
  return 0;
}

// This function is ugly as fuck
showAccountType(char desiredType, int cuenta[], char type[], float saldo[],
                  int arraySize) {
  for (i = 0; i < arraySize; i++) {
    if (type[i] == desiredType) {
      printf("Datos de cuenta: \nCuenta nro: %d\nTipo: %c\nSaldo: $%.2f\n\n",
             cuenta[i], type[i], saldo[i]);
    }
  }
}