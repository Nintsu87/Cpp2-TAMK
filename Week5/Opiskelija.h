#pragma once
#include "Henkilo.h"
#include <vector>


class Opiskelija : public Henkilo {
public:
	Opiskelija();
	Opiskelija(const Opiskelija& aOpiskelija);
	Opiskelija(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aOpiskelijanumero, const string& aTutkinto);
	~Opiskelija();
	string getOpiskelijanumero() const;
	string getTutkinto() const;
	int getOpintopisteet() const;
	void lisaaKurssi(const string& aKurssi);
	void setTutkinto(const string& aTutkinto);
	void tulostaTiedot() const;
	void lisaaOpintopisteita(const int aPisteet);

private:
	string opiskelijanumero;
	string tutkinto;
	int opintopisteet;
	vector<string> kurssit;
};