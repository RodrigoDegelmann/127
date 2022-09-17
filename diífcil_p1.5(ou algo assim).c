#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char mina[1000];
    int dima;
    int h;
    int i;
    int j;
    int k;
    
    scanf("%d", &j);
    getchar();
    
    /*esse eu não sei se conta exatamente, pq ele não "remove" a "areia",
    mas ele é um tanto quanto mais simples ao meu ver*/
    
    for (h = 0; h < j; h++)
    {
        dima = 0;
        
        fgets(mina, 1000, stdin);
        
        for (i = 0; mina[i] != '\n'; i++)
        {
            if (mina[i] == '<')
                for (k = i; mina[k] != '\n'; k++)
                    if (mina[k] == '>')
                    {
                        mina[k] = '.';
                        mina[i] = '.';
                        
                        dima = dima + 1;
                        
                        break;
                    }
        }
        
        printf("%d\n", dima);
    }
}