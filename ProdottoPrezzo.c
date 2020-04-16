/*
 * Damiani Benedetta
 * 3 C IN
*/

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(float v[], int n);
void exchangeSort(float v[], int n);
void scambia(float *a, float *b);
float somma (float v[], int n); 
void stampa (float v[], int n);
int scelta (); 

int main()
{
	int scelta_user = 0; 
	int a = 0, i = 0;
	int numero_articolo = 0;
	float prezzo = 0,s = 0;
	float costo = 0; /* Mi serve per calcolare il costo di un singolo articolo moltiplicato per il numero di unità acquistate */ 
	printf("Inserisci il numero di prodotti che vuoi inserire\n");
	scanf("%d",&a);
	/* Qui dichiari il vettore, con la dimensione che l'utente ti ha chiesto */ 
	float spesa[a]; 
	for(i=0;i<a;i++)
	{
		printf("Inserisci il prezzo del singolo articolo : ");
		scanf("%f",&prezzo);
		printf("Inserisci il numero di articoli acquistati : ");
		scanf("%d",&numero_articolo);
		costo = prezzo*numero_articolo;
		spesa[i] = costo; 
	}
	s = somma (spesa, a); 
	printf("Il prezzo totale della spesa vale %f \n",s);
	
	do{
		scelta_user = scelta();
		switch(scelta_user)
		{
			case 1: 
				bubbleSort(spesa, a);
				stampa(spesa,a); 
				break;
			case 2: 
				exchangeSort(spesa, a);
				stampa(spesa,a); 
				break;
			case 0: 
				printf("Hai scelto di uscire\n"); 
				break; 
			default: 
				printf("Scelta non accettabile\n"); 
				break; 
				
		}
	
	}while(scelta_user != 0); 
	
	return 0;
}

int scelta()
{
	int scelta = 0; 
	printf("1) Ordinamento bubblesort \n");
	printf("2) Ordinamento exchangeSort \n");
	printf("0) Esci \n");
	scanf("%d",&scelta); 
	return scelta; 
	
}

void bubbleSort(float v[], int n)
{ 
	int i;
	bool s;
	do
	{
		s=false;
		for(i=0;i<n-1;i++) 
		{
			if(v[i]>v[i+1]){
				scambia(&v[i],&v[i+1]);
				s=true;
			}
		}
	}while(s);
}

void exchangeSort(float v[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(v[i]>v[j])
				scambia(&v[i], &v[j]);
}	

float somma (float v[], int n)
{
	int i = 0; 
	float somma = 0; 
	for(i = 0; i < n ; i++)
		somma += v[i]; 
	return somma; 
}

void scambia(float *a, float *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void stampa (float v[], int n)
{
	int i = 0; 
	for(i = 0; i < n ; i++)
		printf("Costo Articolo %d : %f \n", i+1, v[i]);    
}
	
