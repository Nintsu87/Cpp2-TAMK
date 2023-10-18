#pragma once
#include <string>
#include <iostream>
using namespace std;

class Osoite
{
public:
	Osoite();
	Osoite(const Osoite&);
	Osoite(const string& aKatu, const string& aPostinumero, const string& aKunta);
	~Osoite();
	string getKatu() const,
		getPostinumero() const,
		getKunta() const;
	void setKatu(const string& aKatu),
		setPostinumero(const string& aPostinumero),
		setKunta(const string& aKunta),
		tulostaOsoite() const;

private:
	string katu,
		postinumero,
		kunta;
};
