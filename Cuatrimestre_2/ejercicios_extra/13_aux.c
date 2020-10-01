#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 30

struct Articulo {
  char desc[MAX_CHARS];
  char proveedor[MAX_CHARS];
  int precio;
};

int main(int argc, char const *argv[]) {
  int i;
  struct Articulo articulo;

  FILE *file = fopen("articulos_pintureria.dat", "wb");
  if (!file) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  char *proveedores[MAX_CHARS] = {"PEREZ", "PRAZZI", "KERBAN", "MARCO", "POLO", "NELA", "ALEN", "OCRAM"};
  char *descriptions[MAX_CHARS] = {"Pintura", "Pincel", "Brocha", "Lija"};

  srand(time(0));
  for (i = 0; i < 50; i++) {
    /* Hardcoded porque no doy más */
    int rand_prov = rand() % 7;
    int rand_desc = rand() % 3;

    strcpy(articulo.proveedor, proveedores[rand_prov]);
    strcpy(articulo.desc, descriptions[rand_desc]);
    articulo.precio = rand() % 501;

    fwrite(&articulo, sizeof(articulo), 1, file);
  }

  printf("\n\n");
  return 0;
}