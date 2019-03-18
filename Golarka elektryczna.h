#pragma once
#include <iostream>
#include <string>

#include "Akumulator.h"
#include "Glowica.h"
#include "Obudowa.h"

using namespace std;

class GolarkaElektryczna
{
public:
	GolarkaElektryczna();
	GolarkaElektryczna(string, string, bool, unsigned int, unsigned int);
	GolarkaElektryczna(string, string, bool, unsigned int, unsigned int, unsigned int, unsigned int, string, string, string, unsigned int);
	GolarkaElektryczna(const GolarkaElektryczna&);
	~GolarkaElektryczna();

	void ustawProducenta(string); // ustawia producenta
	void ustawModel(string); // ustawia model
	void wlaczGolarke()
	{
		stan = 1; // wlacza golarke
	}
	void wylaczGolarke()
	{
		stan = 0; // wylacza golarke
	}
	void ustawWage(unsigned int); // ustawia wage
	void ustawCene(unsigned int); // ustawia cene

	string zwrocProducenta()
	{
		return producent; // zwraca producenta
	}
	string zwrocModel()
	{
		return model; // zwraca model
	}
	bool zwrocStan()
	{
		return stan; // zwraca stan golarki (wlaczona czy wylaczona - true or false)
	}
	unsigned int zwrocWage()
	{
		return waga; // zwraca wage
	}
	unsigned int zwrocCene()
	{
		return cena; // zwraca cene
	}
	static unsigned int ileStworzonychGolarek()
	{
		return licznik_stworzonych_golarek; // statyczna metoda zwracajaca liczbe wszystkich stworzonych golarek
	}
	static unsigned int ileAktualnieIstniejacychGolarek()
	{
		return licznik_aktualnie_istniejacych_golarek; // statyczna metoda zwracajaca liczbe aktualnie istniejacych golarek
	}

	unsigned int zwrocPojemnoscAkumulatora()
	{
		return akumulator.zwrocPojemnosc(); // zwraca pojemnosc akumulatora
	}
	unsigned int zwrocSprawnoscAkumulatora()
	{
		return akumulator.zwrocSprawnosc(); // zwraca sprawnosc akumulatora
	}
	string zwrocElektrolitAkumulatora()
	{
		return akumulator.zwrocElektrolit(); // zwraca elektrolit akumulatora
	}
	
	string zwrocMaterialObudowy()
	{
		return obudowa.zwrocMaterial(); // zwraca material obudowy
	}
	string zwrocKolorObudowy()
	{
		return obudowa.zwrocKolor(); // zwraca kolor obudowy
	}
	unsigned int zwrocLiczbePrzyciskowObudowy()
	{
		return obudowa.zwrocLiczbePrzyciskow(); // zwraca liczbe przyciskow obudowy
	}

	void opiszAkumulator() const; // wyswietla informacje o akumulatorze
	void opiszObudowe() const; // wyswietla informacje o obudowie
	string czyWlaczona() const; // zwraca stan golarki

	void zainstalujGlowice(unsigned int, unsigned int, unsigned int); // dynamicznie tworzy obiekt glowica
	void opiszGlowice() const; // wyswietla informacje o glowicy
	void usunGlowice(); // usuwa obiekt glowica

	GolarkaElektryczna& operator = (const GolarkaElektryczna&); // operator przypisania
	GolarkaElektryczna& operator - (const Obudowa&); // zamienia obudowe i zwraca nowa golarke
	GolarkaElektryczna& operator += (const Akumulator&); // podmienia akumulator 

	friend ostream& operator << (ostream&, const GolarkaElektryczna&); // wyswietla informacje o golarce i jej "parametrach"

	operator int()
	{
		return cena; // konwertuje typ zmiennej "cena" na int
	}

private:
	string producent;
	string model;
	bool stan;
	unsigned int waga;
	unsigned int cena;
	static unsigned int licznik_stworzonych_golarek;
	static unsigned int licznik_aktualnie_istniejacych_golarek;

	Akumulator akumulator;
	Obudowa obudowa;
	Glowica* glowica;
};