#pragma once
typedef struct {
	char ime[20];
	int stanje;
	float ulog;
	int dobitak;
	int maxdobitak;
}IGRAC;

int random(int, int);
void PrintP(char[5][3]);
int provjera(char[5][3]);