#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct autobazary
{
	char kategoria[51];
	char znacka[51];
	char predajca[101];
	int cena;
	int rok_vyroby;
	char stav_vozidla[201];
	struct autobazary *p_dalsie;
} AUTOBAZARY;


void nacitanie_zaznamov(AUTOBAZARY **p_prve);
void vypis(AUTOBAZARY *p_prve);
void ukoncenie(AUTOBAZARY **p_prve);            //ukoncenie programu

int main()
{
	char z;
	int podmienka=0;
	AUTOBAZARY *p_prve=NULL;

	while(podmienka==0)
	{
		scanf("%c",&z);

		switch(z)
		{
		case 'n':
			nacitanie_zaznamov(&p_prve);
			break;
        case 'v':
			vypis(p_prve);
			break;
        case 'k':                       //koniec programu
            ukoncenie(&p_prve);
            podmienka=1;
            break;
			}
	}

	return (0);
}

void nacitanie_zaznamov(AUTOBAZARY **p_prve)
{
	FILE *f;
	int pocet_zaznamov=0, i=-1;
	char riadok[101];
	AUTOBAZARY *p_aktualne=NULL, *p_nove;

    //mazanie zoznamu

	{
		if ((f=fopen("autobazary.txt","r")) == NULL)
			printf("Zaznamy neboli nacitane\n");
		else
		{
			while(fgets(riadok,100,f) != NULL)
			{
				i++;
				riadok[strlen(riadok) - 1] = '\0';

				switch(i)
				{
				case 0:
					if ((p_nove=(AUTOBAZARY *) malloc(sizeof(AUTOBAZARY))) == NULL)
					{
						printf("Nepodarilo sa pridelit pamat\n");
						break;
					}
					pocet_zaznamov++;
					// zapamatanie zaciatku zoznamu, ak ukazuje na NULL tak je to aj zaroven koniec zoznamu
					if (*p_prve == NULL)
						*p_prve=p_nove;
					// pridanie zaznamu na koniec zoznamu
					if (p_aktualne != NULL)
						p_aktualne->p_dalsie=p_nove;
					// zmena aktualneho zaznamu
					p_aktualne=p_nove;
					p_aktualne->p_dalsie=NULL;
					break;
				case 1:
					strcpy(p_aktualne->kategoria,riadok);
					break;
				case 2:
					strcpy(p_aktualne->znacka,riadok);
					break;
				case 3:
					strcpy(p_aktualne->predajca,riadok);
					break;
				case 4:
				    p_aktualne->cena=atoi(riadok);
					break;
				case 5:
					p_aktualne->rok_vyroby=atoi(riadok);
					break;
				case 6:
					strcpy(p_aktualne->stav_vozidla,riadok);
					i=-1;
					break;
				}
			}
		}

		if (fclose(f) == EOF)
			printf("Subor sa nepodarilo zatvorit\n");
	}

	printf("Nacitalo sa %d zaznamov\n", pocet_zaznamov);
}

void vypis(AUTOBAZARY *p_prve)
{
	AUTOBAZARY *p_aktualne;
	int riadok=1;

	p_aktualne=p_prve;

	if (p_aktualne != NULL)
	{
		do
		{

			printf("%d.\n",riadok); //riadok
			printf("kategoria: %s\n",p_aktualne->kategoria);
			printf("znacka: %s\n",p_aktualne->znacka);
			printf("predajca: %s\n",p_aktualne->predajca);
			printf("cena: %d\n",p_aktualne->cena);
			printf("rok vyroby: %d\n",p_aktualne->rok_vyroby);
			printf("stav vozidla: %s\n",p_aktualne->stav_vozidla);

			p_aktualne=p_aktualne->p_dalsie;
			riadok++;

		} while(p_aktualne != NULL);
	}
}


void ukoncenie(AUTOBAZARY **p_prve){ //ukoncenie programu a uvolnenie pamati


    AUTOBAZARY *p_aktualne;

    p_aktualne=*p_prve;

    do{
        *p_prve=p_aktualne->p_dalsie;
        free(p_aktualne);
        p_aktualne=*p_prve;

    }while(*p_prve != NULL);

}

//kk