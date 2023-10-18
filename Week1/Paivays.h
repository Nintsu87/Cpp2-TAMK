#pragma once

class Paivays {
public:
	void setPaiva(int aPaiva);
	void setKuukausi(int aKuukausi);
	void setVuosi(int aVuosi);
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