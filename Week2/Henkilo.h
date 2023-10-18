#pragma once
#include <string>
using std::string;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sis‰lt‰‰ useammantyyppist‰ dataa
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
	// kapseloidut tietoj‰senet, j‰sen muuttuja =  member variables/properties
	string nimi;
	int ika;
};