
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include "Funkcije.h"

void provjeraStanja(IGRAC* igrac) {
	printf("Stanje: %d\n", igrac->stanje);
	printf("Ulog: %d\n", igrac->ulog);
	printf("Dobitak: %d\n", igrac->dobitak);
	printf("Maksimalni dobitak: %d\n", igrac->maxdobitak);
}


void promijenaUloga(IGRAC* igrac) {
	int novi_ulog;
	printf("Unesite novi ulog: ");
	scanf("%d", &novi_ulog);

	if (novi_ulog <= igrac->stanje) {
		igrac->ulog = novi_ulog;
		printf("Ulog je uspjesno promijenjen.\n");
	}
	else if (novi_ulog > igrac->stanje)
	{
		printf("Nemate dovoljno sredstava za postavljeni ulog.\n");
	}
}
char Simboli() {
	int Broj = random(1, 100);

	if (Broj <= 25) {
		return 'J';
	}
	else if (Broj <= 50) {
		return 'Q';
	}
	else if (Broj <= 70) {
		return 'A';
	}
	else if (Broj <= 90) {
		return 'K';
	}
	else if (Broj <= 100)
	{
		return '7';
	}
}
void PrintP(char polje[5][3])
{

	for (int j = 0; j < 3; j++) {
		printf("================");
		printf("||");
		for (int i = 0; i < 5; i++) {
			printf("%c |\t", polje[i][j]);
		}
		printf("================\n");
	}
}
int provjera(char polje[5][3]) {
	//prve 3 linije
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
			return 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7') {
			return 1;
		}
	}
	//1.dijagonala
	if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A') {
		return 1;
	}
	if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K') {
		return 1;
	}
	if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q') {
		return 1;
	}
	if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J') {
		return 1;
	}
	if (polje[0][0] == '7' && polje[1][1] == '7') {
		return 1;
	}
	//2. dijagonala
	if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A') {
		return 1;
	}
	if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K') {
		return 1;
	}
	if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J') {
		return 1;
	}
	if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q') {
		return 1;
	}
	if (polje[0][2] == '7' && polje[1][1] == '7') {
		return 1;
	}
	//6.linija
	if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][2] == '7') {
		return 1;
	}
	//7.linija
	if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][0] == '7') {
		return 1;
	}
	//8.linija
	if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A') {
		return 1;
	}
	if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K') {
		return 1;
	}
	if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J') {
		return 1;
	}
	if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q') {
		return 1;
	}
	if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][1]=='7') {
		return 1;
	}
	//9.linija
	if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A') {
		return 1;
	}
	if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K') {
		return 1;
	}
	if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J') {
		return 1;
	}
	if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q') {
		return 1;
	}
	if (polje[0][2] == '7' && polje[1][0] == '7' && polje[2][1]=='7') {
		return 1;
	}
}
void spin(IGRAC* igrac, char polje[5][3]) {


	if (igrac->stanje < igrac->ulog) {
		printf("Nedovoljno kredita, smanjite ulog!\n");
		return 1;
	}

	igrac->stanje = igrac->stanje - igrac->ulog;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			polje[i][j] = Simboli();
		}
	}

	PrintP(polje);

	float dobitak = 0;

	if (provjera(polje) == 1) {
		printf("Cestitamo, osvojili ste:\n");

		int provjera = 0;
		int provjerad = 0;
		//provjera za prve 3 linije
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J' && polje[4][i] == 'J') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J') {
				dobitak = igrac->ulog * 2.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
				dobitak = igrac->ulog * 0.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q' && polje[3][i] == 'Q' && polje[4][i] == 'Q') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q' && polje[3][i] == 'Q') {
				dobitak = igrac->ulog * 2.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
				dobitak = igrac->ulog * 0.5;
				igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K' && polje[3][i] == 'K' && polje[4][i] == 'K') {
				dobitak = igrac->ulog * 15;
				igrac->stanje = igrac->stanje + igrac->ulog * 15;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K' && polje[3][i] == 'K') {
				dobitak = igrac->ulog * 4;
				igrac->stanje = igrac->stanje + igrac->ulog * 4;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
				dobitak = igrac->ulog * 1;
				igrac->stanje = igrac->stanje + igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A' && polje[3][i] == 'A' && polje[4][i] == 'A') {
				dobitak = igrac->ulog * 15;
				igrac->stanje = igrac->stanje + igrac->ulog * 15;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A' && polje[3][i] == 'A') {
				dobitak = igrac->ulog * 4;
				igrac->stanje = igrac->stanje + igrac->ulog * 4;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
				dobitak = igrac->ulog * 1;
				igrac->stanje = igrac->stanje + igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7' && polje[3][i] == '7' && polje[4][i] == '7') {
				dobitak = igrac->ulog * 150;
				igrac->stanje = igrac->stanje + igrac->ulog * 150;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7' && polje[3][i] == '7') {
				dobitak = igrac->ulog * 75;
				igrac->stanje = igrac->stanje + igrac->ulog * 75;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7') {
				dobitak = igrac->ulog * 10;
				igrac->stanje = igrac->stanje + igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
			else if (polje[0][i] == '7' && polje[1][i] == '7') {
				dobitak = igrac->ulog * 2;
				igrac->stanje = igrac->stanje + igrac->ulog * 2;
				printf(" %f kredita\n", dobitak);
				provjera = 1;

				break;
			}
		}

		//prva dijagonala
		if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J' && polje[3][1] == 'J' && polje[4][0] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J' && polje[3][1] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][1] == 'J' && polje[2][2] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q' && polje[3][1] == 'Q' && polje[4][0] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q' && polje[3][1] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][1] == 'Q' && polje[2][2] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}



		if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K' && polje[3][1] == 'K' && polje[4][0] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K' && polje[3][1] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][1] == 'K' && polje[2][2] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}



		if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A' && polje[3][1] == 'A' && polje[4][0] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A' && polje[3][1] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][1] == 'A' && polje[2][2] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7' && polje[3][1] == '7' && polje[4][0] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7' && polje[3][1] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7' && polje[2][2] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][1] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//suprotna dijagonala
		if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J' && polje[3][1] == 'J' && polje[4][2] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J' && polje[3][1] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][1] == 'J' && polje[2][0] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q' && polje[3][1] == 'Q' && polje[4][2] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q' && polje[3][1] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][1] == 'Q' && polje[2][0] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A' && polje[3][1] == 'A' && polje[4][2] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A' && polje[3][1] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][1] == 'A' && polje[2][0] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K' && polje[3][1] == 'K' && polje[4][2] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K' && polje[3][1] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][1] == 'K' && polje[2][0] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}


		if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7' && polje[3][1] == '7' && polje[4][2] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7' && polje[3][1] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7' && polje[2][0] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][1] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//6.Linija

		if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J' && polje[3][2] == 'J' && polje[4][1] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J' && polje[3][2] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][2] == 'J' && polje[2][2] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q' && polje[3][2] == 'Q' && polje[4][1] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q' && polje[3][2] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][2] == 'Q' && polje[2][2] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A' && polje[3][2] == 'A' && polje[4][1] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A' && polje[3][2] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][2] == 'A' && polje[2][2] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K' && polje[3][2] == 'K' && polje[4][1] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K' && polje[3][2] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][2] == 'K' && polje[2][2] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7' && polje[3][2] == '7' && polje[4][1] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7' && polje[3][2] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7' && polje[2][2] == '7') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][2] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//7.Linija

		if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J' && polje[3][0] == 'J' && polje[4][1] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J' && polje[3][0] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'J' && polje[1][0] == 'J' && polje[2][0] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q' && polje[3][0] == 'Q' && polje[4][1] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q' && polje[3][0] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'Q' && polje[1][0] == 'Q' && polje[2][0] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A' && polje[3][0] == 'A' && polje[4][1] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A' && polje[3][0] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'A' && polje[1][0] == 'A' && polje[2][0] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K' && polje[3][0] == 'K' && polje[4][1] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K' && polje[3][0] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == 'K' && polje[1][0] == 'K' && polje[2][0] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7' && polje[3][0] == '7' && polje[4][1] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7' && polje[3][0] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7' && polje[2][0] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][1] == '7' && polje[1][0] == '7' ) {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

		//8.linija

		if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J' && polje[3][2] == 'J' && polje[4][2] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J' && polje[3][2] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'J' && polje[1][0] == 'J' && polje[2][1] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q' && polje[3][2] == 'Q' && polje[4][2] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q' && polje[3][2] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'Q' && polje[1][0] == 'Q' && polje[2][1] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A' && polje[3][2] == 'A' && polje[4][2] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A' && polje[3][2] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'A' && polje[1][0] == 'A' && polje[2][1] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K' && polje[3][2] == 'K' && polje[4][2] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K' && polje[3][2] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == 'K' && polje[1][0] == 'K' && polje[2][1] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7' && polje[3][2] == '7' && polje[4][2] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7' && polje[3][2] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7' && polje[2][1] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][0] == '7' && polje[1][0] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

	//9.linija

		if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J' && polje[3][0] == 'J' && polje[4][0] == 'J') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J' && polje[3][0] == 'J') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'J' && polje[1][2] == 'J' && polje[2][1] == 'J') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q' && polje[3][0] == 'Q' && polje[4][0] == 'Q') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q' && polje[3][0] == 'Q') {
			dobitak = igrac->ulog * 2.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 2.5;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'Q' && polje[1][2] == 'Q' && polje[2][1] == 'Q') {
			dobitak = igrac->ulog * 0.5;
			igrac->stanje = igrac->stanje + igrac->ulog * 0.5;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A' && polje[3][0] == 'A' && polje[4][0] == 'A') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A' && polje[3][0] == 'A') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'A' && polje[1][2] == 'A' && polje[2][1] == 'A') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K' && polje[3][0] == 'K' && polje[4][0] == 'K') {
			dobitak = igrac->ulog * 15;
			igrac->stanje = igrac->stanje + igrac->ulog * 15;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K' && polje[3][0] == 'K') {
			dobitak = igrac->ulog * 4;
			igrac->stanje = igrac->stanje + igrac->ulog * 4;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == 'K' && polje[1][2] == 'K' && polje[2][1] == 'K') {
			dobitak = igrac->ulog * 1;
			igrac->stanje = igrac->stanje + igrac->ulog * 1;
			printf(" %f kredita\n", dobitak);

		}

		if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7' && polje[3][0] == '7' && polje[4][0] == '7') {
			dobitak = igrac->ulog * 150;
			igrac->stanje = igrac->stanje + igrac->ulog * 150;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7' && polje[3][0] == '7') {
			dobitak = igrac->ulog * 75;
			igrac->stanje = igrac->stanje + igrac->ulog * 75;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7' && polje[2][1] == '7') {
			dobitak = igrac->ulog * 10;
			igrac->stanje = igrac->stanje + igrac->ulog * 10;
			printf(" %f kredita\n", dobitak);

		}
		else if (polje[0][2] == '7' && polje[1][2] == '7') {
			dobitak = igrac->ulog * 2;
			igrac->stanje = igrac->stanje + igrac->ulog * 2;
			printf(" %f kredita\n", dobitak);

		}

	}

	else {
		printf("Niste osvojili, pokusajte ponovno.\n");
	}
}
	
	





int random(int min, int max) {
	return rand() % (max - min) + min;
}