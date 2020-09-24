/* Se dispone del mismo archivo lista.dat del ejercicio anterior y de un archivo adicional llamado
novedades.dat que contiene los nombres de proveedores(string de 20) y porcentajes de aumentos de precio(int).
Actualizar lista.dat según lo que indica novedades.dat. */

/* El profe dijo en el 3 que usemos un char de 30, ahora un char de 20. Podría causar errores */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  FILE *file_productos = fopen("lista.dat", "r+b");
  FILE *file_aumentos = fopen("novedades.dat", "rb");

  if (!file_productos || !file_aumentos) {
    printf("Error abriendo algún archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  /* Primero recorro lista.dat */
  while (!feof(file_aumentos)) {

    /* Ahora recorro los aumentos */
    fread(&product_data, sizeof(product_data), 1, file_productos);
    while (!feof(file_productos)) {
      if (strcmp(product_data.proveedor, aumentos.proveedor) == 0) {

        product_data.price += product_data.price * aumentos.porcentaje / 100;

        fseek(file_productos, -sizeof(product_data), SEEK_CUR);
        fwrite(&product_data, sizeof(product_data), 1, file_productos);
        fseek(file_productos, 0, SEEK_CUR);
      }
      fread(&product_data, sizeof(product_data), 1, file_productos);
    }
    rewind(file_productos);

    fread(&aumentos, sizeof(aumentos), 1, file_aumentos);
  }

  fclose(file_productos);
  fclose(file_aumentos);

  printf("\n\n");
  return 0;
}
