/* Se dispone de un archivo binario con datos de artículos de una pinturería. Los artículos son de distintos
    proveedores. Realice un programa que cree un archivo de texto con los nombres de los proveedores sin
    repetir, uno debajo del otro. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30

struct Articulo {
  char desc[MAX_CHARS];
  char proveedor[MAX_CHARS];
  int precio;
};

long _get_file_size(FILE *);

int main(int argc, char const *argv[]) {
  int i, j;
  struct Articulo articulo;

  FILE *file = fopen("articulos_pintureria.dat", "r+b");
  FILE *f_proveedores = fopen("pintureria_proveedores.txt", "w");

  if (!file || !f_proveedores) {
    printf("Error al abrir el archivo...");
    exit(EXIT_FAILURE);
  }
  
  int articulos_amount = _get_file_size(file) / sizeof(articulo);
  _sort_file(file, articulos_amount);

  char last_name[MAX_CHARS] = "";
  for (i = 0; i < articulos_amount; i++) {
    fread(&articulo, sizeof(articulo), 1, file);

    if (strcmp(last_name, articulo.proveedor) != 0) {
      fprintf(f_proveedores, "%s\n", articulo.proveedor);
      strcpy(last_name, articulo.proveedor);
    }
  }

  printf("\n\n");
  return 0;
}

void _sort_file(FILE *file, int size) {
  int i, j;
  struct Articulo articulo, articulo2, aux;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      fread(&articulo, sizeof(articulo), 1, file);
      fread(&articulo2, sizeof(articulo), 1, file);

      if (strcmp(articulo.proveedor, articulo2.proveedor) > 0) {
        aux = articulo;
        articulo = articulo2;
        articulo2 = aux;

        fseek(file, -2 * sizeof(articulo), SEEK_CUR);
      }
      fseek(file, -sizeof(articulo), SEEK_CUR);
    }
    rewind(file);
  }
}

long _get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);
  return size;
}