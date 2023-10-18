#include "Henkilo.h"
#include "Osoite.h"
#include "o"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "fi_FI"); // avataan tulostukseen ääkköset
	bool loopHelper = true;
	vector<Henkilo*> henkilot;

	while (loopHelper) {
		string komento;
		cout << endl << "1. Lisää uusi henkilö" << endl;
		cout << "2. Tulosta henkilöt" << endl;
		cout << "3. Poista henkilö" << endl;
		cout << "4. Lopeta" << endl;
		cout << "Komento: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, komento);
	
		if (komento == "4") {
			loopHelper = false;
		}
		else if (komento == "1") {
			string nimi,
				osoite,
				postinro,
				kaupunki;
			int ika;
			cout << "Anna nimi: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, nimi);
			cout << "Anna ika: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> ika;
			cout << "Anna katuosoite: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, osoite);
			cout << "Anna postinro: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, postinro);
			cout << "Anna kaupunki: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, kaupunki);
			Henkilo* hlo = new Henkilo{ nimi, ika, Osoite{ osoite, postinro, kaupunki}};
			henkilot.push_back(hlo);
		}
		else if (komento == "2") {
			for (Henkilo* h : henkilot) {
				h->tulostaTiedot();
			}
		}
		else if (komento == "3") {
			string nimi;
			bool onkoVectorissa = false;
			int index = 0;
			cout << "Anna poistettavan henkilön nimi: ";
			getline(cin, nimi);
			for (Henkilo* h : henkilot) {
				if (h->getNimi() == nimi) {
					onkoVectorissa = true;
					break;
				}
				index++;
			}
			if (onkoVectorissa) {
				henkilot.erase(henkilot.begin()+index);
			}
		}
		else {
			cout << "Höpö, vain 1, 2, 3 ja 4 toimii." << endl;
		}

	}
	cout << "Lopetit ohjelman";
	return EXIT_SUCCESS;
}
