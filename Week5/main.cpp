#include "Henkilo.h"
#include "Osoite.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	vector<Henkilo*> koulunVaki;
	Opettaja* ope = new Opettaja{ "ope1", 35, Osoite{"jokukatu 1", "22233", "tre"}, "tite1" };
	koulunVaki.push_back(ope);
	Opettaja* ope1 = new Opettaja{ "ope2", 36, Osoite{"jokukatu 2", "22234", "tre"}, "tite2" };
	koulunVaki.push_back(ope1);
	Opettaja* ope2 = new Opettaja{ "ope3", 37, Osoite{"jokukatu 3", "22235", "tre"}, "tite3" };
	koulunVaki.push_back(ope2);
	Opiskelija* oppija = new Opiskelija{ "oppija1", 21, Osoite{"jokukatu 1", "22233", "tre"}, "123123", "tite1 insinoori" };
	koulunVaki.push_back(oppija);
	Opiskelija* oppija1 = new Opiskelija{ "oppija2", 22, Osoite{"jokukatu 2", "22234", "tre"}, "123123", "tite2 insinoori" };
	koulunVaki.push_back(oppija1);
	Opiskelija* oppija2 = new Opiskelija{ "oppija3", 23, Osoite{"jokukatu 3", "22235", "tre"}, "123123", "tite3 insinoori" };
	koulunVaki.push_back(oppija2);

	for (Henkilo* h : koulunVaki) {
		h->tulostaTiedot();
		cout << "\nToimiiko metodit: " << endl;
		cout << "Henkilon " << h->getNimi() << " ika on " << h->getIka() << endl;
		h->getOsoite().tulostaOsoite();
		cout << endl;
	}



	return EXIT_SUCCESS;
}
