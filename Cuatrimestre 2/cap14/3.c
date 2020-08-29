// Un archivo binario contiene estructuras con información de ventas de un comercio,
// consistentes en nombre del vendedor y monto de la venta.
// Se pide estructurar la información y mostrar en pantalla el nombre del vendedor
// que haya vendido más (sumando los montos).

#include <stdio.h>
#include <stdlib.h>

struct Ventas {
  char vendedor[20];
  float monto;
};

int input_venta(struct Ventas, FILE *);
int record_venta(struct Ventas, FILE *);
int read_venta(FILE *);

int main(int argc, char const *argv[]) {

  FILE *file = fopen("3.txt", "w+b");

    if (!file)

  struct Ventas ventas;
  input_venta(ventas, file);
  read_venta(file);

  fclose(file);
  printf("\n\n");
  return 0;
}

int input_venta(struct Ventas ventas, FILE *file) {
  int size, i;
  float monto_vendido;

  printf("Cuantos datos desea ingresar? ");
  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    printf("Nombre del vendedor: ");
    clean_stdin();
    gets(ventas.vendedor);

    printf("Ingrese el monto vendio: ");
    scanf("%f", &monto_vendido);
    ventas.monto = monto_vendido;

    record_venta(ventas, file);
    printf("\n");
  }
}

int record_venta(struct Ventas ventas, FILE *file) { fwrite(&ventas, sizeof(ventas), 1, file); }

int read_venta(FILE *file) {

  fseek(file, 0, SEEK_SET);
  struct Ventas ventas;
  float max_venta = 0;
  int i = 0, best_seller_index;

  fread(&ventas, sizeof(ventas), 1, file);

  while (!feof(file)) {
    // Si el monto actual es el más grande que se haya encontrado...
    if (ventas.monto > max_venta) {
      // Actualiza el monto más grande y el index del struct.
      max_venta = ventas.monto;
      best_seller_index = i;
    }
    fread(&ventas, sizeof(ventas), 1, file);
    i++;
  }

  // Me desplazo hasta el mejor vendedor...
  fseek(file, best_seller_index * (sizeof(ventas)), SEEK_SET);
  // Cargo el contenido del struct en disco a la memoria temporal...
  fread(&ventas, sizeof(ventas), 1, file);

  printf("\nEl mejor vendedor es %s, con un monto de ventas de %.2f", ventas.vendedor, ventas.monto);
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}
