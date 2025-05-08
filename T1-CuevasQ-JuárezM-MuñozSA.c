#include <stdio.h>
#include <limits.h>

int main()
{
   int matriz1[5][3] = { {3,1,7},{4,8,2},{3,5,2},{6,7,9},{2,1,4} };
   int fila_total, columna_total, suma_total = 0, fila_minimo, columna_minimo, fila_maximo, columna_maximo;
   int valor_minimo = INT_MAX, valor_maximo = INT_MIN;


      printf("Matriz original:\n"); //Hacemos uso de 2 if y 2 for para que recorra toda la matriz actualizando a su
   for(int i = 0; i < 5; i++)    //valor mas pequeño y mas grande
   {
      for(int j = 0; j < 3; j++)
      {
         printf("%i\t",matriz1[i][j]);
         if (matriz1[i][j] < valor_minimo) {
            valor_minimo = matriz1[i][j];
            fila_minimo = i;
            columna_minimo = j;
         }
         if (matriz1[i][j] > valor_maximo) {
            valor_maximo = matriz1[i][j];
            fila_maximo = i;
            columna_maximo = j;
         }
      }
      printf("\n");
   }
   printf("\n");

   printf("Totales de cada fila:\n");
   for(int i = 0; i < 5; i++)
   {
      fila_total = 0;
      for(int j = 0; j < 3; j++)
      {
         fila_total += matriz1[i][j];
      }
      printf("Fila %i: %i\n", i+1, fila_total);
   }
   printf("\n");

      printf("Totales de cada columna:\n");
   for(int j = 0; j < 3; j++)
   {
      columna_total = 0;
      for(int i = 0; i < 5; i++)
      {
         columna_total += matriz1[i][j];
      }
      printf("Columna %i: %i\n", j+1, columna_total);
      suma_total += columna_total;
   }
   printf("\n");

   printf("Porcentajes de cada dato en base al total de cada fila (Y su grafico):\n");
for(int i = 0; i < 5; i++)
{
    printf("Fila %i: \n", i+1);
    float fila_total = 0; // Transformando el valor de porcentaje de un float a un int, imprimimos esa cantidad de asteriscos
    //y tenemos nuestro grafico
    for(int j = 0; j < 3; j++)
    {
        fila_total += matriz1[i][j];
    }
    for(int j = 0; j < 3; j++)
    {
        float porcentaje = ((float)matriz1[i][j] / fila_total) * 100;
        printf("%.2f%%\t", porcentaje);
       int porcentaje1=porcentaje;
        for(int r = 0; r < porcentaje1; r++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

   printf("\n");

printf("Porcentajes de cada dato en base al total de cada columna:\n");
for(int j = 0; j < 3; j++)
{
    printf("Columna %i: ", j+1);
    float columna_total = 0; // mover aquí el cálculo de la suma total
    for(int i = 0; i < 5; i++)
    {
        columna_total += matriz1[i][j];
    }
    for(int i = 0; i < 5; i++)
    {
        float porcentaje = ((float)matriz1[i][j] / columna_total) * 100;
        printf("%.2f%%\t", porcentaje);
    }
    printf("\n");
}
printf("\n");

printf("El valor mas chico (%i) fue en la marca %i en el mes %i \n", valor_minimo, fila_minimo+1, columna_minimo+1);
printf("El valor mas grande (%i) fue en la marca %i en el mes %i \n", valor_maximo, fila_maximo+1, columna_maximo+1);


   FILE *archivo = fopen("matriz_original.txt", "w");
   for(int i = 0; i < 5; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         fprintf(archivo, "%i\t", matriz1[i][j]);
      }
      fprintf(archivo, "\n");
   }
   fclose(archivo);

   return 0;
}
