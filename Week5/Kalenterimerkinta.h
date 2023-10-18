#pragma once
#include "Paivays.h"
#include <string>
using std::string;

class Kalenterimerkinta {
public:
	Kalenterimerkinta();
	Kalenterimerkinta(const Paivays&, const string&, bool);
	Kalenterimerkinta(const Kalenterimerkinta&);
	~Kalenterimerkinta();
	void setPaivays(const Paivays&);
	void setAsia(const string&);
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