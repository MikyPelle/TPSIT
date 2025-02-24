#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct paziente{
    char nome[100];
    int eta;
    char colore[100];
    struct paziente* next;
}Paziente;

bool is_empty(Paziente* head){
    return head == NULL;
}

void enqueue(Paziente** head, Paziente** tail, Paziente* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Paziente* dequeue(Paziente** head, Paziente** tail){
    Paziente* ret = *head;
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

void stampaCoda(Paziente* head){
    Paziente* l = head;
    while (l != NULL){
        printf("%s, %d, %s \n", l->nome, l->eta, l->colore);
        l = l->next;
    }
}


void gestioneOsp(Paziente** headRosso, Paziente**tailRosso, Paziente**headGiallo, Paziente**tailGiallo, Paziente**headVerde, Paziente** tailVerde, Paziente**headBianco, Paziente**tailBianco){
    while(is_empty(*headRosso)!=true || is_empty(*headGiallo)!=true || is_empty(*headVerde)!=true 
                        || is_empty(*headBianco)!=true){
        if(is_empty(*headRosso) != true){
            dequeue(headRosso,tailRosso);
        }else if(is_empty(*headGiallo) != true){
            dequeue(headGiallo,tailGiallo);
        }else if(is_empty(*headVerde) != true){
            dequeue(headVerde,tailVerde);
        }else{
            dequeue(headBianco,tailBianco);
        }
        printf("Progressivo ospedale: \n");
        stampaCoda(*headRosso);
        stampaCoda(*headGiallo);
        stampaCoda(*headVerde);
        stampaCoda(*headBianco);     
}
}

int main(){
    int DIM = 100;
    int n=-1;
    Paziente* headRosso = NULL;
    Paziente* headGiallo = NULL;
    Paziente* headVerde = NULL;
    Paziente* headBianco = NULL;

    Paziente* tailRosso = NULL;
    Paziente* tailGiallo = NULL;
    Paziente* tailVerde = NULL;
    Paziente* tailBianco = NULL;
    do{
        printf("Inserire 1 per caricare paziente, -1 per smettere: ");
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        Paziente* element = (Paziente*) malloc(sizeof(Paziente));
        printf("Inserire il nome del paziente: \n");
        scanf("%s", element->nome);

        printf("Inserire l'eta' del paziente: \n");
        scanf("%d", &(element->eta));

        printf("Inserire il codice colore del paziente: \n");
        scanf("%s", element->colore);

        if((strcmp(element->colore,"rosso"))==0){
            enqueue(&headRosso, &tailRosso, element);
        }else if((strcmp(element->colore,"giallo")==0)){
            enqueue(&headGiallo, &tailGiallo, element);
        }else if((strcmp(element->colore,"verde")==0)){
            enqueue(&headVerde, &tailVerde, element);
        }else{
            enqueue(&headBianco,&tailBianco,element);
        }
    }while(n!=-1);
    stampaCoda(headRosso);
    stampaCoda(headGiallo);
    stampaCoda(headVerde);
    stampaCoda(headBianco);  
    gestioneOsp(&headRosso, &tailRosso, &headGiallo, &tailGiallo, &headVerde, &tailVerde, &headBianco, &tailBianco); 
}