#include <iostream>
using namespace std;

bool isPrime(int);

int main() {
	int number = NULL,
		sum = 1;
	float percent = NULL;

	// prints all prime numbers between 2-10 000 and counts them
	cout << "Prime numbers: ";
	for (int i = 2; i < 10001; i++) {
		if (isPrime(i)) {
			sum++;
			cout << i << " ";
		}
	}
	// counts percent for how many prime numbers there 1-10 000.
	percent = sum / static_cast<float>(10000) * 100;
	cout << "\nThere is " << sum << " of those and it's " << percent << "%.\n";

	return 0;
}

// looks if given number is prime number
bool isPrime(int number) {
	for (int i = 2; i < number; i++) {
		// if remainder is 0 its not prime
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
