#include <iostream>
#include "Henkilo.h"
using namespace std;

Henkilo::Henkilo() : nimi(""), ika(0), kotiOsoite()
{
}

Henkilo::Henkilo(const Henkilo& aHenkilo) = default;

Henkilo::Henkilo(const string& aNimi, int aIka) 
	: nimi(aNimi), ika(aIka), kotiOsoite()
{
	cout << "*Hlo luotu*";
}

Henkilo::Henkilo(const string& aNimi, int aIka, const Osoite& aOsoite) 
	: nimi(aNimi), ika(aIka), kotiOsoite(aOsoite)
{
	cout << "*Hlo luotu*";
}

Henkilo::~Henkilo()
{
	cout << "*Hlo tuhottu*";
}

// aseta metodiin annettu tieto nimi jäsenmuuttujaan
void Henkilo::setNimi(const string& aNimi) {
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

void Henkilo::setOsoite(const Osoite& aOsoite)
{
	kotiOsoite = aOsoite;
}

// ota private jäsenmuuttuja käyttöön public puolella
string Henkilo::getNimi() const {
	return nimi;
}
// ota private jäsenmuuttuja käyttöön public puolella
int Henkilo::getIka() const {
	return ika;
}

Osoite Henkilo::getOsoite() const
{
	return kotiOsoite;
}

// tulostaa tiedot käyttäjälle
void Henkilo::tulostaTiedot() const {
	cout << "\nNimi: " << nimi << "\nIka: " << ika << endl;
	kotiOsoite.tulostaOsoite();
}