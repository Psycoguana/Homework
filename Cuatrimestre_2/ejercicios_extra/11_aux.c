/* Se dispone de dos archivos binarios(ventas realizadas y provincias) compuestos respectivamente de
estas estructuras:

struct venta {
  char vendedor[60];
  float monto;
  int codigoprovincia;
};

 struct provincia {
  char nombre[40];
  int codigoprovincia;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 60
#define PROVINCIAS_SIZE 23

struct Venta {
  char vendedor[60];
  float monto;
  int codigoprovincia;
};

struct Provincia {
  char nombre[40];
  int codigoprovincia;
};

int create_provincias();
int create_ventas();
void _read_provincias();
void _read_ventas();

int main(int argc, char const *argv[]) {

  create_provincias();
  _read_provincias();
  create_ventas();
  _read_ventas();

  printf("\n\n");
  return 0;
}

int create_ventas() {
  int i;
  struct Venta venta;
  FILE *file_ventas = fopen("ventas.dat", "wb");

  if (!file_ventas) {
    printf("Error al crear algún archivo...\n");
    exit(EXIT_FAILURE);
  }

  char proveedores[][MAX_CHARS] = {"PEREZ", "PRAZZI", "KERBAN", "MARCO", "POLO", "NELA", "ALEN"};

  /* El 500 es completamente al azar */
  srand(time(0));
  for (i = 0; i < 500; i++) {
    int rand_prov_index = rand() % ((sizeof(proveedores) / MAX_CHARS));
    int rand_provincia = rand() % PROVINCIAS_SIZE;
    /* Algo raro y feo para obtener un float único para cada artículo. */
    float rand_price = (i + 1) * 3.2;

    strcpy(venta.vendedor, proveedores[rand_prov_index]);
    venta.codigoprovincia = rand_provincia;
    venta.monto = rand_price;

    fwrite(&venta, sizeof(venta), 1, file_ventas);
  }
  fclose(file_ventas);
}

int create_provincias() {
  int i;
  struct Provincia provincia;
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

  FILE *file_provincias = fopen("provincias.dat", "wb");
  if (!file_provincias) {
    printf("Error al crear archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < PROVINCIAS_SIZE; i++) {
    strcpy(provincia.nombre, *(provincias_array + i));
    provincia.codigoprovincia = i;

    fwrite(&provincia, sizeof(provincia), 1, file_provincias);
  }
  fclose(file_provincias);
}

void _read_provincias() {
  int i;
  struct Provincia provincia;

  FILE *file_provincias = fopen("provincias.dat", "rb");
  if (!file_provincias) {
    printf("Error al crear archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&provincia, sizeof(provincia), 1, file_provincias);
  while (!feof(file_provincias)) {
    printf("%d\t%s\n", provincia.codigoprovincia, provincia.nombre);
    fread(&provincia, sizeof(provincia), 1, file_provincias);
  }
}

void _read_ventas() {
  struct Venta venta;
  FILE *file = fopen("ventas.dat", "rb");
  if (!file) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  fread(&venta, sizeof(venta), 1, file);
  while (!feof(file)) {
    fread(&venta, sizeof(venta), 1, file);
  }
}