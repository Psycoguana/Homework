// Realizar un programa denominado PROMEDIO.EXE que reciba valores enteros por linea de comandos e imprima
// el promedio de éstos. Evitar la división por cero y notar que la cantidad de valores es arbitraria.

// PROMEDIO 56 34 789,... 23

#include <stdio.h>
#include <stdlib.h>
// 3.8

int main(int argc, char const *argv[]) {
  int i;
  float aux = 0;

  // Cuento cada valor saltando el primero que es el nombre del programa.
  for (i = 1; i < argc; i++) {
    aux += atof(argv[i]); // Convierto el numero a float y lo sumo a lo que ya tengo en aux.
  }

  // Divido el total por la cantidad de argumenos menos 1 para no contar el nombre del programa.
  printf("El promedio es: %.2f", aux / (argc - 1));

  printf("\n\n");
  return 0;
}
