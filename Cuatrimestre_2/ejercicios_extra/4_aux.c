#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 30
#define MAX_CHARS_2 20

struct Product_data {
  int article_number;
  char description[MAX_CHARS];
  float price;
  char proveedor[MAX_CHARS];
  int stock;
};

struct Aumentos {
  char proveedor[MAX_CHARS_2];
  int porcentaje;
};

int main(int argc, char const *argv[]) {
  struct Product_data product_data;
  struct Aumentos aumentos;

  FILE *products = fopen("lista.dat", "r+b");
  FILE *aumentos_file = fopen("novedades.dat", "wb");

  if (!products || !aumentos_file) {
    printf("Error abriendo los archivos...\n");
    exit(EXIT_FAILURE);
  }

  fread(&product_data, sizeof(product_data), 1, products);
  while (!feof(products)) {
    srand(ftell(products));
    int random_aumento = rand() % 99;
    strcpy(aumentos.proveedor, product_data.proveedor);
    aumentos.porcentaje = random_aumento;

    fwrite(&aumentos, sizeof(aumentos), 1, aumentos_file);
    fread(&product_data, sizeof(product_data), 1, products);
  }
  fclose(products);
  fclose(aumentos_file);
  readF();
  return 0;
}
