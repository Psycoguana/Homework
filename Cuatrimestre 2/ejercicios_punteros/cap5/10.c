// Tomando como base el mismo ejemplo de vectores apareados con cuentas bancarias,
// muestre en pantalla todos los datos de las cuentas cuyo saldo supere los $500,
// ordenados en forma decreciente de saldo(los más grandespri - mero).

#include <stdio.h>
#include <stdlib.h>

showBalanceAbove(float *, char[], float[], int *);

int main(int argc, char const *argv[]) {
  int size = 5;
  char accountType[] = {'A', 'B', 'C', 'A', 'B'};
  float accountBalance[] = {100.3, 98.34, 612.54, 234.6, 2.6};
  float maxBalance = 500;

  showBalanceAbove(&maxBalance, accountType, accountBalance, &size);

  printf("\n\n");
  return 0;
}

showBalanceAbove(float *maxBalance, char accountType[], float accountBalance[], int *size) {
    int i;
    for (i=0; i< *size; i++) {
        if ( *(accountBalance+i) <= *maxBalance ){
            printf("Account type: %c\tBalance: %.2f\n", *(accountType+i), *(accountBalance+i));
        }
    }
}
