#include <stdio.h>
#include <string.h>

void ordenarApellidos(char apellidos[][100], int numApellidos) {
    int i, j;
    char temp[100];

    for (i = 0; i < numApellidos - 1; i++) {
        for (j = 0; j < numApellidos - i - 1; j++) {
            if (strcmp(apellidos[j], apellidos[j + 1]) > 0) {
                strcpy(temp, apellidos[j]);
                strcpy(apellidos[j], apellidos[j + 1]);
                strcpy(apellidos[j + 1], temp);
            }
        }
    }
}

int main() {
    FILE *archivoOriginal, *archivoOrdenado;
    char apellido1[1000], apellido2[1000], apellido3[1000];
    char nombreArchivo[100], nombreArchivoOrdenado[100];

    printf("Este programa lee apellidos y los imprime en un archivo sin ordenar, \n luego los ordena e imprime en otro archivo");
    
    printf("\nEscriba el nombre del archivo como se muestra en las comillas 'T10-A-apellidos sin ordenar': ");
    fgets(nombreArchivo, sizeof(nombreArchivo), stdin);

    // Leer los tres apellidos
    printf("Ingrese el primer apellido: ");
    fgets(apellido1, sizeof(apellido1), stdin);

    printf("Ingrese el segundo apellido: ");
    fgets(apellido2, sizeof(apellido2), stdin);

    printf("Ingrese el tercer apellido: ");
    fgets(apellido3, sizeof(apellido3), stdin);

    // Guardar los tres textos en el archivo
    archivoOriginal = fopen(nombreArchivo, "w");

    if (archivoOriginal == NULL) {
        printf("Error al abrir el archivo para los apellidos.");
        return 1;
    }

    fprintf(archivoOriginal, "%s", apellido1);
    fprintf(archivoOriginal, "%s", apellido2);
    fprintf(archivoOriginal, "%s", apellido3);
    fclose(archivoOriginal);
    printf("Los tres apellidos se han guardado correctamente en el archivo '%s'\n", nombreArchivo);

    // Concatenar los tres apellidos en uno solo
    char apellidosConcatenado[3000];
    strcpy(apellidosConcatenado, apellido1);
    strcat(apellidosConcatenado, apellido2);
    strcat(apellidosConcatenado, apellido3);

    // Separar los apellidos en el texto
    char *token = strtok(apellidosConcatenado, " \n");
    char apellidos[100][100];
    int numApellidos = 0;

    while (token != NULL) {
        strcpy(apellidos[numApellidos], token);
        numApellidos++;
        token = strtok(NULL, " \n");
    }

    // Aplicar el método burbuja al arreglo de apellidos
    ordenarApellidos(apellidos, numApellidos);

    // Pedir el nombre del archivo de salida para el texto ordenado
    printf("Escriba el nombre del archivo como se muestra en las comillas 'T10-D-apellidos ordenados': ");
    fgets(nombreArchivoOrdenado, sizeof(nombreArchivoOrdenado), stdin);

    // Generar archivo con el texto ordenado
    archivoOrdenado = fopen(nombreArchivoOrdenado, "w");

    if (archivoOrdenado == NULL) {
        printf("Error al abrir el archivo para el texto ordenado.");
        return 1;
    }

    for (int i = 0; i < numApellidos; i++) {
        fprintf(archivoOrdenado, "%s\n", apellidos[i]);
    }

    fclose(archivoOrdenado);
    printf("El texto ordenado alfabéticamente se ha guardado correctamente en el archivo '%s'\n", nombreArchivoOrdenado);

    return 0;
}
