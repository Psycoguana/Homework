/* Se desea llevar una estadística de los 80 alumnos de una carrera cuyos datos son:
 * Nombre (string de 20)
 * Sexo (char)
 * Nota de 20 materias codificadas de 1 a 20 (int)
 * Fecha de nacimiento (estructura de tipo fecha)

 Se pide:
 a. Estructurar los datos y permitir el ingreso de los mismos desde teclado.
 b. Indicar cuál es el promedio de notas de los varones y de las mujeres
    (se asegura que hay por lo menos 10 de cada uno).
 c. Mostrar un listado de los datos ordenados en forma decreciente de una materia cuyo código se ingresa
    desde teclado.
 d. Permitir el ingreso de un nombre de un alumno e indicar cuál es su promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha {
  int dia;
  int mes;
  int anio;
};
struct Alumnos {
  char name[20];
  char sex;
  int notas[20];
  struct Fecha birthday;
};

// Prototypes
int input_data(struct Alumnos alumnos_data[]);
int show_data(struct Alumnos alumnos_data[]);
int calculate_promedio(struct Alumnos alumnos_data[]);
int _get_total_notas(int notas[], int size);
int show_specific_materia(struct Alumnos alumnos_data[], int materia);
int _sort_data(struct Alumnos[]);
int get_alumno_promedio(int notas[]);

const int ALUMNOS_SIZE = 80;
const int MATERIAS_SIZE = 20;

int main(int argc, char const *argv[]) {
  struct Alumnos alumnos_data[ALUMNOS_SIZE];

  // For testing:
  // struct Alumnos alumnos_data[] = {{"Nico", 'H', {9, 8}, {18, 5, 1997}},
  //                                  {"Her", 'M', {9, 5}, {8, 2, 1995}},
  //                                  {"Him", 'H', {2, 5}, {1, 3, 2000}},
  //                                  {"Bea", 'M', {10, 9}, {8, 2, 1990}}};

  input_data(alumnos_data);

  calculate_promedio(alumnos_data);

  printf("Elija una materia del 1 al %d y obtenga su información: ", MATERIAS_SIZE);
  int chosen_materia;
  scanf("%d", &chosen_materia);
  show_specific_materia(alumnos_data, chosen_materia);

  printf("Elija un alumno del 1 al %d y obtenga su promedio: ", ALUMNOS_SIZE);
  int chosen_alumno;
  scanf("%d", &chosen_alumno);
  get_alumno_promedio(alumnos_data[chosen_alumno - 1].notas);

  printf("\n\n");
  return 0;
}

int get_alumno_promedio(int notas[]) {
  int total = 0;
  int arraySize = (sizeof(notas) / sizeof(notas[0]));
  int i = 0;

  for (i = 0; i < arraySize; i++) {
    total += notas[i];
  }
  printf("El promedio del alumno es: %d", total);
}

int show_specific_materia(struct Alumnos alumnos_data[], int materia) {
  int i;
  _sort_data(alumnos_data);

  for (i = 0; i < ALUMNOS_SIZE; i++) {
    struct Alumnos curr = alumnos_data[i];
    printf("\nAlumno #%d\nNombre: %s\nSexo: %c\nNota de la materia %d: %d\nFecha de nacimiento: %d-%d-%d\n",
           i + 1, curr.name, curr.sex, materia, curr.notas[materia - 1], curr.birthday.dia, curr.birthday.mes,
           curr.birthday.anio);
  }
}

int _sort_data(struct Alumnos alumnos_data[]) {
  int i, j;
  struct Alumnos auxAlumn;

  for (i = 0; i < ALUMNOS_SIZE; i++) {
    for (j = 0; j < ALUMNOS_SIZE; j++) {
      if (strcmp(alumnos_data[j].name, alumnos_data[j + 1].name) > 0) {
        auxAlumn = alumnos_data[j];
        alumnos_data[j] = alumnos_data[j + 1];
        alumnos_data[j + 1] = auxAlumn;
      }
    }
  }
}

int calculate_promedio(struct Alumnos alumnos_data[]) {
  int i, j;
  int tempTotal, notas_mujeres = 0, notas_hombres = 0, cantidad_hombres = 0;

  for (i = 0; i < ALUMNOS_SIZE; i++) {
    tempTotal = _get_total_notas(alumnos_data[i].notas, MATERIAS_SIZE);

    if (alumnos_data[i].sex == 'H') {
      notas_hombres += tempTotal;
      cantidad_hombres++;
    } else if (alumnos_data[i].sex == 'M') {
      notas_mujeres += tempTotal;
    }
  }

  printf("El promedio de notas de los hombres es: %d\n", (notas_hombres / cantidad_hombres));
  printf("El promedio de notas de las mujeres es: %d\n", (notas_mujeres / (ALUMNOS_SIZE - cantidad_hombres)));
}

int _get_total_notas(int notas[], int size) {
  int i;
  int total = 0;
  for (i = 0; i < size; i++) {
    total += notas[i];
  }
  return total;
}

int show_data(struct Alumnos alumnos_data[]) {
  int i;
  for (i = 0; i < ALUMNOS_SIZE; i++) {
    struct Alumnos curr = alumnos_data[i];
    printf("\nNombre: %s\nSexo: %c\nNota 1: %d\nNota 2: %d\n Fecha de nacimiento: %d-%d-%d", curr.name,
           curr.sex, curr.notas[0], curr.notas[1], curr.birthday.dia, curr.birthday.mes, curr.birthday.anio);
  }
}

int input_data(struct Alumnos alumnos_data[]) {
  int i, j, tempInt, tempInt2, tempInt3;
  printf("Por favor ingrese los datos de los alumnos:\n");
  for (i = 0; i < ALUMNOS_SIZE; i++) {
    struct Alumnos curr_alum = alumnos_data[i];

    printf("Alumno #%d\n Nombre: ", i + 1);
    gets(alumnos_data[i].name);
    // WHY THE ABOVE WORKS AND THE BOTTOM DOESNT!?!?!?!?!?!
    // gets(curr_alum.name);

    printf(" Sexo (H o M): ");
    alumnos_data[i].sex = getchar();

    for (j = 0; j < MATERIAS_SIZE; j++) {
      printf(" Ingrese la nota de la materia #%d: ", j + 1);
      scanf("%d", &tempInt);
      alumnos_data[i].notas[j] = tempInt;

      clean_stdin(); // Necesito esto porque uso Linux.
    }

    printf(" Ingrese la fecha de nacimiento con el formato DD-MM-AAAA: ");
    scanf("%d-%d-%d", &tempInt, &tempInt2, &tempInt3);
    alumnos_data[i].birthday.dia = tempInt;
    alumnos_data[i].birthday.mes = tempInt2;
    alumnos_data[i].birthday.anio = tempInt3;

    clean_stdin();
  }
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
