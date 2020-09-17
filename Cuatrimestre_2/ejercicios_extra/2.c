/* Realizar un programa que maneje un archivo de longitud desconocida,
donde cada registro contiene el nombre de un alumno y cuatro notas.

Hacerlo con un menú que permita:
* Crear el archivo ✔️
* Calcular el promedio ✔️
* Mostrarlo✔️
* Buscar un registro determinado ✔️
* Modificar una nota ✔️
* Agregar registros ✔️
* Ordenar el archivo alfabéticamente. ✔️ */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "records.dat"
#define NAME_SIZE 20

struct Alumno {
  char name[NAME_SIZE];
  float nota;
} Record_aux;

int menu();
int create_record();
int add_record();
int get_promedio();
int show_records();
int modify_record();
int sort_record();

int get_data(struct Alumno *);
bool notOrdered(char *, char *);
void cut_newline(char *);
void clean_stdin(void);

int main(int argc, char const *argv[]) {
  menu();

  printf("\n\n");
  return 0;
}

int menu() {
  bool run = true;
  int choice;
  while (run) {
    printf("Elija una opción:\n");
    printf("1. Crear registro de alumnos.\n");
    printf("2. Calcular el promedio de todas las notas.\n");
    printf("3. Mostrar registro entero.\n");
    printf("4. Modificar una nota.\n");
    printf("5. Agregar registro.\n");
    printf("6. Ordenar registros alfabéticamente.\n");
    printf("\n0. Salir.\n\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      create_record();
      break;
    case 2:
      get_promedio();
      break;
    case 3:
      show_records();
      break;
    case 4:
      modify_record();
      break;
    case 5:
      add_record();
      break;
    case 6:
      sort_record();
      break;

    case 0:
      printf("Bye!");
      run = false;
      break;

    default:
      printf("Opción no válida. Saliendo...");
      run = false;
      break;
    }
  }
}

int create_record() {
  char choice;
  bool run = true;

  FILE *file = fopen(FILE_NAME, "wb");
  if (!file) {
    printf("Hubo un error al intentar crear el archivo D':\n\n");
    exit(EXIT_FAILURE);
  }
  printf("Archivo creado\n");

  while (run) {
    printf("Desea crear un nuevo registro? (y/n) ");
    clean_stdin();
    choice = getchar();

    if (choice == 'n') {
      printf("Ok BYE\n\n");
      fclose(file);
      run = false;
    } else if (choice == 'y') {
      add_record();
    }
  }
}

int add_record() {
  char name[NAME_SIZE];
  float nota;
  struct Alumno record;

  FILE *file = fopen(FILE_NAME, "ab");
  if (!file) {
    printf("Error al abrir archivo para append D':\n\n");
    exit(EXIT_FAILURE);
  }

  get_data(&record);

  fwrite(&record, sizeof(record), 1, file);

  printf("Se agrego el registro para el alumno %s\n\n", record.name);
  fclose(file);
}

int get_promedio() {
  struct Alumno record;
  int notas_amount = 0;
  float total_notas = 0;

  FILE *file = fopen(FILE_NAME, "rb");
  if (!file) {
    printf("Error al abrir archivo para lectura D':\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&record, sizeof(record), 1, file);
  while (!feof(file)) {
    notas_amount++;
    total_notas += record.nota;
    fread(&record, 1, sizeof(record), file);
  }
  fclose(file);

  printf("El promedio de todas las notas es: %.2f\n\n", total_notas / notas_amount);
}

int show_records() {
  int alumn_num = 0;
  struct Alumno record;

  FILE *file = fopen(FILE_NAME, "rb");
  if (!file) {
    printf("Error al abrir el archivo para lectura D':\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&record, sizeof(record), 1, file);
  while (!feof(file)) {
    alumn_num++;
    printf("Alumno # %d\n", alumn_num);
    printf("Nombre: %s\n", record.name);
    printf("Nota: %.2f\n\n", record.nota);

    fread(&record, sizeof(record), 1, file);
  }
  fclose(file);
}

int modify_record() {
  struct Alumno record;
  int record_to_modify;

  FILE *file = fopen(FILE_NAME, "r+b");

  if (!file) {
    printf("Error al intentar abrir archivo modo w+b");
  }

  fseek(file, 0, SEEK_END);
  int record_amount = ftell(file) / sizeof(record);
  char alumno[NAME_SIZE];

  printf("Actualmente hay %d registros almacenados. Cual desea modificar? ", record_amount);
  scanf("%d", &record_to_modify);

  /* Me muevo hasta el registro a modificar usando el size del struct y
  -1 porque el usuario cuenta desde el 1, fseek desde 0 */
  fseek(file, (record_to_modify - 1) * sizeof(record), SEEK_SET);

  /* Leo el record para saber que alumno se va a modificar
  No es necesario, pero queda lindo */
  fread(&record, sizeof(record), 1, file);
  printf("Alumno a modificar: %s\n", record.name);
  /* Ahora vuelvo para poder escribir sobre el registro que acabo de leer */
  fseek(file, (record_to_modify - 1) * sizeof(record), SEEK_SET);

  printf("Nueva nota del alumno: ");
  scanf("%f", &(record.nota));

  int write = fwrite(&record, sizeof(record), 1, file);
  if (write == 0) {
    printf("La escritura fue realizada correctamente :)\n\n");
  } else {
    printf("Hubo un problema durante la escritura...");
  }

  fclose(file);
}

int get_data(struct Alumno *record) {
  printf("Nombre del alumno: ");
  clean_stdin();
  fgets(&(record->name), sizeof(record->name), stdin);
  cut_newline(record->name);

  printf("Nota del alumno: ");
  scanf("%f", &(record->nota));
}

int sort_record() {
  int i, j;
  struct Alumno record;

  FILE *file = fopen(FILE_NAME, "r+b");
  if (!file) {
    printf("Error al intentar abrir el archivo para lecto/escritura\n\n");
    exit(EXIT_FAILURE);
  }

  fseek(file, 0, SEEK_END);
  int record_size = ftell(file) / sizeof(record);
  fseek(file, 0, SEEK_SET);

  struct Alumno *record_array = (struct Alumno *)malloc(record_size * sizeof(record));

  for (i = 0; i < record_size; i++) {
    fread(record_array + i, sizeof(record), 1, file);
  }

  
  for (i = 0; i < record_size - 1; i++) {
    for (j = 0; j < record_size - i - 1; j++) {

      if (notOrdered((record_array + j)->name, (record_array + j + 1)->name)) {
        struct Alumno aux;
        aux = *(record_array + j);
        *(record_array + j) = *(record_array + j + 1);
        *(record_array + j + 1) = aux;
      }
    }
  }

  fseek(file, 0, SEEK_SET);
  fwrite(record_array, record_size * sizeof(record), 1, file);
  free(record_array);

  fclose(file);
}

bool notOrdered(char *s1, char *s2) {
  int i;
  int size = (strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1));

  for (i = 0; i < size; i++) {
      if (*(s1+i) > *(s2+i)) {
          return true;
      } else {
          return false;
      }
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

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
