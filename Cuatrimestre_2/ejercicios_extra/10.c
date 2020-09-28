/* Dentro de los archivos de audio MP3 se encuentra meta información como ser el intérprete, nombre del álbum,
género... Realice un programa que muestre esta información en pantalla. La información se encuentra en los
últimos 128 bytes del MP3, y se encuentra estructurada según esta definición:

struct datosMP3 {
  char tag[3]; // ojo, no es un string terminado en 0
  char titulo[30];
  char artista[30];
  char album[30];
  char anio[4]; // ojo, no es un string terminado en 0
  char comentario[30];
  unsigned char genero;
}; */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosMP3 {
  char tag[3]; // ojo, no es un string terminado en 0
  char titulo[30];
  char artista[30];
  char album[30];
  char anio[4]; // ojo, no es un string terminado en 0
  char comentario[30];
  unsigned char genero;
};

int read_mp3_info(struct datosMP3 *);

int main(int argc, char const *argv[]) {
  struct datosMP3 mp3;

  FILE *file = fopen("/home/psyco/Programming/C/Cuatrimestre_2/ejercicios_extra/robot_stop.mp3", "r+b");

  if (!file) {
    printf("Error al abrir archivo para lectura...\n\n");
    exit(EXIT_FAILURE);
  }

  fseek(file, -128, SEEK_END);
  fread(&mp3, sizeof(mp3), 1, file);
  fclose(file);

  read_mp3_info(&mp3);

  printf("\n\n");
  return 0;
}

int read_mp3_info(struct datosMP3 *mp3) {
  /* Creo que el tag y el año debería manejarse con realloc, pero no estoy seguro */

  printf("Tag: %c%c%c\n", mp3->tag[0], mp3->tag[1], mp3->tag[2]);
  printf("Titulo: %s\n", mp3->titulo);
  printf("Artista: %s\n", mp3->artista);
  printf("Álbum: %s\n", mp3->album);
  printf("Año: %c%c%c%c\n", mp3->anio[0], mp3->anio[1], mp3->anio[2], mp3->anio[3]);
  printf("Comentario: %s\n", mp3->comentario);
  printf("Género: %c\n", mp3->genero);
}
