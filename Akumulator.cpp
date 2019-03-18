#include "Akumulator.h"
#include <iostream>

using namespace std;

Akumulator::Akumulator()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif

	pojemnosc = 0;
	sprawnosc = 0;
	elektrolit = "brak danych";
}

Akumulator::Akumulator(unsigned int pojemnosc_a, unsigned int sprawnosc_a, string elektrolit_a)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif

	pojemnosc = pojemnosc_a;
	sprawnosc = sprawnosc_a;
	elektrolit = elektrolit_a;
}

Akumulator::Akumulator(const Akumulator& a)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY AKUMULATOR" << endl;
#endif
	pojemnosc = a.pojemnosc;
	sprawnosc = a.sprawnosc;
	elektrolit = a.elektrolit;
}

Akumulator::~Akumulator()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY AKUMULATOR" << endl;
#endif
}

void Akumulator::ustawPojemnosc(unsigned int pojemnosc_a)
{
	pojemnosc = pojemnosc_a;
}

void Akumulator::ustawSprawnosc(unsigned int sprawnosc_a)
{
	sprawnosc = sprawnosc_a;
}

void Akumulator::ustawElektrolit(string elektrolit_a)
{
	elektrolit = elektrolit_a;
}

bool Akumulator::operator == (const Akumulator& a) const
{
	if (pojemnosc == a.pojemnosc && sprawnosc == a.sprawnosc && elektrolit == a.elektrolit)
		return true;
	else
		return false;
}

bool Akumulator::operator < (const Akumulator& a) const
{
	if (sprawnosc < a.sprawnosc)
		return true;
	else
		return false;
}

bool Akumulator::operator > (const Akumulator& a) const
{
	if (sprawnosc > a.sprawnosc)
		return true;
	else
		return false;
}

ostream& operator << (ostream& os, const Akumulator& a)
{
	os << "Specyfikacja akumulatora:" << endl
	   << "\tPojemnosc: " << a.pojemnosc << " Ah" << endl
	   << "\tSprawnosc: " << a.sprawnosc << " %" << endl
	   << "\tElektrolit: " << a.elektrolit << endl;
	return os;
}