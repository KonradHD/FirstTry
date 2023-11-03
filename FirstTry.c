#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Nalezy uzupelnic o header biblioteki zawierajacy definicja stalej INT_MAX */
void srednia(int [], int, float [], float, float, float);
#define OCENIAJ 1  // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 


int main(void) {
    int seed, n, max = 999, min = 100;
    float tab2[9], sum = 0, x = 0, size = 0;
    if(OCENIAJ == 0) printf("Wpisz wartosc zarodka: ");
    scanf("%d",&seed);
    if(OCENIAJ == 0) printf("Wpisz liczbe generowanych liczb pseudolosowych: ");
    scanf("%d",&n);
    if(n <= INT_MAX && seed <= INT_MAX){
        int tab[n];
        srand(seed);
        for(int i = 0; i < n; i++){
            tab[i] = rand();
            tab[i] = tab[i]%(max-min+1)+min;
        }
        for(int i = 0; i < 9; i++){
            tab2[i] = 0;
        }
        srednia(tab, n, tab2, sum, x, size);
        for(int i = 0; i < 9; i++){
            printf("%.2f ", tab2[i]);
        }
    } else {
        printf("Za duża liczba");
    }
    return 0;
}

void srednia(int tab[], int n, float tab2[], float sum, float x, float size){
    for(int lim = 200, j = 0; lim <= 1000; lim += 100, j++){
        for(int i = 0; i <= n; i++){
            if(tab[i] >= lim - 100 && tab[i] < lim){
                size = size + 1;
                sum = sum + tab[i];
            }
            x = size;
            if(x != 0){
                tab2[j] = (sum/x);
            } else {
                tab2[j] = sum;
            }
        }
        size = 0;
        sum = 0;
    }
}