#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char* codice;
    float peso;
    float tara;
    struct node* next;
}Node;

int is_empty(Node* head){
    if(head == NULL) return 1;
    else return 0;
}

void push(Node **head, Node *el){
    if(is_empty(*head)){
        *head = el;
        el->next = NULL;
    }else{
        el->next = *head;
        *head = el;
    }
}

Node* pop(Node **head){
    Node* ret = *head;
    if(is_empty(NULL)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Node* head){
    Node* l = head;
    while(l != NULL){
        printf("%5d", l->valore);
        l = l->next;
    }
}

int main(){
    float peso, tara;
    char* cod;
    char car;
    Node* head = NULL;
    Node* l;
    do{
        printf("inserire il codice della nave: ");
        fflush(stdin);
        scanf("%s", cod);
        printf("inserire il peso della nave: ");
        scanf("%f", &peso);
        printf("inserire la tara della nave: ");
        scanf("%f", &tara);
        Node* element = (Node*) malloc(sizeof(Node));
        element->codice = cod;
        element->peso = peso;
        element->tara = tara;
        push(&head, element);
        printf("vuoi fermare? (s o n): ");
        fflush(stdin);
        scanf("%c", &car);
        
    } while (car == 'n');
    stampaPila(head);
    Node* removed = pop(&head);
    printf("\nElemento rimosso: %s, %f, %f\n", removed->codice, removed->peso, removed->tara);
    stampaPila(head);
    return 0;
}
