/*
Se desea llevar el control de los datos de un curso de 12 alumnos. Los datos consisten en:
 * Nombre (string de 20)
 * Nota de 10 materias (enteros de 0 a 10)

Se pide:
 a. Permitir el ingreso por teclado de los nombres de los alumnos.
 b. Completar las notas con números enteros aleatorios comprendidos entre 0 y 10 inclusive.
 c. Mostrar en pantalla la totalidad de los datos, encolumnados correctamente y encabezados por
      los nombres de las materias, pero utilizando solamente las 3 primeras letras de cada uno
      de ellos (Mat, Fis, Qui, etc.).
 d. Permitir el ingreso del nombre de una materia e imprimir el listado de los alumnos que deben
      rendir exámen recuperatorio de ésta por tener calificaión menor que 4.

El programa debe resolverse siguiendo una lógica que considere que la cantidad de materias podría
ser mucho mayor.

Se sugiere utilizar un vector auxiliar que contenga sus nombres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ALUM_AMOUNT = 3;
#define MATERIAS_AMOUNT 4

struct Alumnos {
  char name[20];
  int notas[MATERIAS_AMOUNT];
};

// Prototypes
int input_data(struct Alumnos[]);
int inflateAlumnos(struct Alumnos[]);
int showData(char[][20], struct Alumnos[]);
int naughtyList(struct Alumnos[]);
int _getRecursantes(struct Alumnos[], int);

int main(int argc, char const *argv[]) {
  struct Alumnos alumnos[] = {{"Nico", {10, 2, 5, 7}}, {"Her", {1, 3, 5, 3}}, {"Him", {9, 8, 7, 5}}};

  char materias[][20] = {"Matemáticas", "Fisica", "Quimica", "Programación"};

  showData(materias, alumnos);
  naughtyList(alumnos);

  printf("\n\n");
  return 0;
}

int input_data(struct Alumnos alumnos[]) {
  int i, j;
  printf("Ingrese los datos de los %d alumnos", ALUM_AMOUNT);
  for (i = 0; i < ALUM_AMOUNT; i++) {
    printf("\nAlumno #%d\n   Nombre: ", i + 1);
    gets(alumnos[i].name);

    for (j = 0; j < MATERIAS_AMOUNT; j++) {
      printf("   Ingrese la nota de la materia #%d: ", j + 1);
      int nota;
      scanf("%d", &nota);
      clean_stdin();
      alumnos[i].notas[j] = nota;
    }
  }
  return 0;
}

int inflateAlumnos(struct Alumnos alumnos[]) {
  int i, j;
  srand(time(0));

  for (i = 0; i < ALUM_AMOUNT; i++) {
    for (j = 0; j < MATERIAS_AMOUNT; j++) {
      alumnos[i].notas[j] = (rand() % 10) + 1;
    }
  }
  return 0;
}

int showData(char materias[MATERIAS_AMOUNT][20], struct Alumnos alumnos[]) {
  int i, j;
  for (i = 0; i < MATERIAS_AMOUNT; i++) {
    printf("\t%5c%c%c", materias[i][0], materias[i][1], materias[i][2]);
  }

  for (i = 0; i < ALUM_AMOUNT; i++) {
    printf("\n%s", alumnos[i].name);
    for (j = 0; j < MATERIAS_AMOUNT; j++) {
      printf("\t%6d", alumnos[i].notas[j]);
    }
  }
}

int naughtyList(struct Alumnos alumnos[]) {
  printf("\n\nIngrese el código de la materia a buscar 1-%d: ", MATERIAS_AMOUNT);
  int materiaCode;
  scanf("%d", &materiaCode);

  _getRecursantes(alumnos, materiaCode);
}

int _getRecursantes(struct Alumnos alumnos[], int materiaCode) {
  char recursantes[ALUM_AMOUNT][20]; // Creo un array que contendrá nombres de recursantes.
  int recursantesFound = 0; // Se usa para llevar la cuenta del índice que se debe usar en el array superior.

  // Iteramos en la lista de alumnos buscando las notas pertenecientes a materiaCode.
  int i;
  for (i = 0; i < ALUM_AMOUNT; i++) {
    if (alumnos[i].notas[materiaCode - 1] < 4) {
      strcpy(recursantes[recursantesFound], alumnos[i].name);
      recursantesFound++;
    }
  }

  printf("\nRecursantes:\n");
  for (i = 0; i < recursantesFound; i++) {
    if (strcmp(recursantes[i], "")) {
      printf("%s recursa\n", recursantes[i]);
    }
  }
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
