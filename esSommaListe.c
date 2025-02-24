#include <stdio.h>
#include <stdlib.h>

typedef struct EL 
{
    int dato;
    struct EL *next;
} ELEMENTO;

int sommaLista(ELEMENTO* lista, int m){
    ELEMENTO* l = lista;
    int tro = -1;
    int somma = 0;
    while (l != NULL)
    {
        if(l->dato % m == 0){
            somma += l->dato;
            
        }
        l = l ->next;
        tro++;
    }
    if(tro == -1){
        somma = tro;
    }

    return somma;
}

int main(){
    ELEMENTO* lista = NULL;
    ELEMENTO* l = lista;
    int somma;
    int n;

    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = lista;
            } else {
                l->next = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = l->next;
            }
            l->dato = n;
            l->next = NULL;
        }
    } while (n >= 0);

    printf("Inserire un numero: ");
    scanf("%d", &n);

    somma = sommaLista(lista, n);

    if(somma != -1){
        if(somma != 0)
            printf("La somma dei multlipli di %d e': %d", n, somma);
        else
            printf("Non sono presenti multlipli di %d ", n);
    }else{
        printf("La lista e' vuota.");
    }

    return 0;
}