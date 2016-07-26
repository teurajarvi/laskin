// Write and compile a program
// that asks user what to do (add, substract ...) with the
// two numbers and display the results.

#include <stdio.h> /* lukemista ja tulostusta varten */
#include <ctype.h> /* tyypin tarkistamista varten */
#include <stdlib.h> /* muuntaa merkin luvuksi */
#include <string.h> /* string pituuden laskeminen */

/* omat headerit */
#include "laskin.h"

/* tässä tiedostossa näkyvät muuttujat */
int testi_1 = 0;
int testi_2 = 1;
int pituus = 0;
double summa = 0;
int operaatio = 0;
char luku_1[7];
char luku_2[7];
char luku_3[7];

/* ohjelman pääfunktio */
int main(void)
	{
    int i;
	printf( " Anna kaksi lukua ja lasken niille valitsemasi laskutoimituksen \n" );

	printf( "\n Ensimmäinen luku: " );
	testi_1 = scanf( "%s", luku_1 );
    tarkistus();
    
	printf( "\n Toinen luku: " );
	testi_1 = scanf( "%s", luku_2 );
    tarkistus();

	printf( "\n Valitse operaatio, jonka teen luvuille: " );
	printf( "\n [1] Yhteenlasku" );
	printf( "\n [2] Vähennyslasku" );
	printf( "\n [3] Kertolasku" );
	printf( "\n [4] Jakolasku" );
	printf( "\n :" );
	testi_1 = scanf( "%s", luku_3 );
    tarkistus();
    operaatio = atoi( luku_3 );
    
    switch ( operaatio )
        {
        case 1:
	        luku_lopputulos = laske_yhteen( );
            break;
        case 2:
	        luku_lopputulos = tee_vahennyslasku();
            break;
        case 3:
	        luku_lopputulos = tee_kertolasku();
            break;
        case 4:
	        luku_lopputulos = tee_jakolasku();
            break;
        default:
        	luku_lopputulos = 0;
            break;
        }
	
	summa = 0;
	printf( "\n Lopputulos: %.2f \n", luku_lopputulos );
	luku_lopputulos = 0;

	return 0;
	}

void tarkistus( )
    {
	if ( 0 > testi_1 ) /* negatiivinen arvo indikoi virhettä, positiivinen merkkien määrä */
		{
		printf( "\n Virhe: lukeminen epäonnistui \n");
		}
    else if ( 0 == testi_2 ) /* nolla indigoi virhettä */
		{
		printf( "\n Virhe: annoit vääräntyyppisen merkin, anna numero. \n" );
		}
    }

double laske_yhteen( )
	{
    double eka = 0;
    double toka = 0;

    eka = atof( luku_1 );
    toka = atof( luku_2 );

	summa = eka + toka;
	return summa;
	}

double tee_vahennyslasku()
    {
    double eka = 0;
    double toka = 0;

    eka = atof( luku_1 );
    toka = atof( luku_2 );

	summa = eka - toka;
	return summa;
    }

double tee_kertolasku()
    {
    double eka = 0;
    double toka = 0;

    eka = atof( luku_1 );
    toka = atof( luku_2 );

	summa = eka * toka;
	return summa;
    }

double tee_jakolasku()
    {
    double eka = 0;
    double toka = 0;

    eka = atof( luku_1 );
    toka = atof( luku_2 );

    if ( 0 == toka )
        {
        printf( "\n Et voi jakaa luvulla 0!" );
        return 0;
        }
    else
        {
    	summa = eka / toka;
    	return summa;
        }
    }
