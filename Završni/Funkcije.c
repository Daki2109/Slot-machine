
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include "Funkcije.h"
provjeraStanja(IGRAC* igrac) {
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
int provjera(char polje[5][3], int provjer) {
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
			return provjer = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
			return provjer = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
			return provjer = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
			return provjer = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7') {
			return provjer = 1;
		}
	}
}
void spin(IGRAC* igrac, char polje[5][3]) {


	if (igrac->stanje < igrac->ulog) {
		printf("Nedovoljno kredita, smanjite ulog!\n");
		return 1;
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			polje[i][j] = Simboli();
		}
	}
	printf("%c %c %c", polje[0][0], polje[0][1], polje[0][2]);
	igrac->stanje =igrac->stanje-igrac->ulog;
	PrintP(polje);
	int provjer=0;
	float dobitak = 0;
	provjera(polje,provjer);
	if (provjer=1) {
		printf("Cestitamo, osvojili ste:\n");
		

		for (int i = 0; i < 3; i++) {
			
			if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J') {
				if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J') {
					if (polje[0][i] == 'J' && polje[1][i] == 'J' && polje[2][i] == 'J' && polje[3][i] == 'J' && polje[4][i] == 'J') {
						dobitak = igrac->ulog * 0.5;
						igrac->stanje = igrac->stanje + dobitak;
						printf(" %f kredita\n", dobitak);
						provjer = 0;

						break;
					}
					else {
						dobitak = igrac->ulog * 2.5;
						igrac->stanje = igrac->stanje + dobitak;
						printf(" %f kredita\n", dobitak);
						provjer = 0;

						break;
					}

				}
				else {
					dobitak = igrac->ulog * 10;
					printf(" %f kredita\n", dobitak);
					provjer = 0;
					igrac->stanje = igrac->stanje + dobitak;

					break;
				}

			}
		}

		for (int i = 0; i< 3; i++) {
			if (polje[0][i] == 'Q' && polje[1][i] == 'Q' && polje[2][i] == 'Q') {
				dobitak = igrac->ulog * 0.5;
				printf(" %f kredita\n", dobitak);
				provjer = 0;

				break;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'K' && polje[1][i] == 'K' && polje[2][i] == 'K') {
				dobitak = igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjer = 0;

				break;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == 'A' && polje[1][i] == 'A' && polje[2][i] == 'A') {
				dobitak = igrac->ulog * 1;
				printf(" %f kredita\n", dobitak);
				provjer = 0;

				break;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (polje[0][i] == '7' && polje[1][i] == '7' && polje[2][i] == '7') {
				dobitak = igrac->ulog * 10;
				printf(" %f kredita\n", dobitak);
				provjer = 0;
				break;
			}
		}




	}
	else{
		printf("Niste osvojili, pokusajte ponovno.\n");
	}

}







int random(int min, int max) {
	return rand() % (max - min) + min;
}