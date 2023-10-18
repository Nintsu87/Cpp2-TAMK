#include <iostream>;
#include <string>;
#include <iomanip>;
#include <windows.h>
using namespace std;

// create time structure
struct aika_ty {
	int tunnit, //hours
		minuutit, // minutes
		sekunnit; // seconds
};

// simple function from earlier task for testing purposes
int aika_sekunneiksi(int tunnit, int minuutit, int sekunnit) {

	if (tunnit > 0) {
		sekunnit += tunnit * 3600;
	}
	if (minuutit > 0) {
		sekunnit += minuutit * 60;
	}

	return sekunnit;
}


int main() {
	setlocale(LC_ALL, "fi_FI"); // include finnish letters to prints


	aika_ty aika, 
		aika_kopio, 
		aika_heratys;
	bool whileapu = true; //while loop helper
	aika_ty *aikaPtr = &aika; // a pointer for task shananigans

	// get background color working on terminal
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

	// assign a set times in alarm
	aika_heratys.tunnit = 6;
	aika_heratys.minuutit = 29;
	aika_heratys.sekunnit = 59;

	// asks user times until they are correctly between 0-23 hours
	while (whileapu) {

		cout << "Anna tunnit: ";
		SetConsoleTextAttribute(console_color, 896);
		cin >> aika.tunnit;
		cin.ignore(cin.rdbuf()->in_avail());
		SetConsoleTextAttribute(console_color, 15);
		cout << "Anna minuutit: ";
		SetConsoleTextAttribute(console_color, 896);
		cin >> aika.minuutit; 
		cin.ignore(cin.rdbuf()->in_avail());
		SetConsoleTextAttribute(console_color, 15);
		cout << "Anna sekunnit: ";
		SetConsoleTextAttribute(console_color, 896);
		cin >> aika.sekunnit;
		cin.ignore(cin.rdbuf()->in_avail());
		SetConsoleTextAttribute(console_color, 15);

		if (aika_sekunneiksi(aika.tunnit, aika.minuutit, aika.sekunnit) <= 86400 || aika_sekunneiksi(aika.tunnit, aika.minuutit, aika.sekunnit) >= 0) {
			whileapu = false;
		}
		else {
			cout << "\nAika ei sovi 24h sisalle.";
		}
	
	}

	// check if given times are only 1 number and add 0 to print if not
	if (aika.tunnit < 10) {
		cout << "0" << aika.tunnit << ":";
	}
	else {
		cout << aika.tunnit << ":";
	}
	if (aika.minuutit < 10) {
		cout << "0" << aika.minuutit << ":";
	}
	else {
		cout << aika.minuutit << ":";
	}
	if (aika.sekunnit < 10) {
		cout << "0" << aika.sekunnit;
	}
	else {
		cout << aika.sekunnit;
	}

	cout << "\nNow with the pointer:\n";

	// check if given times are only 1 number and add 0 to print if not
	if (aikaPtr->tunnit < 10) {
		cout << "0" << aikaPtr->tunnit << ":";
	}
	else {
		cout << aikaPtr->tunnit << ":";
	}
	if (aikaPtr->minuutit < 10) {
		cout << "0" << aikaPtr->minuutit << ":";
	}
	else {
		cout << aikaPtr->minuutit << ":";
	}
	if (aikaPtr->sekunnit < 10) {
		cout << "0" << aikaPtr->sekunnit;
	}
	else {
		cout << aikaPtr->sekunnit;
	}

	// copy preassigned struct to the empty one
	aika_kopio = aika_heratys;

	// compaire if structs are similar and copying worked
	if (aika_kopio.tunnit == aika_heratys.tunnit && aika_kopio.minuutit == aika_heratys.minuutit && aika_kopio.sekunnit == aika_heratys.sekunnit) {
		cout << "\n\"Sisällöt ovat samat.\"";
	}

}
