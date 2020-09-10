// Realice un programa que reciba el nombre de un archivo binario por línea de comandos y determine si el
// mismo contiene al menos una vez la siguiente secuencia de 7 bytes: A8 5C 69 7070 AF EF. En caso afirmativo
// imprimir en pantalla “Archivo infectado”, o “Virus no detectado” en caso contrario. Utilice el resultado
// del ejercicio anterior.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_sequence(FILE *, char *, int);

int main(int argc, char const *argv[]) {
  unsigned char sequence[] = "A85C697070AFEF";

  FILE *file = fopen("1.txt", "rb");
  if (!file) {
    printf("Algo salío horriblemente mal al intentar leer el archivo D:\n\n");
    exit(EXIT_FAILURE);
  }

  find_sequence(file, sequence, sizeof(sequence));

  printf("\n\n");
  return 0;
}

int find_sequence(FILE *file, char *sequence, int sequence_size) {
  unsigned char current_char;
  unsigned char possible_sequence[sequence_size];

  unsigned char sequence_start = *(sequence);
  // Por alguna razón, sequence_size == 15, a pesar de solo tiene 14 caractéres incluyendo a '\0'.
  unsigned char sequence_end = *(sequence + sequence_size - 2);

  fread(&current_char, sizeof(unsigned char), 1, file);
  while (!feof(file)) {

    if (current_char == sequence_start) {
      fseek(file, sequence_size-3, SEEK_CUR);
      fread(&current_char, sizeof(unsigned char), 1, file);
      if (current_char == sequence_end) {

        fseek(file, -sequence_size+1, SEEK_CUR);
        fread(&possible_sequence, sequence_size, 1, file);
        
        if (strcmp(sequence, possible_sequence) == 0) {
          printf("Se encontró la secuencia %s luego de leer %li bytes :)\n\n", possible_sequence, ftell(file));
          // Cierro el archivo y termino el programa.
          fclose(file);
          exit(EXIT_SUCCESS);
        }
      }
    } else {
      fread(&current_char, sizeof(unsigned char), 1, file);
    }
  }
}
