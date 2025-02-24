#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo* next;
} Nodo;

typedef struct Coda {
    Nodo* front;
    Nodo* rear;
} Coda;

typedef struct Pila {
    Nodo* head;
} Pila;

struct Coda* creaCoda() { 
    struct Coda* coda = (struct Coda*)malloc(sizeof(struct Coda));
    coda->front = coda->rear = NULL; 
    return coda;
}

Pila* creaPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->head = NULL;
    return pila;
}

int isEmptyCoda(struct Coda* coda) {
    return coda->front == NULL;
}

void enqueue(struct Coda* coda, int val) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->val = val;
    nuovoNodo->next = NULL;
    
    if (isEmptyCoda(coda)) {
        coda->front = coda->rear = nuovoNodo;
    } else {
        coda->rear->next = nuovoNodo;
        coda->rear = nuovoNodo;
    }
}

int dequeue(struct Coda* coda) {
    if (coda->front == NULL) {
        printf("Errore: la coda è vuota\n");
        return -1;
    }
    
    Nodo* temp = coda->front;
    int dato = temp->val;
    coda->front = coda->front->next;
    
    if (coda->front == NULL) {
        coda->rear = NULL;
    }
    
    free(temp);
    return dato;
}

int is_empty(Pila* pila){
    if(pila->head == NULL) return 1;
    else return 0;
}

void push(Pila* pila, int val) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->val = val;
    nuovoNodo->next = pila->head;
    pila->head = nuovoNodo;
}

Nodo* pop(Pila* pila){
    if(is_empty(pila)){
        return NULL;
    }else{
        Nodo* temp = pila->head;
        pila->head = pila->head->next;
        return temp;
    }
}

int equals(Coda* coda1, Coda* coda2) {
    Nodo* nodo1 = coda1->front;
    Nodo* nodo2 = coda2->front;
    
    while (nodo1 != NULL && nodo2 != NULL) {
        if (nodo1->val != nodo2->val) {
            return 0;
        }
        nodo1 = nodo1->next;
        nodo2 = nodo2->next;
    }
    
    return (nodo1 == NULL && nodo2 == NULL);
}

int main() {
    struct Coda* coda1 = creaCoda();
    struct Coda* coda2 = creaCoda();
    Pila* pila = creaPila();
    
    enqueue(coda1, 10);
    enqueue(coda1, 20);
    enqueue(coda1, 30);
    
    printf("Elemento estratto dalla coda: %d\n", dequeue(coda1));
    printf("Elemento estratto dalla coda: %d\n", dequeue(coda1));

    push(pila, 5);
    push(pila, 15);
    push(pila, 25);
    
    printf("Elemento estratto dalla pila: %d\n", pop(pila)->val);
    printf("Elemento estratto dalla pila: %d\n", pop(pila)->val);
    
    enqueue(coda2, 10);
    enqueue(coda2, 20);
    enqueue(coda2, 30);
    
    if (equals(coda1, coda2)) {
        printf("Le code sono uguali\n");
    } else {
        printf("Le code non sono uguali\n");
    }
    
    return 0;
}
