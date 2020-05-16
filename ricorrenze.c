/*
 * Dati due vettori 
 * eliminare le riccorenze 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int check(int v1[], int v2[], int n);
void stampa (int n , int v[]);
int ricerca(int v[], int n, int x);

int main()
{
	srand(time(NULL));
	int n =0 ,i = 0;
	printf("Inserisci la dimensione dei vettori\n");
	scanf("%d",&n); 
	int v1[n];
	int v2[] = {0}; 
    for(i=0;i<n;i++)
	{
		v1[i]=rand()%10+1;
	}
	stampa(n, v1);
	int k = check(v1, v2, n); 
	stampa(k, v2); 
	return 0;
}

int check(int v1[], int v2[], int n)
{
    int i = 0; 
	int j = 0; 
    for(i = 0; i < n ; i++)
    {
		if(ricerca(v2, n, v1[i]) == 0){
			v2[j] = v1[i];
			j++; 
		}
    } 
    return j; 
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

int ricerca(int v[], int n, int x){
	int ricerca = 0, i = 0; 
	for(i = 0; i < n ; i++) 
		if(v[i] == x) 
			return 1; 
	return ricerca; 
}	
