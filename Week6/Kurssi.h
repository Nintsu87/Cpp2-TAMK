#pragma once
#include "Opettaja.h"
#include "Paivays.h"


class Kurssi {
public:
	Kurssi();
	Kurssi(const Kurssi&);
	Kurssi(const string&, const string&, const string&, const int, const Paivays&, const Paivays&);
	Kurssi(const string&, const string&, const string&, const int, const Opettaja&, const Paivays&, const Paivays&);

	int getLaajuus() const;
	string getKoodi() const;
	string getNimi() const;
	Opettaja getOpettaja() const;
	Paivays getAlkupaiva() const;
	Paivays getLoppupaiva() const;
	

	void setNimi(const string&);
	void setKoodi(const string&);
	void setOpettaja(const Opettaja&);
	
	void tulostaTiedot() const;
	


private:
	string kurssinNimi;
	string kurssikoodi;
	string ala;
	int laajuus;
	Opettaja vastuuopettaja;
	Paivays aloituspaiva;
	Paivays paattymispaiva;
	
};
