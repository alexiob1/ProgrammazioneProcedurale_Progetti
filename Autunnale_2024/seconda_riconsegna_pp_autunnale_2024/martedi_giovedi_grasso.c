/**********************************************************/
/* Progetto per la sessione d'esame autunnale 2023 / 2024 */
/*							  */
/* Autori: Biagi     Alessio 	  Matricola: 322735 	  */
/*	   Mangiola  Cristiano	  	     306880	  */
/**********************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/

#include <stdio.h>

/*****************************************/
/* Definizione delle costanti simboliche */
/*****************************************/

#define M_GREGORIANO 	24 /* Costante M del metodo di Gauss per il calendario gregoriano */
#define N_GREGORIANO  	 5 /* Costante N del metodo di Gauss per il calendario gregoriano */

/********************************/
/* Dichiarazione delle funzioni */
/********************************/
void acquisizione_anno(int []);

void calcolo_pasqua(int,
		    int *,
		    int *);

void sottrazione_giorni(int *,
	       		int *,
			int *,
			int);

int giorni_mese(int,
		int);

void stampa_risultato(int,
		      int,
		      int,
		      int);

void stampa_riga_carattere(char,
			   int);

/********************************/
/* Dichiarazione delle funzioni */
/********************************/

/* Definizione della funzione main */
int main()
{
	/* Dichiarazione delle variabili locali */
	int anno[2], 		/* Input:  array contenente i due anni di riferimento */
	    giorno_pasqua[2],	/* Lavoro: array contenente i due giorni della Pasqua per i due anni inseriti */
	    mese_pasqua[2], 	/* Lavoro: array contenente i due mesi della Pasqua per i due anni inseriti */
	    giorno_grasso[2],	/* Output: array contenente i giorni del Martedì (0) e Giovedì (1) Grasso */
	    mese_grasso[2],	/* Output: array contenente i mesi del Martedì (0) e Giovedì (1) Grasso */
    	    i;			/* Lavoro: contatore per i cicli for */	    

	/* Acquisizione dei due anni */
	acquisizione_anno(anno);

	/* Ciclo per il calcolo della data della Pasqua per i due anni inseriti */
	for(i = 0; i < 2; i++)
	{
		calcolo_pasqua(anno[i],
			       &giorno_pasqua[i], 
			       &mese_pasqua[i]);
	}

	/* Ciclo per il calcolo della data del Martedì Grasso e del Giovedì Grasso */
	for(i = 0; i < 2; i++)
	{
		giorno_grasso[i] = giorno_pasqua[i];
		mese_grasso[i] = mese_pasqua[i];

		sottrazione_giorni(&giorno_grasso[i], 
				   &mese_grasso[i], 
				   &anno[i], 
				   i);
	}

	/* Ciclo per la stampa dei risultati */
	for(i = 0; i < 2; i++)
	{
		stampa_risultato(giorno_grasso[i], 
				 mese_grasso[i], 
				 anno[i], 
				 i);
	}

return(0);
}

/* Definizione della funzione per l'acquisizione dei due anni */
void acquisizione_anno(int anno[]) /* Input / output: array in cui memorizzare i due anni inseriti */
{
	/* Dichiarazione delle variabili locali */
	int esito_lettura, 	 /* Lavoro: esito della scanf */
	    acquisizione_errata, /* Lavoro: esito complessivo della scanf */
	    i;			 /* Lavoro: contatore per il ciclo for */

	/* Stampa della specifica del programma all'utente */
	printf("Il programma, previo inserimento di due anni tra il 1900 e il 2099, \n"
	       "calcola il Martedì Grasso per il primo anno e il Giovedì Grasso per il secondo.\n");

	/* Ciclo per acquisire gli anni */
	for(i = 0; i < 2; i++)
	{
		do
		{
			printf("\nInserisci l'anno per il calcolo del %s (compreso tra il 1900 e il 2099): ",
			       (i == 0)? "Martedì Grasso" : "Giovedì Grasso");

			/* Acquisizione e validazione stretta */
			esito_lettura = scanf("%d",
					      &anno[i]);

			acquisizione_errata = esito_lettura != 1 || anno[i] < 1900 || anno[i] > 2099;

			if(acquisizione_errata)
				printf("\nIl valore inserito non è corretto, inseriscine uno valido.\n");
			while(getchar() != '\n');
		}
	       	while (acquisizione_errata); 
	}
}

/* Definizione della funzione per il calcolo del giorno e del mese di Pasqua, usando il metodo di Gauss */
void calcolo_pasqua(int  anno,	 /* Input:  anno inserito dall'utente */
		    int *giorno, /* Output: giorno di Pasqua */
		    int *mese)   /* Output: mese di Pasqua */
{
	/* Dichiarazione delle variabili locali */
	int a,			/* Lavoro: variabile "a" del metodo di Gauss */
	    b,			/* Lavoro: variabile "b" del metodo di Gauss */
	    c,			/* Lavoro: variabile "c" del metodo di Gauss */
	    d,			/* Lavoro: variabile "d" del metodo di Gauss */
	    e,			/* Lavoro: variabile "e" del metodo di Gauss */
	    m = M_GREGORIANO,	/* Lavoro: variabile "M" del metodo di Gauss */
	    n = N_GREGORIANO;	/* Lavoro: variabile "N" del metodo di Gauss */

	/* Calcolo delle variabili "a", "b" e "c" del metodo di Gauss */
	a = anno % 19;
	b = anno % 4;
	c = anno % 7;

	/* Calcolo delle variabili "d" e "e" del metodo di Gauss */
	d = (19 * a + m) % 30;
	e = (2 * b + 4 * c + 6 * d + n) % 7;

	/* Calcolo del giorno di Pasqua */
	*giorno = (d + e);

	/* Determinazione se la Pasqua è in Marzo o Aprile */
	if(*giorno < 10)
	{
		*giorno += 22;
		*mese = 3;
	}
	else
	{
		*giorno -= 9;
		*mese = 4;
	}

	/* Gestione delle eccezioni */
	if(*mese == 4)
	{
		if(*giorno == 26)
			*giorno = 19;

		if(*giorno == 25 && d == 28 && e == 6 && a > 10)
			*giorno = 18;
	}
}

/* Definizione della funzione per sottrarre i giorni dalla data di Pasqua */
void sottrazione_giorni(int *giorno, 		 /* Input / output: giorno della data di partenza */
			int *mese, 		 /* Input / output: mese della data di partenza */
			int *anno, 		 /* Input / output: anno della data di partenza */
			int  tipo_giorno_grasso) /* Input: 0 per Martedì Grasso e 1 per Giovedì Grasso */
{
	/* Dichiarazione delle variabili locali */
	int giorni_da_sottrarre; /* Lavoro: contenitore dei giorni da sottrarre */

	/* Definizione dei giorni da sottrarre */
	if(tipo_giorno_grasso == 0)
	{
		giorni_da_sottrarre = 47; /* Martedì Grasso */
	}
	else
	{
		giorni_da_sottrarre = 52; /* Giovedì Grasso */
	}

	/* Ciclo per la sottrazione dei giorni, attraversando i mesi se necessario */
	while(giorni_da_sottrarre > 0)
	{
		if(giorni_da_sottrarre >= *giorno)
		{
			giorni_da_sottrarre -= *giorno;
			(*mese)--;

			if(*mese < 1)
			{
				*mese = 12;
				(*anno)--;
			}
			
			*giorno = giorni_mese(*mese, 
					      *anno);
		}
		else
		{
			*giorno -= giorni_da_sottrarre;
			giorni_da_sottrarre = 0;
		}
	}
}

/* Definizione della funzione per ottenere il numero di giorni del mese specificato */
int giorni_mese(int mese, /* Input: mese di cui restituire il totale dei giorni */
		int anno) /* Input: anno di riferimento (per la gestione dell'anno bisestile) */
{
	/* Dichiarazione delle variabili locali */
	int giorni; /* Lavoro: variabile per il numero di giorni nel mese */

	/* Determinazione del numero di giorni nel mese specificato */
	switch(mese)
	{
		case 1:
		case 3:
			giorni = 31;
			break;
		case 2:
			giorni = (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0))? 29 : 28; 
			break;
		case 4:
			giorni = 30;
			break;
		default:
			giorni = 0;
			break;
	}

return(giorni);
}

/* Definizione della funzione di stampa dei risultati */
void stampa_risultato(int giorno,	      /* Input: giorno del Martedì / Giovedì Grasso */ 
                      int mese, 	      /* Input: mese del Martedì / Giovedì Grasso */
                      int anno,		      /* Input: anno in cui cade Martedì / Giovedì Grasso */ 	      
                      int tipo_giorno_grasso) /* Input: 0 per Martedì Grasso e 1 per Giovedì Grasso */ 
{
	/* Dichiarazione delle variabili locali */
	char contenitore[6];	/* Output: array per la stampa del risultato */
	int  prima_cifra, 	/* Lavoro: prima cifra del giorno */
	     seconda_cifra, 	/* Lavoro: seconda cifra del giorno */
	     v, 		/* Lavoro: contatore verticale */
	     o;			/* Lavoro: contatore orizzontale */
	
	/* Stampa del Martedì / Giovedì Grasso */
	if(tipo_giorno_grasso == 0)
		printf("\nIl Martedì Grasso nell'anno %d cade nel giorno:\n\n",
		       anno);
	else
		printf("\nIl Giovedì Grasso nell'anno %d cade nel giorno:\n\n",
		       anno);
	
	/* Estrazione delle cifre del giorno */
	prima_cifra = giorno / 10;
	seconda_cifra = giorno % 10;
	
	/* Preparazione per i dati per la stampa */
	contenitore[0] = '0' + prima_cifra;
	contenitore[1] = '0' + seconda_cifra;
	contenitore[2] = ' ';
	
	/* Selezione del mese per la stampa */
	switch(mese) 
	{
		case 1:
			contenitore[3] = 'G';
			contenitore[4] = 'E';
			contenitore[5] = 'N';
			break;
		case 2:
			contenitore[3] = 'F';
			contenitore[4] = 'E';
			contenitore[5] = 'B';
			break;
		case 3:
			contenitore[3] = 'M';
			contenitore[4] = 'A';
			contenitore[5] = 'R';
			break;
	}
	
	/* Ciclo per la stampa del risultato riga per riga */
	for (v = 0; v < 5; v++) 
	{
		for (o = 0; o < 6; o++)
		       	stampa_riga_carattere(contenitore[o], 
					      v);
		printf("\n");
	}
}
  
/* Definizione della funzione di stampa del carattere specificato */
void stampa_riga_carattere(char carattere, /* Input: carattere da stampare */
			   int v)	   /* Input: riga da stampare */
{
	/* Stampa della v-esima riga del carattere */
	switch(carattere)
	{
		case ' ':
			printf("       ");
			break;
		case '0':
			printf(v == 0 || v == 4 ? " ***** " : " *   * ");
			break;
		case '1':
			printf(v == 0 ? "   *   " :
			       v == 1 ? "  **   " :
			       v == 2 ? " * *   " :
			       v == 3 ? "   *   " :
			       		" ***** ");
			break;
		case '2':
			printf(v == 0 ? " ***** " :
			       v == 1 ? "     * " :
			       v == 2 ? " ***** " :
			       v == 3 ? " *     " :
			       		" ***** ");
			break;
		case '3':
			printf(v == 0 || v == 2 || v == 4 ? " ***** " : "     * ");
			break;
		case '4':
			printf(v == 0 || v == 1 ? " *   * " :
			       v == 2           ? " ***** " :
			       			  "     * ");
			break;
		case '5':
			printf(v == 0 || v == 2 || v == 4 ? " ***** " :
			       v == 1                     ? " *     " :
			       				    "     * ");
			break;
		case '6':
			printf(v == 0 || v == 2 || v == 4 ? " ***** " :
			       v == 1                     ? " *     " :
			       				    " *   * ");
			break;
		case '7':
			printf(v == 0 ? " ***** " : "     * ");
			break;
		case '8':
			printf(v == 0 || v == 2 || v == 4 ? " ***** " : " *   * ");
			break;
		case '9':
			printf(v == 0 || v == 2 ? " ***** " :
			       v == 1           ? " *   * " :
			       			  "     * ");
			break;
		case 'A':
			printf(v == 0           ? " ***** " :
			       v == 2           ? " ***** " :
			       			  " *   * ");
			break;
		case 'B':
			printf(v == 0 || v == 4 ? " ***** " :
			       v == 2           ? " **** " :
			       			  " *   * ");
			break;
		case 'E':
			printf(v == 0 || v == 2 || v == 4 ? " ***** " : " *     ");
			break;
		case 'F':
			printf(v == 0 ? " ***** " :
			       v == 1 ? " *     " :
			       v == 2 ? " **** " :
			       		" *     ");
			break;
		case 'G':
			printf(v == 0 || v == 4 ? " ***** " :
			       v == 1           ? " *     " :
			       v == 2           ? " * *** " :
			       			  " *   * ");
			break;
		case 'M':
			printf(v == 0 || v == 4 ? " *   * " :
			       v == 1           ? " ** ** " :
			      			  " * * * ");
			break;
		case 'N':
			printf(v == 0 || v == 4 ? " *   * " :
			       v == 1           ? " **  * " :
			       v == 2           ? " * * * " :
			       			  " *  ** ");
			break;
		case 'R':
			printf(v == 0 || v == 2 ? " ***** " :
			       v == 1 || v == 4 ? " *   * " :
			       			  " *  *  ");
			break;
  }
}
