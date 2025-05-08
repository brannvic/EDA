#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Product {
    int codigo;
    char descripcion[30];
    float precio;
    int existencia;
};

int i, j;
Product altaProd(Product x, int codigo, char descripcion[], float precio, int existencia);

void mostrarProd(Product R);


int main()
{
	setlocale(LC_CTYPE, "spanish");
    Product *pP;
    pP = (Product *) malloc(5 * sizeof(Product));
    printf ("pP %u\n", pP);

    Product pP1, pP2, pP3, pP4, pP5, producto[5];
    pP[0] = altaProd(pP1,3, "Camara", 250, 5);
    pP[1] = altaProd(pP2, 8, "Hub", 60, 8);
    pP[2] = altaProd(pP3, 12, "Teclado", 120, 6);
    pP[3] = altaProd(pP4, 15, "Mouse", 40, 10);
    pP[4] = altaProd(pP5, 10, "Conector", 5, 20);

    printf("Array de Productos:\n");
    for( i=0; i<5; i++)
    {
        mostrarProd(pP[i]);
    }
	
	
	
	Product *pProds;
	int m;
    printf("\n¿Cuantos elementos adicionales entre (3-5) desea manejar? ");
    scanf("%d", &m);
    pProds = (Product *) calloc(m, sizeof(Product));
	
	if (m < 3 || m >5){
		printf("\nHas ingresado un numero fuera del rango");
		return 0;
	}
	else{
		for(j = 3; j < m*2; j++){
		    printf("\nIngrese el código del producto %i:", j-2);
		    scanf("%d", &pProds[j].codigo);
		    fflush(stdin);
		    printf("Ingrese el nombre del producto %i: ", j-2);
		    fgets(pProds[j].descripcion, 30, stdin);
		    printf("Ingrese el precio del producto %i: ", j-2);
		    scanf("%f", &pProds[j].precio);
		    printf("Ingrese las existencias del producto %i: ", j-2);
		    scanf("%d", &pProds[j].existencia);
	    }
	}

    printf("Array de Productos:\n");
    for( j = 3; j < m*2; j++)
    {
        mostrarProd(pProds[j]);
        printf("\n");
    }

	free(pP);
	free(pProds);
    getch();
    return 0;
}

Product altaProd(Product x, int cod, char desc[], float pre, int exis)
{
    x.codigo = cod;
    strcpy(x.descripcion, desc);
    x.precio = pre;
    x.existencia = exis;

    return x;
}

void mostrarProd(Product R)
{
    printf("Codigo: %d\tDescripcion: %s\tPrecio: $%.2f\tExistencia: %d\n",
           R.codigo, R.descripcion, R.precio, R.existencia);
}

