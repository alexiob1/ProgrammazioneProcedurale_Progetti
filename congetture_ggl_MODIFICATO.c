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
int selezione(int);
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
	/* Dichiarazione delle variabili locali */
	int scelta,              /* Input: scelta dell'utente           */
	    esito_lettura,       /* Lavoro: esito della scanf           */
	    acquisizione_errata; /* Lavoro: esito errato della scanf    */

    /* Richiesta della scelta dell'utente */
	do
	{
		printf("Quale congettura vuoi verificare?\n"
		"1. Congettura di Gilbreath\n"
		"2. Congettura debole di Goldbach\n"
		"3. Congettura di Legendre\n"
		"Inserisci il numero della congettura\n");
		esito_lettura = scanf("%d",
	              		      &scelta);
        
        /* Validazione stretta del valore inserito */
		acquisizione_errata = esito_lettura = scelta > 3 || scelta <= 0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);
	
	/* Chiamata della funzione di selezione della congettura */
	selezione();

return(0);
}

/* Definizione della funzione di selezione e esecuzione della congettura */
int selezione(int scelta) /* Input: Scelta dell'utente */
{
    /* Selezione della congettura */
	switch(scelta)
	{
		case 1:
		{
		    /* Chiamata di funzione per la congettura di Gilbreath */
			gilbreath();
			break;
		}
        
		case 2:
		{
		    /* Chiamata di funzione per la congettura debole di Goldbach */
			goldbach();
			break;
		}
        
		case 3:
		{
			/* Chiamata di funzione per la congettura di Legendre*/
			legendre();
			break;
		}
	}

return(0);
}

/* Definizione della funzione per la congettura di Gilbreath */
void gilbreath(void)
{


}

/* Definizione della funzione per la congettura debole di Goldbach */
void goldbach(void)
{
    /* Dichiarazione delle variabili locali */
	int n,	                 /* Input: Numero inserito dall'utente      */
	    i,                   /* Lavoro: Primo numero primo trovato      */
	    j,                   /* Lavoro: Secondo numero primo trovato    */
	    k,                   /* Lavoro: Terzo numero primo trovato      */
	    esito_lettura,       /* Lavoro: esito della scanf               */
	    acquisizione_errata, /* Lavoro: esito errato della scanf        */
	    esito;               /* Lavoro: esito della funzione "numprim"  */
	
	/* Richiesta dei dati */
	do
	{
		printf("Inserire un numero dispari e >5\n");
		esito_lettura = scanf("%d",
	      		              &n);
		
		/* Validazione stretta dei dati acquisiti */
		acquisizione_errata = esito_lettura != 1 || n <= 5 || n % 2 == 0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);
    
    /* Calcolo dei tre numeri primi */
	for(i = 2; i <= n/3; i++)
	{
		esito = numprim(i);
		
		/* Controllo che il primo numero sia primo */
		if (esito == 1)
		{
			for(j = i; j <= n/2; j++)
			{
				esito = numprim(j);
				
				/* Controllo che il secondo numero sia primo */
				if (esito == 1)
				{
					k = n - i -j;
					
					esito = numprim(k);
					
					/* Controllo che il terzo numero sia primo */
					if (esito == 1)
						printf("%d + %d + %d = %d\n",
						       i, j, k, n);
				}
			}
		}
	}
}

/* Definizione della funzione per la congettura di Legendre */
void legendre(void)
{
	
}

/* Definizione della funzione per controllare se un numero è primo */
int numprim(int n) /* Input: Numero da controllare */
{
    /* Dichiarazione delle variabili locali */
	int cdiv = 2,   /* Lavoro: Contatore dei divisori */
	    esito = 1;  /* Output: Esito del controllo: 1 = primo, 0 = non primo*/
	
	/* Controllo del numero */
	while(cdiv <= n/2)
	{
		if(n % cdiv == 0)
			esito = 0;  /* Il numero non è primo */
		cdiv++;
	}

return(esito);
}