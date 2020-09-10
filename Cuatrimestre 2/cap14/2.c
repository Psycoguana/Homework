// Realice un programa que reciba el nombre de un archivo binario por línea de comandos y determine si el
// mismo contiene al menos una vez la siguiente secuencia de 7 bytes: A8 5C 69 7070 AF EF. En caso afirmativo
// imprimir en pantalla “Archivo infectado”, o “Virus no detectado” en caso contrario. Utilice el resultado
// del ejercicio anterior.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(FILE *);

int main(int argc, char const *argv[]) {

  unsigned char sequence_start = 'A';
  unsigned char sequence_end = 'F';
  unsigned char sequence[] = "A85C697070AFEF";
  unsigned char possible_sequence[sizeof(sequence)];
  unsigned char current_char;

  FILE *file = fopen("1.txt", "rb");
  if (!file) {
    printf("Algo salío horriblemente mal al intentar leer el archivo D:\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&current_char, sizeof(unsigned char), 1, file);
  while (!feof(file)) {
    int current_position = ftell(file);
    if (current_char == sequence_start) {
      fseek(file, 0, sizeof(sequence));
      fread(&current_char, sizeof(unsigned char), 1, file);
      if (current_char == sequence_end) {
        // Esto falla porque tengo que usar el arg offset para 
        // especificar posiciones != principio/final del archivo.
        // int a = fseek(file, 0, current_position);
        
        // 
        fseek(file, -sizeof(sequence) + 3, SEEK_CUR);
        fread(&possible_sequence, sizeof(sequence), 1, file);
        if (strcmp(sequence, possible_sequence) == 0) {
          printf("Se encontró la secuencia %s luego de leer %li bytes :)", possible_sequence, ftell(file));
          fseek(file, 0, SEEK_END); // Termina el programa.
        }
      }
    } else {
      fread(&current_char, sizeof(unsigned char), 1, file);
    }
  }

  printf("\n\n");
  return 0;
}
