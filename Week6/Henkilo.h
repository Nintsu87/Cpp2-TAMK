#pragma once

#include "Osoite.h"
#include <string>
using namespace std;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sisältää useammantyyppistä dataa
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
	// kapseloidut tietojäsenet, jäsen muuttuja =  member variables/properties
	string nimi;
	int ika;
	//Paivays syntymapaiva;
	Osoite kotiOsoite;
};