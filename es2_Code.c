#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct persona{
    char* nome;
    char* cognome;
    int eta;
    struct persona* next;
}Persona;

bool is_empty(Persona* head){
    return head == NULL;
}

void enqueue(Persona** head, Persona** tail, Persona* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Persona* dequeue(Persona** head, Persona** tail){
    Persona* ret = *head;
    if(is_empty(*head)){
        printf("\nErrore coda vuota");
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

int calcolaLunghezza(Persona* head){
    Persona* h = head;
    int lung = 0;
    while (h != NULL)
    {
        lung++;
        h = h->next;
    }
    return lung; 
}

void stampaCoda(Persona* head){
    Persona* l = head;
    while (l != NULL)
    {
        printf("\n%s ", l->cognome);
        printf("\n%s ", l->nome);
        printf("\n%d\n ", l->eta);
        l = l ->next;
    }
}

void rimuoviTutti(Persona** head, Persona** tail){
    Persona* corrente =  *head;
    Persona* next;
    while(corrente != NULL){
        next=corrente->next;
        free(corrente);
        corrente=next;
    }
    *head=NULL;
    *tail=NULL;
}

int main() {
    Persona* head = (Persona*)malloc(sizeof(Persona));
    Persona* tail = (Persona*)malloc(sizeof(Persona));

    head = NULL;
    tail = NULL;

    Persona* elemento = (Persona*)malloc(sizeof(Persona));

    elemento->cognome = "Giorgis";
    elemento->nome = "Marco";
    elemento->eta = 18;
    elemento->next = NULL;

    enqueue(&head, &tail, elemento);

    Persona* elemento2 = (Persona*)malloc(sizeof(Persona));

    elemento2->cognome = "Rossi";
    elemento2->nome = "Mario";
    elemento2->eta = 16;
    elemento2->next = NULL;

    enqueue(&head, &tail, elemento2);

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    Persona* temp = dequeue(&head, &tail);
    printf("\n%s", temp->cognome);

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    rimuoviTutti(&head, &tail);
    Persona* temp1 = dequeue(&head, &tail);

    free(elemento);
    free(elemento2);
    return 0;
}