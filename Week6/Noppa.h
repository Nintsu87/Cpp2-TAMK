#pragma once
#include <random>
#include <iostream>
#include <time.h>
#include <vector>

class Noppa {
public:
	Noppa();
	Noppa(int);

	std::vector<int>  getViimeisinLukema();
	int getNoppienLukumaara();
	void setNoppienLukumaara(int);
	void heitaNoppaa();
	void kerroViimeisenHeitonLukema();

private:
	int 
		mNoppa_maara = 0,
		mYhteensa = 0;
	std::vector<int> mViimeisin_lukema;
};