// Un archivo binario PRODUCTOS.DAT contiene la información de los productos vendidos en un supermercado,
// consistentes en código de artículo(int), proveedor(char de 30) y precio(float).
//
// En otro archivo binario AUMENTOS.DAT se encuentra un vector de estructuras conformadas por:
// nombre de proveedor(char de 30) y un porcentaje(float).
//
// Se pide aplicar a los productos del primer archivo los porcentajes de aumento indicados en el segundo
// archivo. Todos los productos de un mismo proveedor deben recibir el aumento indicado en el segundo archivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Productos {
  int ean;
  char proveedor[30];
  float precio;
};

struct Aumentos {
  char proveedor[30];
  float porcentaje;
};

register_prods(struct Productos *, char *, int);
register_aumentos(struct Aumentos *, char *, int);
show_aumentos(char *, char *);
float search_aumento(char *, char *);

int main(int argc, char const *argv[]) {

  struct Productos productos[] = {{2489, "Coca", 130.50}, {2375, "Coca", 50.34}, {3498, "Leche", 45.78}};
  struct Aumentos aumentos[] = {{"Coca", 32.6}, {"Oreos", 34.6}, {"Leche", 3.6}};

  char file_prods[] = "PRODUCTOS.DAT";
  char file_aumentos[] = "AUMENTOS.DAT";

  int size_prods = sizeof(productos) / sizeof(*productos);
  int size_aumentos = sizeof(aumentos) / sizeof(*aumentos);

  register_prods(productos, file_prods, size_prods);
  register_aumentos(aumentos, file_aumentos, size_aumentos);
  show_aumentos(file_prods, file_aumentos);

  printf("\n\n");
  return 0;
}

register_prods(struct Productos *productos, char *filename, int size) {
  FILE *file = fopen(filename, "wb");
  int i;

  if (!file) {
    printf("Algo salió horriblemente mal intentando abrir el archivo para escritura D:\n\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < size; i++) {
    fwrite(productos + i, sizeof(*productos), 1, file);
  }
  fclose(file);
}

register_aumentos(struct Aumentos *aumentos, char *filename, int size) {
  int i;
  FILE *file = fopen(filename, "wb");

  if (!file) {
    printf("Algo salió horriblemente mal intentando abrir el archivo para escritura D:\n\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < size; i++) {
    fwrite(aumentos + i, sizeof(*aumentos), 1, file);
  }
  fclose(file);
}

show_aumentos(char *prod_path, char *aument_path) {
  FILE *prod_file = fopen(prod_path, "rb");
  struct Productos current_prod;

  if (!prod_file) {
    printf("Algo salió horriblemente mal intentando abrir el archivo para lectura D:\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&current_prod, sizeof(current_prod), 1, prod_file);
  while (!feof(prod_file)) {
    // Busco si existe algún aumento
    float aumento_porcentaje = search_aumento(aument_path, current_prod.proveedor);
    // Calculo el monto que se debe aumentar al precio original
    float precio_extra = (aumento_porcentaje / 100) * current_prod.precio;

    printf("Proveedor: %s\nAumento: $%.2f\n\n", current_prod.proveedor, current_prod.precio + precio_extra);
    fread(&current_prod, sizeof(current_prod), 1, prod_file);
  }
}

float search_aumento(char *aumento_file, char *proveedor) {
  FILE *file = fopen(aumento_file, "rb");
  struct Aumentos aumentos;
  if (!file) {
    printf("Algo salió horriblemente mal intentando abrir el archivo para lectura D:\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&aumentos, sizeof(aumentos), 1, file);
  while (!feof(file)) {
    if (strcmp(proveedor, aumentos.proveedor) == 0) {
      return aumentos.porcentaje;
    }
    fread(&aumentos, sizeof(aumentos), 1, file);
  }
  // Terminé de leer el archivo y no encontré un proveedor que coincida,
  // puedo suponer que no hay ningún aumento.
  return 0;
}