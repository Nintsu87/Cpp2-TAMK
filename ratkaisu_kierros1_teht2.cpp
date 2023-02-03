#include <iostream>
using namespace std;

//* this is done with pointer variable (osoitinparametrimekanismi)
void swap(int* swap1, int* swap2) {
	int helper = *swap1;
	*swap1 = *swap2;
	*swap2 = helper;
}

// this is done with reference variable (viittausparametrimekanismi)
void swap2(int &swap1, int &swap2) {
	int helper = swap1;
	swap1 = swap2;
	swap2 = helper;
}



int main() {
	int number1 = 1, number2 = 2; // create swappable variables
	cout << "Before swaps: #1: " << number1 << " #2: " << number2;
	swap(number1, number2); // swap them once with pointers
	cout << "\nAfter pointer swap: #1: " << number1 << " #2: " << number2 << endl;
	swap2(number1, number2); // swap them once with reference
	cout << "After referencew swap: #1: " << number1 << " #2: " << number2 << endl;
	return 0;
}