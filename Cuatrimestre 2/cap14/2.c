/*
Realice un programa que reciba el nombre de un archivo binario por línea de comandos y determine si el
mismo contiene al menos una vez la siguiente secuencia de 7 bytes: A8 5C 69 7070 AF EF. En caso afirmativo
imprimir en pantalla “Archivo infectado”, o “Virus no detectado” en caso contrario. Utilice el resultado
del ejercicio anterior.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int find_sequence(FILE *, unsigned char *, int);
bool compareHex(unsigned char *, unsigned char *, int);

int main(int argc, char const *argv[]) {
  unsigned char sequence[] = {0xA8, 0x5C, 0x69, 0x70, 0x70, 0xAF, 0xEF};

  FILE *file = fopen("1.txt", "rb");
  if (!file) {
    printf("Algo salío horriblemente mal al intentar leer el archivo D:\n\n");
    exit(EXIT_FAILURE);
  }

  find_sequence(file, sequence, sizeof(sequence));

  printf("\n\n");
  return 0;
}

int find_sequence(FILE *file, unsigned char *sequence, int sequence_size) {
  unsigned char current_char;
  unsigned char sequence_start = *sequence;
  unsigned char *possible_sequence = (unsigned char *) malloc(sequence_size);

  fread(&current_char, sizeof(unsigned char), 1, file);
  while (!feof(file)) {
    if (current_char == sequence_start) {
      
      /* Si el char actual es igual al primer char de la secuencia leo la secuencia entera. */
      fseek(file, -sizeof(unsigned char), SEEK_CUR);
      fread(possible_sequence, 1, sequence_size, file);

      if (compareHex(sequence, possible_sequence, sequence_size)) {
        printf("Se encontró la secuencia luego de leer %li bytes :)\n\n", ftell(file));
        /* Cierro el archivo, libero la memoria que ya no necesito y termino el programa. */
        free(possible_sequence);
        fclose(file);
        exit(EXIT_SUCCESS);

      } else {
        /* Oops, esa no era la secuencia. Vuelvo para atrás... */
        fseek(file, -sequence_size + 1, SEEK_CUR);
        /* Leo el siguiente byte para cambar el valor de current char
         y no volver a entrar en el if de la línea 36. */
        fread(&current_char, 1, sizeof(unsigned char), file);
      }

    } else {
      /* Current char es distinto de sequence start, entonces leo el siguiente byte en current char. */
      fread(&current_char, 1, sizeof(unsigned char), file);
    }
  }
  /* Si no se encuentra una coincidencia en la línea 42, el free de la línea 45 nunca es llamado.
  Por eso también lo llamo acá. */
  free(possible_sequence);
}

bool compareHex(unsigned char *ch1, unsigned char *ch2, int size) {
  /* Compara byte a byte. Si en algún momento la secuencia no es igual, devuelve falso. */
  int i;
  for (i = 0; i < size; i++) {
    if (*(ch1 + i) != *(ch2 + i)) {
      return false;
    }
  }
}
