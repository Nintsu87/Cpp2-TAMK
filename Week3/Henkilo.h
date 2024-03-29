#pragma once
#include <string>
#include "Osoite.h"
using namespace std;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sisältää useammantyyppistä dataa
public:
	Henkilo();
	Henkilo(string, int);
	Henkilo(string, int, Osoite);

	// Purkaja (Destructor)
	~Henkilo();
	// Setterit:
	void setNimi(string);
	void setIka(int);
	void setOsoite(Osoite);
	// Getterit
	string getNimi() const;
	int getIka() const;
	Osoite getOsoite() const;
	void tulostaTiedot() const;

private:
	// kapseloidut tietojäsenet, jäsen muuttuja =  member variables/properties
	string nimi;
	int ika;
	//Paivays syntymapaiva;
	Osoite kotiOsoite;
};