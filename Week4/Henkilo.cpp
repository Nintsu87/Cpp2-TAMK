#include <iostream>
#include "Henkilo.h"
using namespace std;

Henkilo::Henkilo() : nimi(""), ika(0), kotiOsoite()
{
}

Henkilo::Henkilo(const Henkilo& aHenkilo) : nimi(aHenkilo.nimi), kotiOsoite(aHenkilo.kotiOsoite)
{
	cout << "Anna ika:";
	cin >> ika;
}

Henkilo::Henkilo(const string& aNimi, int aIka) : nimi(aNimi), ika(aIka), kotiOsoite()
{
}

Henkilo::Henkilo(const string& aNimi, int aIka, const Osoite& aOsoite) : nimi(aNimi), ika(aIka), kotiOsoite(aOsoite)
{
}

Henkilo::~Henkilo()
{
	cout << "Henkilo -olio vapautettu" << endl;
}

// aseta metodiin annettu tieto nimi j�senmuuttujaan
void Henkilo::setNimi(const string& aNimi) {
	nimi = aNimi;
}

// aseta metodiin annettu tieto ika j�senmuuttujaan
// jos numero on tietyn rangen sis�ll�
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

// ota private j�senmuuttuja k�ytt��n public puolella
string Henkilo::getNimi() const {
	return nimi;
}
// ota private j�senmuuttuja k�ytt��n public puolella
int Henkilo::getIka() const {
	return ika;
}

Osoite Henkilo::getOsoite() const
{
	return kotiOsoite;
}

// tulostaa tiedot k�ytt�j�lle
void Henkilo::tulostaTiedot() const {
	cout << "\nNimi: " << nimi << "\n\nIka: " << ika << endl;
	kotiOsoite.tulostaOsoite();
}