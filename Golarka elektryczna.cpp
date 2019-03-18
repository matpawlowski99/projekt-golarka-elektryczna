#include "Golarka elektryczna.h"
#include <iostream>

using namespace std;

unsigned int GolarkaElektryczna::licznik_stworzonych_golarek = 0;
unsigned int GolarkaElektryczna::licznik_aktualnie_istniejacych_golarek = 0;

GolarkaElektryczna::GolarkaElektryczna()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = "brak danych";
	model = "brak danych";
	stan = 0;
	waga = 0;
	cena = 0;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = producent_golarki;
	model = model_golarki;
	stan = stan_golarki;
	waga = waga_golarki;
	cena = cena_golarki;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(string producent_golarki, string model_golarki, bool stan_golarki, unsigned int waga_golarki, unsigned int cena_golarki, // golarka elektryczna
	                                   unsigned int pojemnosc_akumulatora, unsigned int sprawnosc_akumulatora, string elektrolit_akumulatora, // akumulator
	                                   string material_obudowy, string kolor_obudowy, unsigned int liczba_przyciskow_obudowy) : // obudowa
                                       akumulator(pojemnosc_akumulatora, sprawnosc_akumulatora, elektrolit_akumulatora),
	                                   obudowa(material_obudowy, kolor_obudowy, liczba_przyciskow_obudowy)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = producent_golarki;
	model = model_golarki;
	stan = stan_golarki;
	waga = waga_golarki;
	cena = cena_golarki;

	glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::GolarkaElektryczna(const GolarkaElektryczna& gol)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	producent = gol.producent;
	model = gol.model;
	stan = gol.stan;
	waga = gol.waga;
	cena = gol.cena;

	akumulator = gol.akumulator;
	obudowa = gol.obudowa;

	if (gol.glowica != nullptr)
		glowica = new Glowica(*(gol.glowica));
	else
		glowica = nullptr;
	licznik_stworzonych_golarek++;
	licznik_aktualnie_istniejacych_golarek++;
}

GolarkaElektryczna::~GolarkaElektryczna()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY GOLARKA ELEKTRYCZNA" << endl;
#endif

	delete glowica;
	glowica = nullptr;
	licznik_aktualnie_istniejacych_golarek--;
}

void GolarkaElektryczna::ustawProducenta(string producent_gol)
{
	producent = producent_gol;
}

void GolarkaElektryczna::ustawModel(string model_gol)
{
	model = model_gol;
}

void GolarkaElektryczna::ustawWage(unsigned int waga_gol)
{
	waga = waga_gol;
}

void GolarkaElektryczna::ustawCene(unsigned int cena_gol)
{
	cena = cena_gol;
}

void GolarkaElektryczna::opiszAkumulator() const
{
	cout << akumulator;
}

void GolarkaElektryczna::opiszObudowe() const
{
	cout << obudowa;
}

string GolarkaElektryczna::czyWlaczona() const
{
	if (stan)
		return string("Golarka wlaczona");
	else
		return string("Golarka wylaczona");
}

void GolarkaElektryczna::zainstalujGlowice(unsigned int liczba_glowic_g, unsigned int liczba_oslonek_g, unsigned int liczba_nozykow_g)
{
	if (glowica != nullptr)
		cout << "Golarka jest juz zainstalowana" << endl;
	else
	{
		glowica = new Glowica(liczba_glowic_g, liczba_oslonek_g, liczba_nozykow_g);
		cout << "Zainstalowano glowice" << endl;
	}
}

void GolarkaElektryczna::opiszGlowice() const
{
	if (glowica != nullptr)
		cout << *glowica;
	else
		cout << "Zadna glowica nie jest zainstalowana" << endl;
}

void GolarkaElektryczna::usunGlowice()
{
	if (glowica != nullptr)
	{
		cout << "Usunieto glowice" << endl;
		delete glowica;
		glowica = nullptr;
	}
	else
		cout << "Zadna glowica nie jest zainstalowana" << endl;
}

GolarkaElektryczna& GolarkaElektryczna::operator = (const GolarkaElektryczna& gol)
{
	if (this == &gol)
		return *this;
	else
	{
		producent = gol.producent;
		model = gol.model;
		stan = gol.stan;
		waga = gol.waga;
		cena = gol.cena;
		akumulator = gol.akumulator;
		obudowa = gol.obudowa;

		if (gol.glowica != nullptr)
			glowica = new Glowica(*(gol.glowica));
		else
			glowica = nullptr;
		return *this;
	}
}

GolarkaElektryczna& GolarkaElektryczna::operator - (const Obudowa& o)
{
	obudowa = o;
	return *this;
}

GolarkaElektryczna& GolarkaElektryczna::operator += (const Akumulator& a)
{
	akumulator = a;
	return *this;
}

ostream& operator << (ostream& os, const GolarkaElektryczna& gol)
{
	 os << "Informacje o golarce elektrycznej: " << endl
		<< "\tProducent: " << gol.producent << endl
		<< "\tModel: " << gol.model << endl
		<< "\tStan: " << gol.stan << endl
		<< "\tWaga: " << gol.waga << " g" << endl
		<< "\tCena: " << gol.cena << " zl" << endl
		<< gol.akumulator // wypisuje informacje o akumulatorze
		<< gol.obudowa; // wypisuje informacje o obudowie
	return os;
}