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

  char last_proveedor[MAX_CHARS_2] = "";
  fread(&product_data, sizeof(product_data), 1, products);
  while (!feof(products)) {

    /* Hago un checkeo para que los proveedores no se agreguen más de una vez. */
    if (strcmp(product_data.proveedor, last_proveedor) != 0) {
      srand(ftell(products));
      int random_aumento = rand() % 99;
      strcpy(aumentos.proveedor, product_data.proveedor);
      aumentos.porcentaje = random_aumento;

      fwrite(&aumentos, sizeof(aumentos), 1, aumentos_file);
      strcpy(last_proveedor, aumentos.proveedor);
    }
    fread(&product_data, sizeof(product_data), 1, products);
  }
  fclose(products);
  fclose(aumentos_file);
  
  return 0;
}
