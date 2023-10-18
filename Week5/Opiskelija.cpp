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
	cout << "Anna uusi tutkinto: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, tutkinto);
	
}

Opiskelija::Opiskelija(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aOpiskelijanumero, const string& aTutkinto)
	: Henkilo(aNimi, aIka, aOsoite), opiskelijanumero(aOpiskelijanumero), tutkinto(aTutkinto), opintopisteet(0)
{
	cout << "Opiskelija-luokka rakennettu." << endl;
}

Opiskelija::~Opiskelija()
{
	cout << "Opiskelija-luokka tuhottu." << endl;
}

void Opiskelija::lisaaKurssi(const string& aKurssi)
{
	kurssit.push_back(aKurssi);
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
	cout << "Kurssit: " << endl;
	if (kurssit.size() > 0) {
		for (string s : kurssit) {
			cout << "- " << s << endl;
		}
	}
	else {
		cout << "* Ei kursseja." << endl;
	}
	cout << "Opintopisteet yhteensa: " << getOpintopisteet() << endl;
	cout << endl;
}

void Opiskelija::lisaaOpintopisteita(const int aPisteet)
{
	opintopisteet += aPisteet;
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
