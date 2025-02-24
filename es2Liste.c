#include <stdio.h>
#include <stdlib.h>

typedef struct el
{
    int s;
    struct el *next;
} Elemento;

int FirstEven(Elemento *head)
{
    Elemento *l = head;
    int cont = 0;
    while (l != NULL)
    {
        if (l->s % 2 == 0)
            return cont;
        else {l = l->next;
        cont++;}
    }
    return NULL;
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
    int n;
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
    int pos = FirstEven(lista);
    printf("primo numero pari posizione: %d", pos);
    return 0;
}