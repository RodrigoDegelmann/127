#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char mina1[1000];
    char mina2[1000];
    int dima;
    int sand;
    int h;
    int i;
    int j;
    int k;
    
    scanf("%d", &j);
    getchar();
    
    /*você salva no segundo vetor todos char não '.' do primeiro, caso no segundo
    passe a ter "<>" a contagem de diamantes++ e "<>" --> "..", depois o processo
    se repete do segundo pro primeiro e vice-versa até não haver mais '.' para
    serem retirados*/
    
    for (h = 0; h < j; h++)
    {
        dima = 0;
        
        fgets(mina1, 1000, stdin);
        
        mina1[strlen(mina1) - 1] = '\0';
        
        while(1)
        {
            sand = 0;
            
            k =  0;
            
            for (i = 0; mina1[i] != '\0'; i++)
            {
                if (mina1[i] != '.')
                {
                    mina2[k] = mina1[i];
                    k = k + 1;
                }
            }
            
            mina2[k] = '\0';
            
            for (i = 0; mina2[i] != '\0'; i++)
                if (mina2[i] == '<' && mina2[i + 1] == '>')
                {
                    mina2[i] = '.';
                    mina2[i + 1] = '.';
                    
                    dima = dima + 1;
                }
            
            k = 0;
            
            for (i = 0; mina2[i] != '\0'; i++)
            {
                if (mina2[i] != '.')
                {
                    mina1[k] = mina2[i];
                    k = k + 1;
                }
            }
            
            mina1[k] = '\0';
            
            for (i = 0; mina1[i] != '\0'; i++)
                if (mina1[i] == '<' && mina1[i + 1] == '>')
                {
                    mina1[i] = '.';
                    mina1[i + 1] = '.';
                    
                    dima = dima + 1;
                }
            
            for (i = 0; mina1[i] != '\0'; i++)
                if (mina1[i] == '.')
                    sand = 1;
            
            if (sand == 0)
                break;
        }
        
        printf("%d\n", dima);
    }
}