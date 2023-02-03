#include <iostream>
using namespace std;



// prints all array values
void list_print(int lista[10]) {
	for (int i = 0; i < 10; i++) {
		cout << " " << lista[i];
	}
}

//* this is done with pointer variable (osoitinparametrimekanismi)
void swap(int* swap1, int* swap2) {
	int helper = *swap1;
	*swap1 = *swap2;
	*swap2 = helper;
}

int main() {
	const int size = 10; // size of the array
	int index = 9;	// aid variable for swapping
	int list[size]; // array
	// change all array slots to 1 -> 10
	for (int i = 0; i < size; i++) {
		list[i] = i + 1;
	}

	// print the created list
	cout << "Normal:";
	list_print(list);
	
	// swap all values on opposite spots 10 -> 1
	for (int i = 0; i < (size / 2); i++) {
		swap(*(list + i), *(list + (index - i)));
	}

	// print after swap
	cout << "\nTurned:";
	list_print(list);



	return 0;
}