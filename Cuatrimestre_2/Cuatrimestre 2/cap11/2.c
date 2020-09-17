// Utilizando la siguiente definición de estructura, realice un programa que solicite memoria para 5 alumnos.
//
// struct alumno {
//     int legajo;
//     char sexo;
//     char nombre[30];
//     float promedio;
// }
//
// El usuario ingresará por teclado los datos que se cargan en las estructuras.
// Mostrar el nombre de los alumnos uno debajo del otro.
// A continuación mostrar cuál es el alumno con mejor promedio.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
  int legajo;
  char sexo;
  char nombre[30];
  float promedio;
};

#define N 5

int writeData(struct Alumno[], int);
int readData(struct Alumno[], int);
int bestProm(struct Alumno[], int);

fail() { exit(1); }

int main(int argc, char const *argv[]) {

  // Asigno memoria.
  struct Alumno *alumnoArray = malloc(N * sizeof(struct Alumno));
  if (alumnoArray == NULL) {
    fail();
  }

  // Pedir data de alumnos.
  writeData(alumnoArray, N);
  printf("\n\n");

  printf("Mostrando los nombres de los alumnos...");
  readData(alumnoArray, N);

  // Mostrar mayor promedio.
  bestProm(alumnoArray, N);

  // Libero memoria que ya no necesito.
  free(alumnoArray);

  printf("\n\n");
  return 0;
}

int writeData(struct Alumno array[], int size) {
  int i;
  for (i = 0; i < N; i++) {
    // Esto es solo por comodidad.
    struct Alumno *current = (array + i);

    printf("Ingrese información del alumno #%d:\n", i + 1);

    printf("Legajo: ");
    scanf("%d", &current->legajo);

    clean_stdin();

    printf("Sexo: ");
    (current->sexo) = getchar();
    clean_stdin();

    printf("Nombre: ", i + 1);
    gets(current->nombre);

    printf("Promedio: ");
    scanf("%f", &current->promedio);

    clean_stdin();
    printf("\n");
  }
}

int readData(struct Alumno array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    struct Alumno *current = array + i;
    printf("Alumno #%d\n", i + 1);
    printf("Nombre: %s\n\n", current->nombre);
  }
}

int bestProm(struct Alumno array[], int size) {
  int i;
  struct Alumno *maxPointer = array;

  for (i = 0; i < size; i++) {
    struct Alumno *current = (array + i);

    if (current->promedio > maxPointer->promedio) {
      maxPointer = current;
    }
  }
  printf("El mayor promedio es de %.2f y pertenece a %s", maxPointer->promedio, maxPointer->nombre);
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}