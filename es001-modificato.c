/*
author: Pellegrino Michele
date:
es.     001
testo La videoteca "Ciak film" necessita di un programma che carichi la
        lista film in un array di struttura e che stampi a video i 5 campi :
        numero, titolo film, genere, anno di uscita, disponibilit� film
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200
#define DIM 200

typedef struct {
    int n;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char disp[LUNG];
} Film;

void leggiLista(Film lista[], int n, int *cont) {
    FILE *fp;

    //creo una stringa che mi legge le righe intere una alla volta
    char riga[LUNG];
    //questa variabile serve a leggere le parti della riga una alla volta ed inserirle nella struttura
    char *pezzo;
    *cont = 0;

    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file non trovato.");
    } else {
        while(fgets(riga, LUNG, fp) != NULL) {

            /*con la funzione strtok() posso dividere una stinga in pi� parti passando anche un
            carattere come delimitatore, cio� se legge quel carattere si ferma nella lettura, ma
            se si rid� il comando riprende da dove aveva interrotto*/
            pezzo = strtok(riga, ",");
            //la funzione atoi serve per convertire una stringa in un intero
            lista[*cont].n = atoi(pezzo);
            pezzo = strtok(NULL, ",");
            strcpy(lista[*cont].titolo, pezzo);
            pezzo = strtok(NULL, ",");
            strcpy(lista[*cont].genere, pezzo);
            pezzo = strtok(NULL, ",");
            lista[*cont].anno = atoi(pezzo);
            pezzo = strtok(NULL, ",");
            strcpy(lista[*cont].disp, pezzo);

            (*cont)++;
        }
    }
    fclose(fp);
}

void stampaLista(Film lista[], int n){
    for(int k = 0; k < n; k++){
        printf("N. film: %2d\n", lista[k].n);
        printf("Tiolo: %s\n", lista[k].titolo);
        printf("Genere: %s\n", lista[k].genere);
        printf("Anno uscita: %d\n", lista[k].anno);
        printf("%s\n", lista[k].disp);
    }
}

void cercaFilm(Film lista[], int n, int anno){
    for(int k = 0; k < n; k++){
        if (lista[k].anno == anno){
            printf("N. film: %2d\n", lista[k].n);
            printf("Tiolo: %s\n", lista[k].titolo);
            printf("Genere: %s\n", lista[k].genere);
            printf("Anno uscita: %d\n", lista[k].anno);
            printf("%s\n", lista[k].disp);
        }
    }
}

int main() {
    Film lista[DIM];
    int cont = 0;
    int anno;

    leggiLista(lista, DIM, &cont);

    stampaLista(lista, cont);

    printf("inserisci l'anno dei film che vuoi cercare: ");
    scanf("%d", &anno);

    cercaFilm(lista, cont, anno);
    return 0;
}
