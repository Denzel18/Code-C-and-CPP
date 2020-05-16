/*
 * Dati due vettori di medesima dimensione crea un terzo vettore popolandolo in maniera alternata
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int alterna(int v1[], int v2[], int v3[], int n);
void stampa (int n , int v[]);

int main()
{
	srand(time(NULL));
	int n =0 ,i = 0,s = 0;
	printf("Inserisci la dimensione dei vettori\n");
	scanf("%d",&n);
	int v1[n],v2[n],v3[2*n]; 
    for(i=0;i<n;i++)
	{
		v1[i]=rand()%100+1;
	}
	stampa(n, v1);
	for(i=0;i<n;i++)
	{
		v2[i]=rand()%100+1;
	}
	stampa(n, v2);
	s=alterna(v1,v2,v3,n);
	stampa(2*n, v3); 
	printf("La somma del terzo vettore e': %d",s);	
	return 0;
}

int alterna(int v1[], int v2[], int v3[], int n)
{
    int i = 0; 
    int j = 0;
    int k = 0; 
    int somma = 0; 
    for(i = 0; i < 2*n ; i++)
    {
        if(i % 2 == 0)
        {
            v3[i] = v1[j]; 
            j++;
        }
        else
        {
            v3[i] = v2[k]; 
            k++;
        }
        somma += v3[i];
    }
    return somma; 
}

void stampa (int n , int v[])
{
	int i = 0; 
	for(i = 0; i < n ; i++)
	{
		printf("%d\t", v[i]); 
	}
	printf("\n");
}
		

