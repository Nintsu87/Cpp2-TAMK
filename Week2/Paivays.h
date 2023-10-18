#pragma once

class Paivays {
public:
	// Rakentaja (Constructor): 
	// - Metodi, jonka tehtävä on alustaa olio
	// - on aina saman niminen kuin luokka
	// - ei ole paluuarvoa
	Paivays();
	Paivays(int, int, int);


	// Purkaja (Destructor):
	~Paivays();

	void setPaiva(int);
	void setKuukausi(int);
	void setVuosi(int);
	int getPaiva();
	int getKuukausi();
	int getVuosi();
	void tulostaPaivays();
	void lisaaPaiva();
	void kysyPaiva();
private:
	int paiva,
		kuukausi,
		vuosi;
};