#include "iostream"
using namespace std;

const int SIZE = 1026670;

// const int SIZE = 1026671; <-- gives an error
// therefore biggest size of array is 1Mbytes on my set up

char gArray[SIZE] = {};

void m();
void m2();

int main()
{
	m();
	return 0;
}

void m()
{
	char array[SIZE] = {};

	m2();
}

void m2()
{
	char* array_p = new char[SIZE];

	delete[] array_p;
	array_p = nullptr;
}
