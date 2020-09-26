/* Dado el mismo archivo con artículos lista.dat, mostrar en pantalla y almacenar en un archivo la
“nota de pedido” para completar el stock mínimo de artículos. El stock mínimo de cada artículo está almacenado
en un archivo llamado SM.dat estructurado como nº de artículo (int) y cantidad mínima (int).
Se pide armar una lista de productos que son necesarios reponer y cuántos deben comprarse de cada uno
(como mínimo) para alcanzar el nivel de stock mínimo.
El archivo con la nota de pedido debe poder abrirse con un editor de texto normal. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30

struct Product_data {
  int article_number;
  char description[MAX_CHARS];
  float price;
  char proveedor[MAX_CHARS];
  int stock;
};

struct Stock_min {
  int numero_articulo;
  int cantidad_minima;
};

int crear_pedido(FILE *, int, struct Stock_min *);

int main(int argc, char const *argv[]) {
  struct Product_data product_data;
  struct Stock_min stock_min;

  FILE *file_products = fopen("lista.dat", "rb");
  FILE *file_stock = fopen("SM.dat", "rb");
  FILE *file_pedidos = fopen("pedidos.txt", "w");

  if (!file_products || !file_stock || !file_pedidos) {
    printf("Error al abrir un archivo...\n\n");
    exit(EXIT_FAILURE);
  }

  /* Leo los archivos de a uno... */
  fread(&product_data, sizeof(product_data), 1, file_products);
  while (!feof(file_products)) {

    /* Como los productos y el stock tienen la misma cantidad de elemntos, puedo leer sin preocuparme por un
     * EOF */
    fread(&stock_min, sizeof(stock_min), 1, file_stock);

    /* Si el numero de articulo de lista.dat coincide con el de SM.dat
     * y falta stock */
    if (product_data.article_number == stock_min.numero_articulo) {
      if (product_data.stock < stock_min.cantidad_minima) {
        crear_pedido(file_pedidos, product_data.stock, &stock_min);
      }
    }
    fread(&product_data, sizeof(product_data), 1, file_products);
  }
  fclose(file_pedidos);
  fclose(file_products);
  fclose(file_stock);

  printf("\n\n");
  return 0;
}

int crear_pedido(FILE *file_pedido, int current_stock, struct Stock_min *stock_min) {
  int stock_to_buy = stock_min->cantidad_minima - current_stock;
  fprintf(file_pedido, "Artículo: %d\n\tCantidad a comprar: %d\n\n", stock_min->numero_articulo,
          stock_to_buy);
}
