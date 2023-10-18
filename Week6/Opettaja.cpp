#include "Opettaja.h"

Opettaja::Opettaja() 
	: Henkilo(), koulutusala("")
{
	
}

Opettaja::Opettaja(const Opettaja& aOpettaja) 
	: Henkilo(aOpettaja), koulutusala(aOpettaja.koulutusala)
{
	cout << "*Opettaja kopioitu* ";
	
}

Opettaja::Opettaja(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aKoulutusala)
	: Henkilo(aNimi, aIka, aOsoite), koulutusala(aKoulutusala)
{
	cout << "*Opettaja " << aNimi << " luotu * ";
}

Opettaja::~Opettaja()
{
	cout << "*Opettaja tuhottu* ";
}

string Opettaja::getKoulutusala() const
{
	return koulutusala;
}

void Opettaja::lisaaKurssi(const string & aKurssi)
{
	kurssit.push_back(aKurssi);
}

void Opettaja::setKoulutusala(const string& aKoulutusala)
{
	koulutusala = aKoulutusala;
}

void Opettaja::poistaKurssi(const string& aKurssi)
{
	bool oliko = false;
	int indx = 0;
	for (string s : kurssit) {
		if (s == aKurssi) {
			kurssit.erase(kurssit.begin() + indx);
			oliko = true;
			break;
		}
		
		indx++;
	}
	if (!oliko) {
		cout << "Kurssia " << aKurssi << "ei ollut vectorissa." << endl;
	}
}

void Opettaja::tulostaTiedot() const
{
	cout << "Opettajan tiedot: " << endl;
	cout << "Nimi: " << getNimi() << endl;
	cout << "Ika: " << getIka() << endl;
	getOsoite().tulostaOsoite();
	cout << "Koulutusala: " << getKoulutusala() << endl;
	cout << "Vastuukurssit: " << endl;
	if (kurssit.size() > 0) {
		for (string s : kurssit) {
			cout << "- " << s << endl;
		}
	}
	else {
		cout << "* Ei kursseja" << endl;
	}
	cout << endl;
}
