/****************************************************************/
/*    Progetto per la sessione d'esame autunnale 2023 / 2024    */
/*                                                              */
/*    Autori: Biagi Alessio             Matricola: 322735       */
/*            Mangiola Cristiano                   306880       */
/****************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/

#include <stdio.h>

/*****************************************/
/* Definizione delle costanti simboliche */
/*****************************************/

#define M_GREGORIANO     24  /* Costante M del metodo di Gauss per il calendario gregoriano */
#define N_GREGORIANO     5   /* Costante N del metodo di Gauss per il calendario gregoriano */

/********************************/
/* Dichiarazione delle funzioni */
/********************************/
int acquisizione_anno(void); 

void calcolo_gauss(int, 
                   int *,
                   int *);

void calcolo_pasqua(int,
                    int,
                    int *,
                    int *);

void calcolo_martedi_grasso(int,
                            int,
                            int,
                            int *,
                            int *);

void calcolo_giovedi_grasso(int,
                            int,
                            int,
                            int *,
                            int *);

void sottrazione_giorni(int *,
                        int *,
                        int *,
                        int);

int giorni_mese(int,
                int);

int anno_bisestile(int);

void stampa_risultato(int,
                      int);

void stampa_riga_carattere(char,
		           int);

/******************************/
/* Definizione delle funzioni */
/******************************/

/* Definizione della funzione main */
int main(void)
{
    /* Dichiarazione delle variabili locali alla funzione                                           */
    int primo_anno,             /* Input:  anno di riferimento per il calcolo del martedì grasso    */
        secondo_anno,           /* Input:  anno di riferimento per il calcolo del giovedì grasso    */
        a_1,                    /* Lavoro: variabile a del metodo di Gauss per il primo anno        */
        a_2,                    /* Lavoro: variabile a del metodo di Gauss per il secondo anno      */
        f_1,                    /* Lavoro  2b + 4c del metodo di Gauss, per il primo anno           */
        f_2,                    /* Lavoro: 2b + 4c del metodo di Gauss, per il secondo anno         */
        giorno_pasqua_1,        /* Lavoro: contenitore del giorno della Pasqua, per il primo anno   */
        giorno_pasqua_2,        /* Lavoro: contenitore del giorno della Pasqua, per il secondo anno */
        mese_pasqua_1,          /* Lavoro: contenitore del mese della Pasqua, per il primo anno     */
        mese_pasqua_2,          /* Lavoro: contenitore del mese della Pasqua, per il secondo anno   */
        giorno_martedi_grasso,  /* Output: giorno in cui cade il martedì grasso per il primo anno   */
        giorno_giovedi_grasso,  /* Output: giorno in cui cade il giovedì grasso per il secondo anno */
        mese_martedi_grasso,    /* Output: mese in cui cade il martedì grasso per il primo anno     */
        mese_giovedi_grasso;    /* Output: mese in cui cade il giovedì grasso per il secondo anno   */

    /* Stampare la specifica all'utente */
    printf("Il programma, previo inserimento di due anni tra il 1900 e il 2099,\n"
           "calcola il martedì grasso per il primo anno e il giovedì grasso per il secondo.\n");

    /* Acquisire il primo anno */
    primo_anno = acquisizione_anno();

    /* Acquisire il secondo anno */
    secondo_anno = acquisizione_anno();

    /* Calcolare i valori di a e dell'espressione 2b + 4c del metodo di Gauss */
    /* Per il primo anno inserito: */
    calcolo_gauss(primo_anno, 
                  &a_1,
                  &f_1);

    /* Per il secondo anno inserito: */
    calcolo_gauss(secondo_anno,
                  &a_2,
                  &f_2);

    /* Calcolare la data della pasqua */
    /* Per il primo anno inserito: */
    calcolo_pasqua(a_1,
                   f_1,
                   &giorno_pasqua_1,
                   &mese_pasqua_1);

    /* Per il secondo anno inserito: */
    calcolo_pasqua(a_2,
                   f_2,
                   &giorno_pasqua_2,
                   &mese_pasqua_2);

    /* Calcolare la data del martedì grasso */
    /* Per il primo anno inserito: */
    calcolo_martedi_grasso(giorno_pasqua_1,
                           mese_pasqua_1,
                           primo_anno,
                           &giorno_martedi_grasso,
                           &mese_martedi_grasso);
    
    /* Per il secondo anno inserito: */
    calcolo_giovedi_grasso(giorno_pasqua_2,
                           mese_pasqua_2,
                           secondo_anno,
                           &giorno_giovedi_grasso,
                           &mese_giovedi_grasso);

    /* Stampare il risultato del martedì grasso */
    printf("\n\nIl martedì grasso nell'anno %d, cade il: \n\n",
           primo_anno);
    stampa_risultato(giorno_martedi_grasso,
                     mese_martedi_grasso);

    /* Stampare il risultato del martedì grasso */
    printf("\n\nIl giovedì grasso nell'anno %d, cade il: \n\n",
            secondo_anno);
    stampa_risultato(giorno_giovedi_grasso,
                     mese_giovedi_grasso);
    
    printf("\n\n");
    return (0);
}

/* Definizione della funzione per l'acquisizione dell'anno */
int acquisizione_anno(void)
{
    /* Dichiarazione della variabili locali della funzione             */
    int anno_scelto,          /* Output: anno digitato dall'utente     */
        esito_lettura,        /* Lavoro: esito della scanf             */
        acquisizione_errata;  /* Lavoro: esito complessivo della scanf */

        /* Acquisizione dell'anno */
        do
        {
            printf("\nInserisci un anno compreso tra il 1900 e il 2099: ");
            
            /* Acquisizione e validazione stretta */
            esito_lettura = scanf("%d",
                                  &anno_scelto);

            acquisizione_errata = esito_lettura != 1 || anno_scelto < 1900 || anno_scelto > 2099;

            if(acquisizione_errata)
                printf("\nIl valore inserito non è corretto, inseriscine uno valido!\n");
            while (getchar() != '\n'); 
        } 
        while (acquisizione_errata);
	return(anno_scelto);        
}

/* Definizione della funzione per il calcolo di a e di 2b + 4c del metodo di Gauss  */
void calcolo_gauss(int anno,  /* Input: anno inserito dall'utente                   */
                   int *a,    /* Output: variabile a del metodo di Gauss            */
                   int *f)    /* Output: identificatore per 2b + 4c                 */
{
    /* Dichiarazione delle variabili locali alla funzione */
    int b,  /* Lavoro: variabile b del metodo di Gauss    */
        c;  /* Lavoro: variabile c del metodo di Gauss    */

    /* Calcolare le variabili a, b e c del metodo di Gauss */
    *a = anno % 19;
    b = anno % 4,
    c = anno % 7;

    /* Calcolare l'espressione 2b + 4c */
    *f = (2 * b) + (4 * c);
}

/* Definizione della funzione per il calcolo del giorno e del mese di Pasqua  */
void calcolo_pasqua(int a,        /* Input: variabile a del metodo di Gauss   */
                    int f,        /* Input: identificatore di 2b + 4c         */
                    int *giorno,  /* Output: giorno di Pasqua                 */
                    int *mese)    /* Output: giorno di Pasqua                 */
{
  /* Dichiarazione delle variabili locali alla funzione             */
  int d,                 /* Lavoro: variabile d del metodo di Gauss */
      e,                 /* Lavoro: variabile e del metodo di Gauss */
      m = M_GREGORIANO,  /* Lavoro: variabile M del metodo di Gauss */
      n = N_GREGORIANO;  /* Lavoro: variabile N del metodo di Gauss */

  /* Calcolare giorno e mese, usando il metodo di Gauss */
  d = (19 * a + m) % 30;
  e = (f + 6 * d + n) % 7;
  *giorno = (d + e);

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
  if (*mese == 4)
  {
    if (*giorno == 26)
        *giorno = 19;
    
    if (*giorno == 25 && d == 28 && e == 6 && a > 10)
        *giorno = 18;
  }
}

/* Definizione della funzione per il calcolo del martedì grasso per il primo anno inserito.              */
void calcolo_martedi_grasso(int giorno_pasqua,           /* Input: giorno in cui cade la Pasqua          */
                            int mese_pasqua,             /* Input: mese in cui cade la Pasqua            */
                            int primo_anno,              /* Input: primo anno inserito dall'utente       */
                            int *giorno_martedi_grasso,  /* Output: giorno in cui cade il martedì grasso */
                            int *mese_martedi_grasso)    /* Output: mese in cui cade il martedì grasso   */
{
    *giorno_martedi_grasso = giorno_pasqua;
    *mese_martedi_grasso = mese_pasqua;

    sottrazione_giorni(giorno_martedi_grasso,
                       mese_martedi_grasso,
                       &primo_anno,
                       47);
}

/* Definizione della funzione per il calcolo del giovedì grasso  per il secondo anno inserito.           */
void calcolo_giovedi_grasso(int giorno_pasqua,           /* Input: giorno in cui cade la Pasqua          */
                            int mese_pasqua,             /* Input: mese in cui cade la Pasqua            */
                            int secondo_anno,            /* Input: secondo anno inserito dall'utente     */
                            int *giorno_giovedi_grasso,  /* Output: giorno in cui cade il giovedì grasso */
                            int *mese_giovedi_grasso)    /* Output: mese in cui cade il giovedì grasso   */
{
    *giorno_giovedi_grasso = giorno_pasqua;
    *mese_giovedi_grasso = mese_pasqua;

    sottrazione_giorni(giorno_giovedi_grasso,
                       mese_giovedi_grasso,
                       &secondo_anno,
                       52);
}

/* Definizione della funzione per sottrarre giorni da una data specificata                */
void sottrazione_giorni(int *giorno,              /* Input / output: giorno della data    */
                        int *mese,                /* Input / output: mese della data      */
                        int *anno,                /* Input / output: anno della data      */
                        int giorni_da_sottrarre)  /* Input: numero di giorni da sottrarre */
{
    while (giorni_da_sottrarre > 0) 
    {

        if (giorni_da_sottrarre >= *giorno) 
	{
            giorni_da_sottrarre -= *giorno;
            (*mese)--;

            if (*mese < 1) 
	    {
                *mese = 12;
                (*anno)--;
            }
	    *giorno = giorni_mese(*mese, *anno);
        } 
	else 
	{
		*giorno -= giorni_da_sottrarre;
		giorni_da_sottrarre = 0;
        }
    }
}

/* Definizione della funzione per ottenere il numero di giorni nel mese specificato            */
int giorni_mese(int mese,  /* Input: mese di cui calcolare i giorni                            */
                int anno)  /* Input: anno di riferimento (per la gestione dell'anno bisestile) */
{
    switch (mese) 
    {
        case 2:
            return anno_bisestile(anno) ? 29 : 28;
        case 4:
            return 30;
        case 3:
            return 31;
        default:
            return 0;
    }
}

/* Definizione della funzione per verificare se un anno è bisestile  */
int anno_bisestile(int anno)  /* Input: anno da verificare           */
{
    return (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0);
}

/* Definizione della funzione per la stampa del risultato       */
void stampa_risultato(int giorno,  /* Input: giorno da stampare */
		      int mese)    /* Input: mese da stampare   */
{
  /* Dichiarazione delle variabili locali alla funzione                  */
  char contenitore[6];  /* Lavoro: contenitore dei dati per la stampa    */
  int  prima_cifra,	/* Lavoro: prima cifra da sinistra del giorno    */
       seconda_cifra,	/* Lavoro: seconda cifra da sinistra del giorno  */
       v,	        /* Lavoro: contatore per asse verticale          */
       o;		/* Lavoro: contatore per avanzamento orizzontale */

  /* Ricavare la prima e la seconda cifra del giorno */
  prima_cifra = giorno / 10;
  seconda_cifra = giorno % 10;

  /* Caricare il contenitore dei dati per la stampa */ 
  contenitore[0] = '0' + prima_cifra;
  contenitore[1] = '0' + seconda_cifra;
  contenitore[2] = ' ';

  if (mese == 2)
  {
    contenitore[3] = 'F';
    contenitore[4] = 'E';
    contenitore[5] = 'B';
  }
  else if (mese == 3)
  {
    contenitore[3] = 'M';
    contenitore[4] = 'A';
    contenitore[5] = 'R';
  }
  else
  {
    contenitore[3] = 'A';
    contenitore[4] = 'P';
    contenitore[5] = 'R';
  }
  

  /* Emissione dei dati utilizzando la stampa riga per riga */
  for (v = 0; v < 5; v++)
  {
    for (o = 0; o < 6; o++)
      stampa_riga_carattere(contenitore[o], v);

    printf("\n");
  }
}

/* Definizione della funzione per la stampa del carattere                           	   */
void stampa_riga_carattere(char carattere,  /* Input: carattere da stampare                */ 
		     	   int  v)	    /* Input: indicazione posizione asse verticale */
{
  /* Stampare la v-esima riga del carattere */
  switch(carattere)
  {
    case ' ':
      printf("%5s", "");
      break;
    case '0':
      printf(v == 0 || v == 4 ? " ***** " : " *   * ");
      break;
    case '1':
      if (v == 1)
        printf("  **   ");
      else if (v == 2)
        printf(" * *   ");
      else if (v == 4)
        printf(" ***** ");
      else
        printf("   *   ");
      break;
    case '2':
      if (v == 1)
        printf("     * ");
      else if (v == 3)
        printf(" *     ");
      else
	printf(" ***** ");
      break;
    case '3':
      printf(v == 1 || v == 3 ? "     * " : " ***** "); 
      break;
    case '4':
      if (v == 0 || 
          v == 1) 
        printf(" *   * ");
      else if (v == 2)
        printf(" ***** ");
      else
        printf("     * ");
      break;
    case '5':
    case '6':
      if (v == 1)
        printf(" *     ");
      else if (v == 3)
        printf(carattere == '5' ? "     * " : " *   * ");
      else
        printf(" ***** ");
      break;
    case '7':
      printf(v == 0 ? " ***** " : "     * ");
      break;
    case '8':
      printf(v == 0 || v == 2 || v == 4 ? " ***** " : " *   * ");
      break;
    case '9':
      if (v == 1)
        printf(" *   * ");
      else if (v == 3)
        printf("     * ");
      else
        printf(" ***** ");
      break;
    case 'A':
      if (v == 0)
        printf("   *   ");
      else if (v == 1)
        printf("  * *  ");
      else if (v == 2)
        printf(" ***** ");
      else
        printf(" *   * ");
      break;
    case 'B':
      if (v == 0 || v == 2 || v == 4)
        printf(" ***** ");
      else
        printf(" *   * ");
    break;
    case 'E':
      if (v == 0 || v == 2 || v == 4)
        printf(" ***** ");
      else
        printf(" *     ");
    break;
    case 'F':
      if (v == 0 || v == 2)
        printf(" ***** ");
      else
        printf(" *     ");
    break;
    case 'M':
      if (v == 1)
        printf(" ** ** ");
      else if (v == 2)
        printf(" * * * ");
      else
        printf(" *   * ");
      break;
    case 'P':
      if (v == 0 ||
          v == 2)
        printf(" ***** ");
      else if (v == 1)
        printf(" *   * ");
      else
        printf(" *     ");
      break;
    case 'R':
      if (v == 1)
        printf(" *   * ");
      else if (v == 3)
        printf(" *  *  ");
      else if (v == 4)
        printf(" *   * ");
      else
        printf(" ***** ");
      break;
  }
}
