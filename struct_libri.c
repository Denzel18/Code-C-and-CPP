#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct libri
{
    char titolo[20];
    char autore[20];
    int disponibilita;
    float prezzo;
};

void dati(struct libri *libro,int n);
bool elimina(struct libri *libro,int *n,char titolo[]);
void prezzoMin(struct libri *libro,int n,float *max);
void prezzoMax(struct libri *libro,int n,float *min);
float prezzoMedio(struct libri *libro,int n);
void stampa(struct libri *libro,int n);
void stampaLibro(char cerca[],struct libri *libro,int n,int scelta);
void scambia(struct libri *libro,struct libri *libro1);
int menu();

int main()
{
	//FILE *fp;
    struct libri *libro,*p;
    char titolo[20],autore[20];
    int n,scelta,scelta1;
    float media,max,min;
    bool a;
    printf("Quanti libri vuoi inserire?\n");
    scanf("%d",&n);
    //fp=fopen("file.txt","r");
	//if(fp==NULL)
		//exit(-1);
    libro=(struct libri *)malloc(sizeof(struct libri)*n);
    if(libro==NULL)
        exit(-1);
    p=libro;
    do
    {
        scelta=menu();
        switch(scelta)
        {
            case 1:
                n++;
                libro=(struct libri *)realloc(libro,sizeof(struct libri)*n);
                if(libro==NULL)
                    exit(-1);
                libro+=n;
                
                
                printf("Inserisci il titolo\n");
                scanf("%s",libro->titolo);
                printf("Inserisci l'autore\n");
                scanf("%s",libro->autore);
                printf("Inserisci il prezzo\n");
                scanf("%f",&libro->prezzo);
                libro=p;
                break;
            case 2:
            {
                printf("Inserisci il libro da eliminare\n");
                scanf("%s",titolo);
                a=elimina(p,&n,titolo);
                if(a==true)
                    libro=(struct libri *)realloc(libro,sizeof(struct libri)*n);
                break;
            }
            case 3:
                dati(p,n);
                break;
            case 4:
                prezzoMax(p,n,&max);
                printf("Il prezzo maggiore vale %f\n",max);
                break;
            case 5:
                prezzoMin(p,n,&min);
                printf("Il prezzo minimo vale %f\n",min);
                break;
            case 6:
                media=prezzoMedio(p,n);
                printf("La media dei valori vale %f\n",media);
                break;
            case 7:
				stampa(p,n);
				break;
            case 8:
                do
                {
                    printf("Si vuole ricercare il libro per autore(1) o per titolo(2)?\n");
                    scanf("%d",&scelta1);
                }while(scelta1!=1 && scelta1!=2);
                if(scelta1==1)
                {
                    printf("Inserisci il nome dell'autore\n");
                    scanf("%s",autore);
                    stampaLibro(autore,p,n,scelta1);
                }
                else if(scelta1==2)
                {
                    printf("Inserisci il titolo\n");
                    scanf("%s",titolo);
                    stampaLibro(autore,p,n,scelta1);
                }
                break;
            case 0:
                break;
            default:
                printf("La scelta è inesistente\n");
        }
    }while(scelta!=0);
    //free(alunno);
    return 0;
}

int menu()
{
    int scelta;
    printf("1)Aggiungi un libro\n");
    printf("2)Togli un libro\n");
    printf("3)Inserisci i dati dei libri\n");
    printf("4)Trova il massimo dei prezzi\n");
    printf("5)Trova il minimo dei prezzi\n");
    printf("6)Calcola la media totale dei prezzi\n");
    printf("7)Stampa il catalogo\n");
    printf("8)Stampa le informazioni di un libro\n");
    printf("0)Esci\n");
    scanf("%d",&scelta);
    return scelta;
}

bool elimina(struct libri *libro,int *n,char titolo[])
{
    int i,j,a;
    struct libri *p;
    p=libro;
    a=false;
    for(i=0;i<(*n);i++)
    {
        if(strcmp(libro->titolo,titolo)==0)
        {
            for(j=i;j<(*n);j++)
            {
                scambia(libro,libro+1);
                libro++;
            }
            a=true;
            break;
        }
        libro++;
    }
    *n-=1;
    return a;
}

void dati(struct libri *libro,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Inserisci il titolo\n");
        scanf("%s",libro->titolo);
        printf("Inserisci l'autore\n");
        scanf("%s",libro->autore);
        printf("Inserisci il prezzo\n");
        scanf("%f",&libro->prezzo);
        libro++;
    }
}

void prezzoMax(struct libri *libro,int n,float *max)
{
    int i;
    *max=libro->prezzo;
    libro++;
    for(i=1;i<n;i++)
    {
        if(libro->prezzo>*max)
            *max=libro->prezzo;
        libro++;
    }
}

void prezzoMin(struct libri *libro,int n,float *min)
{
    int i;
    *min=libro->prezzo;
    libro++;
    for(i=1;i<n;i++)
    {
        if(libro->prezzo<*min)
            *min=libro->prezzo;
        libro++;
    }
}

float prezzoMedio(struct libri *libro,int n)
{
    int i;
    float media,somma;
    somma=0.0;
    for(i=0;i<n;i++)
    {
        somma+=libro->prezzo;
        libro++;
    }
    media=(float)somma/n;
    return media;
}

void stampa(struct libri *libro,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Titolo: %s\tAutore: %s\tPrezzo: %f\n",libro->titolo,libro->autore,libro->prezzo);
        libro++;
    }
}

void stampaLibro(char cerca[],struct libri *libro,int n,int scelta)
{
    int i;
    bool a;
    a=false;
    if(scelta==1)
    {
        for(i=0;i<n;i++)
        {
            if(strcmp(libro->autore,cerca)==0)
            {
                printf("Titolo: %s\tAutore: %s\tPrezzo: %f\n",libro->titolo,libro->autore,libro->prezzo);
                a=true;
            }
            libro++;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(strcmp(libro->titolo,cerca)==0)
            {
                printf("Titolo: %s\tAutore: %s\tPrezzo: %f\n",libro->titolo,libro->autore,libro->prezzo);
                a=true;
            }
            libro++;
        }
    }
    if(a==false)
        printf("Libro non trovato\n");
}

void scambia(struct libri *libro,struct libri *libro1)
{
    struct libri varAppoggio;
    memcpy(&varAppoggio,libro,sizeof(struct libri));
    memcpy(libro,libro1,sizeof(struct libri));
    memcpy(libro1,&varAppoggio,sizeof(struct libri));
}

