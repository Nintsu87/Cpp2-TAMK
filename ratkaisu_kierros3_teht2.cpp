#include <iostream>;
using namespace std;


// create seconds to time -function prototype
int sekunnit_ajaksi(int, int&, int&);
// create time to seconds -function prototype
int aika_sekunneiksi(int, int, int);


int main() {

	int sekunnit = NULL, // seconds
		minuutit = NULL, // minutes
		tunnit = NULL;	// hours

	// ask user for hours, minutes and seconds
	cout << "Anna tunnit: ";
	cin >> tunnit;
	cout << "Anna minuutit: ";
	cin >> minuutit;
	cout << "Anna sekunnit: ";
	cin >> sekunnit;

	// print values before functions
	cout << "\n" << tunnit << " tuntia, " << minuutit << " minuuttia ja " << sekunnit << " sekunttia";
	
	// call time to seconds -function to get amount of seconds
	sekunnit = aika_sekunneiksi(tunnit, minuutit, sekunnit);

	// print that to user
	cout << " on " << sekunnit << " sekunttia, ";

	// call function to return seconds and add minutes and hours
	sekunnit = sekunnit_ajaksi(sekunnit,minuutit,tunnit);

	// print that to user
	cout << "joka on " << tunnit << " tuntia, " << minuutit << " minuuttia ja " << sekunnit << " sekunttia.";

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