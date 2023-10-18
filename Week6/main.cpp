#include "Henkilo.h"
#include "Osoite.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include "Koulu.h"
#include <iostream>
#include <string>
using namespace std;

// tulostaa infotekstin
void tulostaInfo();
Kurssi* luoKurssiOpettajalle();


int main() {

	setlocale(LC_ALL, "fi_FI"); // avataan tulostukseen ‰‰kkˆset
	Koulu tamk{ "tamk" }; // luo tamk koulun
	bool loop = true; // p‰‰loopin avustaja
	bool info = true; // infon tulostuksen avustaja

	while (loop) {
		string komento = "";

		// jos jossain on tapahtunut virhe, ei ohjelma aina tulosta uutta infoa
		if (info) {
			tulostaInfo();
		}
		info = true;

		// kysyt‰‰ k‰ytt‰j‰lt‰ mit‰ halutaan tehd‰ ja toimitaan sen mukaisesti
		cout << "Anna komento: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, komento);

		if (komento == "1") { // lis‰‰ opettaja
			string nimi,
				ala,
				ika,
				katuosoite,
				postinro,
				kunta;
			int ikaNro;
			bool ikaCheck = true;
			// kysyy k‰ytt‰j‰lt‰ opettajan nime‰
			cout << "Anna opettajan nimi: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, nimi);
			// kysyy ik‰‰, kunnes se on int tyyppinen
			while (ikaCheck) {
				cout << "Anna ika: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, ika);
				try {
					ikaNro = stoi(ika);
					ikaCheck = false;
				}
				catch (...) {
					cout << "I‰n pit‰‰ olla kokonaisluku. Yrit‰ uudestaan." << endl;
				}
			}
			// kysyy osoitetietoja
			cout << "Anna katuosoite: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, katuosoite);
			cout << "Anna postinumero: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, postinro);
			cout << "Anna kunta: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, kunta);
			// kysyy koulutusalaa
			cout << "Anna koulutusala: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, ala);
			// luo tallennettavat oliot osoitteelle ja opettajalle.
			Osoite* oso = new Osoite{ katuosoite,postinro,kunta };
			Opettaja* ope = new Opettaja{ nimi, ikaNro, *oso, ala };
			// lis‰‰ valmiiksi luotuun kouluun opettajan
			tamk.lisaaOpettaja(ope);
		}
		else if (komento == "2") { // lis‰‰ opettajalle kurssi
			// ottaa koululta opettajalistan
			vector<Opettaja*> opet = tamk.getOpettajat();
			// jos opettajia on lis‰tty kouluun
			if (opet.size() > 0) {

				string oNimi;
				// tulostaa kaikki opettajat
				cout << "\nOpettajat: " << endl;
				for (Opettaja* o : opet) {
					cout << "- " << o->getNimi() << endl;
				}
				// kysyy kenelle halutaan lis‰t‰ kurssi
				cout << "Kelle haluat lis‰t‰ kurssin?\nAnna opettajan nimi: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, oNimi);
				// k‰y opettajat l‰pi
				for (Opettaja* o : opet) {
					// jos opettajan nimi t‰sm‰‰
					if (o->getNimi() == oNimi) {
						// luo kurssin
						Kurssi* kurssi = luoKurssiOpettajalle();
						// lis‰‰ kurssiin vastuuopettajan
						kurssi->setOpettaja(*o);
						// lis‰‰ opettajalle kurssinimen
						o->lisaaKurssi(kurssi->getNimi());
						// lis‰‰ koululle kurssin
						tamk.lisaaKurssi(kurssi);
					}
				}
			}
			else { // jos ei opettajia, ilmoittaa asiasta k‰ytt‰j‰lle
				cout << "Koulussa ei viel‰ ole opettajia, joille voisi lis‰t‰ kurssin." << endl;
				info = false; // ei infoteksti‰
			}

		}
		else if (komento == "3") { // lis‰‰ oppilas
			string nimi,
				ika,
				opiskelijanumero,
				tutkinto,
				katuosoite,
				postinro,
				kunta;
			int ikaNro;
			bool ikaCheck = true; 
			// pyyt‰‰ oppilaan nime‰
			cout << "Anna oppilaan nimi: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, nimi);
			// kysyy k‰ytt‰j‰lt‰ ik‰‰, kunnes se on int muotoinen
			while (ikaCheck) {
				cout << "Anna ika: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, ika);
				try {
					ikaNro = stoi(ika);
					ikaCheck = false;
				}
				catch (...) {
					cout << "I‰n pit‰‰ olla kokonaisluku. Yrit‰ uudestaan." << endl;
				}
			}
			// pyyt‰‰ osoitetiedot
			cout << "Anna katuosoite: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, katuosoite);
			cout << "Anna postinumero: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, postinro);
			cout << "Anna kunta: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, kunta);
			// pyyt‰‰ loput oppilaan tiedot
			cout << "Anna opiskelijanumero: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, opiskelijanumero);
			cout << "Anna tutkinto: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, tutkinto);
			// luo osoitteen ja opiskelijan
			Osoite* oso = new Osoite{ katuosoite,postinro,kunta };
			Opiskelija* oppija = new Opiskelija(nimi, ikaNro, *oso, opiskelijanumero, tutkinto);
			// lis‰‰ opiskelijan koulun vectoriin
			tamk.lisaaOpiskelija(oppija);
		}
		else if (komento == "4") { // lis‰‰ opiskelijalle kurssi
			string oNimi,
				opeNimi,
				inKomento;
			// ottaa apuvectorit koulun tiedoista
			vector<Kurssi*> kurssit = tamk.getKurssit();
			vector<Opiskelija*> opiskelijat = tamk.getOpiskelijat();
			vector<Opettaja*> opet = tamk.getOpettajat();

			// jos opiskelijoita
			if (opiskelijat.size() > 0) {
				// tulostaa opiskelijoiden nimet
				cout << "Oppilaat: " << endl;
				for (Opiskelija* o : opiskelijat) {
					cout << "- " << o->getNimi() << endl;
				}
				// pyyt‰‰ opiskelijan nimen, jolle lis‰t‰‰n kurssi
				cout << "Kelle haluat lis‰t‰ kurssin?\nAnna opiskelijan nimi: ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, oNimi);
				// jos opiskelijoista lˆytyy t‰m‰n niminen kurssi
				for (Opiskelija* o : opiskelijat) {
					if (o->getNimi() == oNimi) {
						bool opeBool = true;
						// kysyy haluaako lis‰t‰ vai valita olemassaolevan
						if (kurssit.size() > 0) {
							cout << "Haluatko lis‰t‰ vai valita olemassaolevan kurssin?" << endl;
							cout << "1. Lis‰‰" << endl;
							cout << "2. Olemassaoleva" << endl;
							cout << "Anna komento: ";
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, inKomento);

							if (inKomento == "1") { // lis‰‰ uusi kurssi
								// luo uuden kurssin
								Kurssi* kurssi = luoKurssiOpettajalle();
								// jos opettajan nimi on oikein, lis‰‰ kurssille opettajan
								while (opeBool) {
									// tulostaa opettajat
									cout << "Opettajat:" << endl;
									for (Opettaja* o : opet) {
										cout << "- " << o->getNimi() << endl;
									}
									// pyyt‰‰ opettajan nimen, joka lis‰t‰‰n kurssin vastuuopettajaksi
									// kunnes se on oikein
									cout << "Kenet lis‰t‰‰n?\nAnna opettajan nimi: ";
									cin.ignore(cin.rdbuf()->in_avail());
									getline(cin, opeNimi);
									for (Opettaja* o : opet) {
										if (o->getNimi() == opeNimi) {
											kurssi->setOpettaja(*o);
											opeBool = false;
										}
										else {
											cout << "Annoit v‰‰r‰n nimen." << endl;
										}
									}
								}
								// lis‰‰ kurssin oppilaalle
								o->lisaaKurssi(kurssi);
								// lis‰‰ kurssin koululle
								tamk.lisaaKurssi(kurssi);

							}
							else if (inKomento == "2") { // lis‰‰ olemassaolevista kursseista
								string kNimi;
								bool lisaBool = true;
								// tulostaa kurssit
								cout << "Kurssit: " << endl;
								for (Kurssi* k : kurssit) {
									cout << "- " << k->getNimi() << endl;
								}
								// lis‰‰ kurssin opiskelijalle kunnes kurssin nimi t‰sm‰‰
								while (lisaBool) {
									// pyyt‰‰ kurssin nime‰
									cout << "Mik‰ kursseista lis‰t‰‰n?\nAnna kurssin nimi: ";
									cin.ignore(cin.rdbuf()->in_avail());
									getline(cin, kNimi);
									// k‰y l‰pi onko annettua nime‰ kursseissa
									for (Kurssi* k : kurssit) {
										if (k->getNimi() == kNimi) {
											lisaBool = false;
											o->lisaaKurssi(k);
										}
									}
									if (lisaBool) { 
										cout << "Nimi ei t‰sm‰nnyt. Yrit‰ uudelleen." << endl;
									}
								}
							}
						} 
						else { // jos kurssilista on tyhj‰ aloittaa uuden kurssin luomisen
							Kurssi* kurssi = luoKurssiOpettajalle(); // luo kurssin
							while (opeBool) {
								// tulostaa opettajien nimet
								cout << "Opettajat:" << endl;
								for (Opettaja* o : opet) {
									cout << "- " << o->getNimi() << endl;
								}
								// kysyy lis‰tt‰v‰n opettajan nime‰
								cout << "Kenet lis‰t‰‰n?\nAnna opettajan nimi: ";
								cin.ignore(cin.rdbuf()->in_avail());
								getline(cin, opeNimi);
								// lis‰‰ kurssille opettajan jos nimi t‰sm‰‰
								for (Opettaja* o : opet) {
									if (o->getNimi() == opeNimi) {
										kurssi->setOpettaja(*o);
										opeBool = false;
									}
									else {
										cout << "Annoit v‰‰r‰n nimen." << endl;
									}
								}
							}
							// lis‰‰ oppilaalle kurssin.
							o->lisaaKurssi(kurssi);
						}
					}
				}
			}
			else {
				cout << "* Koulun opiskelijalista on tyhj‰." << endl;
			}
		}
		else if (komento == "5") { // tulostaa koulun opettajat
			tamk.tulostaOpettajat();
		}
		else if (komento == "6") { // tulostaa koulun oppilaat
			tamk.tulostaOpiskelijat();
		}
		else if (komento == "7") { // tulostaa koulun kurssit
			tamk.tulostaKurssit();
		}
		else if (komento == "8") { // tulostaa koulun kaikki tiedot
			tamk.tulostaKaikkiTeidot();
		}

		else if (komento == "0") { // lopettaa ohjelman
			loop = false;
		}
		else { // jos komento on hˆpˆ, ilmoittaa siit‰ k‰ytt‰j‰lle
			cout << "Komento " << komento << " v‰‰r‰. Yrit‰ uudelleen." << endl;
			info = false;
		}
	}
	// ohjelma loppuu
	cout << "Kiitos ohjelman k‰ytˆst‰!" << endl;

	return EXIT_SUCCESS;
}

// tulostaa infotekstin
void tulostaInfo() {
	cout << "\n1. Lis‰‰ opettaja" << endl;
	cout << "2. Lis‰‰ opettajalle kurssi" << endl;
	cout << "3. Lis‰‰ oppilas" << endl;
	cout << "4. Lis‰‰ oppilaalle kurssi" << endl;
	cout << "5. Tulosta opettajat" << endl;
	cout << "6. Tulosta oppilaat" << endl;
	cout << "7. Tulosta opetettavat kurssit" << endl;
	cout << "8. Tulosta koulun tiedot" << endl;
	cout << "0. Lopeta" << endl;
}
// luo kurssin ilman lis‰tty‰ opettajaa
Kurssi* luoKurssiOpettajalle() {
	string knimi,
		tunnus,
		ala,
		laajuus;
	Paivays alkupva,
		loppupva;
	int laajuusNro;
	bool laajuusCheck = true;
	// pyyt‰‰ kurssin tiedot
	cout << "Anna kurssin nimi: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, knimi);
	cout << "Anna kurssitunnus: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, tunnus);
	cout << "Anna ala: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, ala);
	// tarkistaa onko laajuus int muotoinen
	while (laajuusCheck) {
		cout << "Anna laajuus (op): ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, laajuus);
		try {
			laajuusNro = stoi(laajuus);
			laajuusCheck = false;
		}
		catch (...) {
			cout << laajuus << " ei ole kokonaisluku. Yrit‰ uudelleen." << endl;
		}
	}
	// luo kurssin p‰iv‰ykset
	cout << "Aloitusp‰iv‰: " << endl;
	alkupva.kysyPaiva();
	cout << "Lopetusp‰iv‰: " << endl;
	loppupva.kysyPaiva();
	// luo kurssin annetuista tiedoista
	Kurssi* kurssi = new Kurssi{ knimi,tunnus,ala,laajuusNro,alkupva,loppupva };
	// palauttaa p‰‰koodiin luodun kurssin osoitteen
	return kurssi;
}

