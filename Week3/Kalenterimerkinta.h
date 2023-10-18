#pragma once
#include "Paivays.h"
#include <string>
using std::string;

class Kalenterimerkinta {
public:
	Kalenterimerkinta();
	Kalenterimerkinta(Paivays, string, bool);
	~Kalenterimerkinta();
	void setPaivays(Paivays);
	void setAsia(string);
	void setMuistutus(bool);
	Paivays getPaivays() const;
	string getAsia() const;
	bool getMuistutus() const;
	void tulostaMerkinta() const;
	void kysyTiedot();

private:
	Paivays mPaivays;
	string mAsia;
	bool mMuistutus;
};