#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//retorna o tamanho do vetor result
int no_repeat(int a[5], int result[5])
{
    int size;
    //pass0 permite a entrada de apenas 1 zero no vetor(que foi inicializado com 0's)
    int pass0;
    //pass bloqueia números repetidos 
    int pass;
    int i;
    int j;
    int k;
    
    k = 0;
    size = 0;
    pass0 = 1;
    
    //limpando lixo na memória de result
    memset(result, 0, 5);
    
    for (i = 0; i < 5; i++)
    {
        pass = 1;
        
        for (j = 0; j < 5; j++)
        {
            if (result[j] == a[i])
            {
                pass = 0;
                break;
            }
        }
        
        if (pass || (a[i] == 0 && pass0))
        {
            result[k] = a[i];
            size = size + 1;
            k = k + 1;
            if (a[i] == 0)
                pass0 = 0;
        }
    }
    
    return size;
}

//CODE⬆️ TEST⬇️

int main (void)
{
    int in[5];
    int out[5];
    int i;
    int k;
    
    for (i = 0; i < 5; i++)
        scanf("%d", &in[i]);
    
    k = no_repeat(in, out);
    
    for (i = 0; i < k; i++)
        printf("%d ", out[i]);
}