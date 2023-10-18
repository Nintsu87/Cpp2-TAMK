#include "Kurssi.h"

Kurssi::Kurssi()
	: kurssinNimi(""), kurssikoodi(""), laajuus(0)
{
	cout << "*Tyhja kurssi luotu* ";
}

Kurssi::Kurssi(const Kurssi& aKurssi)
	: kurssinNimi(aKurssi.kurssinNimi), ala(aKurssi.ala), laajuus(aKurssi.laajuus)
{	
	cout << "*Kurssi kopioitu* ";
}

Kurssi::Kurssi(const string& aNimi, const string& aKoodi, const string& aAla, const int aPisteet, const Paivays& aAlkupva, const Paivays& aLoppupva)
	: kurssinNimi(aNimi), kurssikoodi(aKoodi), ala(aAla), laajuus(aPisteet), aloituspaiva(aAlkupva), paattymispaiva(aLoppupva)
{
	cout << "*Kurssi luotu* ";
}

Kurssi::Kurssi(const string& aNimi, const string& aKoodi, const string& aAla, const int aPisteet, const Opettaja& aOpettaja, const Paivays& aAlkupva, const Paivays& aLoppupva)
	: kurssinNimi(aNimi), kurssikoodi(aKoodi), ala(aAla), laajuus(aPisteet), vastuuopettaja(aOpettaja), aloituspaiva(aAlkupva), paattymispaiva(aLoppupva)
{
	cout << "*Kurssi luotu* ";
}

int Kurssi::getLaajuus() const
{
	return laajuus;
}

string Kurssi::getKoodi() const
{
	return kurssikoodi;
}

string Kurssi::getNimi() const
{
	return kurssinNimi;
}

Opettaja Kurssi::getOpettaja() const
{
	return vastuuopettaja;
}

Paivays Kurssi::getAlkupaiva() const
{
	return aloituspaiva;
}

Paivays Kurssi::getLoppupaiva() const
{
	return paattymispaiva;
}

void Kurssi::setNimi(const string& aNimi)
{
	kurssinNimi = aNimi;
}

void Kurssi::setKoodi(const string& aKoodi)
{
	kurssikoodi = aKoodi;
}

void Kurssi::setOpettaja(const Opettaja& aOpettaja)
{
	vastuuopettaja = aOpettaja;
}

void Kurssi::tulostaTiedot() const
{
	cout << endl <<  "Kurssin " << kurssikoodi << " nimi on: " << kurssinNimi << endl;
	cout << "Vastuuopettaja: " << vastuuopettaja.getNimi() << endl;
	cout << "Laajuus: " << laajuus << endl;
	cout << "Ajankohta: ";
	aloituspaiva.tulostaPaivays();
	cout << " - ";
	paattymispaiva.tulostaPaivays(); 
	cout << endl;
}


