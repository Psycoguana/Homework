/* Dado el archivo con artículos del punto 3, cree dos índices que permitan ver los artículos
ordenados alfabéticamente por descripción,
y el otro ver los artículos con stock menor a 5. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30

struct Product_data {
  int article_number;
  char description[MAX_CHARS];
  float price;
  char proveedor[MAX_CHARS];
  int stock;
};

struct Index {
  int id;
  int article_number;
};

int create_alfa_index(struct Product_data *, int);
int _read_index();
bool _not_ordered(char *, char *);
int _load_in_memory(struct Product_data *, FILE *);
int _get_filesize(FILE *);

int main(int argc, char const *argv[]) {
  struct Product_data *product_array;

  FILE *file = fopen("lista.dat", "rb");
  if (!file) {
    printf("Error al abrir archivo para lectura\n\n");
    exit(EXIT_FAILURE);
  }

  int file_size = _get_filesize(file);
  product_array = (struct Product_data *)malloc(file_size);

  /* Checkeo que el pedido de memoria se haya hecho correctamente. */
  if (!product_array) {
    printf("Error al asignar un espacio de %d bytes.\n\n", file_size);
    exit(EXIT_FAILURE);
  }

  _load_in_memory(product_array, file);
  create_alfa_index(product_array, file_size / sizeof(struct Product_data));

  /* Libero todo lo que ya no necesito */
  free(product_array);
  fclose(file);

  printf("\n\n");
  return 0;
}

int create_alfa_index(struct Product_data *product_array, int products_size) {
  int i, j;
  struct Index index;

  FILE *file_index = fopen("index_alfa.dat", "wb");
  if (!file_index) {
    printf("Error al crear el índice...\n\n");
    exit(EXIT_FAILURE);
  }

  /* Ordeno alfabéticamente */
  for (i = 0; i < products_size - 1; i++) {
    for (j = 0; j < products_size - i - 1; j++) {
      struct Product_data *first = (product_array + j);
      struct Product_data *second = (product_array + j + 1);
      struct Product_data aux;

      if (_not_ordered(first->description, second->description)) {
        aux = *first;
        *first = *second;
        *second = aux;
      }
    }
  }

  /* Inflo la estructura Index y la escribo */
  for (i = 0; i < products_size; i++) {
    index.id = i;
    index.article_number = (product_array + i)->article_number;

    fwrite(&index, sizeof(index), 1, file_index);
  }
  fclose(file_index);
  _read_index();
}

int _read_index() {
  struct Index index;

  FILE *file = fopen("index_alfa.dat", "rb");
  if (!file) {
    printf("Error al crear el índice...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&index, sizeof(index), 1, file);
  while (!feof(file)) {
    printf("Index id: %d\n", index.id);
    printf("Art number: %d\n\n", index.article_number);
    fread(&index, sizeof(index), 1, file);
  }
}

bool _not_ordered(char *string_1, char *string_2) { return (strcmp(string_1, string_2) > 0); }

int _load_in_memory(struct Product_data *array, FILE *file) {
  int i;
  int elements = _get_filesize(file) / sizeof(*array);

  for (i = 0; i < elements; i++) {
    fread(array + i, sizeof(*array), 1, file);
  }
  rewind(file);
}

int _get_filesize(FILE *file) {
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  return size;
}