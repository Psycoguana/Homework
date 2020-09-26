/* Hacer un programa que ordene un archivo binario que contiene los datos de los alumnos de un curso
(nombre, edad, sexo), en forma alfabética aplicando burbujeo simple, directamente sobre el archivo. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20

struct Alumno {
  char nombre[MAX_CHAR];
  int edad;
  char sexo;
};

int create_file();
bool not_ordered(char *, char *);
int read_file();

int main(int argc, char const *argv[]) {
  int i, j;
  read_file();
  create_file();
  struct Alumno alumno;
  struct Alumno alumno_2;
  struct Alumno alumno_aux;

  FILE *file = fopen("datos_alumnos.dat", "r+b");
  if (!file) {
    printf("Error al crear el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  int elements_amount = get_file_size(file) / sizeof(alumno);

  for (i = 0; i < elements_amount - 1; i++) {
    for (j = 0; j < elements_amount - i - 1; j++) {
      fread(&alumno, sizeof(alumno), 1, file);
      fread(&alumno_2, sizeof(alumno), 1, file);

      if (not_ordered(alumno.nombre, alumno_2.nombre)) {
        /* Si no están ordenados, swappeo */
        alumno_aux = alumno;
        alumno = alumno_2;
        alumno_2 = alumno_aux;

        /* Retrocedo dos lecturas, así puedo hacer dos escrituras */
        fseek(file, -2 * sizeof(alumno), SEEK_CUR);
        fwrite(&alumno, sizeof(alumno), 1, file);
        fwrite(&alumno_2, sizeof(alumno_2), 1, file);
      }
      /* Retrocedo un lugar sin importar si los nombres estában ordenados o no */
      fseek(file, -sizeof(alumno), SEEK_CUR);
    }
    /* Debo hacer un rewind para quitar la flag de EOF */
    rewind(file);
  }

  fclose(file);
  read_file();

  printf("\n\n");
  return 0;
}

bool not_ordered(char *s1, char *s2) { return (strcmp(s1, s2) > 0); }

int get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  return size;
}

int create_file() {
  /* Una función auxiliar para tener algunos datos con los que trabajar */
  int i;
  struct Alumno alumno;

  FILE *file = fopen("datos_alumnos.dat", "wb");
  if (!file) {
    printf("Error al crear el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  int edad[] = {23, 21, 22, 32, 49, 17, 26};
  char sexo[] = {'H', 'M', 'M', 'H', 'H', 'M', 'M'};
  char alumnos[][MAX_CHAR] = {"Nico", "Joy", "Mica", "Mark", "Zek", "Lara", "Paola"};

  for (i = 0; i < 7; i++) {
    strcpy(alumno.nombre, alumnos[i]);
    alumno.edad = edad[i];
    alumno.sexo = sexo[i];

    fwrite(&alumno, sizeof(alumno), 1, file);
  }
  fclose(file);
}

int read_file() {
  struct Alumno alumno;

  FILE *file = fopen("datos_alumnos.dat", "rb");
  if (!file) {
    printf("Error al crear el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&alumno, sizeof(alumno), 1, file);
  while (!feof(file)) {
    printf("#################\n");
    printf("# Nombre: %s\n", alumno.nombre);
    printf("# Edad: %d\n", alumno.edad);
    printf("# Sexo: %c\n", alumno.sexo);
    printf("#################\n\n");

    fread(&alumno, sizeof(alumno), 1, file);
  }
  fclose(file);
}