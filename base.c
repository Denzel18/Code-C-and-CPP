#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>

int dimensione();
void caricamentoCasuale(int v[],int n);
void stampa(int v[],int n);
void bubbleSort(int v[], int n);
void exchangeSort(int v[], int n);
void scambia(int *a, int *b);
int ricerca(int v[], int n);
int menu();

int main(){
    srand(time(NULL));
    int v1[100],n,scelta;
    n=100;
    int ris = 0; 
    do{
        scelta=menu();
        switch(scelta){
            case 1:
				        n=dimensione();
                break;
            case 2:
                caricamentoCasuale(v1,n);
                printf("Caricamento eseguito\n");
                break;
            case 3:
				        printf("Hai scelto la stampa del vettore\n"); 
				        stampa(v1,n);
				        break;
			      case 4:
				        printf("Hai scelto l'ordinamento bubblesort\n");
				        bubbleSort(v1,n);
				        break;
            case 5:
				        printf("Hai scelto l'ordinamento exchangesort\n");
				        exchangeSort(v1,n);
				        break; 
			      case 6:
				        ris = ricerca(v1,n);
				        if(ris != -1)
					         printf("il numero è stato trovato in posizione :  %d\n", ris); 
				        else
					         printf("il numero non è stato trovato\n"); 
				        break;
            case 0:
				        printf("Hai scelto di uscire\n"); 
				        break;
            default:
                printf("Scelta inesistente\n");
                break;
        }
    }while(scelta!=0);
    return 0;
}

int menu(){
	int scelta;
	printf("\nMENU\n");
	printf("1)Inserisci la dimensione del vettore(default 100)\n");
	printf("2)Carica casualmente il vettore\n");
	printf("3)Stampa il vettore\n");
	printf("4)Ordinamento bubbleSort\n");
	printf("5)Ordinamento exchangeSort\n");
	printf("6)Ricerca elemento\n");
	printf("0)ESCI\n");
	scanf("%d",&scelta);
	return scelta;
}

int dimensione(){
	int n;
	do{
		printf("Inserisci la dimensione del vettore\n");
		scanf("%d",&n);
    if(n <= 0)
      printf("Dimensione inserita non valida, inserisci una dimensione > 0 e < 100");
	}while(n<=0);
	if(n>100){
		printf("Dimensione non valida\n");
	}else{ 
		printf("Dimensione valida");
	}
	return n;
}

void caricamentoCasuale(int v[],int n){
	int i;
	for(i=0;i<n;i++){
		v[i]=rand()%100+1;
	}
}
void stampa(int v[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",v[i]);
	}
	printf("\n");
}

void bubbleSort(int v[], int n){ 
	int i;
	bool s;
	do{
		s=false;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1]){
				scambia(&v[i],&v[i+1]);
				s=true;
			}
		}
	}while(s);
}

void scambia(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void exchangeSort(int v[], int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(v[i]>v[j])
				scambia(&v[i], &v[j]);
}

int ricerca(int v[], int n){
	int i= 0,k = 0 ;
	printf("Inserisci il valore che vuoi ricercare\n");
	scanf("%d",&k);
	printf("Stai ricercando il numero : %d\n",k); 
	stampa(v,n);
	for(i=0;i<n;i++){
		if(v[i]==k){
			printf("l'elemento è stato trovato\n");
			return i;
		}
	}
	return -1;
}
