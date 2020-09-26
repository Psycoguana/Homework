/* El stock mínimo de cada artículo está almacenado en un archivo llamado SM.dat
estructurado como nº de artículo(int) y cantidad mínima(int). */

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

struct Stock_min {
  int numero_articulo;
  int cantidad_minima;
};

int main(int argc, char const *argv[]) {
  struct Product_data product_data;
  struct Stock_min stock_min;

  FILE *file_stock = fopen("SM.dat", "wb");
  FILE *file_articulos = fopen("lista.dat", "rb");

  if (!file_stock || !file_articulos) {
    printf("Error de archivos. Cada vez me da más paja escribir esto...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&product_data, sizeof(product_data), 1, file_articulos);
  while (!feof(file_articulos)) {

    srand(ftell(file_articulos));
    int rand_min_stock = rand() % 500;

    stock_min.cantidad_minima = rand_min_stock;
    stock_min.numero_articulo = product_data.article_number;
    fwrite(&stock_min, sizeof(stock_min), 1, file_stock);

    fread(&product_data, sizeof(product_data), 1, file_articulos);
  }
  fclose(file_stock);
  fclose(file_articulos);

  printf("\n\n");
  return 0;
}

int read_stock() {
  struct Stock_min stock_min;
  FILE *file_stock = fopen("SM.dat", "rb");
  fread(&stock_min, sizeof(stock_min), 1, file_stock);
  while (!feof(file_stock)){
    
    printf("Art numb: %d\n", stock_min.numero_articulo);
    printf("Art stock: %d\n\n", stock_min.cantidad_minima);
    fread(&stock_min, sizeof(stock_min), 1, file_stock);
  }
}
