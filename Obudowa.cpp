#include "Obudowa.h"
#include <iostream>

using namespace std;

Obudowa::Obudowa()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY OBUDOWA" << endl;
#endif

	material = "brak danych";
	kolor = "brak danych";
	liczba_przyciskow = 0;
}

Obudowa::Obudowa(string material_o, string kolor_o, unsigned int liczba_przyciskow_o)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY OBUDOWA" << endl;
#endif

	material = material_o;
	kolor = kolor_o;
	liczba_przyciskow = liczba_przyciskow_o;
}

Obudowa::~Obudowa()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY OBUDOWA" << endl;
#endif
}

void Obudowa::ustawMaterial(string material_o)
{
	material = material_o;
}

void Obudowa::ustawKolor(string kolor_o)
{
	kolor = kolor_o;
}

void Obudowa::ustawLiczbePrzyciskow(unsigned int liczba_przyciskow_o)
{
	liczba_przyciskow = liczba_przyciskow_o;
}

Obudowa& Obudowa::operator++()
{
	liczba_przyciskow++;
	return *this;
}

ostream& operator << (ostream& os, const Obudowa& o)
{
	 os << "Specyfikacja obudowy:" << endl
		<< "\tMaterial: " << o.material << endl
		<< "\tKolor: " << o.kolor << endl
		<< "\tLiczba przyciskow: " << o.liczba_przyciskow << endl;
	return os;
}