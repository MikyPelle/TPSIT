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
    int sup, sca;

    sup = n - 1;
    
    while (sup > 0)
    {
        sca = 0;
        for (int* p = vett; p < vett + n; p++)
        {
            if (*p > *(p + 1))
            {
                scambio(p,  (p + 1));
                sca = p - vett;
            }
        }
        sup = sca;
    }
}

void stampaVett(int vett[], int n){
    for (int* p = vett; p < vett + DIM; p++){
        printf("%3d", *p);
    }
}

int main()
{
    int vett[DIM] = {1, 5, 6, 9, 84, 5, 10, 66, 77, 13}; 
    
    bubbleSort3(vett, DIM);
    stampaVett(vett, DIM);

    return 0;
}

