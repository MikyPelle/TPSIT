#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void scambio(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int v[],int n) {
    int *k,*kmin,*j;
    for(k = v;k <v + (n-1); k++) {
        kmin = k;
    for(j = k+1; j < v+n; j++){
        if(*kmin > *j)
            kmin = j;

}
    if(kmin != k)
    scambio(k, kmin); 
}   
}

void stampaVett(int vet[], int n){
    for (int* p = vet; p < vet + DIM; p++){
        printf("%3d", *p);
    }
}

int main()
{
    int vet[DIM] = {1, 5, 6, 9, 84, 5, 10, 66, 77, 13};
    
    printf("Vettore disordinato: \n");
    stampaVett(vet, DIM);
    selectionSort(vet, DIM);
    printf(" \nVettore ordinato: \n");
    stampaVett(vet, DIM);
    
}