#pragma once
#include <string>
#include "Osoite.h"
using namespace std;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sis‰lt‰‰ useammantyyppist‰ dataa
public:
	Henkilo();
	Henkilo(const Henkilo&);
	Henkilo(const string&, int);
	Henkilo(const string&, int, const Osoite&);

	// Purkaja (Destructor)
	~Henkilo();
	// Setterit:
	void setNimi(const string&);
	void setIka(int);
	void setOsoite(const Osoite&);
	// Getterit
	
	int getIka() const;
	Osoite getOsoite() const;
	void tulostaTiedot() const;
	string getNimi() const;
	
private:
	// kapseloidut tietoj‰senet, j‰sen muuttuja =  member variables/properties
	string nimi;
	int ika;
	//Paivays syntymapaiva;
	Osoite kotiOsoite;
};