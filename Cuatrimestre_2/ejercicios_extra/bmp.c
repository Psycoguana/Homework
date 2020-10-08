#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tagBITMAPINFOHEADER {
  /* Me re robé esto de stackoverflow ups */
  char file_type[2];
  unsigned int biSize;  /* specifies the number of bytes required by the struct */
  long biWidth;         /* specifies width in pixels */
  long biHeight;        /* species height in pixels */
  int biPlanes;         /* specifies the number of color planes, must be 1 */
  int biBitCount;       /* specifies the number of bit per pixel */
  int biCompression;    /* specifies the type of compression */
  int biSizeImage;      /* size of image in bytes */
  long biXPelsPerMeter; /* number of pixels per meter in x axis */
  long biYPelsPerMeter; /* number of pixels per meter in y axis */
  int biClrUsed;        /* number of colors used by the bitmap */
  int biClrImportant;   /* number of colors that are important */
} bitmap_info;

int main(int argc, char const *argv[]) {

  FILE *file = fopen("image.bmp", "rb");
  if (!file) {
    printf("Error al abrir imagen...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&bitmap_info, sizeof(bitmap_info), 1, file);
  printf("Image type: %c%c\n", bitmap_info.file_type[0], bitmap_info.file_type[1]);
  printf("File size: %u\n", bitmap_info.biSize);
  printf("Ancho: %ld\n", bitmap_info.biWidth);
  printf("Alto: %ld\n", bitmap_info.biHeight);
  printf("Tamaño de imagen: %d\n", bitmap_info.biSizeImage);
  printf("Colores usados: %d\n", bitmap_info.biClrUsed);

  printf("\n\n");
  return 0;
}
