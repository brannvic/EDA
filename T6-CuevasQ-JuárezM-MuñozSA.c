#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXQUEUE 6

typedef struct nodo {
    int paciente;
    int time;
    struct nodo* link;
} Nodo;

Nodo* HEAD = NULL;
Nodo* TAIL = NULL;
int queueItems = 0;

void QInsert(int paciente, int time) {
    Nodo* pN;
    if (queueItems >= MAXQUEUE) {
        printf("***No hay espacio en la fila***\n");
        return;
    }
    pN = (Nodo*)malloc(sizeof(Nodo));
    pN->paciente = paciente;
    pN->time = time;
    pN->link = NULL;
    if (HEAD == NULL) {
        HEAD = pN;
    }
    if (TAIL == NULL) {
        TAIL = pN;
    }
    else {
        TAIL->link = pN;
        TAIL = pN;
    }
    queueItems++;
    printf("El paciente %d se ha agregado a la fila.\n", paciente);
    if (queueItems > 1) {
        int tiempo_final = 0;
        Nodo* pN_plazo = HEAD; // Inicializar pN_plazo aquí
        while (pN_plazo->link != NULL) {
            tiempo_final += pN_plazo->time;
            pN_plazo = pN_plazo->link;
        }
        tiempo_final += pN_plazo->time;
        printf("Tiempo estimado de espera para el paciente %d: %d minutos.\n", paciente, tiempo_final);
    }
}

int QRemove() {
    int paciente;
    Nodo* pN;
    if (HEAD == NULL) {
        printf("*** No hay nadie formado ***\n");
        return -1;
    }
    paciente = HEAD->paciente;
    pN = HEAD;
    HEAD = HEAD->link;
    free(pN);
    queueItems--;
    printf("El paciente %d ha sido atendido.\n", paciente);
    return paciente;
}

void showQueue() {
    Nodo* pN;
    printf("*** Estado de la cola HEAD=%p TAIL=%p ***\n", HEAD, TAIL);
    if (HEAD == NULL) {
        printf("*** Fila vacia ***\n");
        return;
    }
    pN = HEAD;
    while (pN != NULL) {
        printf("Paciente: %d, Tiempo: %d\n", pN->paciente, pN->time);
        pN = pN->link;
    }
}
void atenderEmergencia(int paciente) {//Paciente con emergencia
    Nodo* pN;
    Nodo* primero = NULL;
    pN = HEAD;
    while (pN != NULL && pN->paciente != paciente) {
        primero = pN;
        pN = pN->link;
    }
    if (pN == NULL) {
        printf("El paciente no se encuentra en la cola.\n");
        return;
    }
    if (primero == NULL) { // Paciente con emergencia es el primer nodo de la lista
        printf("El paciente %d con emergencia ha sido atendido.\n", pN->paciente);
        HEAD = pN->link;
        if (TAIL == pN) {
            TAIL = NULL;
        }
        free(pN);
    } else {
        printf("El paciente %d con emergencia se pasó al frente.\n", pN->paciente);
        primero->link = pN->link;
        if (TAIL == pN) {
            TAIL = primero;
        }
        free(pN);
        QInsert(paciente, 0); // Si hay una emergencia ponemos al paciente el frente de la fila sin tiempo de espera
    }
}


int main() {
    srand(time(NULL));
    int opcion,paciente;
    while (1) {
        printf("*********** Fila de Hospital ********\n");
        printf("\t1. Formar paciente.\n");
        printf("\t2. Atender paciente.\n");
        printf("\t3. Mostrar estado de la fila.\n");
        printf("\t4. Atender emergencia.\n");
        printf("\t5. Salir.\n");
        printf("\tOpcion? "); scanf("%d", &opcion);
        switch (opcion) {
        case 1:
            if (queueItems >= MAXQUEUE) {
                printf("La fila está llena.\n");
                break;
            }
            int paciente, tiempo;
            printf("Ingrese el número del paciente (1-6): ");
            scanf("%d", &paciente);
            printf("Ingrese el tiempo estimado de atención (1-5 minutos): ");
           scanf("%d", &tiempo);
if (tiempo > 5 || tiempo < 1) {
printf("El tiempo de atención debe ser de 1 a 5 minutos.\n");
} else {
QInsert(paciente, tiempo);
}
break;
case 2:
paciente = QRemove();
if (paciente != -1) {
printf("El paciente %d ha sido atendido.\n", paciente);
}
break;
case 3:
showQueue();
break;
case 4:
    if (queueItems == 0) {
        printf("La fila está vacía.\n");
        break;
    }

    printf("Ingrese el número del paciente con emergencia (1-6): ");
    scanf("%d", &paciente);
    atenderEmergencia(paciente);
    break;
case 5:
   exit(0);
default:
printf("Opción no válida.\n");
}
}
return 0;
}
