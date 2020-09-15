// Realice un programa que cree un archivo binario con bytes aleatorios,
// garantizando que en algún lugar del programa se encuentre la siguiente
// secuencia de 7 bytes: A8 5C 69 70 70 AF EF.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int inflate(FILE *);
int randInsert(FILE *, char*, int);

int main(int argc, char const *argv[]) {
  char filePath[] = "1.txt";
  unsigned char sequence[] = {0xA8, 0x5C, 0x69, 0x70, 0x70, 0xAF, 0xEF};

  FILE *file = fopen(filePath, "w+b");
  if (!file) {
    printf("Error while opening file D:");
    exit(EXIT_FAILURE);
  }

  inflate(file);
  randInsert(file, sequence, sizeof(sequence));

  fclose(file);
  printf("\n\n");
  return 0;
}

int inflate(FILE *file) {
  int i, fileSize = 2000;

  printf("Inflating file...\n");
  for (i = 0; i < fileSize; i++) {
    unsigned char randHex = rand() % 255;
    fwrite(&randHex, sizeof(randHex), 1, file);
  }
}

int randInsert(FILE *file, char *sequence, int sequenceSize) {
  int i;

  // Obtengo el tamaño del archivo.
  int fileSize = ftell(file);

  // Lo uso para generar un índice random donde escribir.
  srand(time(NULL));
  int randIndex = rand() % fileSize;

  printf("\nFile size: %u bytes. Rand position: %d\n", fileSize, randIndex);
  // Me muevo al index random.
  fseek(file, randIndex, SEEK_SET);

  printf("\nInserting sequence...\n");
  for (i = 0; i < sequenceSize; i++) {
    fwrite((sequence+i), sizeof(unsigned char), 1, file);
  }
}
