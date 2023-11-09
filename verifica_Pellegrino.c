#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#define DIM_RIGA 200
#define QUOTA_MAX 2200
#define QUOTA 100

typedef struct
{
    char* data;
    char* cognome;
    int quota;
}Alunno;

typedef struct
{
    char* cognome;
    int quota;
}Io;



int contaRighe(char filename[]){
    FILE *fp;
    int cont = 0;
    char riga[DIM_RIGA];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        while(fgets(riga, DIM_RIGA, fp)){  
            cont++;
        }
    }
    fclose(fp);
    return cont;
}

void caricaClasse(Alunno classe[], char filename[], int nRighe){
    FILE *fp;
    char* campo; 
    char riga[DIM_RIGA];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        for(Alunno *p = classe; p < classe + nRighe; p++){  
            fgets(riga, DIM_RIGA, fp);
            campo = strtok(riga, ";");  
            p->data = strdup(campo); 

            campo = strtok(NULL, ";");
            p->cognome = strdup(campo);  

            campo = strtok(NULL, ";");
            p->quota = atoi(campo);
        }
    }
    fclose(fp);
}

int calcolaQuota(Alunno classe[], int nRighe){
    int somma = 0;
    for(Alunno* p = classe; p < classe + nRighe; p++){
        somma = somma + p->quota;
    }
    return somma;
}

void cercaCognome(Alunno classe[], Io io[], int nRighe, bool *tro){
    for(Alunno* p = classe; p < classe + nRighe; p++){
        if(strcmp(p->cognome, io->cognome) == 0){
            io->quota = p->quota;
            p = classe + nRighe;
            *tro = true;
        }
    }
}

void visClasse(Alunno classe[], int nRighe){
    for(Alunno *p = classe; p < classe + nRighe; p++){
        if(p->quota == QUOTA){
            printf("\n%s %s %d", p->data, p->cognome, p->quota);
        }else{
            printf("\n%s %s %d    --> DA CONTROLLARE", p->data, p->cognome, p->quota);
        }
        
    }
}

int main(){
    Alunno* classe;
    Io* io;
    char* filename= "4AROB_GITA.csv";
    int nRighe = contaRighe(filename);
    int quotaTot;
    bool tro = false;

    classe = (Alunno*) malloc(nRighe * sizeof(Alunno));

    caricaClasse(classe, filename, nRighe);

    quotaTot = calcolaQuota(classe, nRighe);

    if(quotaTot == QUOTA_MAX){
        printf("Gli studenti della 4AROB hanno raggiunto la quota di %d euro.", QUOTA_MAX);
    }else{
        printf("Agli studenti della 4AROB mancano %d euro per raggiungere la quota di %d euro.", QUOTA_MAX - quotaTot, QUOTA_MAX);
    }

    printf("\nInserisci un cognome da cercare: ");
    gets(io->cognome);

    cercaCognome(classe, io, nRighe, &tro);
    if(tro){
        if(io->quota == QUOTA){
            printf("%s %d", io->cognome, io->quota);
        }else{
            printf("%s %d", io->cognome, QUOTA - io->quota);
        }
    }else{
        printf("L'alunno cercato non e' presente nella classe 4AROB.");
    }
    
    visClasse(classe, nRighe);

    free(classe);

    return 0;
}