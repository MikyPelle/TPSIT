/*
author: Pellegrino Michele
date:
es.     001
testo La videoteca "Ciak film" necessita di un programma che carichi la
        lista film in un array di struttura e che stampi a video i 5 campi :
        numero, titolo film, genere, anno di uscita, disponibilità film
*/
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

    //creo una stringa che mi legge le righe intere una alla volta
    char riga[LUNG];
    //questa variabile serve a leggere le parti della riga una alla volta ed inserirle nella struttura
    char *pezzo;
    int k = 0;

    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file non trovato.");
    } else {
        while(fgets(riga, LUNG, fp) != NULL) {

            /*con la funzione strtok() posso dividere una stinga in più parti passando anche un
            carattere come delimitatore, cioè se legge quel carattere si ferma nella lettura, ma
            se si ridà il comando riprende da dove aveva interrotto*/
            pezzo = strtok(riga, ",");

            //controllo che effettivamente legga qualcosa
            if (pezzo != NULL) {
                //la funzione atoi serve per convertire una stringa in un intero
                lista[k].n = atoi(pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy(lista[k].titolo, pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy(lista[k].genere, pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                lista[k].anno = atoi(pezzo);
                pezzo = strtok(NULL, ",");
            }
            if (pezzo != NULL) {
                strcpy(lista[k].disp, pezzo);
            }
            k++;
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

main() {
    Film lista[DIM];

    leggiLista(lista, DIM);

    stampaLista(lista, DIM);
}
