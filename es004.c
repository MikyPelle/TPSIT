#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int calcolaSomma(int vet[], int n){
    int somma = 0;

    for(int* p = vet; p < vet + DIM; p++){
        somma += *p;
    }
    return somma;
}

int main(){
    int vet[DIM] = {1, 5, 6, 9, 84, 5, 10, 66, 77, 13};
    int somma;
    
    somma = calcolaSomma(vet, DIM);

    printf("La somma e' %d", somma);

    return 0;
}