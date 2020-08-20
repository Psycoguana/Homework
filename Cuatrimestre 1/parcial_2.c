#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto {
  char nombre[40];
  float precio;
  int ventas_mes[12];
};
#define CANT_PRODUCTOS 4

// Prototype
int mostrar_ventas_anio(struct producto[], int, char[]);
int inicializar(struct producto[], int);
int mostrar_precio(struct producto[], int);
float calcular_ventas_totales(struct producto[], int);
int mostrar_mas_vendido(struct producto[], int);
int mostrar_alfabetico(struct producto[], int);

int main() {
  struct producto ventas[CANT_PRODUCTOS];
  float aux = 0.0;
  /* PUNTO 1: Inicializar el vector de ventas_mes con ceros, para todos los productos */
  inicializar(ventas, CANT_PRODUCTOS);
  /* ahora cargo algunos productos para poder trabajar, no modificar esto */
  strcpy(ventas[0].nombre, "Arandela");
  ventas[0].precio = 1.5;
  ventas[0].ventas_mes[0] = 300; /* cantidad de arandelas vendidas en enero */
  ventas[0].ventas_mes[5] = 100; /* cantidad de arandelas vendidas en junio */
  ventas[0].ventas_mes[11] = 50; /* cantidad de arandelas vendidas en diciembre */
  strcpy(ventas[1].nombre, "Tuerca");
  ventas[1].precio = 2.2;
  ventas[1].ventas_mes[0] = 200;
  ventas[1].ventas_mes[5] = 100;
  ventas[1].ventas_mes[11] = 50;
  strcpy(ventas[2].nombre, "Tornillo");
  ventas[2].precio = 3.5;
  ventas[2].ventas_mes[0] = 400;
  ventas[2].ventas_mes[5] = 200;
  ventas[2].ventas_mes[11] = 150;
  strcpy(ventas[3].nombre, "Tarugo");
  ventas[3].precio = 5.2;
  ventas[3].ventas_mes[0] = 500;
  ventas[3].ventas_mes[5] = 300;
  ventas[3].ventas_mes[11] = 250;
  /* PUNTO 2: Mostrar las ventas que tuvo un producto en todo el año, dado su nombre */
  /* Resultado esperado: Tornillo 750 unidades */
  mostrar_ventas_anio(ventas, CANT_PRODUCTOS, "Tornillo");
  /* PUNTO 3: Mostrar todos los productos en orden decreciente de precio (más caros primero). */
  /* Resultado esperado: Tarugo Tornillo Tuerca Arandela */
  mostrar_precio(ventas, CANT_PRODUCTOS);
  /* PUNTO 4: Mostrar todos los productos en orden alfabético. */
  /* Resultado esperado: Arandela Tarugo Tornillo Tuerca */
  // mostrar_alfabetico(ventas, CANT_PRODUCTOS);
  /* PUNTO 5: Calcular y retornar el dinero total vendido en el año */
  /* Resultado esperado: $ 8855.00 */
  aux = calcular_ventas_totales(ventas, CANT_PRODUCTOS);
  printf("$ %.2f", aux);
  /* PUNTO 6: Mostrar el nombre del producto más vendido (en cantidad) en el año */
  /* Resultado esperado: Tarugo 1050 unidades */
  mostrar_mas_vendido(ventas, CANT_PRODUCTOS);
}

int inicializar(struct producto ventas[], int cant_prods) {
  int i, j;

  for (i = 0; i < cant_prods; i++) {
    for (j = 0; j < 11; j++) {
      ventas[i].ventas_mes[j] = 0;
    }
  }
}

int mostrar_ventas_anio(struct producto producto[], int prod_amount, char product_name[]) {
  int i, j;
  int total = 0;

  for (i = 0; i < prod_amount; i++) {
    if (strcmp(producto[i].nombre, product_name) == 0) {
      for (j = 0; j < 12; j++) {
        total += producto[i].ventas_mes[j];
      }
    }
  }
  printf("El producto: %s fue vendido %d veces en el año\n", product_name, total);
}

int mostrar_precio(struct producto producto[], int prod_amount) {
  int i, j;
  struct producto aux;
  for (i = 0; i < prod_amount; i++) {
    for (j = 0; j < prod_amount - i - 1; j++) {
      if (producto[j].precio < producto[j + 1].precio) {
        aux = producto[j];
        producto[j] = producto[j + 1];
        producto[j + 1] = aux;
      }
    }
  }
  printf("Productos ordenados por su precio: ");
  for (i = 0; i < prod_amount; i++) {
    printf("\n%s: $%.2f ", producto[i].nombre, producto[i].precio);
  }
  printf("\n");
}

float calcular_ventas_totales(struct producto producto[], int cant_prod) {
  int i, j;
  float total = 0;
  int mes = 0;

  for (i = 0; i < cant_prod; i++) {
    for (j = 0; j < 12; j++) {
      mes += producto[i].ventas_mes[j];
    }
    total += producto[i].precio * mes;
    mes = 0;
  }
  return total;
}

int mostrar_mas_vendido(struct producto producto[], int cant_prod) {
  int i, j;
  int tempTotal = 0, total = 0;
  int good_index;

  for (i = 0; i < cant_prod; i++) {
    tempTotal = 0;
    for (j = 0; j < 12; j++) {
      tempTotal += producto[i].ventas_mes[j];
    }
    if (tempTotal > total) {
      total = tempTotal;
      good_index = i;
    }
  }
  printf("\nProducto más vendido: %s con %d unidades", producto[good_index].nombre, total);
}

int mostrar_alfabetico(struct producto producto[], int cant_prod) {
  int i, j, k;
  struct producto aux;
  int bigger;

  for (i = 0; i < cant_prod; i++) {
    for (j = 0; j < cant_prod - i - 1; j++) {
      for (k = 0; k < 20; k++) {
        if (producto[j].nombre[k] > producto[j + 1].nombre[k]) {
          continue;
        } else if (producto[j].nombre[k] == producto[j + 1].nombre[k]) {
          continue;
        }
        else if (producto[j].nombre[k] > producto[j + 1].nombre[k]) {
          aux = producto[j];
          producto[j] = producto[j + 1];
          producto[j + 1] = aux;
          break;
        }
      }
    }
  }

  for (i = 0; i < cant_prod; i++) {
    printf("\n%s", producto[i].nombre);
  }
}