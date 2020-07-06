/*
Los datos de los 130 integrantes de las divisiones inferiores de un club se
encuentran almacenados en un vector de estructuras de la siguiente manera:
Nombre(string de 20 caracteres),
sexo (char),
fecha de nacimiento (estructura de tipo fecha: int dia, int mes, int anio).

Se pide mostrar los nombres discriminados por sexo y categoría sabiendo que:
* Juveniles incorpora hasta los nacidos en 2005
* Cadetes hasta 2007
* Infantiles hasta 2009
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INTEGRANTES = 130;
const int JUVENILES = 2005;

struct Birthday {
  int dia;
  int mes;
  int anio;
};

struct ClubDivision {
  char nombre[20];
  char sex;
  struct Birthday birthday;
};

// PROTOTYPES
int input_data(struct ClubDivision[]);
struct ClubDivision sort_years(struct ClubDivision[], int min_year, int max_year);
void clean_stdin(void);

int main(int argc, char const *argv[]) {
  // Uncomment for testing
  // struct ClubDivision data_array[] = {{"Nico", 'H', {18, 05, 2007}},
  //                                     {"Lara", 'M', {18, 05, 2009}},
  //                                     {"Mark", 'H', {11, 05, 1947}},
  //                                     {"Lola", 'M', {18, 05, 2008}}};
  struct ClubDivision data_array[INTEGRANTES];
  input_data(data_array);

  sort_sex(data_array);
  show_data(data_array);

  printf("\n\n");
  return 0;
}

int show_data(struct ClubDivision data[]) {
  int i;

  printf("\n_______________/-------Datos-------\\_______________\n\n");
  printf("Juveniles\tCadetes\t\tInfantiles\n");

  for (i = 0; i < INTEGRANTES; i++) {
    if (data[i].birthday.anio <= 2005) {
      printf("%s", data[i].nombre);
    } else if (data[i].birthday.anio <= 2007) {
      printf("\t\t%s", data[i].nombre);
    } else if (data[i].birthday.anio <= 2009) {
      printf("\t\t\t\t%s", data[i].nombre);
    }
    printf("\n");
  }
}

int input_data(struct ClubDivision data_array[]) {
  int i;
  int d, m, a;

  for (i = 0; i < INTEGRANTES; i++) {
    printf("Ingreso de datos del integrante #%d\nIngrese el nombre: ", i + 1);
    gets(data_array[i].nombre);
    printf("Ingrese el sexo (H o M): ");
    data_array[i].sex = getchar();
    printf("Ingrese la fecha de nacimiento (DD-MM-AA): ");
    scanf("%d-%d-%d", &d, &m, &a);
    printf("\n");
    data_array[i].birthday.dia = d;
    data_array[i].birthday.mes = m;
    data_array[i].birthday.anio = a;

    clean_stdin();
  }
}

int sort_sex(struct ClubDivision data[]) {
  int i, j;
  struct ClubDivision aux;
  for (i = 0; i < INTEGRANTES; i++) {
    for (j = 0; j < INTEGRANTES - i - 1; j++) {
      if (data[j].sex == 'H' && data[j + 1].sex == 'M') {
        aux = data[j];
        data[j] = data[j + 1];
        data[j + 1] = aux;
      }
    }
  }
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
