#include <stdio.h>
#include <stdlib.h>

typedef struct El {
    int s;
    struct El *next;
}ElementoLista;

typedef ElementoLista *ListaDiinteri;

ListaDiinteri FirstEven(ListaDiinteri lis) {
    while (lis != NULL) {
        if (lis->s % 2 == 0)
            return lis;
        else
            lis = lis ->next;
    }
    return NULL;
}

int main(){
    ElementoLista* lista;
    ElementoLista* l = lista;
    int n;

    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = lista;
            } else {
                l->next = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = l->next;
            }
            l->s = n;
            l->next = NULL;
        }
    } while (n >= 0);


    l = FirstEven(lista);
    if(l != NULL)
        printf("Il primo elemento pari della lista e' %d", l->s);
    else
        printf("Non sono presenti numeri pari nella lista.");
    
}