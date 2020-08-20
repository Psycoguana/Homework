// Tomando como base el ejemplo de vectores apareados con cuentas bancarias,
// muestre en pantalla todos los datos de cuentas de tipo “A”.

#include <stdio.h>
#include <stdlib.h>

const int size = 5;

showAccountType(char, char[], float[], int *);

int main(int argc, char const *argv[]) {
  char accountType[] = {'A', 'B', 'C', 'A', 'B'};
  float accountBalance[] = {100.3, 98.34, 412.54, 234.6, 2.6};

  showAccountType('A', accountType, accountBalance, &size);

  printf("\n\n");
  return 0;
}

showAccountType(char accountType, char array1[], float array2[], int *size) {
  int i;
  for (i = 0; i < *size; i++) {
    if (*(array1 + i) == accountType) {
      printf("Account type: %c\tBalance: %.2f\n", *(array1 + i), *(array2 + i));
    }
  }
}
