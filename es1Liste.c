#include <stdio.h>
#include <stdlib.h>

typedef struct el
{
    int s;
    struct el *next;
} Elemento;

int sommaLista(Elemento *head, int n)
{
    Elemento *l = head;
    int s = 0;
    while (l != NULL)
    {
        if(l->s % n ==0)
            s += l->s;
        l = l->next;
    }
    return s;
}

void stampaLista(Elemento *head)
{
    Elemento *l = head;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->s);
        l = l->next;
    }
}

int main()
{
    int n, div;
    Elemento *lista = NULL;
    Elemento *l;

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL)
            {
                lista = (Elemento *)malloc(sizeof(Elemento));
                l = lista;
            }
            else
            {
                l->next = (Elemento *)malloc(sizeof(Elemento));
                l = l->next;
            }
            l->s = n;
            l->next = NULL;
        }
    } while (n >= 0);
    stampaLista(lista);
    printf("Inserisci il divisore\n");
    scanf("%d", &div);
    int somma = sommaLista(lista, div);
    printf("somma: %d", somma);
    return 0;
}