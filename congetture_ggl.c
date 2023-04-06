/************************************************************************/
/*  ESAME DI PROGRAMMAZIONE PROCEDURALE - SESSIONE ESTIVA 2023          */					   
/*                                                                      */					   
/* Programma che, in base alla scelta eseguita dall'utente, 	        */
/* esegue le congetture di Gilbreath, debole di Goldbach e Legendre.    */
/*                                                                      */                                   
/* Autori:  Biagi Alessio (Matricola: 322735)                           */
/*          Fabbri Nicole (Matricola: 321119)                           */
/************************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/********************************/
/* Dichiarazione delle funzioni */
/********************************/
int selezione(void);
void gilbreath(void);
void goldbach(void);
void legendre(void);
int numprim(int);

/***********************************/
/* Definizione delle funzioni      */
/***********************************/

/* Definizione della funzione main */
int main()
{
	/*Richiamo della funzione di selezione*/
	selezione();

return(0);
}

int selezione(void)
{
	int esito_lettura, 
	    acquisizione_errata,
	    scelta;

	do
	{
		printf("Quale congettura vuoi verificare?\n"
		"1. Congettura di Gilbreath\n"
		"2. Congettura debole di Goldbach\n"
		"3. Congettura di Legendre\n"
		"Inserisci il numero della congettura\n");
		esito_lettura = scanf("%d",
	              		      &scelta);

		acquisizione_errata=esito_lettura=scelta>3||scelta<=0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);

	switch(scelta)
	{
		case 1:
		{
			gilbreath();
			break;
		}

		case 2:
		{
			goldbach();
			break;
		}

		case 3:
		{
			legendre();
			break;
		}
	}

return(0);
}

void gilbreath(void)
{


}

void goldbach(void)
{
	int n,	    /*Input: Numero inserito dall'utente*/
	    i,
	    j,
	    k,
	    esito_lettura,
	    acquisizione_errata,
	    esito;
	do
	{
		printf("Inserire un numero dispari e >5\n");
		esito_lettura = scanf("%d",
	      		              &n);
		
		acquisizione_errata = esito_lettura != 1 || n <= 5 || n % 2 == 0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);

	for(i = 2; i <= n/3; i++)
	{
		esito = numprim(i);
		if (esito == 1)
		{
			for(j = i; j <= n/2; j++)
			{
				esito = numprim(j);
				if (esito == 1)
				{
					k = n - i -j;
					
					esito = numprim(k);
					if (esito == 1)
						printf("%d + %d + %d = %d\n",
						       i, j, k, n);
				}
			}
		}
	}
}

void legendre(void)
{
	
}

int numprim(int n)
{
	int cdiv = 2,
	    esito = 1; /* 1 = primo, 0 = non primo*/
	
	while(cdiv <= n/2)
	{
		if(n % cdiv == 0)
			esito = 0; /* il numero non è primo */
		cdiv++;
	}

return(esito);
}
