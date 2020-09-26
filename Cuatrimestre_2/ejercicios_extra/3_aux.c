/* Programa auxiliar que debe crear un archivo "lista.dat" con el siguiente contenido:
* Número de artículo(int)
* Descripción (string de 30 caracteres)
* Precio(float)
* Proveedor(string de 30)
* Stock(int)

Varias entradas deben ser del proveedor PEREZ.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 30
#define ENTRY_NUM 10

struct Product_data {
  int article_number;
  char description[MAX_CHARS];
  float price;
  char proveedor[MAX_CHARS];
  int stock;
};

int generate_random_data();

int main(int argc, char const *argv[]) {
  int i;
  struct Product_data product_data;

  generate_random_data();

  printf("\n\n");
  return 0;
}

int generate_random_data() {
  int i, j;
  int count = 1;

  FILE *file = fopen("lista.dat", "w+b");
  if (!file) {
    printf("Error al abrir el archivo para escritura...\n\n");
    exit(EXIT_FAILURE);
  }

  char *proveedores[MAX_CHARS] = {"PEREZ", "PRAZZI", "KERBAN", "MARCO", "POLO", "NELA", "ALEN", "OCRAM"};
  char *descriptions[MAX_CHARS] = {"Arroz",     "Coca",  "Jamón", "Pizza",
                                   "Chocolate", "Patys", "Queso", "Si, todo es comida"};

  int proveedores_size = sizeof(proveedores) / MAX_CHARS;
  int products_size = sizeof(descriptions) / MAX_CHARS;

  struct Product_data current_data;

  for (i = 0; i < proveedores_size; i++) {
    for (j = 0; j < products_size; j++) {
      current_data.article_number = count++;
      strcpy(current_data.description, *(descriptions + j));
      strcpy(current_data.proveedor, *(proveedores + i));
      current_data.stock = rand() % 100;

      /* Algo raro y feo para obtener un float única para cada artículo. */
      float price = (j + 1) * 3.2;
      current_data.price = price;
      fwrite(&current_data, sizeof(current_data), 1, file);
    }
  }
}
