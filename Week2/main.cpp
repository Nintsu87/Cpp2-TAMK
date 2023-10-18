#include <iostream>
#include "Henkilo.h"
using namespace std;


int main() {
	// testaillaan olioiden toimintaa
	{
		Henkilo hemmo;
		hemmo.tulostaTiedot();

	} // tassa kohtaa pekan pitäisi hajota

	cout << "hemmo on hajotettu aiemmin";

	{
		Henkilo* pekka = new Henkilo{ "pekka", 20 };
		(*pekka).tulostaTiedot();
		//delete(pekka);
	} // pekka ei hajoa kekomuistipaikasta ilman delete-käskyä, 
	//mutta sen osoittaja hajoaa eli sitä ei enää voi kutsua

	
	return EXIT_SUCCESS;
}
