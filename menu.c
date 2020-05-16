
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int menu();
int main() 
{
 	int scelta;
 	do
    {
        scelta=menu();
        switch(scelta)
        {
            case 1:
                printf("Scelta numero 1\n");
                //funzione1
                break;
            case 2:
				printf("Scelta numero 2\n");
				//funzione2
				break;
            /*
            ....
            ....
            ....
            */
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

int menu()
{
	int scelta;
	printf("\nMENU\n");
	printf("1)Scelta numero 1\n");
	printf("2)Scelta numero 2\n");
    /*
    ....
    ....
    ....
    */
	printf("0)ESCI\n");
	scanf("%d",&scelta);
	return scelta;
}

