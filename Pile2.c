#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char carattere;
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
        printf("%c", l->carattere);
        l = l->next;
    }
}

int main(){
    char* str;
    Node* head = NULL;
    Node* l;

    printf("Inserisci una stringa: ");
    fflush(stdin);
    scanf("%s", str);
    printf("%s", str);
    
    for(int k = 0; k < strlen(str); k++){
        Node* element = (Node*) malloc(sizeof(Node));
        element->carattere = str[k];
        push(&head, element);
    }
    stampaPila(head);
    /*
    if(strlen(str) % 2 == 0){
        printf("\nPari");
        
    }else{
        printf("\nDispari");
    }*/
    

    return 0;
}