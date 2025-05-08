#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descripcion[30];
    float precio;
    int existencia;
} Producto;

int i;
Producto altaProd(int codigo, char descripcion[], float precio, int existencia);
void mostrarProd(Producto P);

int main() {

    Producto p1, p2, p3, p4, p5, productos[8];
    p1 = altaProd(3, "Camara", 250, 5);
    p2 = altaProd(8, "Hub", 60, 8);
    p3 = altaProd(12, "Teclado", 120, 6);
    p4 = altaProd(15, "Mouse", 40, 10);
    p5 = altaProd(10, "Conector", 5, 20);

    productos[0] = p1;
    productos[1] = p2;
    productos[2] = p3;
    productos[3] = p4;
    productos[4] = p5;
    productos[5] = altaProd(20, "Monitor", 300, 3);
    productos[6] = altaProd(25, "Bocinas", 50, 12);

    printf("Array de Productos:\n");
    for(int i=0; i<8; i++) {
        mostrarProd(productos[i]);
    }

    return 0;
}

Producto altaProd(int cod, char desc[], float pre, int exis) {
    Producto P;
    P.codigo = cod;
    strcpy(P.descripcion, desc);
    P.precio = pre;
    P.existencia = exis;

    return P;
}

void mostrarProd(Producto P) {
    printf("Codigo: %d\tDescripcion: %s\tPrecio: $%.2f\tExistencia: %d\n",
           P.codigo, P.descripcion, P.precio, P.existencia);
}
