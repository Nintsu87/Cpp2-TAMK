#include <iostream>
#include "Kalenterimerkinta.h"
using namespace std;

Kalenterimerkinta::Kalenterimerkinta() : mPaivays(), mAsia(""), mMuistutus(false)
{
}
Kalenterimerkinta::Kalenterimerkinta(const Paivays& aPaivays, const string& aAsia, bool aMuistutus) : mPaivays(aPaivays), mAsia(aAsia), mMuistutus(aMuistutus)
{
}

Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta)
	: mAsia(aKalenterimerkinta.mAsia), mMuistutus(aKalenterimerkinta.mMuistutus)
{
	cout << "merkintakopio tehty" << endl;
	mPaivays.kysyPaiva();
}

Kalenterimerkinta::~Kalenterimerkinta()
{
	cout << "Kalenterimerkinta vapautettu." << endl;
}

void Kalenterimerkinta::setPaivays(const Paivays& aPaivays)
{
	mPaivays = aPaivays;
}

void Kalenterimerkinta::setAsia(const string& aAsia)
{
	mAsia = aAsia;
}

void Kalenterimerkinta::setMuistutus(bool aMuistutus)
{
	mMuistutus = aMuistutus;
}

Paivays Kalenterimerkinta::getPaivays() const
{
	return mPaivays;
}

string Kalenterimerkinta::getAsia() const
{
	return mAsia;
}

bool Kalenterimerkinta::getMuistutus() const
{
	return mMuistutus;
}

void Kalenterimerkinta::tulostaMerkinta() const
{
	cout << endl << "Paiva: ";
	mPaivays.tulostaPaivays();
	cout << std::endl;
	cout << "Asia: " << mAsia << std::endl;
	cout << "Muistutus: ";
	if (!mMuistutus) {
		std::cout << "ei ";
	}
	std::cout << "paalla." << std::endl;
	
}

void Kalenterimerkinta::kysyTiedot()
{	
	string muistutus = "",
		asia = "";
	mPaivays.kysyPaiva();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Syota asia: ";
	getline(cin, asia);
	mAsia = asia;
	cout << "Muistutus (ei/joo): ";
	getline(cin, muistutus);
	if (muistutus == "joo")
		mMuistutus = true;
	else if (muistutus == "ei")
		mMuistutus = false;
	else
		std::cout << "En tunnistanut komentoa: \"" << muistutus << "\" joten muistutusta ei lisatty." << endl;
}
