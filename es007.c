#include <stdio.h>
#include <stdlib.h>

void caricaVet(int p[], int n){
    for(int* k = p; k < p + n; k++){
        printf("Inserisci un valore: ");
        scanf("%d", k);
    }
}

void stampaVett(int p[], int n){
    for (int* k = p; k < p + n; k++){
        printf("%3d", *k);
    }
}

int main(){
    int* p;
    int n;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);
    p = (int*) malloc(n * sizeof(int));

    caricaVet(p, n);

    stampaVett(p, n);


    free(p);
    return 0;
}