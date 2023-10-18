#pragma once
#include "Opiskelija.h"


class Koulu {
public:
	Koulu();
	Koulu(const Koulu&);
	Koulu(const string&);

	~Koulu();

	void setNimi(const string&);
	void lisaaOpettaja(Opettaja*);
	void lisaaOpiskelija(Opiskelija*);
	void lisaaKurssi(Kurssi*);
	vector<Opettaja*> getOpettajat();
	vector<Opiskelija*> getOpiskelijat();
	vector<Kurssi*> getKurssit();
	void tulostaOpettajat();
	void tulostaOpiskelijat();
	void tulostaKurssit();
	void tulostaKaikkiTeidot();

private:
	string koulu;
	vector<Opettaja*> opettajat;
	vector<Opiskelija*> opiskelijat;
	vector<Kurssi*> kurssit;


};
