#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200
#define DIM 30

typedef struct {
    int n;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char disp[LUNG];
} Film;

void leggiLista(Film lista[], int n) {
    FILE *fp;

    char riga[LUNG];
    char *pezzo;
    int k = 0;

    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file non trovato.");
    } else {
        while(fgets(riga, LUNG, fp) != NULL) {

            pezzo = strtok(riga, ",");

            if (pezzo != NULL) {
            
                (lista + k) -> n = atoi(pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy((lista + k) -> titolo, pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy((lista + k) -> genere, pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                (lista + k) -> anno = atoi(pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy((lista + k) -> disp, pezzo);
            }
            k++;
        }
    }
    fclose(fp);
}

void stampaLista(Film lista[], int n){
    for(int k = 0; k < n; k++){
        printf("N. film: %2d\n", (lista + k) -> n);
        printf("Tiolo: %s\n", (lista + k) -> titolo);
        printf("Genere: %s\n", (lista + k) -> genere);
        printf("Anno uscita: %d\n", (lista + k) -> anno);
        printf("%s\n", (lista + k) -> disp);
    }
}

int contaRighe(){
    FILE* fp;
    char riga[LUNG];
    int k = 0;
    fp = fopen("listafilm.csv", "r");
    if(fp == NULL){
        printf("File non trovato.");
    }
    else{
        while (fgets(riga, LUNG, fp) != NULL)
        {
            k++;
        }
        
    }
    fclose(fp);
    return k;
}

int main() {
    Film *lista;
    int n;
    n = contaRighe();
    
    lista = (Film*) malloc(n * sizeof(Film));

    leggiLista(lista, DIM);

    stampaLista(lista, DIM);
    printf("\n%d", n);
    return 0;
}