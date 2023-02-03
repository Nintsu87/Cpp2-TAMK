#include <iostream>
#include <math.h>
using namespace std;

// asks user a value and tell which numbers it's inbetween
int main() {
	// open finnish charset
	setlocale(LC_ALL, "fi_FI"); 

	double double_number = NULL;
	int	round_up = NULL, 
		round_down = NULL;

	// asking number from the user
	cout << "Anna luku: ";
	cin >> double_number;
	// rounding up and down
	round_up = ceil(double_number);
	round_down = floor(double_number);

	// if both roundings are same its either not double or something else is wrong
	if (round_up == round_down) {
		cout << "Et antanut desimaalilukua tai käytit pilkkua pisteen sijasta.\n";
	}
	// tells inbetween which numbers the input value is
	else {
		cout << "Luku " << double_number << " on " << round_down << " ja " << round_up << " välillä.\n";
	}

	return 0;
}
