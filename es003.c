#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void scambio(int *x, int *y){
    int a;
    a = *x;
    *x = *y;
    *y = a;
}

void bubbleSort3(int vett[], int n){
    int k, sup, sca;

    sup = n - 1;
    
    while (sup > 0)
    {
        sca = 0;
        for (k = 0; k < sup; k++)
        {
            if (*(vett + k) > *(vett + k + 1))
            {
                scambio((vett + k), (vett + k + 1));
                sca = k;
            }
        }
        sup = sca;
    }
}

void stampaVett(int vett[], int n){
    for (int k = 0; k < n; k++){
        printf("%3d", *(vett + k));
    }
}

int main()
{
    int vett[DIM] = {1, 5, 6, 9, 84, 5, 10, 66, 77, 13}; 
    
    bubbleSort3(vett, DIM);
    stampaVett(vett, DIM);

    return 0;
}

