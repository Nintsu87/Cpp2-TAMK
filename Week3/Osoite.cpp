#include "Osoite.h"

Osoite::Osoite() : katu(""), postinumero(""), kunta("")
{
}

Osoite::Osoite(string aKatu, string aPostinumero, string aKunta) : katu(aKatu), postinumero(aPostinumero), kunta(aKunta)
{
}

string Osoite::getKatu() const
{
	return katu;
}

string Osoite::getKunta() const
{
	return kunta;
}

void Osoite::setKatu(string aKatu)
{
	katu = aKatu;
}

void Osoite::setKunta(string aKunta)
{
	kunta = aKunta;
}

void Osoite::setPostinumero(string aPostinumero)
{
	postinumero = aPostinumero;
}

string Osoite::getPostinumero() const
{
	return postinumero;
}

void Osoite::tulostaOsoite() const 
{
	cout << "Osoitetiedot" << endl;
	cout << "Katu: " << katu << endl;
	cout << "Postinumero: " << postinumero << endl;
	cout << "Kunta: " << kunta << endl;
}