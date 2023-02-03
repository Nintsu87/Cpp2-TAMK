#include <iostream>
using namespace std;

// create enum datatype for different triangles
enum {EPASAA, TASAK, TASAS, SUORAK, TASASUORAK};

// create prototype for function
bool is_it_triangle(int side1, int side2, int side3, int& triangle);


int main() {
	// open finnish charset
	setlocale(LC_ALL, "fi_FI"); 

	int triangle = NULL;
	int side1 = NULL, 
		side2 = NULL, 
		side3 = NULL;
	bool if_triangle = false;

	// asking triangle side lenghts from the user
	cout << "Anna 1. sivun pituus: ";
	cin >> side1;
	cout << "Anna 2. sivun pituus: ";
	cin >> side2;
	cout << "Anna 3. sivun pituus: ";
	cin >> side3;

	//using my function to check if the sides can make a triangle
	if_triangle = is_it_triangle(side1, side2, side3, triangle);

	if (if_triangle) {
		cout << "Annetuista sivuista voidaan muodostaa ";
		// checking enum result if_triangle -function created in triangle variable
		// and tells which kind of triangle it is to the user
		switch (triangle) {
			case 0:
				cout << "epäsäännöllisen kolmion.\n"; 
				break;
			case 1: 
				cout << "tasakylkisen kolmion.\n"; 
				break;
			case 2:
				cout << "tasasivuisen kolmion.\n"; 
				break;
			case 3:
				cout << "suorakulmaisen kolmion.\n"; 
				break;
			case 4:
				cout << "suorakulmaisen tasakylkisen kolmion.\n"; 
				break;
		}

	}
	// lets user know if sides didnt make any triangle.
	else {
		cout << "Sivut eivät muodostaneet kolmioo.\n";
	}
	return 0;
}
// uses int variables to check if sides can make a triangle
// and use enum to tell which kind of triangle
bool is_it_triangle(int side1, int side2, int side3, int& triangle) {
	int helper = 0;
	bool bhelper = false;
	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
		if (side1 != side2 && side1 != side3 && side2 != side3)
			triangle = EPASAA; // scalene triangle

		else if (side1 == side2 && side1 == side3 && side2 == side3)
			triangle = TASAS; // equilateral triangle
		 
		else if (side1 == side2 || side1 == side3 || side2 == side3) {
			triangle = TASAK; // isosceles triangle
			helper++;
		}
		else {
			if (helper == 1)
				triangle = TASASUORAK; // isosceles triangle and right-angled triangle
			else
				triangle = SUORAK; // right-angled triangle
		}
		bhelper = true;
	}


	return bhelper;
}