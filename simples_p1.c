#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fiz em main pq não pediu como função
int main(void)
{
    int vet[10];
    int i;
    int x;
    int y;
    
    for (i = 0; i < 10; i++)
        scanf("%d", &vet[i]);
    
    scanf("%d", &x);
    scanf("%d", &y);
    
    printf("Soma = %d", vet[x-1] + vet[y-1]);
}