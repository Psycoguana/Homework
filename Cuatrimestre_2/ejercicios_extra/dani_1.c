/* EJERCICIO 1 : El archivo BDVOTOS está formado por registros de la forma:
struct {
    char NOM[20]; char
  DISTRITO[20];
  int VOTOS;
};

Contiene los datos de una elección, en donde figuran en cada registro la cantidad de votos que obtuvo cada
candidato en cada uno de los distritos. Se pide:
1. Construir el archivo depurado BD_RESUMEN donde figure cada candidato UNA SOLA VEZ con la cantidad total
de votos obtenidos. Cada registro será igual al anterior, pero sin el distrito.
2. Determinar el Candidato ganador.
3. Indicar en que DISTRITO obtuvo mas votos.

NOTA: NO SE PUEDEN BAJAR LOS ARCHIVOS A MEMORIA PUES NO SE PUEDE ASEGURAR QUE ESTA SEA SUFICIENTE. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Candidato {
  char nombre[20];
  char distrito[20];
  int votos;
};

long _get_file_size(FILE *);

int main(int argc, char const *argv[]) {
  int i, j, total_votos, max_votos, max_distrito;
  long elements_amount;
  char last_candidato[30], max_candidato[30], max_distrito_char[30];
  struct Candidato candidato;

  FILE *votos = fopen("BDVOTOS", "r+b");
  FILE *resultados = fopen("BD_RESUMEN", "w");
  if (!votos || !resultados) {
    printf("Error de archivos...\n\n");
    exit(EXIT_FAILURE);
  }

  /* create_db(votos); */
  elements_amount = _get_file_size(votos) / sizeof(candidato);
  sort_file(votos, elements_amount);
  show_file(votos);

  strcpy(last_candidato, "");
  strcpy(max_candidato, "");
  total_votos = 0;
  max_votos = 0;

  fread(&candidato, sizeof(candidato), 1, votos);
  strcpy(last_candidato, candidato.nombre);
  strcpy(max_distrito_char, candidato.distrito);
  max_distrito = candidato.votos;

  while (!feof(votos)) {
    if (strcmp(candidato.nombre, last_candidato) == 0) {
      total_votos += candidato.votos;

      if (max_distrito < candidato.votos && strcmp(max_candidato, candidato.nombre) == 0) {
        strcpy(max_distrito_char, candidato.distrito);
        max_distrito = candidato.votos;
      }

    } else {
      /* Empiezo a procesar un nuevo candidato, entonces escribo la información del anterior en disco */
      fprintf(resultados, "Candidato: %s\n\tVotos: %d\n\n", last_candidato, total_votos);
      if (total_votos > max_votos) {
        max_votos = total_votos;
        strcpy(max_candidato, candidato.nombre);
      }

      strcpy(last_candidato, candidato.nombre);
      total_votos = candidato.votos;
    }
    fread(&candidato, sizeof(candidato), 1, votos);
  }
  fprintf(resultados, "\n\nGANADOR: %s con %d votos.", max_candidato, max_votos);
  fprintf(resultados, "\nEl distrito con mayor votos fue %s con %d votos.", max_distrito_char, max_distrito);

  fclose(votos);
  fclose(resultados);
  printf("\n\n");
  return 0;
}

int sort_file(FILE *file, int elements_amount) {
  int i, j;
  struct Candidato candidato, first, second;

  for (i = 0; i < elements_amount - 1; i++) {
    for (j = 0; j < elements_amount - i - 1; j++) {
      fseek(file, j * sizeof(candidato), SEEK_SET);

      fread(&first, sizeof(candidato), 1, file);
      fread(&second, sizeof(candidato), 1, file);

      if (strcmp(first.nombre, second.nombre) > 0) {
        fseek(file, j * sizeof(candidato), SEEK_SET);

        fwrite(&second, sizeof(candidato), 1, file);
        fwrite(&first, sizeof(candidato), 1, file);
      }
    }
  }
  rewind(file);
}

int show_file(FILE *file) {
  struct Candidato candidato;

  fread(&candidato, sizeof(candidato), 1, file);
  while (!feof(file)) {
    printf("Candidato: %s\n", candidato.nombre);
    printf("Distrito: %s\n", candidato.distrito);
    printf("Votos: %d\n\n", candidato.votos);

    fread(&candidato, sizeof(candidato), 1, file);
  }
  rewind(file);
}

int create_db(FILE *file) {
  int i, j;
  int candidatos_size, provincias_size;
  struct Candidato candidato;

  char *candidatos[30] = {"PEREZ", "PRAZZI", "KERBAN", "MARCO", "POLO", "NELA", "ALEN", "OCRAM"};
  char *provincias_array[30] = {"Buenos Aires",
                                "Catamarca",
                                "Chaco",
                                "Chubut",
                                "Córdoba",
                                "Corrientes",
                                "Entre Ríos",
                                "Formosa",
                                "Jujuy",
                                "La Pampa",
                                "La Rioja",
                                "Mendoza",
                                "Misiones",
                                "Neuquén",
                                "Río Negro",
                                "Salta",
                                "San Juan",
                                "San Luis",
                                "Santa Cruz",
                                "Santa Fe",
                                "Santiago del Estero",
                                "Tierra del Fuego",
                                "Tucumán"};

  srand(time(NULL));

  candidatos_size = 8;
  provincias_size = 23;

  for (i = 0; i < provincias_size; i++) {
    for (j = 0; j < candidatos_size; j++) {
      strcpy(candidato.nombre, candidatos[j]);
      strcpy(candidato.distrito, provincias_array[i]);
      candidato.votos = rand() % 100;

      fwrite(&candidato, sizeof(candidato), 1, file);
    }
  }
  rewind(file);
}

long _get_file_size(FILE *file) {
  int size;

  fseek(file, 0, SEEK_END);
  size = ftell(file);
  rewind(file);

  return size;
}