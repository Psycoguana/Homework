/* Dados los archivos del punto anterior, realice un programa que reciba por línea de comandos un código de
    provincia y cree un archivo de texto con los montos, uno debajo del otro, de todas las ventas realizadas
    en esa provincia. Guardarlos con dos decimales. Verificar que el archivo se puede abrir con un editor de
    texto regular. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Venta {
  char vendedor[60];
  float monto;
  int codigoprovincia;
};

struct Provincia {
  char nombre[40];
  int codigoprovincia;
};

int main(int argc, char const *argv[]) {

  int provincia_code = atoi(argv[1]);

  struct Venta venta;

  FILE *file_montos = fopen("monto_ventas.txt", "w");
  FILE *file_ventas = fopen("ventas.dat", "rb");
  if (!file_ventas || !file_montos) {
    printf("Error al abrir el archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  fprintf(file_montos, "Ventas registradas para la provincia con código %d\n\n\n", provincia_code);
  fread(&venta, sizeof(venta), 1, file_ventas);
  while (!feof(file_ventas)) {
    if (venta.codigoprovincia == provincia_code) {
      fprintf(file_montos, "Proveedor: %s\n\tMonto: $%.2f\n\n", venta.vendedor, venta.monto);
    }

    fread(&venta, sizeof(venta), 1, file_ventas);
  }

  printf("\n\n");
  return 0;
}
