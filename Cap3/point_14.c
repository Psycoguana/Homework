#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int nota_max = 0;
  int legajo_max = 0;

  printf("Ingresar datos de 5 alumnos: ");

  for (int alumnos_total = 0; alumnos_total < 5; alumnos_total++) {
    int temp_legajo = 0, temp_nota = 0, temp_notas_sum = 0;
    printf("\nAlumno #%d\nLegajo: ", alumnos_total + 1);
    scanf(" %d", &temp_legajo);

    // Pedir 8 notas.
    for (int nota_amount = 0; nota_amount < 8; nota_amount++) {
      printf("Nota #%d: ", nota_amount + 1);
      scanf(" %d", &temp_nota);
      temp_notas_sum += temp_nota;
    }

    // La suma de las mejores notas (el mejor promedio) se guarda en nota_max.
    if (temp_notas_sum > nota_max) {
      nota_max = temp_notas_sum;
      legajo_max = temp_legajo;
    }

    // Si se guardó el legajo sumar contador, else printear error. (La nota sigue cambiando)
    if (temp_legajo != 0) {
      alumnos_total++;
    } else {
      printf("Sucedió un error...");
    }
  }

  printf("%d es el alumno con el mejor promedio (%d).\n", legajo_max,
         (nota_max / 8));

  printf("\n\n");
  return 0;
}
