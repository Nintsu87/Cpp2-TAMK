#include "Noppa.h"

Noppa::Noppa() : mNoppa_maara(1) 
{
	srand(time(0)); 
	heitaNoppaa();
}

Noppa::Noppa(int aNoppa_maara) : mNoppa_maara(aNoppa_maara)
{
	srand(time(0));
	heitaNoppaa();
}

std::vector<int> Noppa::getViimeisinLukema()
{
	return mViimeisin_lukema;
}

int Noppa::getNoppienLukumaara()
{
	return mNoppa_maara;
}

void Noppa::setNoppienLukumaara(int aNoppa_maara)
{
	mNoppa_maara = aNoppa_maara;
}

void Noppa::heitaNoppaa()
{	

	for (int i = 0; i < mNoppa_maara; i++) {
		int random_numero = rand() % 6 + 1;
		mViimeisin_lukema.push_back(random_numero);
	}
	
}

void Noppa::kerroViimeisenHeitonLukema()
{	
	if (mNoppa_maara == 1) {
		for (int i = 0; i < mNoppa_maara; i++) {
			std::cout << "Viimeisin heitto: " << mViimeisin_lukema[i] << std::endl;
		}
	}
	else {
		for (int i = 0; i < mNoppa_maara; i++) {
			std::cout << "Viimeisin heitto " << i + 1 << ". noppa: " << mViimeisin_lukema[i] << std::endl;
			mYhteensa += mViimeisin_lukema[i];
		}
		std::cout << "Yhteensa: " << mYhteensa << std::endl;
		mYhteensa = 0;
	}
	
}
