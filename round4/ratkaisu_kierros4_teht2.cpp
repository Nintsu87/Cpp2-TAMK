#include <iostream>;
#include <string>;
#include <fstream>;
using namespace std;


int main() {
	// create .txt file data copying object
	ifstream infile;
	int number, 
		counter = 0, 
		sum = 0;
	double avrg;


	// open the file for copying
	infile.open("Random.txt");

	// if file is open
	if (infile) {

		// add to counter and sum up while there is ints
		while (infile >> number) {
			counter++;
			sum += number;
		}

		// close the file after reading
		infile.close();

		// count average of the numbers
		avrg = static_cast<double>(sum) / counter;

		// tell the user what was counted
		cout << "A) Count of numbers in the file: " << counter << endl 
			<< "B) Sum of numbers in the file: " << sum << endl 
			<< "C) Average of numbers in the file: " << avrg;
	}

	// if opening file had issues, tell user
	else {
		cout << "Can't open the file.";
	}
	return 0;
}
