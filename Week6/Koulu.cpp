#include "Koulu.h"

Koulu::Koulu()
	: koulu("")
{
	cout << "*Tyhja koulu luotu*";
}

Koulu::Koulu(const Koulu& aKoulu)
	: koulu(aKoulu.koulu)
{
	cout << "*Koulu kopioitu*";
}

Koulu::Koulu(const string& aNimi)
	: koulu(aNimi)
{
	cout << "*Koulu luotu*";
}

Koulu::~Koulu()
{
	cout << "*Koulu tuhottu*";
}

void Koulu::setNimi(const string& aNimi)
{
	koulu = aNimi;
}

void Koulu::lisaaOpettaja(Opettaja* aOpettaja)
{
	opettajat.push_back(aOpettaja);
}

void Koulu::lisaaOpiskelija(Opiskelija* aOpiskelija)
{
	opiskelijat.push_back(aOpiskelija);
}

void Koulu::lisaaKurssi(Kurssi* aKurssi)
{
	kurssit.push_back(aKurssi);
}

vector<Opettaja*> Koulu::getOpettajat()
{
	return opettajat;
}

vector<Opiskelija*> Koulu::getOpiskelijat()
{
	return opiskelijat;
}

vector<Kurssi*> Koulu::getKurssit()
{
	return kurssit;
}

void Koulu::tulostaOpettajat()
{
	if (opettajat.size() > 0) {
		cout << "Kaikki opettajat(" << opettajat.size() << "kpl): " << endl;
		for (Opettaja* o : opettajat) {
			o->tulostaTiedot();
		}
	}
	else {
		cout << "* Ei opettajia." << endl;
	}
}

void Koulu::tulostaOpiskelijat()
{
	if(opiskelijat.size() > 0) {
		cout << "Kaikki opiskelijat(" << opiskelijat.size() << "kpl): " << endl;
		for (Opiskelija* o : opiskelijat) {
			o->tulostaTiedot();
		}
	}
	else {
		cout << "* Ei opiskelijoita." << endl;
	}
}

void Koulu::tulostaKurssit()
{
	
	if (kurssit.size() > 0) {
		cout << "\nKaikki kurssit(" << kurssit.size() << "kpl): " << endl;
		for (Kurssi* k : kurssit) {
			k->tulostaTiedot();
		}
	}
	else {
		cout << "* Ei kursseja." << endl;
	}
}

void Koulu::tulostaKaikkiTeidot()
{
	cout << "Koulun nimi: " << koulu << endl;
	tulostaOpettajat();
	tulostaOpiskelijat();
	tulostaKurssit();
	
}
