/*
Se desea organizar un torneo de tenis doble mixto con 16 parejas. Los datos de los participantes son:
- Nombre(string de 20 caracteres)
- Sexo (char)
- Handicap (int)

Se pide:
a. Estructurar los datos y permitir su ingreso desde teclado utilizando un solo vector de estructuras.
b. Indicar cuáles son las parejas formadas considerando que el hombre de mayor handicap debe jugar con la
mujer de menor handicap y viceversa, y así sucesivamente, a fin de obtener un torneo parejo. c. Indicar los
nombres de la pareja cuya suma de handicaps es la máxima (considerarla única).


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
const int PLAYERS = 16;

// Structs
struct PlayerData {
  char name[20];
  char sex;
  int handicap;
};
struct Partners {
  char name_1[20];
  char name_2[20];
  int combined_handicap;
};

// Prototypes
int input_data(struct PlayerData[]);
int sort_players(struct PlayerData data[]);
int assign_partner(struct PlayerData data[], struct Partners assigned_partners[]);
int show_partners(struct Partners assigned_partners[]);

int main(int argc, char const *argv[]) {
  struct PlayerData myData[PLAYERS];
  input_data(myData);
  // Esto es para testear:
  // struct PlayerData myData[] = {
  //     {"Arthur", 'H', 10}, {"Roco", 'H', 2},  {"Pantero", 'H', 3}, {"Roger", 'H', 9},
  //     {"Pocho", 'H', 10},  {"Greg", 'H', 1},  {"Julio", 'H', 7},   {"Elliot", 'H', 5},

  //     {"Rhonda", 'M', 8},  {"Lara", 'M', 10}, {"Azul", 'M', 3},    {"Marge", 'M', 4},
  //     {"Luna", 'M', 5},    {"Vero", 'M', 7},  {"Gladys", 'M', 1},  {"La jessi", 'M', 9}};

  sort_players(myData);

  // Creo una estructura que me permite guardar 3 datos de un equipo: Nombres de los dos participantes, y su
  // handicap combinado.
  struct Partners assigned_partners[PLAYERS / 2];
  // Asigno los compañeros de equipo como se pide. Lo hago dentro de la estructura assigned_partners.
  assign_partner(myData, assigned_partners);
  show_partners(assigned_partners);

  return 0;
}

int input_data(struct PlayerData data[]) {
  int i;
  int handicapTemp;
  printf("Ingrese datos de los jugadores\n");
  for (i = 0; i < PLAYERS; i++) {
    printf("Jugador #%d\nNombre: ");
    gets(data[i].name);

    printf("Sexo (H o M): ");
    data[i].sex = getchar();

    printf("Handicap: ");
    scanf("%d", &handicapTemp);
    data[i].handicap = handicapTemp;

    clean_stdin(); // Necesito esto porque uso Linux
  }
  return 0;
}

int sort_players(struct PlayerData data[]) {
  int i, j;
  struct PlayerData aux;
  for (i = 0; i < PLAYERS; i++) {
    for (j = 0; j < PLAYERS - i - 1; j++) {
      // Acá no solo hago un sort del handicap, también especifico que solo se realice si el sexo de j y j+1
      // son iguales, esto nos deja con la primera mitad del array con un sexo y la segunda mitad del array
      // con otro sexo.
      if (data[j].handicap > data[j + 1].handicap && data[j].sex == data[j + 1].sex) {
        aux = data[j];
        data[j] = data[j + 1];
        data[j + 1] = aux;
      }
    }
  }
  return 0;
}

int assign_partner(struct PlayerData data[], struct Partners assigned_partners[]) {
  int i;
  for (i = 0; i < (PLAYERS / 2); i++) {
    struct PlayerData current = data[i];
    // Se asume que el jugador en la posición +2 del array tendrá como compañero al jugador que este en la
    // posición -2 del array. Para encontrar al 2do compañero digo que su índice es el total del array - i
    // (por lo explicado arriba) - 1 (porque los arrays cuentan desde 0).
    struct PlayerData current_2 = data[PLAYERS - i - 1];

    strcpy(assigned_partners[i].name_1, current.name);
    strcpy(assigned_partners[i].name_2, current_2.name);
    assigned_partners[i].combined_handicap = current.handicap + current_2.handicap;
  }
  return 0;
}

int show_partners(struct Partners partners[]) {
  int i;
  for (i = 0; i < (PLAYERS / 2); i++) {
    printf("Equipo #%d: %s - %s\nHandicap combinado: %d\n\n", i + 1, partners[i].name_1, partners[i].name_2,
           partners[i].combined_handicap);
  }
  return 0;
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
