#pragma once
#include <iostream>
#include <string>

using namespace std;

class Akumulator
{
public:
	Akumulator();
	Akumulator(unsigned int, unsigned int, string);
	Akumulator(const Akumulator&);
	~Akumulator();

	void ustawPojemnosc(unsigned int); // ustawia pojemnosc
	void ustawSprawnosc(unsigned int); // ustawia sprawnosc
	void ustawElektrolit(string); // ustawia elektrolit

	unsigned int zwrocPojemnosc() const
	{
		return pojemnosc; // zwraca pojemnosc
	}
	unsigned int zwrocSprawnosc() const
	{
		return sprawnosc; // zwraca sprawnosc
	}
	string zwrocElektrolit() const
	{
		return elektrolit; // zwraca elektrolit
	}

	bool operator == (const Akumulator&) const; // porownuje wszystkie parametry
	bool operator < (const Akumulator&) const; // porownuje sprawnosc
	bool operator > (const Akumulator&) const; // porownuje sprawnosc
	friend ostream& operator << (ostream&, const Akumulator&); // wyswietla informacje o akumulatorze

private:
	unsigned int pojemnosc;
	unsigned int sprawnosc;
	string elektrolit;
};