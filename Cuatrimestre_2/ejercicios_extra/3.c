/* Se tiene un archivo lista.dat que contiene la base de datos de artículos de un negocio:
* Número de artículo(int)
* Descripción (string de 30 caracteres)
* Precio(float)
* Proveedor(string de 30)
* Stock(int)
Actualizar esta base de datos aplicando un 20% de aumento a todos los artículos del proveedor “PEREZ”.
Para probar el funcionamiento deberá crear primero el archivo con un programa auxiliar. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30

struct Product_data {
  int article_number;
  char description[MAX_CHARS];
  float price;
  char proveedor[MAX_CHARS];
  int stock;
};

int main(int argc, char const *argv[]) {
  FILE *file = fopen("lista.dat", "r+b");

  if (!file) {
    printf("Error al abrir archivo para escritura\n\n");
    exit(EXIT_FAILURE);
  }

  struct Product_data product_data;

  fread(&product_data, sizeof(product_data), 1, file);
  while (!feof(file)) {
    if (strcmp(product_data.proveedor, "PEREZ") == 0) {
      product_data.price += product_data.price * 20 / 100;
    }
    print_article(&product_data);
    fread(&product_data, sizeof(product_data), 1, file);
  }

  printf("\n\n");
  return 0;
}

int print_article(struct Product_data *productos) {
  printf("#######################\n");
  printf("# Proveedor: %s\n", productos->proveedor);
  printf("# Producto: %s\n", productos->description);
  printf("# Precio: %.2f\n", productos->price);
  printf("# Stock: %d\n", productos->stock);
  printf("# Número de artículo: %d\n", productos->article_number);
  printf("#######################\n\n");
}
