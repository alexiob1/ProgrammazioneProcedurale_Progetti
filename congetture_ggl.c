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
int selezione();
void gilbreath(void);
void goldbach(void);
void legendre(void);
int generaprimi(int);
int numprim(int);

/***********************************/
/* Definizione delle funzioni      */
/***********************************/

/* Definizione della funzione main */
int main()
{
	/* Dichiarazione delle variabili locali */
	int congettura;     /* Input: congettura scelta dall'utente */

	/* Richiamo della funzione di selezione */
	congettura = selezione();

	switch(congettura)
	{
		case 1:
		{
		    /* Richiamo della funzione per la congettura di Gilbreath */
			gilbreath();
			break;
		}

		case 2:
		{
		    /* Richiamo della funzione per la congettura debole di Goldbach */
			goldbach();
			break;
		}

		case 3:
		{
		    /* Richiamo della funzione per la congettura di Legendre */
			legendre();
			break;
		}
	}
	
return(0);
}

/* Definizione della funzione di selezione della congettura */
int selezione()
{
	/* Dichiarazione delle variabili locali alla funzione */
	int scelta,                 /* Input/Output: Scelta dell'utente      */
	    esito_lettura,          /* Lavoro: Esito della scanf             */
        acquisizione_errata;    /* Lavoro: Esito complessivo della scanf */
    
    /* Acquisizione della congettura scelta dall'utente */
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
		acquisizione_errata = esito_lettura = scelta > 3||scelta <= 0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);

return(scelta);
}

/* Definizione della funzione per la congettura di Gilbreath */
void gilbreath() 
{
	/* Dichiarazione delle variabili locali alla funzione */
    int n,			         /* Input:  Numero inserito dall'utente 		 */
	    esito_lettura,       /* Lavoro: Esito della scanf 			         */
	    acquisizione_errata, /* Lavoro: Esito complessivo della scanf 	     */
	    dim;                 /* Lavoro: Dimensione dell'array di primi       */
	    i,			         /* Lavoro: Contatore delle sequenze da generare */
	    j = 0, 		         /* Lavoro: Contatore dei numeri delle sequenze  */
	    num, 		         /* Lavoro: Numeri primi della sequenza 	     */
	    esito;		         /* Lavoro: Controllo del numero primo           */
    int *primi;		         /* Output: Sequenza dei numeri primi		     */
	int differenze[10];	     /* Output: Sequenze generate successivamente	 */

	/* Richiesta del numero di sequenze da generare all'utente */
	do
	{
		printf("Inserisci il numero di sequenze da generare\n");
		esito_lettura = scanf("%d",
				              &n);
                              
		/* Validazione stretta del valore inserito */
		acquisizione_errata = esito_lettura != 1 || n <= 0;
		if(acquisizione_errata)
			printf("Il valore inserito non è valido \n");
	 	while (getchar() !='\n');
	}
	while(acquisizione_errata);

    /* Calcolo della dimensione dell'array */
    dim = 10 + n;
    
    /* Allocazione dell'array dinamico */
    primi = malloc(dim*sizeof(int));
    
    /* Calcolo delle sequenze */
	for (i = 0; i <= n; i++) 
	{
        if (i == 0) 
        {
            printf("Sequenza di numeri primi di partenza: \n");

            for (num = 2; j < dim; num++) 
            {
    		    /* Invocazione della funzione per verificare che il numero sia primo */
            	esito = numprim(num);
            
            	/* Controllo se il numero è primo */
            	if (esito == 1)
            	{
        			primi[j] = num;
        			printf("%d ", primi[j]);
        			j = j + 1;
            	}
    	     }
	    printf("\n");
        }
        else 
        {
            /* Messaggio di stampa del risultato */
    		if (i == 1)
    		{
    			switch(n)
    			{
    				case 1:
    					printf("Ecco la sequenza generata:\n");
    					break;
    
    				default:
    					printf("Ecco le %d sequenze generate:\n",
               	   			       n);
    					break;
    			}
    		}

    		j = 0;
    		while (j < 10) 
            {
                differenze[j] = abs(primi[j] - primi[j + 1]);
                printf("%d ", differenze[j]);
    			j++;
            }
            printf("\n");
    
    		/* Copio la sequenza appena generata in primi */
            for (j = 0; j < 10; j++) 
            {
                primi[j] = differenze[j] + 1;
            }
        }
    }
}

/* Definizione della funzione per la congettura deble di Goldbach */
void goldbach(void)
{
    /* Dichiarazione delle variabili locali alla funzione */
	int n,	                 /* Input:  Numero inserito dall'utente         */
	    i,                   /* Lavoro: Contatore del primo numero primo    */
	    j,                   /* Lavoro: Contatore del secondo numero primo  */
	    k,                   /* Lavoro: Contatore del terzo numero primo    */
	    esito_lettura,       /* Lavoro: Esito della scanf                   */
        acquisizione_errata, /* Lavoro: Esito complessivo della scanf       */
	    esito;               /* Lavoro: Controllo del numero primo          */
	
	/* Acquisizione del numero inserito dall'utente */
	do
	{
		printf("Inserire un numero dispari e >5\n");
		esito_lettura = scanf("%d",
	      		              &n);
		
		/* Validazione stretta del valore inserito */
		acquisizione_errata = esito_lettura != 1 || n <= 5 || n % 2 == 0;
		if (acquisizione_errata)
			printf("Il valore inserito non è valido\n");
		while(getchar() != '\n');
	}
	while(acquisizione_errata);

    /* Ricerca e stampa dei tre numeri primi */
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

/* Definizione della funzione per la congettura di Legendre */
void legendre(void)
{
    /* Dichiarazione delle variabili locali */
    int n,                   /* Input:  Numero inserito dall'utente         */
        esito_lettura,       /* Lavoro: Esito della scanf                   */
        acquisizione_errata, /* Lavoro: Esito complessivo della scanf       */
        quadrato,            /* Lavoro: Quadrato di n                       */
        succquadr,           /* Lavoro: Quadrato del successivo di n        */
        esito,               /* Lavoro: Esito della funzione "numprim"      */
        i,                   /* Lavoro/Output: Contatore e numero trovato   */
        j;
    
    /* Richiesta del numero da controllare all'utente */
    do
    {
        printf("Inserisci un numero naturale >= 1\n");
        esito_lettura = scanf("%d",
                              &n);
                              
        /* Validazione stretta del valore inserito */
        acquisizione_errata = esito_lettura != 1 || n <= 0;
		if(acquisizione_errata)
			printf("Il valore inserito non è valido \n");
	 	while (getchar() !='\n');
    }
    while(acquisizione_errata);
    
    /* Calcolo del quadrato e del successivo del quadrato di n */
    quadrato = pow(n, 2);
    succquadr = pow((n+1), 2);
    
    /* Ricerca del numero compreso tra n ed il suo successivo */
    for(j = 0; j == 0; )
    {
        for(i = quadrato+1; ((i > quadrato) && (i < succquadr)); i++)
        {
            /* Invocazione della funzione del numero primo */
            esito = numprim(i);
    		
    		/* Controllo che il numero sia primo */
    		if (esito == 1)
    		{
    		    j = i;
    		    i = succquadr;
    		}
        }
        printf("Il numero primo compreso tra %d e %d è %d \n",
    		           quadrato, succquadr, j);
    		           
    }
}

/* Definizione della funzione per controllare se un numero è primo */
int numprim(int n)  /* Input: Numero da controllare                */
{
    /* Definizione delle variabili locali alla funzione */
	int cdiv = 2,   /* Lavoro: Contatore dei divisori del numero             */
	    esito = 1;  /* Lavoro: Esito del controllo: 1 = primo, 0 = non primo */
	
	/* Controllo che il numero non abbia più di due divisori */
	while(cdiv <= n/2)
	{
		if(n % cdiv == 0)
			esito = 0;      /* Il numero non è primo */
		cdiv++;
	}

return(esito);
}