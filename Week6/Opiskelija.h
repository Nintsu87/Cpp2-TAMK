#pragma once
#include "Kurssi.h"

class Opiskelija : public Henkilo {
public:
	Opiskelija();
	Opiskelija(const Opiskelija& aOpiskelija);
	Opiskelija(const string& aNimi, int aIka, const Osoite& aOsoite, const string& aOpiskelijanumero, const string& aTutkinto);
	~Opiskelija();
	string getOpiskelijanumero() const;
	string getTutkinto() const;
	int getOpintopisteet() const;
	vector<Kurssi*> getKurssit();
	void lisaaKurssi(Kurssi*);
	void setTutkinto(const string& aTutkinto);
	void tulostaTiedot() const;

private:
	string opiskelijanumero;
	string tutkinto;
	int opintopisteet = 0;
	vector<Kurssi*> kurssit;
};