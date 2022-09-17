#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*essa função retorna o tamanho do vetor que contem os primos e recebe os 
seguintes parâmetros: o vetor 'a' que queremos saber a quantidade de primos e o
vetor result que recebera os primos*/
//essa função não descarta números repetidos
int encontra_primo(int a[5], int result[5])
{
    //contador para o número de vezes que o resto de uma divisão foi 0
    int rest0;
    //total = quantidade de num primos
    int total;
    int i;
    int j;
    int k;
    
    k = 0;
    total = 0;
    
    for (i = 0; i < 5; i++)
    {
        rest0 = 0;
        
        for (j = 2; j <= sqrt(a[i]); j++)
            if (a[i]%j == 0)
            {
                rest0 = 1;
                break;
            }
        
        
        if  (rest0 == 0 && a[i] != 1)
        {
            result[k] = a[i];
            total = total + 1;
            k = k + 1;
        }
    }
    
    return total;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    int vet[5];
    int out[5];
    int i;
 
    for (i =0; i < 5; i++)
        scanf("%d", &vet[i]);
    
    for (i = 0; i < encontra_primo(vet, out); i++)
        printf("%d ", out[i]);
}