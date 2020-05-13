#include <stdio.h>
#include <stdlib.h>

int i, j, k;

// PROTOTIPO
int POTENCIA(int, int);
int FERMAT(int numb_base, int numb_2);
int isPrimo(int);

int main() {
  int min = 2;
  int max = 8;
  int potencia[3] = {3, 5, 7};
  int currentNumb;

  for (k = min; k < max + 1; k++) {
    for (currentNumb = 0; currentNumb < 3; currentNumb++) {
      if (FERMAT(k, potencia[currentNumb]) == 1) {
        printf("Con base %d y potencia %d, Fermat se cumple\n", k,
               potencia[currentNumb]);
      } else {
        printf("Con base %d y potencia %d, Fermat NO se cumple\n", k,
               potencia[currentNumb]);
      }
    }
  }

  printf("\n\n");
  return 0;
}

int FERMAT(int numb_base, int numb_2) {
  // printf("\nA=%d - B=%d", numb_base, numb_2);
  if (isPrimo(numb_2) == 0) {
    int potenciado = POTENCIA(numb_base, numb_2);
    if ((potenciado - numb_base) % numb_2 == 0) {
      return 1;
    }
    return 0;
  }
}

int POTENCIA(int contenido_base, int exponente) {
  int suma = contenido_base;
  for (i = 1; i < exponente; i++) {
    suma = suma *= contenido_base;
  }
  return suma;
}

int isPrimo(int number) {
  int div;

  if (number > 1) {
    for (div = 2; div < number; div++) {
      if (number % div == 0) {
        return 1;
      }
    }
  }
  return 0;
}
