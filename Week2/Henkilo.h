#pragma once
#include <string>
using std::string;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sisältää useammantyyppistä dataa
public:
	Henkilo();
	Henkilo(string, int);

	// Purkaja (Destructor)
	~Henkilo();
	// Setterit:
	void setNimi(string);
	void setIka(int);
	// Getterit
	string getNimi();
	int getIka();
	void tulostaTiedot();

private:
	// kapseloidut tietojäsenet, jäsen muuttuja =  member variables/properties
	string nimi;
	int ika;
};