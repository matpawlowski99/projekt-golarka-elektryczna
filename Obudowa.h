#pragma once
#include <iostream>
#include <string>

using namespace std;

class Obudowa
{
public:
	Obudowa();
	Obudowa(string, string, unsigned int);
	~Obudowa();

	void ustawMaterial(string); // ustawia material
	void ustawKolor(string); // ustawia kolor
	void ustawLiczbePrzyciskow(unsigned int); // ustawia liczbe przyciskow

	string zwrocMaterial() const
	{
		return material; // zwraca material
	}
	string zwrocKolor() const
	{
		return kolor; // zwraca kolor
	}
	unsigned int zwrocLiczbePrzyciskow() const
	{
		return liczba_przyciskow; // zwraca liczbe przyciskow
	}

	Obudowa& operator ++(); // jednoargumentowy operator zwiekszajacy liczbe przyciskow o 1

	friend ostream& operator << (ostream&, const Obudowa&); // wyswietla informacje o obudowie

private:
	string material;
	string kolor;
	unsigned int liczba_przyciskow;
};