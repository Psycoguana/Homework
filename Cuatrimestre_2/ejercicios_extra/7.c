/* Dado el archivo ya ordenado del ejercicio anterior, ingresar un nombre por teclado, buscarlo en el archivo
utilizando un algoritmo de búsqueda binaria y mostrar en pantalla los datos que le
correspondan si es encontrado, o bien un mensaje de error en su ausencia. */

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
bool binary_search(char *, struct Alumno *, FILE *);
int _get_file_size(FILE *file);
int _cut_newline(char *);

int main(int argc, char const *argv[]) {
  char nombre[MAX_CHAR];
  struct Alumno alumno;

  FILE *file = fopen("datos_alumnos.dat", "rb");
  if (!file) {
    printf("Error al abrir el archivo para lectura...\n\n");
    exit(EXIT_FAILURE);
  }

  printf("Ingrese el nombre del alumno que desea buscar: ");
  fgets(nombre, sizeof(nombre), stdin);
  _cut_newline(nombre);

  if (binary_search(nombre, &alumno, file)) {
    printf("\nAlumno: %s\nEdad: %d\nSexo: %c\n\n", alumno.nombre, alumno.edad, alumno.sexo);
  } else {
    printf("\nAlumno no encontrado.");
  }

  printf("\n\n");
  return 0;
}

bool binary_search(char *word, struct Alumno *alumno, FILE *file) {
  int right = (_get_file_size(file) / sizeof(*alumno)) - 1;
  int left = 0;

  while (left <= right) {
    int middle = left + ((right - left) / 2);
    fseek(file, middle * sizeof(*alumno), SEEK_SET);
    fread(alumno, sizeof(*alumno), 1, file);

    int comparacion = strcmp(word, alumno->nombre);

    if (comparacion == 0) {
      return true;
    } else if (comparacion < 0) {
      right = middle - 1;
    } else if (comparacion > 0) {
      left = middle + 1;
    }
  }
  return false;
}

int _get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  rewind(file);

  return file_size;
}

int _cut_newline(char *string) {
  /* This function removes the trailing \n from strings */

  int size = strlen(string);
  if (string != NULL) {
    if (string[size - 1] == '\n') {
      string[size - 1] = '\0';
    }
  }
}
