#include <iostream>
#include "Paivays.h"
using namespace std;


Paivays::Paivays() : paiva(1), kuukausi(1), vuosi(1970)
{
	// konstruktorin tehtävä on alustaa olio (olion data)
	
}

Paivays::Paivays(int aPaiva, int aKuukausi, int aVuosi) : paiva(aPaiva), kuukausi(aKuukausi), vuosi(aVuosi)
{
	// konstruktorin tehtävä on alustaa olio (olion data)

}


Paivays::~Paivays()
{
	cout << "Paivays vapautettu" << endl;
}

void Paivays::setPaiva(int aPaiva) {
	paiva = aPaiva;
}
void Paivays::setKuukausi(int aKuukausi) {
	kuukausi = aKuukausi;
}
void Paivays::setVuosi(int aVuosi) {
	vuosi = aVuosi;
}
int Paivays::getPaiva() const{
	return paiva;
}
int Paivays::getKuukausi() const {
	return kuukausi;
}
int Paivays::getVuosi() const {
	return vuosi;
}
void Paivays::tulostaPaivays() const {
	cout << paiva << "." << kuukausi << "." << vuosi;
}
void Paivays::lisaaPaiva() {
	int karkaus_pva = 28;
	if (vuosi % 4 == 0) {
		if (vuosi % 100 == 0) {
			if (vuosi % 400 == 0) {
				karkaus_pva = 29;
			}
		}
		else {
			karkaus_pva = 29;
		}
	}
	paiva++;

	if (paiva > 31 || (paiva > karkaus_pva && kuukausi == 2) || (paiva > 30 && (kuukausi == 4 || kuukausi == 6 || kuukausi == 9 || kuukausi == 11 ))) {
		paiva = 1;
		kuukausi++;
	}
	if (kuukausi > 12) {
		kuukausi = 1;
		vuosi++;
	}
}
void Paivays::kysyPaiva() {
	bool looper = true;
	int input = 0;
	
	while (looper) {
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Anna vuosi: ";
		cin >> input;
		if (cin.fail()) {
			cout << "Vuoden on oltava integeri(kokonaisluku)." << endl;			
		}
		else {
			if (input > 0) {
				vuosi = input;
				looper = false;
				
			}
			else {
				cout << "Vuosi ei voi olla negatiivinen\n";
			}
		}
		cin.clear();
	}
	looper = true;
	while (looper) {
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Anna kuukausi: ";
		cin >> input;
		if (cin.fail()) {
			cout << "Kuukauden on oltava positiivinen integeri(kokonaisluku)." << endl;
		}
		else {
			if (input > 0 && input <= 12) {
				kuukausi = input;
				looper = false;
			}
			else {
				cout << "Kuukauden on oltava pienempi kuin 12.\n";	
			}
			
		}
		cin.clear();

	}
	looper = true;
	while (looper) {
		int karkaus_pva = 28;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Anna paiva: ";
		cin >> input;
		if (cin.fail()) {
			cout << "Paiva on oltava positiivinen integeri(kokonaisluku)." << endl;
		}
		else {
			if (input > 0) {
				if (vuosi % 4 == 0) {
					if (vuosi % 100 == 0) {
						if (vuosi % 400 == 0) {
							karkaus_pva = 29;
						}
					}
					else {
						karkaus_pva = 29;
					}
				}
				if (kuukausi == 2 && input <= karkaus_pva) {
					paiva = input;
					looper = false;
				}
				else if ((kuukausi == 4 || kuukausi == 6 || kuukausi == 9 || kuukausi == 11) && input <= 30)  {
					paiva = input;
					looper = false;
				}
				else if ((kuukausi == 1 || kuukausi == 3 || kuukausi == 7 || kuukausi == 8 || kuukausi == 10 || kuukausi == 12) && input <= 31) {
					paiva = input;
					looper = false;
				}
				else {
					cout << "Paivien maara oltava positiivinen alle 28/29, 30 tai 31 riippuen kuukaudesta." << endl;
				}
			}
			else {
				cout << "Paivien maara oltava positiivinen alle 28/29, 30 tai 31 riippuen kuukaudesta." << endl;
			}
		}
		cin.clear();
	}
}
