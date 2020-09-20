/*

1.  HACER UN PROGRAMA DE LECTURA ✔️
2.  MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8 ✔️
3.  DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA
4.  PERMITIR EL INGRESO DE UN #ART Y BUSCARLO ✔️
5.  INDEXAR EL ARCHIVO
6.  ORDENAR EL INDICE
7.  REPETIR EL PUNTO 4 CON UNA BUSQUEDA BINARIA INDEXADA.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Article {
  short int article_number;
  char code[50];
  char description[100];
  char fabricante[50];
  short int stock;
};

struct Index {
  int id;
  int article_number;
};

int show_all(FILE *);
int show_max_stock(FILE *, int);
int get_file_size(FILE *);
int bigger_provider(FILE *);
int find_article(FILE *);
int create_index(FILE *);
int read_index(FILE *);

int main(int argc, char const *argv[]) {

  FILE *file = fopen("/home/psyco/Programming/C/Cuatrimestre_2/indexados/BDARTICULOS", "rb");
  if (!file) {
    printf("Error intentando leer el archivo...\n\n");
    printf("\n\n");
  }

  /* show_all(file); */
  /* show_max_stock(file, 8); */
  /* bigger_provider(file); */
  /* find_article(file); */
  create_index(file);

  printf("\n\n");
  return 0;
}

int create_index(FILE *articles_file) {
  /* Yo lo voy a hacer con structs, la verdad no sé si es lo mejor, pero no veo porque no. */
  int i;
  struct Index index;
  struct Article article;
  FILE *index_file = fopen("index.dat", "wb");

  if (!index_file) {
    printf("Error al crear el índice D':\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&article, sizeof(article), 1, articles_file);
  while (!feof(articles_file)) {

    index.id = i;
    index.article_number = article.article_number;
    int a = fwrite(&index, sizeof(index), 1, index_file);

    int b = fread(&article, sizeof(article), 1, articles_file);
    i++;
  }

  fseek(articles_file, 0, SEEK_SET);
  fseek(index_file, 0, SEEK_SET);

  read_index(index_file);
}

int read_index(FILE *index_file) {
  struct Index index;

  fread(&index, sizeof(index), 1, index_file);
  while (!feof(index_file)) {
    printf("ID: %d\n", index.id);
    printf("Article_number: %d\n\n", index.article_number);

    fread(&index, sizeof(index), 1, index_file);
  }
}

int find_article(FILE *file) {
  int i;
  int times_found = 0;
  struct Article article;
  short int article_number;

  printf("Ingrese el número de articulo que deseas buscar: ");
  scanf("%d", &article_number);

  fread(&article, sizeof(article), 1, file);
  while (!feof(file)) {
    if (article.article_number == article_number) {
      printf("\n");
      print_article(&article);
      times_found++;
    }

    fread(&article, sizeof(article), 1, file);
  }
  fseek(file, 0, SEEK_SET);

  if (times_found == 0) {
    printf("Artículo no encontrado :'(");
  }
}

int bigger_provider(FILE *file) {}

int show_max_stock(FILE *file, int max_stock) {
  struct Article article;

  fread(&article, sizeof(article), 1, file);
  while (!feof(file)) {
    if (article.stock < max_stock) {
      print_article(&article);
    }
    fread(&article, sizeof(article), 1, file);
  }
  fseek(file, 0, SEEK_SET);
}

int show_all(FILE *file) {
  struct Article article;

  fread(&article, sizeof(article), 1, file);
  while (!feof(file)) {
    print_article(&article);
    fread(&article, sizeof(article), 1, file);
  }
  fseek(file, 0, SEEK_SET);
}

int print_article(struct Article *article) {
  printf("Número de artículo: %d\n", article->article_number);
  printf("Descripción: %s\n", article->description);
  printf("Fabricante: %s\n", article->fabricante);
  printf("Stock: %d\n\n", article->stock);
}

int get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  return size;
}
