#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Paivays.h"
using namespace std;

int main() {
	/*
	// Luo t�m�n p�iv�lle p�iv�lle ymm�rrett�v� datetime
	time_t tanaan_real;
	tanaan_real = time(NULL);

	tm* nyt = localtime(&tanaan_real);

	// luo tanaan olio t�m�n p�iv�n p�iv�m��rill�
	Paivays tanaan;
	tanaan.setPaiva(nyt->tm_mday);
	tanaan.setKuukausi(nyt->tm_mon + 1);
	tanaan.setVuosi(nyt->tm_year + 1900);

	// luo huomisen p�iv�n olion k�ytt�en t�m�n p�iv�n tietoja
	Paivays huomenna;
	huomenna.setPaiva(nyt->tm_mday + 1);
	huomenna.setKuukausi(nyt->tm_mon + 1);
	huomenna.setVuosi(nyt->tm_year + 1900);
	*/
	Paivays tanaan;
	tanaan.kysyPaiva();
	cout << "annettu pva: ";
	tanaan.tulostaPaivays();
	cout << endl;
	tanaan.lisaaPaiva();
	cout << "seuraava pva: ";
	tanaan.tulostaPaivays();

	
}