#include <iostream>
using namespace std;

int main() {
	int variable; // create unassigned int variable
	int* variable_p = &variable; // create pointer variable from int variable
	*variable_p = 7;
	
	// testing to use pointers back and forward like in the task description.
	cout << "muuttuja = " << variable << endl
		<< "muuttuja_p = " << variable_p << endl
		<< "&muuttuja = " << &variable << endl
		<< "&muuttuja_p = " << &variable_p << endl
		<< "*&muuttuja = " << *&variable << endl
		<< "&*muuttuja_p = " << &*variable_p << endl
		<< "sizeof(muuttuja) = " << sizeof(variable) << endl
		<< "sizeof(muuttuja_p) = " << sizeof(variable_p) << endl;

		/* I also tested nullptr, but it doesnt let me run it so i let it here in the comment
		not assigned int variable give me some weird number of -80000 or something like that and 
		I assume the address it printed was something "random".
		int none_variable;
		int* none_variable_p = nullptr;
		*/
	
	return 0;
}
