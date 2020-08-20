#include <stdio.h>
#include <stdlib.h>

// PROTOTIPO
char sumASCII();

int main() {
  sumASCII();

  printf("\n\n");
  return 0;
}

char sumASCII() {
  char singleChar;

  printf("Ingrese una letra: ");
  scanf("%c", &singleChar);

  printf("%c", singleChar + 1);
  return singleChar;
}
