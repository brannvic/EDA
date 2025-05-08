#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descripcion[30];
    float precio;
    int existencia;
} Producto, Productos;

int i, j;
Producto altaProd(int codigo, char descripcion[], float precio, int existencia);
void mostrarProd(Producto R);

Productos altaProds(int cod1, char desc1[], float pre1, int exis1);
void mostrarProds(Producto R);

int main()
{
    Producto *pP;
    pP = (Producto *) malloc(sizeof(Producto));
    printf ("pP %u\n", pP);

    Producto pP1, pP2, pP3, pP4, pP5, producto[5];
    pP1 = altaProd(3, "Camara", 250, 5);
    pP2 = altaProd(8, "Hub", 60, 8);
    pP3 = altaProd(12, "Teclado", 120, 6);
    pP4 = altaProd(15, "Mouse", 40, 10);
    pP5 = altaProd(10, "Conector", 5, 20);

    producto[0]=pP1;
    producto[1]=pP2;
    producto[2]=pP3;
    producto[3]=pP4;
    producto[4]=pP5;

    printf("Array de Productos:\n");
    for( i=0; i<5; i++)
    {
        mostrarProd(producto[i]);
    }

    Productos *pProds;
    int m, cod1, pre1, exis1;
    char desc1[30];

    printf("\n¿Cuantos elementos adicionales entre (3-5) desea manejar? ");
    scanf("%d", &m);
    pProds = (Productos *) calloc(m, sizeof(Productos));

    for(j=1; j<m; j++)
    {
    printf("\n¿Cual es el codigo del producto? ");
    scanf("%d", &cod1);
    printf("\nEscribe el nombre del producto ");
    scanf(" %c", desc1);
    printf("\n¿Cual es el precio del producto? ");
    scanf("%f", &pre1);
    printf("\n¿Cuantas existencias hay del producto? ");
    scanf("%d", &exis1);
    }

    pProds = (Productos *) realloc(pProds, m * sizeof(Productos));

    Productos pProds1, pProds2, pProds3, pProds4, pProds5, productos[6];
    pProds1 = altaProds(cod1, desc1, pre1, exis1);
    pProds2 = altaProds(cod1, desc1, pre1, exis1);
    pProds3 = altaProds(cod1, desc1, pre1, exis1);
    pProds4 = altaProds(cod1, desc1, pre1, exis1);
    pProds5 = altaProds(cod1, desc1, pre1, exis1);

    productos[0]=pProds1;
    productos[1]=pProds2;
    productos[2]=pProds3;
    productos[3]=pProds4;
    productos[4]=pProds5;

    printf("Array de Productos:\n");
    for( j=0; j<m; j++)
    {
        mostrarProd(productos[j]);
    }

    getch();

    return 0;
}

Producto altaProd(int cod, char desc[], float pre, int exis)
{
    Producto R;
    R.codigo = cod;
    strcpy(R.descripcion, desc);
    R.precio = pre;
    R.existencia = exis;

    return R;
}

void mostrarProd(Producto R)
{
    printf("Codigo: %d\tDescripcion: %s\tPrecio: $%.2f\tExistencia: %d\n",
           R.codigo, R.descripcion, R.precio, R.existencia);
}

Productos altaProds(int cod1, char desc1[], float pre1, int exis1)
{
    Productos R;
    R.codigo = cod1;
    strcpy(R.descripcion, desc1);
    R.precio = pre1;
    R.existencia = exis1;

    return R;
}

void mostrarProds(Producto R)
{
    printf("Codigo: %d\tDescripcion: %s\tPrecio: $%.2f\tExistencia: %d\n",
           R.codigo, R.descripcion, R.precio, R.existencia);
}
