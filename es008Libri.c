#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100
#define LUNG 200

typedef struct{
    char* titolo;
    char* autore;
    int anno;
}Libro;

int contaRighe(char filename[]){
    FILE *fp;
    int cont = 0;
    char riga[LUNG];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        while(fgets(riga, LUNG, fp)){  
            cont++;
        }
    }
    fclose(fp);
    return cont;
}

void caricaArchivio(Libro persone[], char filename[], int nRighe){
    FILE *fp;
    char* campo; 
    char riga[LUNG];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
        exit(1);
    } else {
        for(Libro *p = persone; p < persone + nRighe; p++){  
            fgets(riga, LUNG, fp);
            campo = strtok(riga, ",");  
            p->titolo = strdup(campo); 

            campo = strtok(NULL, ",");
            p->autore = strdup(campo);  

            campo = strtok(NULL, ",");
            p->anno = atoi(campo);
        }
    }
    fclose(fp);
}

int menu(){
    int x;
    printf("\nMenu:\n");
    printf("0 - Esci\n");
    printf("1 - Stampa archivio dei libri\n");
    printf("2 - Stampa l’archivio dei libri pubblicati in un certo anno\n");
    printf("3 - Stampa tutti i libri pubblicati in ordine di anno\n");
    printf("Scelta: ");
    scanf("%d", &x);
    return x;
}

void stampaArchivio(Libro archivio[], int nRighe){
    for(Libro *p = archivio; p < archivio + nRighe; p++){
        printf("%s %s %d\n", p->titolo, p->autore, p->anno);
    }
}

void stampaLibriAnno(Libro archivio[], int nRighe, int data){
    int k = 0;
    for(Libro *p = archivio; p < archivio + nRighe; p++){
        if(data == p->anno){
            printf("%s %s %d\n", p->titolo, p->autore, p->anno);
            k++;
        }
    }
    if(k == 0){
        printf("Non ci sono libri pubblicati nel %d", data);
    }
}
void scambio(Libro *p1, Libro *p2){
    Libro temp = * p1; 
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void ordinaArchivio(Libro archivio[], int nRighe){
    int sup, sca;
    sup = nRighe - 1 ;
    while (sup > 0) {
        sca = 0 ;
        for (Libro *k = archivio; k < archivio + sup; k++) {
            if (k->anno > (k + 1)->anno){
                scambio(k, k + 1);
                sca = k - archivio;
            }
        }
        sup = sca ;
    }
}

int main(){
    Libro *archivio;
    char filename[] = "listaLibri.csv";
    int scelta;
    int data;

    int nRighe = contaRighe(filename);
    archivio = (Libro*) malloc (nRighe * sizeof(Libro));

    caricaArchivio(archivio, filename, nRighe);

    do
    {
        scelta = menu();
        switch(scelta){
            case 0:
            break;
            case 1:
                stampaArchivio(archivio, nRighe);
            break;
            case 2:
                printf("Inserisci un anno: ");
                scanf("%d", &data);
                stampaLibriAnno(archivio, nRighe, data);
            break;
            case 3:
                ordinaArchivio(archivio, nRighe);
                stampaArchivio(archivio, nRighe);
            break;
        }
    } while (scelta != 0);

    free(archivio);

    return 0;
}