#include <iostream>
#include "Henkilo.h"
using namespace std;


int maini() {
	// testaillaan olioiden toimintaa
	Henkilo pekka;
	pekka.setNimi("pekka");
	pekka.setIka(20);
	
	Henkilo maija;
	maija.setIka(22);
	maija.setNimi("maija");
	pekka.tulostaTiedot();
	maija.setIka(119);

	return EXIT_SUCCESS;
}
