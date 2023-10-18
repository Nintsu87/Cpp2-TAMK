#include <iostream>;
#include <string>;
#include <iomanip>;
using namespace std;


// create time structure
struct aika_ty {
	int tunnit, //hours
		minuutit, // minutes
		sekunnit; // seconds
};

// create seconds to time -function prototype
int sekunnit_ajaksi(int, int&, int&);
// create time to seconds -function prototype
int aika_sekunneiksi(int, int, int);
// create time subtraction function prototype
aika_ty aikojen_erotus(aika_ty, aika_ty);


int main() {
	setlocale(LC_ALL, "fi_FI"); // include finnish letters to prints

	aika_ty eka_aika, 
		toka_aika, 
		erotus;


	// ask user 2 different times without any checks assuming user is giving 
	// correct kind of info
	cout << "Anna isomman ajan tunnit: ";
		
	cin >> eka_aika.tunnit;
	cin.ignore(cin.rdbuf()->in_avail());
		
	cout << "Anna isomman ajan minuutit: ";
		
	cin >> eka_aika.minuutit;
	cin.ignore(cin.rdbuf()->in_avail());
		
	cout << "Anna isomman ajan sekunnit: ";
		
	cin >> eka_aika.sekunnit;
	cin.ignore(cin.rdbuf()->in_avail());
		
	cout << "Anna pienemmän ajan tunnit: ";

	cin >> toka_aika.tunnit;
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "Anna pienemmän ajan minuutit: ";

	cin >> toka_aika.minuutit;
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "Anna pienemmän ajan sekunnit: ";

	cin >> toka_aika.sekunnit;
	cin.ignore(cin.rdbuf()->in_avail());
	// creates structure for subtraction eka_aika - toka_aika
	erotus = aikojen_erotus(eka_aika, toka_aika);
	cout << "\n\nErotus on: ";
	// check if given time are only 1 number and add 0 to print if not
	if (erotus.tunnit < 10) {
		cout << "0" << erotus.tunnit << ":";
	}
	else {
		cout << erotus.tunnit << ":";
	}
	if (erotus.minuutit < 10) {
		cout << "0" << erotus.minuutit << ":";
	}
	else {
		cout << erotus.minuutit << ":";
	}
	if (erotus.sekunnit < 10) {
		cout << "0" << erotus.sekunnit;
	}
	else {
		cout << erotus.sekunnit;
	}

	

}

// counts subtraction of time 1 and time2 and returns it back as a time structure
aika_ty aikojen_erotus(aika_ty aika1, aika_ty aika2) {
	aika_ty helper;
	int sekunnit1, 
		sekunnit2,
		erotus;

	sekunnit1 = aika_sekunneiksi(aika1.tunnit, aika1.minuutit, aika1.sekunnit);
	sekunnit2 = aika_sekunneiksi(aika2.tunnit, aika2.minuutit, aika2.sekunnit);
	erotus = sekunnit1 - sekunnit2;
	helper.sekunnit = sekunnit_ajaksi(erotus, helper.minuutit, helper.tunnit);

	return helper;
}



// changes seconds to minutes and hours depending on how many seconds user gives
int sekunnit_ajaksi(int sekunnit, int& minuutit, int& tunnit) {

	// if seconds are big enough to have hours in
	if (sekunnit / 3600 > 0) {

		// if seconds hour remainder is not 0 
		if (sekunnit % 3600 != 0) {
			// assingn remainder seconds and count hours
			tunnit = (sekunnit - (sekunnit % 3600)) / 3600;
			sekunnit = sekunnit % 3600;
		}
		// if no remainder, just count hours and assign minutes and seconds to 0.
		else {
			tunnit = sekunnit / 3600;
			minuutit = 0;
			sekunnit = 0;
		}
	}

	// if seconds amount is enough for minutes
	if (sekunnit / 60 > 0) {
		// if seconds minute remainder is not 0 
		if (sekunnit % 60 != 0) {
			// assign remainder to seconds and count minutes 
			minuutit = (sekunnit - (sekunnit % 60)) / 60;
			sekunnit = sekunnit % 60;
		}
		// if no remainder, just count minutes and assign seconds to 0
		else {
			minuutit = sekunnit / 60;
			sekunnit = 0;
		}
	}
	return sekunnit;
}
// hours, minutes and seconds to amount of seconds
int aika_sekunneiksi(int tunnit, int minuutit, int sekunnit) {

	if (tunnit > 0) {
		sekunnit += tunnit * 3600;
	}
	if (minuutit > 0) {
		sekunnit += minuutit * 60;
	}

	return sekunnit;
}
