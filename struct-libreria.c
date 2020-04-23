#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct t_libro
{
    char titolo[20];
    char autore[20];
    int disponibilita;
    float prezzo;
};
 
typedef struct t_libro libro; 

int aggiungiLibro(libro libreria [], int n);
void stampaLista(struct t_libro *libreria, int n);
void cercaLibro(struct t_libro *libreria, int n);
void salvaSuFile(struct t_libro *libreria, int n);
int recuperoDaFile(struct t_libro *libreria);
int menu(); 


int main()
{
	
	libro libreria [100]; 
	int x = -1; 
	int libri_recuperati = 0; 
	libri_recuperati = recuperoDaFile(libreria);
	printf("Hai recuperato %d libri\n",  libri_recuperati); 
	do{
		x = menu();
		switch(x){
			case 1: 
				printf("Hai scelto il recupero del inventario\n");
				libri_recuperati = recuperoDaFile(libreria);
				printf("Hai recuperato %d libri\n",  libri_recuperati); 
				break; 
			case 2: 
				printf("Hai scelto l'aggiunta di un nuovo libro\n");
				libri_recuperati = aggiungiLibro(libreria, libri_recuperati);
				
				printf("I libri attuali sono %d \n", libri_recuperati);   
				break; 
			case 3: 
				printf("Hai scelto la scrittura su file \n");
				salvaSuFile(libreria, libri_recuperati); 
				break; 
			case 4: 
				printf("Hai scelto la stampa-inventario \n");  
				stampaLista(libreria,libri_recuperati); 
				break; 
			case 5: 
				printf("Hai scelto la ricerca di un libro ...\n"); 
				cercaLibro(libreria,libri_recuperati); 
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


int aggiungiLibro(struct t_libro *libreria, int n)
{
	int libri = n; 
	struct t_libro *tmp; 
	tmp = (struct t_libro*) malloc(sizeof(struct t_libro));
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
	
	struct t_libro libro_nuovo;
	memcpy(&libro_nuovo,tmp,sizeof(struct t_libro));
	libreria[n] = libro_nuovo; 
	libri = n+1; 
		

	printf("------------------\n");
	return libri; 
	
}


int recuperoDaFile(struct t_libro *libreria)
{
	FILE *catalogo;
	catalogo=fopen("file.bin","rb");
	if(catalogo == NULL){
		printf("C'e' stato un problema con la lettura del file \n"); 
		exit(1);
	}
	int posix = 0; 
	
	
	struct t_libro *tmp; 
	while(!feof(catalogo))
	{
		tmp = (struct t_libro*) malloc(sizeof(struct t_libro));
		if(tmp == NULL)
			exit(-1);
		
		fread(tmp, sizeof(struct t_libro), sizeof(struct t_libro), catalogo);
		 
		//printf("%s\n", tmp->titolo); 
		//printf("%s\n", tmp->autore); 
		//printf("%d\n", tmp->disponibilita); 
		//printf("%f\n", tmp->prezzo); 

		 
		struct t_libro libro_recuperato;
		memcpy(&libro_recuperato,tmp,sizeof(struct t_libro));
		libreria[posix] = libro_recuperato; 
		posix++;

	}
	fclose(catalogo);
	return posix; 
}


void salvaSuFile(struct t_libro *libreria, int n){
	FILE *catalogo;
	catalogo=fopen("file.bin","wb");
	if(catalogo == NULL){
		printf("C'e' stato un problema con la scrittura del file \n"); 
		exit(1);
	}
	fwrite(libreria, sizeof(struct t_libro), n, catalogo);
	
	fclose(catalogo);
}


void cercaLibro(struct t_libro *libreria, int n)
{
	char titolo[20]; 
	printf("Inserisci il titolo del libro che stai cercando ... "); 
	scanf("%s",titolo);
	for(int i = 0; i < n; i++)
	{
		printf("Libro non ancora trovato ...\n"); 
		if(strcmp(libreria[i].titolo,titolo)==0)
		{
			printf("\n------------------\n"); 
			printf("Titolo : %s \n",libreria[i].titolo); 
			printf("Autore : %s \n", libreria[i].autore); 
			printf("Disponibilita : %d \n", libreria[i].disponibilita); 
			printf("Prezzo : %f \n",libreria[i].prezzo); 
			printf("\n------------------\n"); 
			break;  
		} 	
	}		
}


void stampaLista(struct t_libro *libreria, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("------------------\n"); 
		printf("Titolo : %s \n",libreria[i].titolo); 
		printf("Autore : %s \n", libreria[i].autore); 
		printf("Disponibilita : %d \n", libreria[i].disponibilita); 
		printf("Prezzo : %f \n",libreria[i].prezzo); 
		printf("------------------\n");  
	}
	
}
