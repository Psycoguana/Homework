/* Se dispone de dos archivos binarios(ventas realizadas y provincias) compuestos respectivamente de
estas estructuras:

struct venta {
  char vendedor[60];
  float monto;
  int codigoprovincia;
};

 struct provincia {
  char nombre[40];
  int codigoprovincia;
};

Realice un programa que muestre en pantalla cuántas ventas se hicieron en cada provincia.
Debe imprimir el nombre de las provincias y la cantidad de ventas.
Los archivos originales solo están accesibles para modo lectura. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Venta {
  char vendedor[60];
  float monto;
  int codigoprovincia;
};

struct Provincia {
  char nombre[40];
  int codigoprovincia;
};

long _get_file_size(FILE *);
void _sort_ventas(struct Venta *, int);
void *_load_in_memory(FILE *, int);

int main(int argc, char const *argv[]) {
  int i, j;

  FILE *file = fopen("ventas.dat", "rb");
  FILE *file_provincias = fopen("provincias.dat", "rb");
  if (!file || !file_provincias) {
    printf("Error abriendo el archivo\n\n");
    exit(EXIT_FAILURE);
  }

  /* Alojo ambos arrays de estructuras en memoria */
  struct Venta *ventas_array = (struct Venta *)_load_in_memory(file, sizeof(struct Venta));
  struct Provincia *provincias_array =
      (struct Provincia *)_load_in_memory(file_provincias, sizeof(struct Provincia));

  /* Como los archivos están cargados en memoria, ya no los necesito */
  fclose(file);
  fclose(file_provincias);

  long ventas_amount = _get_file_size(file) / sizeof(*ventas_array);
  long provincias_size = _get_file_size(file_provincias) / sizeof(*provincias_array);

  _sort_ventas(ventas_array, ventas_amount);

  /* Recorre cada provincia */
  for (i = 0; i < provincias_size; i++) {
    int sum = 0;
    /* Recorre cada venta */
    for (j = 0; j < ventas_amount; j++) {
      if ((ventas_array + j)->codigoprovincia == (provincias_array + i)->codigoprovincia)
        sum++;
    }
    printf("%s realizó %d ventas\n", (provincias_array + i)->nombre, sum);
  }

  free(provincias_array);
  free(ventas_array);

  printf("\n\n");
  return 0;
}

void *_load_in_memory(FILE *file, int struct_size) {
  long file_size = _get_file_size(file);
  int elements_amount = file_size / struct_size;

  void *array = malloc(file_size);
  if (!array) {
    printf("Error al asignar memoria...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(array, struct_size, elements_amount, file);

  return array;
}

void _sort_ventas(struct Venta *ventas_array, int size) {
  int i, j;
  struct Venta aux;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      struct Venta *first = (ventas_array + j);
      struct Venta *second = (ventas_array + j + 1);

      if (first->codigoprovincia > second->codigoprovincia) {
        aux = *first;
        *first = *second;
        *second = aux;
      }
    }
  }
}

long _get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);
  return size;
}