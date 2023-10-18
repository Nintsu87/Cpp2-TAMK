#include <iostream>
#include "Henkilo.h"
using namespace std;

Henkilo::Henkilo() : nimi("hemmo"), ika(1)
{
}

Henkilo::Henkilo(string aNimi, int aIka) : nimi(aNimi), ika(aIka)
{
}

Henkilo::~Henkilo()
{
	cout << "Henkilo -olio vapautettu" << endl;
}

// aseta metodiin annettu tieto nimi jäsenmuuttujaan
void Henkilo::setNimi(string aNimi) {
	nimi = aNimi;
}

// aseta metodiin annettu tieto ika jäsenmuuttujaan
// jos numero on tietyn rangen sisällä
void Henkilo::setIka(int aIka) {
	if (aIka >= 0 && aIka < 120) {
		ika = aIka;
	}
	else {
		cout << "\nInput \"" << aIka << "\" was invalid.";
	}
}

// ota private jäsenmuuttuja käyttöön public puolella
string Henkilo::getNimi() {
	return nimi;
}
// ota private jäsenmuuttuja käyttöön public puolella
int Henkilo::getIka() {
	return ika;
}

// tulostaa tiedot käyttäjälle
void Henkilo::tulostaTiedot() {
	cout << "\nNimi: " << nimi << "\n\nIka: " << ika << endl;
}