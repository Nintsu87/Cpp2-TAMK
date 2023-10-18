#pragma once
#include <string>
#include <iostream>
using namespace std;

class Osoite
{
public:
	Osoite();
	Osoite(string aKatu, string aPostinumero, string aKunta);
	string getKatu() const,
		getPostinumero() const,
		getKunta() const;
	void setKatu(string aKatu),
		setPostinumero(string aPostinumero),
		setKunta(string aKunta),
		tulostaOsoite() const;

private:
	string katu,
		postinumero,
		kunta;
};
