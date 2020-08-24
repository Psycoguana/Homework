// Construir un programa que determine si “PATH” se encuentra entre las variables ce entorno.
//     Realizar una comparación para que no importenlas diferencias en mayúsculas y minúsculas.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getEnv(char *[], char[]);
bool myStrCmp(char[], char[]);
char lower(char);
bool isUpper(char);

int main(int argc, char const *argv[], char const *envp[]) {
  int i;

  for (i = 0; *(envp + i); i++) {
    if (myStrCmp(*(envp + i), "PATh")) {
      printf("%s", *(envp + i));
    }
  }

  printf("\n\n");
  return 0;
}

bool myStrCmp(char s1[], char s2[]) {
  int i = 0;

  char currentChar;
  char currentChar2;

  do {
    char currentChar = *(s1 + i);
    char currentChar2 = *(s2 + i);

    if (!currentChar || !currentChar2) {
      return true;
    }

    if (isUpper(currentChar)) {
      currentChar = (lower(currentChar));
    }

    if (isUpper(currentChar2)) {
      currentChar2 = (lower(currentChar2));
    }

    if (currentChar != currentChar2) {
      return false;
    }
    i++;
  } while (currentChar != "=");
}

char lower(char ch) { return (char)(((int)ch) + 32); }

bool isUpper(char ch) {
  if ((int)ch < 65 || (int)ch > 90) {
    return false;
  }
  return true;
}
