#include <iostream>
#include "Henkilo.h"
using namespace std;


int main() {
	// testaillaan olioiden toimintaa
	{
		Henkilo hemmo;
		hemmo.tulostaTiedot();

	} // tassa kohtaa pekan pit�isi hajota

	cout << "hemmo on hajotettu aiemmin";

	{
		Henkilo* pekka = new Henkilo{ "pekka", 20 };
		(*pekka).tulostaTiedot();
		//delete(pekka);
	} // pekka ei hajoa kekomuistipaikasta ilman delete-k�sky�, 
	//mutta sen osoittaja hajoaa eli sit� ei en�� voi kutsua

	
	return EXIT_SUCCESS;
}
