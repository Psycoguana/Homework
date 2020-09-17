/* Realizar un programa que busque una palabra en un archivo de texto. Indique la cantidad de ocurrencias
de la palabra, o bien su ausencia. El usuario ingresará el nombre del archivo en donde buscar y la palabra
que será buscada. La palabra puede tener un máximo de 10 caracteres. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_chars 10

int search_word(char *, char *, int);
void cut_newline(char *);

int main(int argc, char const *argv[]) {
  char file_path[max_chars], wanted_word[max_chars];

  printf("Ingrese el nombre del archivo para escanear: ");
  fgets(file_path, sizeof(file_path), stdin);
  cut_newline(file_path);

  printf("Ahora ingrese la palabra que desea buscar: ");
  fgets(wanted_word, sizeof(wanted_word), stdin);
  cut_newline(wanted_word);

  /* Si le paso el size con strlen, sé perfectamente el tamaño del string.
    https://pbs.twimg.com/profile_images/1043795316942802944/YtKZollX_400x400.jpg */
  search_word(file_path, wanted_word, strlen(wanted_word));

  printf("\n\n");
  return 0;
}

int search_word(char *file_path, char *wanted_word, int word_size) {
  char first_char = *wanted_word;
  char *possible_word = (char *)malloc(word_size);
  char current_char;
  int times_found = 0;

  FILE *file = fopen(file_path, "rb");
  if (!file) {
    printf("Algo salió horriblemente mal intentando leer el archivo %s\n\n", file_path);
    free(possible_word);
    exit(EXIT_FAILURE);
  }

  fread(&current_char, sizeof(char), 1, file);
  while (!feof(file)) {
    if (first_char == current_char) {
      fseek(file, -sizeof(char), SEEK_CUR);
      fread(possible_word, 1, word_size, file);

      if (strcmp(possible_word, wanted_word) == 0) {
        /* La palabra se encontró, aumento el contador y leo el siguiente char,
        para que que el if en la línea 48 se ejecuté correctamente. */
        times_found++;
        fread(&current_char, sizeof(char), 1, file);
      } else {
        /* Si no se encontró, debo retroceder el tamaño de la palabra + un char 
        que ya había sido leído y comparado. */
        fseek(file, -word_size + 1, SEEK_CUR);
        /* Ahora leo el siguiente char para entrar correctamente en el if de la línea 48 */
        fread(&current_char, sizeof(char), 1, file);
      }
      
    } else {
      fread(&current_char, 1, sizeof(char), file);
    }
  }
  fclose(file);
  free(possible_word);

  if (times_found == 0) {
    printf("\nNo se encontró la palabra %s en el archivo %s", wanted_word, file_path);
  } else if (times_found > 0) {
    printf("\nSe encontró la palabra %s %d veces en el archivo %s", wanted_word, times_found, file_path);
  } else {
    printf("WTF just happened...");
  }
}

void cut_newline(char *ch) {
  /* This function removes the trailing \n from strings */

  int char_size = strlen(ch);

  if (ch != NULL) {
    if (ch[char_size - 1] == '\n') {
      ch[char_size - 1] = '\0';
    }
  }
}
