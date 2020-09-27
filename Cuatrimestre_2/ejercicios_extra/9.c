/* Realice un programa que lea un archivo que contiene un programa en lenguaje C y lo escriba en otro archivo
pero omitiendo los saltos de línea. Esta operación busca optimizar el espacio en disco,
partiendo del conocimiento de que para el compilador estos saltos no son significativos.
Verifique que el programa “minimizado” se puede compilar y ejecutar normalmente del mismo modo que el
original y que tiene menor tamaño. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_line(char *, FILE *, FILE *);
check_files_sizes();

int main(int argc, char const *argv[]) {
  char string[90];
  FILE *file = fopen("/home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_aux.c", "r");
  FILE *new_file = fopen("/home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_new.c", "w");
  if (!file) {
    printf("Error al abrir archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  printf("Achicando archivo...\n");
  write_line(string, file, new_file);
  while (!feof(file)) {
    write_line(string, file, new_file);
  }
  fclose(new_file);
  fclose(file);

  printf("Compilando archivo...\n");
  int return_value = system("$(which gcc) /home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_new.c "
                            "-o /home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_new");

  if (return_value == 0) {
    printf("Archivo compilado correctamente :)\n");
  } else {
    printf("Error al compilar archivo... :'(\n");
  }

  check_files_sizes();

  printf("\n\n");
  return 0;
}

check_files_sizes() {
  FILE *file_old = fopen("/home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_aux.c", "rb");
  FILE *file_new = fopen("/home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/9_new.c", "rb");

  if (!file_new || !file_old) {
    printf("Error al abrir un archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  fseek(file_old, 0, SEEK_END);
  fseek(file_new, 0, SEEK_END);
  int old_size = ftell(file_old);
  int new_size = ftell(file_new);

  if (new_size < old_size) {
    printf("El nuevo archivo pesa %d bytes menos :o", old_size - new_size);
  } else {
    printf("Hubo un error.\nTamaño viejo: %d\nTamaño nuevo: \n", old_size, new_size);
  }

  fclose(file_old);
  fclose(file_new);
}

int write_line(char *string, FILE *file, FILE *new_file) {
  fgets(string, sizeof(string), file);
  _cut_newline(string);
  fprintf(new_file, "%s", string);
}

int _cut_newline(char *string) {
  /* This function removes the trailing \n from strings
  and replaces with a ; when necessary */

  /* Sin esto, las líneas vacías se convierten en un ; */
  if (strcmp(string, "\n") == 0) {
    strcpy(string, " ");
  }
  
  int size = strlen(string);
  if (string != NULL) {
    /* Si el string termina con un salto de línea y un ;, solo elimino el salto de línea */
    if (string[size - 1] == '\n' && string[size - 2] == ';') {
      string[size - 1] = '\0';
      /* Si eso no sucede, checkeo que termine con un salto de línea y reemplazo con ; */
    } else if (string[size - 1] == '\n') {
      string[size - 1] = ';';
    }
  }
}
