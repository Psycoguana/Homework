// Se ingresarán (en un orden cualquiera) los datos de 16 equipos de fútbol,
//     compuestos por código del equipo(int) y cantidad de puntos(int). Mostrar la tabla de
//     posiciones(ordenada) y a continuación el fixture de la primera fecha de play offs,
//     es decir, los partidos entre el primero y el último, el segundo y el anteúltimo, etc.

#include <stdio.h>
#include <stdlib.h>

int sortData(int[], int[], int *);
int showData(int[], int[], int *);
int swap(int *, int *);

int main(int argc, char const *argv[]) {
  int size = 16;
  int equiposCode[] = {1, 12, 3, 4, 5, 10, 7, 8, 9, 6, 11, 2, 13, 14, 15, 16};
  int equiposPuntos[] = {3, 9, 5, 1, 2, 7, 8, 5, 3, 2, 6, 9, 8, 7, 3, 4};

  sortData(equiposCode, equiposPuntos, &size);
  showData(equiposCode, equiposPuntos, &size);

  printf("\n\n");
  return 0;
}

int sortData(int playerCode[], int playerPoints[], int *size) {
  int i, j;

  for (i = 0; i < (*size) - 1; i++) {
    for (j=0; j < (*size) - i - 1; j++) {
      if (*(playerCode + j) > *(playerCode + j + 1)) {
        swap(playerCode+j, playerCode+j+1);
      }
    }
  }
}

int showData(int PlayerCode[], int playerPoints[], int *size) {
  int i;
  for (i = 0; i < *size; i++) {
    printf("%d\n", *(PlayerCode + i));
  }
}

int swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}