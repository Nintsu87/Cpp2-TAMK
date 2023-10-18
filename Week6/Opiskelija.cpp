#include "Opiskelija.h"

Opiskelija::Opiskelija()
	: Henkilo(), tutkinto("")
{
	cout << "Anna opiskelijanumero: ";
	cin >> opiskelijanumero;
}

Opiskelija::Opiskelija(const Opiskelija& aOpiskelija)
	: Henkilo(aOpiskelija), opiskelijanumero(aOpiskelija.getOpiskelijanumero())
{
	cout << "*Opiskelija kopioitu* ";
	
}

Opiskelija::Opiskelija(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aOpiskelijanumero, const string& aTutkinto)
	: Henkilo(aNimi, aIka, aOsoite), opiskelijanumero(aOpiskelijanumero), tutkinto(aTutkinto)
{
	cout << "*Opiskelija luotu* ";
}

Opiskelija::~Opiskelija()
{
	cout << "*Opiskelija tuhottu* ";
}

void Opiskelija::lisaaKurssi(Kurssi* aKurssi)
{
	kurssit.push_back(aKurssi);
	
	opintopisteet += aKurssi->getLaajuus();
}

void Opiskelija::setTutkinto(const string& aTutkinto)
{
	tutkinto = aTutkinto;
}

void Opiskelija::tulostaTiedot() const
{
	cout << "Opiskelijan " << getOpiskelijanumero() << " tiedot: " << getNimi() << endl;
	cout << "Ika: " << getIka() << endl;
	getOsoite().tulostaOsoite();
	cout << "Tutkinto: " << getTutkinto() << endl;
	cout << "Suoritetut kurssit: " << endl;
	if (kurssit.size() > 0) {
		for (Kurssi* k : kurssit) {
			k->tulostaTiedot();
		}
	}
	else {
		cout << "* Ei kursseja." << endl;
	}
	cout << "Opintopisteet yhteensa: " << getOpintopisteet() << endl;
	cout << endl;
}

string Opiskelija::getOpiskelijanumero() const
{
	return opiskelijanumero;
}

string Opiskelija::getTutkinto() const
{
	return tutkinto;
}

int Opiskelija::getOpintopisteet() const
{
	return opintopisteet;
}

vector<Kurssi*> Opiskelija::getKurssit()
{
	return kurssit;
}
