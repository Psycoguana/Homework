
/* EJERCICIO 2 : Se dispone del archivo BD cargado con los artículos de un supermercado. Las estructuras que
lo componen tienen la siguiente forma: int ART; char DESC[20]; int STOCK; char PROVE[15]; float COSTO; Cada
proveedor puede suministrar varios artículos .Se pide determinar cual es el proveedor que suministra mayor
cantidad de artículos distintos(se lo considera único). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Articulo {
  int articulo;
  char descripcion[20];
  int stock;
  char proveedor[15];
  float costo;
};

long _get_file_size(FILE *);

int main(int argc, char const *argv[]) {
  int i, j;
  int elements;
  struct Articulo articulo;
  int max_sum = 0, current_sum;
  char max_prov[15] = "", current_prov[15];

  FILE *file = fopen("Cuatrimestre_2/ejercicios_extra/dats/BDPEREZ", "rb");
  if (!file) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  elements = _get_file_size(file) / sizeof(articulo);

  for (i = 0; i < elements; i++) {
    fseek(file, i * sizeof(articulo), SEEK_SET);
    fread(&articulo, sizeof(articulo), 1, file);

    /* Inicializo los datos que voy a usar en el 2do for para comparar
    cada producto con los proveedores uno a uno */
    strcpy(current_prov, articulo.proveedor);
    current_sum = 0;

    fseek(file, 0, SEEK_SET);
    for (j = 0; j < elements; j++) {
      fread(&articulo, sizeof(articulo), 1, file);
      /* Checkeo uno a uno cada articulo, y lo comparo con el proveedor que leí antes */
      if (strcmp(current_prov, articulo.proveedor) == 0) {
          /* Si son iguales, aumento el contador */
        current_sum++;
      }
    }
    /* Cada vez que termina el segundo for, compruebo si el ultimo proveedor que checkeee
    es el proveedor con más artículos */
    if (current_sum > max_sum) {
      strcpy(max_prov, current_prov);
      max_sum = current_sum;
    }
  }
  /* El hacerlo de esta manera en vez de ordenarlo el archivo alfabéticamente es medio una caca porque
  terminas comprobando los proveedores muuuchas mas veces de las necesarias */
  printf("La mayor proveedora es %s con %d artículos\n", max_prov, max_sum);

  fclose(file);
  printf("\n\n");
  return 0;
}

long _get_file_size(FILE *file) {
  float size;
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  rewind(file);
  return size;
}