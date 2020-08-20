#include <stdio.h>
#include <stdlib.h>

#define teamsSize 16

int i, j;

int addTeams(int equiposCode[], int equiposPuntos[], int arraySize);
int sortTeams(int equiposCode[], int equiposPuntos[], int arraySize);
int showTeams(int equiposCode[], int equiposPuntos[], int arraySize);
int showFixture(int equiposCode[], int equiposPuntos[], int arraySize);

int main(int argc, char const *argv[]) {
  // Los valores los dejo para testeo, mientras se ingresen 16 valores 
  // en addTeams, no debería haber problemas.
  int equiposCode[teamsSize] = {1, 12, 3,  4, 5,  10, 7,  8,
                                9, 6,  11, 2, 13, 14, 15, 16};
  int equiposPuntos[teamsSize] = {3, 9, 5, 1, 2, 7, 8, 5,
                                  3, 2, 6, 9, 8, 7, 3, 4};

  addTeams(equiposCode, equiposPuntos, teamsSize);
  sortTeams(equiposCode, equiposPuntos, teamsSize);
  showTeams(equiposCode, equiposPuntos, teamsSize);
  showFixture(equiposCode, equiposPuntos, teamsSize);

  printf("\n\n");
  return 0;
}

int addTeams(int equiposCode[], int equiposAmount[], int arraySize) {
  int tempInt;
  printf("Por favor, ingrese los datos de los jugadores:\n\n");
  for (i = 0; i < arraySize; i++) {
    printf("\nJugador #%d\n", i + 1);

    // Ingresar el código del equipo
    printf("Código: ");
    scanf(" %d", &tempInt);
    equiposCode[i] = tempInt;

    // Ingresar los puntos del equipo
    printf("Puntos: ");
    scanf(" %d", &tempInt);
    equiposAmount[i] = tempInt;
  }
}

int sortTeams(int equiposCode[], int equiposPuntos[], int arraySize) {
  int auxInt;
  for (i = 0; i < arraySize - 1; i++) {
    for (j = 0; j < arraySize - i - 1; j++) {
      if (equiposCode[j] > equiposCode[j + 1]) {
        auxInt = equiposCode[j];
        equiposCode[j] = equiposCode[j + 1];
        equiposCode[j + 1] = auxInt;

        auxInt = equiposPuntos[j];
        equiposPuntos[j] = equiposPuntos[j + 1];
        equiposPuntos[j + 1] = auxInt;
      }
    }
  }
}

int showTeams(int equiposCode[], int equiposPuntos[], int arraySize) {
  for (i = 0; i < arraySize; i++) {
    printf("Equipo #%d: %d puntos\n", equiposCode[i], equiposPuntos[i]);
  }
  printf("\n");
}

int showFixture(int equiposCode[], int equiposPuntos[], int arraySize) {
  for (i = 0; i < arraySize / 2; i++) {
    int teamACode = equiposCode[i];
    int teamAPoints = equiposPuntos[i];

    int teamBCode = equiposCode[arraySize - i - 1];
    int teamBPoints = equiposPuntos[arraySize - i - 1];

    printf("Fixture: \n");
    printf("Equipo #%d Vs. Equipos #%d --> %d <-> %d\n", teamACode, teamBCode,
           teamAPoints, teamBPoints);
  }
}
