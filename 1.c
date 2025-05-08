#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { int aluNumCuenta; char aluNombre[15]; float aluPromedio; }
Alumno;
main ()
{ printf("Sizeof Alumno %d = %d +%d+%d\n", sizeof(Alumno),
sizeof(int), sizeof(char [15]), sizeof(float));
Alumno *pa1, *pa2;
pa1 = (Alumno *) malloc(sizeof(Alumno));
printf ("pa1 @ %u\n", pa1);
pa1->aluNumCuenta = 25; pa1->aluPromedio = 8.9; strcpy(pa1->aluNombre,"MaryLopez");
printf("%4d %-15s %4.1f \n", pa1->aluNumCuenta, pa1->aluNombre, pa1->aluPromedio);
pa2 = (Alumno *) malloc(sizeof(Alumno));
printf ("pa2 @ %u\n", pa2);
pa2->aluNumCuenta = 31; pa2->aluPromedio = 8.5; strcpy(pa2->aluNombre,"AnaGomez");
printf("%4d %-15s %4.1f \n", pa2->aluNumCuenta, pa2->aluNombre, pa2->aluPromedio);
float * pf1, *pf2, *pf3;
int k, m, inc, m2;
printf("Cuantos elementos? "); scanf("%d", &m);
pf1 = (float *) malloc(m*sizeof(float));
printf("pf1 @ %d\n", pf1);
for (k=0; k < m; k++)
*(pf1+k) = k*2;
for (k=0; k < m; k++)
printf("%4.1f -",*(pf1+k));
printf("\n\n");
pf2 = (float *) calloc(m, sizeof(float));
printf("pf2 @ %d\n", pf2);
for (k=0; k < m; k++)
*(pf2+k) = k*5;
for (k=0; k < m; k++)
printf("%4.1f -",*(pf2+k));
printf("\n\n");
printf("Cuantos elementos adicionales (3-5)? "); scanf("%d", &inc);
m2 = m + inc;
pf3 = (float *) realloc(pf2, m*sizeof(float));
printf("pf3 @ %d\n", pf3);
for (k=m; k < m2; k++)
*(pf3 + k) = k*7;
for (k=0; k < m2; k++)
printf("%4.1f -",*(pf3+k));
printf("\n\n");
free(pf1); // free(pf2);
free(pf3);
getch();
}
