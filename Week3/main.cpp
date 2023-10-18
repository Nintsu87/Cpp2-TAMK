#include "Kalenterimerkinta.h"
using namespace std;


int main() {
	Kalenterimerkinta merkinta1 = Kalenterimerkinta();
	Kalenterimerkinta merkinta2 = Kalenterimerkinta(Paivays(23, 11, 1987), "synket", true);
	Kalenterimerkinta merkinta3;
	merkinta3.kysyTiedot();

	merkinta1.tulostaMerkinta();
	merkinta2.tulostaMerkinta();
	merkinta3.tulostaMerkinta();

	return EXIT_SUCCESS;
}
