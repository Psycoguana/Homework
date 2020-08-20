/*
Ingresar la nómina de 10 alumnos, es decir, sus nombres y sus respectivos
promedios. Determinar quién es el alumno de mejor promedio (suponerlo
único).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

int main(int argc, char const *argv[]) {
  int alumnosAmount = 3;
  // Array para nombres
  char alumnos[alumnosAmount][30];
  // Array para promedios
  int promedios[alumnosAmount];

  for (i = 0; i < alumnosAmount; i++) {
    printf("Datos del alumno #%d:\n", i+1);

    printf("Nombre: ");
    gets(alumnos[i]);

    printf("Promedio: ");
    scanf(" %d", &promedios[i]);
    
    // Uso linux y fflush(stdin) no me funciona, esta función si.
    clean_stdin();
  }

  int maxPromedioIndex = 0;
  for (i = 0; i < alumnosAmount - 1; i++) {
    if (promedios[i] > promedios[maxPromedioIndex]) {
      // Como voy a necesitar datos de dos vectores, es mejor guardar el índice del mayor valor.
      maxPromedioIndex = i;
    }
  }

  printf("El estudiante con mayor promedio es: %s con %d de promedio.", alumnos[maxPromedioIndex], promedios[maxPromedioIndex]);

  printf("\n\n");
  return 0;
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
