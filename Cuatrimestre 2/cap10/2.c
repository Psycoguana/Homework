// Construir un programa que determine si “PATH” se encuentra entre las variables de entorno.
//     Realizar una comparación para que no importenlas diferencias en mayúsculas y minúsculas.

// El código es horrible pero funciona.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getEnv(char[], char[]);
bool isUpper(char *);
char lower(char *);

int main(int argc, char const *argv[], char const *envp[]) {
  int i;
  char wantedEnv[] = "PaTh";

  for (i = 0; *(envp + i); i++) {
    if (getEnv(*(envp + i), wantedEnv)) {
      printf("La variable %s se encuentra entre las variables de entorno, y su valor es:\n\n", wantedEnv);
      printf("%s", *(envp + i));
    }
  }

  printf("\n\n");
  return 0;
}

bool getEnv(char s1[], char s2[]) {
  int i = 0;
  char currentEnv;

  while (currentEnv != "=") {
    currentEnv = *(s1 + i);
    char wantedEnv = *(s2 + i);

    if (!currentEnv || !wantedEnv) {
      return true;
    }

    if (isUpper(&currentEnv)) {
      currentEnv = (lower(&currentEnv));
    }

    if (isUpper(&wantedEnv)) {
      wantedEnv = (lower(&wantedEnv));
    }

    if (currentEnv != wantedEnv) {
      return false;
    }
    i++;
  }
}

char lower(char *ch) { return *ch + 32; }

bool isUpper(char *ch) {
  // Si no es mayúscula...
  if (*ch < 65 || *ch > 90) {
    return false;
  }
}
