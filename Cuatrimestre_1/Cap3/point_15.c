#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int nota_m = 0;
  int nota_f = 0;
  int alumnos_m = 0;
  int alumnas_f = 0;

  printf("Ingresar datos de 5 alumnos (SEXO NOTA): ");

  while ((alumnas_f + alumnos_m) < 5) {
    printf("\nAlumno #%d: ", (alumnos_m + alumnas_f) + 1);
    char temp_sex;
    int temp_nota = 0;

    scanf(" %c %d", &temp_sex, &temp_nota);

    switch (temp_sex) {
      case 'M':
        alumnos_m++;
        nota_m += temp_nota;
        break;

      case 'F':
        alumnas_f++;
        nota_f += temp_nota;
        break;

      default:
        printf("Algo no esta bien, cerrando el programa...");
        printf("\nscanf: %d", temp_nota);
        break;
    }
  }
  float promedio_f = nota_f / alumnas_f;
  float promedio_m = nota_m / alumnos_m;

  switch (promedio_f > promedio_m) {
    case true:
      printf("\nLas mujeres tienen mayor promedio.");
      break;
    case false:
      printf("\nLos hombres tienen mayor promedio.");
    default:
      printf("\nUps, algo salió mal...");
      break;
  }

  printf("\n\n");
  return 0;
}
