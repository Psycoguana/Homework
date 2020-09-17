/* Realizar un programa que busque una palabra en un archivo de texto. Indique la cantidad de ocurrencias
de la palabra, o bien su ausencia. El usuario ingresará el nombre del archivo en donde buscar y la palabra
que será buscada. La palabra puede tener un máximo de 10 caracteres. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_chars 10

int search_word(char *, char *, int size);
bool isEqual(char *, char *);

int main(int argc, char const *argv[]) {
  char file_path[max_chars], wanted_word[max_chars];

  printf("Ingrese el nombre del archivo para escanear: ");
  fgets(file_path, sizeof(file_path), stdin);

  printf("\nAhora ingrese la palabra que desea buscar: ");
  fgets(wanted_word, sizeof(wanted_word), stdin);

  int word_size = strlen(wanted_word);
  int file_str_size = strlen(file_path);

  /* TODO: Conseguir algo mejor que esto */

  if (wanted_word[word_size - 1] == '\n') {
    wanted_word[word_size - 1] = '\0';
  }

  if (file_path[file_str_size - 1] == '\n') {
    file_path[file_str_size - 1] = '\0';
  }

  /* Si le paso el size con strlen, sé perfectamente el tamaño del string.
    https://pbs.twimg.com/profile_images/1043795316942802944/YtKZollX_400x400.jpg */
  search_word(file_path, wanted_word, strlen(wanted_word));

  printf("\n\n");
  return 0;
}

int search_word(char *file_path, char *wanted_word, int size) {
  char first_char = *wanted_word;
  char *possible_word = (char *)malloc(size);
  char current_char;

  FILE *file = fopen(file_path, "rb");
  if (!file) {
    printf("Algo salió horriblemente mal intentando leer el archivo %s\n", file_path);
    printf("\nContenido de la carpeta\n");
    system("ls");
    printf("\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&current_char, sizeof(char), 1, file);
  while (!feof(file)) {
    if (first_char == current_char) {
      fseek(file, -sizeof(char), SEEK_CUR);
      fread(possible_word, 1, size, file);

      if (strcmp(possible_word, wanted_word) == 0) {
        printf("Se encontró la palabra %s en el archivo %s luego de leer %ul bytes", possible_word, file_path,
               ftell(file));

        fclose(file);
        exit(EXIT_SUCCESS);

      } else {
        fseek(file, -size + 1, SEEK_CUR);
        fread(&current_char, sizeof(char), 1, file);
      }

    } else {
      fread(&current_char, 1, sizeof(char), file);
    }
  }
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
