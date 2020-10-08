/*
Construir una función que reciba dos vectores de estructuras. El primero de ellos esta compuesto
por 12 estructuras BASEDAT que contiene los datos de una lista de precios.

El segundo es un vector compuesto por estructuras AUMENTO. Este último finaliza con un nombre 
de proveedor llamado "FIN".

Se pide:
    a. Actualizar la lista de precios aplicando los aumentos porcentuales indicados en el segundo
        vector a los artículos de cada proveedor del primer vector.
    b. Imprimir la lista de precios completa ordenada por proveedor y dentro de estos, en forma
        creciente de número de artículo.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct BASEDAT {
    char name[20];
    int precio;
};

struct AUMENTO {
    char proveedor[20];
};

#define PROD_AMOUNT 12

int foo(struct BASEDAT[12], struct AUMENTO[12])