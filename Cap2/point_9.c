#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float factura = 0, discount_percent = 0;

  printf("Ingresar total de la factura: ");
  scanf("%f", &factura);
  printf("Ingresar total a descontar: ");
  scanf("%f", &discount_percent);

  float discount = (discount_percent * factura) / 100;

  printf("El precio con un descuento de %%%.2f es: $%.2f", discount_percent,
         factura - discount);

  printf("\n\n");
  return 0;
}
