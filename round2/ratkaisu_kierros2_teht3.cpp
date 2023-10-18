#include <iostream>
#include <algorithm>
using namespace std;

int min(int x, int y);
int min(int x, int y, int z);
int min(int x, int y, int z, int w);

int main() {
	int small1 = 4,
		small2 = 3,
		small3 = 2,
		small4 = 1;
	// example prints to show functions work
	cout << "int min(int x=4, int y=3) returns: " << min(small1, small2) << endl;
	cout << "int min(int x=4, int y=3, int z=2) returns: " << min(small1, small2, small3) << endl;
	cout << "int min(int x=4, int y=3, int z=2, int w=1) returns: " << min(small1, small2, small3, small4) << endl;


	return 0;
}

// i'm aware with algorithm i can use std::min() function here
// i'm also aware its better to use only one return, but for simple function i find this is better.
// compaires if x or y is smaller
int min(int x, int y) {
	if (x < y)
		return x;
	return y;
}

// compaires which of the given integers is smallest using same name function
int min(int x, int y, int z) {
	int helper = min(x, y);
	return min(helper, z);
}
// compaires which of the given integers is smallest using same name function which calls function
int min(int x, int y, int z, int w) {
	int helper = min(x, y, z);
	return min(helper, w);
}
