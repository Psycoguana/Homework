// Realice un programa que cree un archivo binario con bytes aleatorios,
// garantizando que en algún lugar del programa se encuentre la siguiente
// secuencia de 7 bytes: A8 5C 69 70 70 AF EF.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int inflate(FILE *);
int randInsert(FILE *, char*, int);
int readFile(FILE *);

int main(int argc, char const *argv[]) {
  char filePath[] = "1.txt";
  // Si intento esto, pierdo el primer carácter de cada elemento.
  // unsigned char sequence[] = {'A8', '5C', '69', '70', '70', 'AF', 'EF'};
  unsigned char sequence[] = "A85C697070AFEF";

  FILE *file = fopen(filePath, "w+b");
  if (!file) {
    printf("Error while opening file D:");
    exit(EXIT_FAILURE);
  }

  inflate(file);
  randInsert(file, sequence, sizeof(sequence));
  readFile(file);

  fclose(file);
  printf("\n\n");
  return 0;
}

int inflate(FILE *file) {
  int i, fileSize = 2000;

  printf("Inflating file with...\n");
  for (i = 0; i < fileSize; i++) {
    unsigned char randHex = rand() % 255;
    printf("%X ", randHex);

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

  printf("\n\nFile size: %u bytes. Rand position: %d\n", fileSize, randIndex);
  // Me muevo al index random.
  fseek(file, randIndex, SEEK_SET);

  printf("\nInserting sequence...\n");
  for (i = 0; i < sequenceSize; i++) {
    printf("Char: %c Hex: %x\n", *(sequence+i), *(sequence+i));
    fwrite((sequence+i), sizeof(unsigned char), 1, file);
  }
}

int readFile(FILE *file) {
  unsigned char curr;

  fseek(file, 0, SEEK_SET);
  printf("\n\nReading file...\n");


  fread(&curr, sizeof(unsigned char), 1, file);
  while (!feof(file)) {
    printf("%c", curr);
    fread(&curr, sizeof(unsigned char), 1, file);
  }
}
