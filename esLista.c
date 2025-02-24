#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node* next;   
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l ->next;
    }
    return lung; 
}

int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

void stampaLista(Node* lista){
    Node* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

void aggiungiElementoHead(Node** lista, int n){
    Node* l = *lista;
    
    while (l->next != NULL)
    {
        l = l ->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l = l ->next;
    l->valore = n;
    l->next = NULL;
}

void aggiungiElementoFondo(Node** lista, int num){
    Node* l = *lista;
    while(l->next  != NULL){
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l = l ->next;
    l->valore = num;
    l->next = NULL; 
}

void eliminiaUltimoElemento(Node** lista){
    Node* l = *lista;
    while (l->next != NULL)
    {
        l = l->next;
    }
    free(l->next);
    l->next = NULL;
    
}

int main(){
    int n;
    int lung = 0;
    Node* lista = NULL;
    Node* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    l = lista;
    printf("numeri inseriti: ");
    printf("\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);

    printf("\nInserisci un numero: ");
    scanf("%d", &n);

    aggiungiNum(&lista, n);
    stampaListaRicorsiva(lista);
    eliminiaUltimoElemento(&lista);
    stampaListaRicorsiva(lista);
    eliminiaUltimoElemento(&lista);
    stampaListaRicorsiva(lista);
    aggiungiElementoHead(&lista, n);
    stampaListaRicorsiva(lista);
    


    return 0;
}