// Construir un programa que determine si “PATH” se encuentra entre las variables de entorno.
//     Realizar una comparación para que no importenlas diferencias en mayúsculas y minúsculas.

// El código es horrible pero funciona.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getEnv(char[], char[]);
bool isLower(char *);
char upper(char *);

int main(int argc, char const *argv[], char const *envp[]) {
  int i;
  char wantedEnv[] = "PaTh";

  for (i = 0; *(envp + i); i++) {
    if (getEnv(*(envp + i), wantedEnv)) {
      printf("La variable %s se encuentra entre las variables de entorno, y su valor es:\n\n", wantedEnv);
      printf("%s\n\n", *(envp + i));
    }
  }

  printf("\n\n");
  return 0;
}

bool getEnv(char s1[], char s2[]) {
  int i = 0;
  char envChar;

  while (envChar != "=") {
    envChar = *(s1 + i);
    char wantedChar = *(s2 + i);

    // Si se termino de iterar sobre el segundo string
    // podemos decir que SI existe dentro del primer string.
    if (!wantedChar) {
      return true;
    }

    if (isLower(&wantedChar)) {
      wantedChar = (upper(&wantedChar));
    }

    if (envChar != wantedChar) {
      return false;
    }
    i++;
  }
}

char upper(char *ch) { return *ch - 32; }

bool isLower(char *ch) {
  // Si no es minúscula...
  if (*ch < 97 || *ch > 122) {
    return false;
  }
}
