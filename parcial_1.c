#include <stdio.h>
#include <stdlib.h>

// PROTOTYPE
int input_card();
int show_card(int card_1, int card_2);
float input_compras();
int ask_day();
int _calculate_visa(int card_1);
float _discount_price(float price, int discount);

// DEFINES
#define VISA_DIA 2
#define VISA_DESC 20
#define MASTER_DIA 4
#define MASTER_DESC 25

// GLOBALS
int card_1, card_2;
float suma_compras;
int isVisa = 1;  // Visa = 1    Master = 0

int main(int argc, char const *argv[]) {
  int exit = 0;
  while (exit == 0) {
    int option = 0;
    printf(
        "Eliga una opcion:\n1. Ingrese Número de su tarjeta\n2. Ver tarjeta "
        "ingresada\n3. Ingrese montos de compras\n4. Ver monto a pagar con "
        "descuento\n\n\n0. Salir\n");
    scanf(" %d", &option);

    switch (option) {
      case 0:
        exit = -1;
        break;
      case 1:
        input_card();
        break;
      case 2:
        show_card(card_1, card_2);  // INCOMPLETE
        break;
      case 3:
        suma_compras = input_compras();
        break;

      case 4:
        ask_day(isVisa);
        break;
      default:
        break;
    }
  }

  return 0;
}

int input_card() {
  printf("Ingrese los primeros 8 números de su tarjeta: ");
  scanf(" %d", &card_1);
  printf("\nIngrese los últimos 8 números de su tarjeta: ");
  scanf(" %d", &card_2);

  return 0;
}

int show_card(int card_1, int card_2) {
  isVisa = _calculate_visa(card_1);
  if (isVisa == 1) {
    printf("El número de su tarjeta Visa es: ");
  } else if (isVisa == 0) {
    printf("El número de su tarjeta Mastercard es: ");
  }
  printf("%d%d\n\n", card_1, card_2);
}

int _calculate_visa(int card_1) {
  int i;
  int temp = card_1;

  for (i = 0; i < 6; i++) {  // Divido por 10, "sacando" los últimos números
    temp /= 10; 
    if (temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55) { // Checkeo si es mastercard
      isVisa = 0;  // Es Master
    } else if (temp == 4) {
      isVisa = 1;  // Es Visa
    }
  }
  return isVisa;
}

float input_compras() {
  float compras_sum = 0.0;
  float current_input = 0.0;

  while (current_input >= 0) {
    printf("Ingrese un monto para su compra: $");
    scanf(" %f", &current_input);

    if (current_input > 0) { // Si el monto de la compra no es negativo sumo la compra
      compras_sum += current_input;
    }
  }

  printf("El total a pagar es de: $%.2f\n\n", compras_sum);
  return compras_sum;
}

int ask_day(int isVisa) {
  // Esta parte del código es horrible, usando chars podría poner un poco menos de boilerplate.
  
  
  int shopping_day;
  float discounted_price = suma_compras;
  float percent_discount = 0.0;

  printf(
      "\nEn que dia hizo la compra?\n0. Domingo\n1. Lunes\n2. Martes\n3. "
      "Miércoles\n4. Jueves\n5. Viernes\n6. Sábado\n");
  scanf("%d", &shopping_day);

  if (shopping_day == VISA_DIA && isVisa == 1) {
    discounted_price = _discount_price(suma_compras, VISA_DESC);
    printf("\nAplica descuento del %%%d por tener Visa y comprar un Martes. Total a pagar: $%.2f\n",
        VISA_DESC, discounted_price);

  } else if (shopping_day == MASTER_DIA && isVisa == 0) {
    discounted_price = _discount_price(suma_compras, MASTER_DESC);

    printf("\nAplica descuento del %%%d por tener Mastercard y comprar un Jueves. Total a pagar: $%.2f\n",
        MASTER_DESC, discounted_price);

  } else if (shopping_day >= 0 && shopping_day < 7) {
    printf("\nNo hay descuento. Total del precio: $%.2f\n\n", discounted_price);
  } else {
    printf("\nOpción inválida. Elija un número entre 0 y 6\n");
  }

  return 0;
}

float _discount_price(float price, int discount) {
  int dicount_amount = (suma_compras * discount) / 100;
  return price - dicount_amount;
}