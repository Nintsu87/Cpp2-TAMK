#pragma once
#include <string>
using std::string;

class Henkilo {
	// rakenteellinen tietotyyppi
	// voi sis‰lt‰‰ useammantyyppist‰ dataa
public:
	// datalle luodaan methodeita (setterit ja getterit)
	// Setterit:
	void setNimi(string aNimi);
	void setIka(int aIka);
	// Getterit
	string getNimi();
	int getIka();
	void tulostaTiedot();

private:
	// kapseloidut tietoj‰senet, j‰sen muuttuja =  member variables/properties
	string nimi;
	int ika;
};