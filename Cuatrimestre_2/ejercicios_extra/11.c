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
struct Venta *_load_ventas();
struct Provincia *_load_provincias();
void _sort_array(struct Venta *, int);

int main(int argc, char const *argv[]) {
  int i, j;
  struct Venta *ventas_array = _load_ventas();
  struct Provincia *provincias_array = _load_provincias();

  FILE *file = fopen("ventas.dat", "rb");
  FILE *file_provincias = fopen("provincias.dat", "rb");

  if (!file || !file_provincias) {
    printf("Error abriendo el archivo\n\n");
    exit(EXIT_FAILURE);
  }

  long ventas_amount = _get_file_size(file) / sizeof(*ventas_array);
  long provincias_size = _get_file_size(file_provincias) / sizeof(*provincias_array);

  _sort_array(ventas_array, ventas_amount);

  for (i = 0; i < provincias_size; i++) {
    int sum = 0;
    for (j = 0; j < ventas_amount; j++) {
      if ((ventas_array + j)->codigoprovincia == (provincias_array + i)->codigoprovincia)
        sum++;
    }
    printf("%s realizó %d ventas\n", (provincias_array + i)->nombre, sum);
  }

  free(provincias_array);
  free(ventas_array);

  fclose(file);
  fclose(file_provincias);

  printf("\n\n");
  return 0;
}

struct Provincia *_load_provincias() {
  int i;
  FILE *file = fopen("provincias.dat", "rb");
  if (!file) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  long file_size = _get_file_size(file);
  struct Provincia *array = malloc(file_size);
  int elements_size = file_size / sizeof(*array);

  for (i = 0; i < elements_size; i++) {
    fread((array + i), sizeof(*array), 1, file);
  }
  fclose(file);
  return array;
}

struct Venta *_load_ventas() {
  int i;

  FILE *file = fopen("ventas.dat", "rb");
  if (!file) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  long file_size = _get_file_size(file);
  struct Venta *ventas_array = malloc(file_size);
  int elements = file_size / sizeof(*ventas_array);

  for (i = 0; i < elements; i++) {
    fread((ventas_array + i), sizeof(*ventas_array), 1, file);
  }
  fclose(file);
  return ventas_array;
}

void _sort_array(struct Venta *ventas_array, int size) {
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