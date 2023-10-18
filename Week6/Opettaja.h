#pragma once
#include <vector>
#include "Henkilo.h"



class Opettaja : public Henkilo {
public:
	Opettaja();
	Opettaja(const Opettaja& aOpettaja);
	Opettaja(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aKoulutusala);
	~Opettaja();
	string getKoulutusala() const;
	void lisaaKurssi(const string& aKurssi);
	void setKoulutusala(const string& aKoulutusala);
	void poistaKurssi(const string& aKurssi);
	void tulostaTiedot() const;

private:
	vector<string> kurssit;
	string koulutusala;

};