/***********************************************************************/
/* ESAME DI PROGRAMMAZIONE PROCEDURALE - SESSIONE INVERNALE 2022/2023  */					   
/*								       */					   
/* Programma che, in base alla scelta eseguita dall'utente, 	       */
/* esegue le congetture di Beal, Collatz e Cramer 		       */
/*                                                                     */                                   
/* Autori: Biagi Alessio (Matricola: 322735) 			       */
/* 	   Fabbri Nicole (Matricola: 321119)                           */
/***********************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/********************************/
/* Dichiarazione delle funzioni */
/********************************/

int leggi_scelta(int);
void beal(void);
void collatz(void);
void cramer(void);
int num_primo(int);


/***********************************/
/* Definizione delle funzioni      */
/***********************************/

/* Definizione della funzione main */
int main()
{	
	/* Dichiarazione variabili locali */
	int scelta = 0; /* Input: scelta dell'utente */

	/* Acquisizione della scelta della congettura dell'utente */
	scelta = leggi_scelta(scelta);

	/* Selezione della congettura */
	switch(scelta)
	{
		 case 1:
		 /* Funzione per la congettura di Beal */
		 {
		 	beal();
		 	break;
		 }
		 case 2:
		 /* Funzione per la congettura di Collatz */
		 {
			collatz();
		 	break;
		 }

		 case 3:
		 /* Funzione per la congettura di Cramer */
		 {
		     cramer();
		     break;	 
		 }
    	}

return(0);
}

/* Definizione della funzione per leggere la scelta effettuata dall'utente */
int leggi_scelta(int scelta) /* Input: Scelta dell'utente */
{
	/* Dichiarazione delle variabili locali alla funzione */
	int esito_lettura,        /*Lavoro: esito della scanf	 	   */
	    acquisizione_errata;  /*Lavoro: esito complessivo della scanf  */
	
	/* Richiesta della scelta dell'utente */
	do
	{
		printf("Quale congettura vuoi verificare? \n");
		printf("1. Congettura di Beal \n");
		printf("2. Congettura di Collatz \n");
		printf("3. Congettura di Cramer \n");
		printf("Inserisci il numero della congettura desiderata: ");
		esito_lettura = scanf("%d",
		                      &scelta);
		
		/* Validazione stretta del valore inserito */
		acquisizione_errata = esito_lettura = scelta>3 || scelta <= 0;
		if(acquisizione_errata)
			printf("Il valore inserito non è valido \n");
	 	while (getchar() !='\n');
	}
	while(acquisizione_errata);

return(scelta);
}

/* Definizione della funzione per eseguire la congettura di Beal */
void beal(void)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int  param[5], 		     /* Input:  array contenente i parametri        */
             esito_lettura,          /* Lavoro: esito della scanf 	            */
             acquisizione_errata,    /* Lavoro: esito complessivo della scanf       */
             c_param,		     /* Lavoro: contatore dei parametri             */
	     c_primi,	             /* Lavoro: contatore dei numeri primi          */
             fatt_primi = 0;	     /* Output: fattore primo in comune             */
	char elementi[6] = {'a',
                            'b',
                            'c',
                            'x',
                            'y',
                            'z'};    /* Output: posizione corrente dell'array        */
	

	/* Inserimento dei dati */
	for(c_param = 0;
            c_param < 6;
            c_param++)
    	{
		do 
		{
			if(c_param <=2)
				printf("Digita il valore %c >=1: ",
                        	       elementi[c_param]);	
			else
               	 		printf("Digita il valore %c >=3: ",
                        	       elementi[c_param]);
                        
			esito_lettura = scanf("%d",
                                   	      &param[c_param]);
                        

	      		/* Validazione stretta dei valori inseriti */	
			if(c_param == 0 || c_param<=2)
				acquisizione_errata = esito_lettura !=1 || 
				                      param[c_param]<1;
			else
				acquisizione_errata = esito_lettura !=1 || 
				                      param[c_param]<3;
			
			if(acquisizione_errata)
				printf("Valore non accettabile \n");
			while(getchar() != '\n');
        	}
		while (acquisizione_errata);
    	}

	/* Ricerca del fattore primo in comune */
	for(c_primi =1 ; 
	    c_primi <= param[0] && 
	    c_primi <= param[1] && 
	    c_primi <= param[2]; 
	    c_primi++)
	{
		if(param[0] % c_primi ==0 && 
	           param[1] % c_primi ==0 && 
		   param[2] % c_primi ==0)

		   fatt_primi = c_primi;
	    
	}

	/* Comunicazione degli esiti all'utente */
	if(pow(param[0],param[3])+pow(param[1],param[4])==pow(param[2],param[5]))
		printf("\nLa congettura di Beal è verificata.\n");
	else
		printf("\nLa congettura di Beal non è verificata.\n");

	if(fatt_primi > 0 && fatt_primi != 1)
		printf("Il fattore in comune tra %d, %d e %d è: %d \n",
			param[0], param[1], param[2], fatt_primi);
	else
		printf("Non è presente nessun fattore primo tra %d, %d e %d \n",
			param[0], param[1], param[2]);

}

/* Definizione della funzione per eseguire la congettura di Collatz */
void collatz(void)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int n = 0, 		 /* Input/Output: variabile dell'espressione    */
	    esito_lettura,	 /* Lavoro: esito della scanf 	                */
	    acquisizione_errata; /* Lavoro: esito complessivo della scanf       */

	/* Inserimento del dato e validazione stretta */
	do
	{
		printf("Inserisci numero >=1: ");
		esito_lettura = scanf("%d",
	      		      	      &n);
			
		acquisizione_errata = esito_lettura != 1 || n<1;

		if(acquisizione_errata)
			printf("Valore non accettabile.\n");
		while(getchar() !='\n');
	}	
	while(acquisizione_errata);

	/* Calcolo e comunicazione dell'esito */
	do
	{
		if((n % 2) == 0)
		{
			n=n/2;
			printf("\n %d \n",
			       n);
		}
		else
		{
			n=(n*3)+1;
			printf("\n %d\n",
		       	       n);
		}
	}
	while(n != 1);
}

/* Definizione della funzione per eseguire la congettura di Cramer */
void cramer(void)
{
    	/* Dichiarazione delle variabili locali alla funzione */
    	int    variab[]={0,0},      /* Input:  Array dei due numeri primi        	    	    */
               esito_lettura,	    /* Lavoro: esito della scanf 		              	    */
               acquisizione_errata, /* Lavoro: esito complessivo della scanf       	            */
               c_variab,	    /* Lavoro: contatore delle variabili 		 	    */
	       ris_a = 0,	    /* Lavoro: controllo del valore variab[0]          		    */		     
	       ris_b = 0,           /* Lavoro: controllo del valore variab[1] 	    		    */
	       consec = 0,          /* Lavoro: controllo consecutività variabili	            */
	       v_assoluto;	    /* Output: valore assoluto della differenza 		    */
    	double log_naturale;	    /* Output: logaritmo naturale del minore			    */
    
	/* Richiesta dei dati */
    	printf("Inserisci due numeri diversi, primi, =>11 e consecutivi\n"
	       "(Premere INVIO dopo l'inserimento di ogni numero):\n");
    
	/* Inserimento dei dati */
    	for(c_variab = 0;
	    c_variab < 2;
            c_variab++)
    	{
        	do
        	{   
			esito_lettura = scanf("%d",
                                               &variab[c_variab]);
                        
		        /* Validazione stretta dei dati */	
            		acquisizione_errata = esito_lettura !=1 || 
				              variab[c_variab]<11;
			
			if(acquisizione_errata)
				printf("Valore non accettabile, riprova.\n");
			else
			{
				ris_a = num_primo(variab[c_variab]);
				
				/* Controllo che il valore sia primo */
				if(ris_a==0)
				{
					printf("Il numero inserito non è primo.\n");
					acquisizione_errata=1;
				}
				
				/* Controllo che il valore 0 sia minore di 1 */
				if(ris_a == 1 &&
				   c_variab == 1 &&
				   variab[1] < variab[0])
				{
					printf("Hai inserito un valore minore del primo.\n");
					acquisizione_errata = 1;
				}

				/* Controllo che i valori siano diversi  */
				if(ris_a == 1 &&
				   c_variab == 1 &&
				   variab[1] == variab[0])
				{
					printf("I valori inseriti sono uguali.\n");
					acquisizione_errata = 1;
				}

				/* Controllo che i valori siano consecutivi */
				if(ris_a == 1 &&
				   c_variab == 1 &&
				   variab[1] > variab[0])
				{
					consec = variab[0] + 1;

					do
					{
						ris_b += num_primo(consec);
						consec++;
					}
					while(consec < variab[1]);
					
					if(ris_b != 0)
					{
						printf("Non è consecutivo al primo numero.\n");
						acquisizione_errata = 1;
						ris_b = 0;
					}
				}

			}	
			while(getchar() !='\n');
		}
		while(acquisizione_errata);
	}

	/* Calcolo degli output */
	v_assoluto = abs(variab[1] - variab[0]);
	
	log_naturale = pow(log(variab[0]),2);
	
	/* Comunicazione degli esiti */
	if(v_assoluto<log_naturale)
		printf("La congettura è verificata.\n");
	else
		printf("La congettura non è verificata.\n");
	
	printf("Il valore assoluto della differenza dei due numeri è: %d\n",
               v_assoluto);
	
	printf("Il quadrato del logaritmo del più piccolo dei 2 numeri è: %f\n",
               log_naturale);
}

/* Definizione della funzione per controllare se un numero è primo */
int num_primo(int n) /*Input: numero da controllare */
{
	/* Dichiarazione delle variabili locali */
	int c_div = 1,	/* Lavoro: contatore dei divisori */
	    esito = 1;	/* Output: esito del controllo	  */
        
	/* Calcolo dei divisori */
	for(c_div=2; c_div<(int)sqrt(n); c_div++)
	{
		if(n % c_div == 0)
			esito=0;
	}

return (esito);
}
