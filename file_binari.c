#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct libro
{
    char titolo[20];
    char autore[20];
    int disponibilita;
    float prezzo;
    struct libro *succ; 
};

typedef struct libro t_libro; 
typedef struct libro *t_lista;


//firme
t_lista creaLista(); 
t_lista inserisciTesta(t_lista l, t_libro x);
void stampaLista(t_lista l);
t_lista aggiungiLibro(t_lista l);
void cercaLibro(t_lista l);
void salvaSuFile(t_lista l);
t_lista recuperoDaFile(t_lista l);
int menu(); 


int main()
{
	//creazione lista
	t_lista  lista; 
	lista = creaLista(); 
	lista = recuperoDaFile(lista);
	int x = -1; 
	do{
		x = menu();
		switch(x){
			case 1: 
				printf("Hai scelto il recupero del inventario\n");
				lista = recuperoDaFile(lista);
				break; 
			case 2: 
				printf("Hai scelto l'aggiunta di un nuovo libro\n");
				lista = aggiungiLibro(lista);
				break; 
			case 3: 
				printf("Hai scelto la scrittura su file \n");
				salvaSuFile(lista); 
				break; 
			case 4: 
				printf("Hai scelto la stampa-inventario \n"); 
				stampaLista(lista); 
				break; 
			case 5: 
				printf("Hai scelto la ricerca di un libro ...\n"); 
				cercaLibro(lista); 
				break; 
			case 0: 
				printf("Hai scelto di uscire\n");
				break; 
			default: 
				printf("Scelta non disponibile	\n");
				break; 
		}	
	}while(x != 0); 
	return 0; 
}


//funzioni
int menu()
{
	int scelta = -1; 
	printf("1) Recupera Libri da File  \n"); 
	printf("2) Aggiungi Libro \n"); 
	printf("3) Salva Libri su File \n"); 
	printf("4) Stampa - Inventario \n"); 
	printf("5) Cerca Libro \n"); 
	printf("0) Esci \n"); 
	scanf("%d",&scelta); 
	return scelta; 
}
t_lista creaLista() 
{
	return NULL; 
}

void stampaLista(t_lista l)
{
	while(l->succ != 0)
	{
		printf("------------------\n"); 
		printf("Titolo : %s \n",l->titolo); 
		printf("Autore : %s \n", l->autore); 
		printf("Disponibilita : %d \n", l->disponibilita); 
		printf("Prezzo : %f \n", l->prezzo); 
		printf("------------------\n"); 
		l = l->succ; 
	}
	
}

t_lista aggiungiLibro(t_lista l)
{
	t_libro *tmp;
	tmp = malloc(sizeof(struct libro));
	if(tmp == NULL)
			exit(-1);
	printf("------------------\n");
	printf("Inserisci Titolo : ");
	scanf("%s",tmp->titolo); 
	printf("Inserisci Autore : "); 
	scanf("%s",tmp->autore); 
	printf("Inserisci Disponibilita' : "); 
	scanf("%d",&tmp->disponibilita); 
	printf("Inserisci Prezzo : "); 
	scanf("%f",&tmp->prezzo); 
	l = inserisciTesta(l,*tmp); 
	printf("------------------\n");
	return l; 
	
}


void cercaLibro(t_lista l)
{
	char titolo[20]; 
	printf("Inserisci il titolo del libro che stai cercando ... "); 
	scanf("%s",titolo);
	while(l->succ != NULL) 
	{
		printf("Libro non ancora trovato ...\n"); 
		if(strcmp(l->titolo,titolo)==0)
		{
			printf("\n------------------\n"); 
			printf("Titolo : %s \n",l->titolo); 
			printf("Autore : %s \n", l->autore); 
			printf("Disponibilita : %d \n", l->disponibilita); 
			printf("Prezzo : %f \n", l->prezzo); 
			printf("\n------------------\n"); 
			break;  
		}
		l = l->succ; 
			
	}		
}
 

t_lista inserisciTesta(t_lista l, t_libro x)
{
	struct libro *tmp;
	tmp = malloc(sizeof(t_libro)); 	
	
	strcpy(tmp->titolo, x.titolo); 
	strcpy(tmp->autore,x.autore); 
	tmp->disponibilita = x.disponibilita; 
	tmp->prezzo = x.prezzo;  
	
	tmp->succ = l; 
	l = tmp;  

	return l; 
}



void salvaSuFile(t_lista l){
	FILE *catalogo;
	catalogo=fopen("file.txt","w");
	if(catalogo == NULL){
		printf("C'e' stato un problema con la scrittura del file \n"); 
		exit(1);
	}
	while((l) != 0){
		fprintf(catalogo, "%s\n%s\n%d\n%f\n", l->titolo,l->autore,l->disponibilita, l->prezzo);
		l= l->succ; 
	}
	fclose(catalogo);
}

t_lista recuperoDaFile(t_lista l)
{
	FILE *catalogo;
	catalogo=fopen("file.txt","r");
	if(catalogo == NULL){
		printf("C'e' stato un problema con la lettura del file \n"); 
		exit(1);
	}
	
	//variabili di appoggio
	char f_titolo[20];
	char f_autore[20];
	int f_disponibilita = 0 ;
	float f_prezzo = 0; 
	
	//lettura da file
	t_libro *tmp; 
	while(!feof(catalogo))
	{
		tmp = malloc(sizeof(struct libro));
		if(tmp == NULL)
			exit(-1);
		fscanf(catalogo, "%s\n%s\n%d\n%f\n",f_titolo,f_autore, &f_disponibilita, &f_prezzo );
		//printf("Titolo: %s \n Autore: %s \n disponibilita: %d \n prezzo %f \n",f_titolo,f_autore,f_disponibilita,f_prezzo); 
		strcpy(tmp->titolo,f_titolo); 
		strcpy(tmp->autore,f_autore); 
		tmp->disponibilita = f_disponibilita; 
		tmp->prezzo = f_prezzo;
		l = inserisciTesta(l, *tmp); 
	}
	fclose(catalogo);
	return l;
}
