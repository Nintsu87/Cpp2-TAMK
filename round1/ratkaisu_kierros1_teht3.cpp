#include <iostream>
using namespace std;

// change arrays all values +1 using index iteration
void add_one_with_index(int lista[10]) {
	for (int i = 0; i < 10; i++) {
		lista[i] = lista[i] + 1;
	}
}

// change arrays all values +1 without using index
void add_one_with_pointer(int lista[], int size) {
	for (int i = 0; i < size; i++) {
		*(lista + i) += 1;
	}
}

// prints all array values
void list_print(int lista[10]) {
	for (int i = 0; i < 10; i++) {
		cout << " " << lista[i];
	}
}



int main() {
	const int size = 10; // size of the array
	int list[size]; // array
	// change all array slots to 0
	for (int i = 0; i < 10; i++) {
		list[i] = 0;
	}
	// print the 0 array
	cout << "Zero list: ";
	list_print(list);
	cout << endl;

	// change array values + 1 using index
	add_one_with_index(list);

	// print the changes
	cout << "After index using function: ";
	list_print(list);
	cout << endl;

	// change all array slots back to 0
	for (int i = 0; i < 10; i++) {
		list[i] = 0;
	}

	// print the 0 array
	cout << "Zero list: ";
	list_print(list);
	cout << endl;

	// change array values +1 without index
	add_one_with_pointer(list, size);

	// print changed array
	cout << "After no index using function: ";
	list_print(list);
	cout << endl;

	return 0;
}
