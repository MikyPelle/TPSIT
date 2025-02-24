#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALORE_ARRIVO 5
#define MAX_VALORE_RAMDOMICO 10

typedef struct Elemento {
    int valore_arrivo;
    int valore_randomico;
    struct Elemento* next;
} Elemento;

typedef struct {
    Elemento* top;
} Pila;

typedef struct {
    Elemento* front;
    Elemento* rear;
} Coda;

void inizializza_pila(Pila* pila) {
    pila->top = NULL;
}

void inizializza_coda(Coda* coda) {
    coda->front = NULL;
    coda->rear = NULL;
}

void push(Pila* pila, int valore_arrivo, int valore_randomico) {
    Elemento* nuovo_elemento = (Elemento*)malloc(sizeof(Elemento));
    nuovo_elemento->valore_arrivo = valore_arrivo;
    nuovo_elemento->valore_randomico = valore_randomico;
    nuovo_elemento->next = pila->top;
    pila->top = nuovo_elemento;
}

void enqueue(Coda* coda, int valore_arrivo, int valore_randomico) {
    Elemento* nuovo_elemento = (Elemento*)malloc(sizeof(Elemento));
    nuovo_elemento->valore_arrivo = valore_arrivo;
    nuovo_elemento->valore_randomico = valore_randomico;
    nuovo_elemento->next = NULL;

    if (coda->rear == NULL) {
        coda->front = nuovo_elemento;
        coda->rear = nuovo_elemento;
    } else {
        coda->rear->next = nuovo_elemento;
        coda->rear = nuovo_elemento;
    }
}

Elemento* pop(Pila* pila) {
    if (pila->top == NULL) {
        return NULL;
    }
    Elemento* ret = pila->top;
    pila->top = pila->top->next;
    return ret;
}

Elemento* dequeue(Coda* coda) {
    if (coda->front == NULL) {
        return NULL;
    }
    Elemento* ret = coda->front;
    coda->front = coda->front->next;
    if (coda->front == NULL) {
        coda->rear = NULL;
    }
    return ret;
}

void confronta_elementi(Pila* pila, Coda* coda) {
    Elemento* elemento_pila = pop(pila);
    Elemento* elemento_coda = dequeue(coda);

    if (elemento_pila == NULL || elemento_coda == NULL) {
        printf("Pila o coda vuote!\n");
        return;
    }

    if (elemento_pila->valore_randomico < elemento_coda->valore_randomico) {
        printf("Il valore randomico nella coda è maggiore, quindi elimino l'elemento dalla coda.\n");
        free(elemento_coda);
    } else if (elemento_pila->valore_randomico > elemento_coda->valore_randomico) {
        printf("Il valore randomico nella pila è maggiore, quindi elimino l'elemento dalla pila e diminuisco il valore della coda.\n");
        free(elemento_pila);
        elemento_coda->valore_randomico -= elemento_pila->valore_randomico;
        enqueue(coda, elemento_coda->valore_arrivo, elemento_coda->valore_randomico);
        free(elemento_coda);
    } else {
        printf("I valori randomici sono uguali, quindi elimino entrambi gli elementi.\n");
        free(elemento_pila);
        free(elemento_coda);
    }
}

int main() {
    srand(time(NULL));

    Pila pila;
    Coda coda;
    inizializza_pila(&pila);
    inizializza_coda(&coda);

    for (int i = 0; i < 5; i++) {
        int valore_arrivo = rand() % MAX_VALORE_ARRIVO + 1;
        int valore_randomico = rand() % MAX_VALORE_RAMDOMICO + 1;
        push(&pila, valore_arrivo, valore_randomico);
        enqueue(&coda, valore_arrivo, valore_randomico);
    }

    while (pila.top != NULL && coda.front != NULL) {
        confronta_elementi(&pila, &coda);
    }

    // Libera eventuali elementi rimasti nella pila
    while (pila.top != NULL) {
        Elemento* elemento_pila = pop(&pila);
        free(elemento_pila);
    }

    // Libera eventuali elementi rimasti nella coda
    while (coda.front != NULL) {
        Elemento* elemento_coda = dequeue(&coda);
        free(elemento_coda);
    }

    return 0;
}
