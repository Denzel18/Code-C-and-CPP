#include <stdio.h>

struct jet{
    int velocita;
    int caratteristica;
};
struct elicottero{
    int velocita;
    int caratteristica;
};
struct aereoMerci{
    int velocita;
    int caratteristica;
};
union aereo{
    struct jet unJet;
    struct elicottero unElicottero;
    struct aereoMerci unAereoMerci;
};

void stampa(union aereo aerei[100],int e,int a,int j,int sommap, int sommac, int pmax, int amax, int cmax);

int main(){
    union aereo aerei[100];
    int n,i,risposta,j=0,e=0,a=0,sommap=0,passegg=0,chili=0,sommac=0,pmax,amax,cmax;
    pmax=50;
    amax=1000;
    cmax=500;
    printf("Inserisci il numero di aerei\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Inserisci il tipo di aereo:\n1)Jet\n2)Elicottero\n3)Aereo merci\n");
        scanf("%d", &risposta);
        switch(risposta){
            case 1:
                if(j==0){
                    printf("Inserisci la velocita'\n");
                    scanf("%d",&aerei[i].unJet.velocita);
                }
                printf("Quanti passeggeri prendono questo volo?\n");
                scanf("%d", &passegg);
                if(passegg>pmax){
                    printf("Numero di posti limitato, Riprovare\n");
                    i--;
                    break;
                }
                sommap=sommap+passegg;
                j++;
                break;
            case 2:
                if(e==0){
                    printf("Inserisci la velocità\n");
                    scanf("%d", &aerei[i].unElicottero.velocita);
                }
                e++;
                break;
            case 3:
                if(a==0){              
                    printf("Inserisci la velocità\n");
                    scanf("%d",&aerei[i].unAereoMerci.velocita);
                }
                printf("Quanti chili di carico vuoi trasportare?\n");
                scanf("%d", &chili);
                if(chili>cmax){
                    printf("Carico troppo elevato, riprovare\n");
                    i--;
                    break;
                }
                sommac=sommac+chili;
                a++;
                break;
        }
    }
    stampa(aerei,e,a,j,sommap,sommac,pmax,amax,cmax);
    return 0;
}

void stampa(union aereo aerei[100],int e,int a,int j,int sommap, int sommac, int pmax, int amax, int cmax){
    printf("Numero di Jet: %d   Velocita' dei Jet: %d   Numero massimo di passeggeri: %d    Numero di passeggeri totali: %d\n", j,aerei->unJet.velocita,pmax, sommap);
    printf("Numero di Elicotteri: %d   Velocita' degli Elicotteri: %d   Altezza massima: %d\n", e,aerei->unElicottero.velocita,amax);
    printf("Numero di Aereo Merci: %d   Velocita' degli Aereo Merci: %d   Carico massimo: %d    Carico totale trasportato: %d\n", a,aerei->unAereoMerci.velocita,cmax, sommac);
}

