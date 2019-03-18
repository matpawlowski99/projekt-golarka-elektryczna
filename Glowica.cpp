#include "Glowica.h"
#include <iostream>

using namespace std;

Glowica::Glowica()
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GLOWICA" << endl;
#endif

	liczba_glowic = 0;
	liczba_oslonek = 0;
	liczba_nozykow = 0;
}

Glowica::Glowica(unsigned int liczba_glowic_g, unsigned int liczba_oslonek_g, unsigned int liczba_nozykow_g)
{
#ifdef _DEBUG
	cout << "UTWORZONO OBIEKT KLASY GLOWICA" << endl;
#endif

	liczba_glowic = liczba_glowic_g;
	liczba_oslonek = liczba_oslonek_g;
	liczba_nozykow = liczba_nozykow_g;
}

Glowica::~Glowica()
{
#ifdef _DEBUG
	cout << "USUNIETO OBIEKT KLASY GLOWICA" << endl;
#endif
}

void Glowica::ustawLiczbeGlowic(unsigned int liczba_glowic_g)
{
	liczba_glowic = liczba_glowic_g;
}

void Glowica::ustawLiczbeOslonek(unsigned int liczba_oslonek_g)
{
	liczba_oslonek = liczba_oslonek_g;
}

void Glowica::ustawLiczbeNozykow(unsigned int liczba_nozykow_g)
{
	liczba_nozykow = liczba_nozykow_g;
}

bool Glowica::operator <= (const Glowica& g) const
{
	if (liczba_glowic <= g.liczba_glowic)
		return true;
	else
		return false;
}

bool Glowica::operator >= (const Glowica& g) const
{
	if (liczba_glowic >= g.liczba_glowic)
		return true;
	else
		return false;
}

ostream& operator << (ostream& os, const Glowica& g)
{
	os << "Specyfikacja glowicy:" << endl
	   << "\tLiczba glowic: " << g.liczba_glowic << endl
	   << "\tLiczba oslonek: " << g.liczba_oslonek << endl
	   << "\tLiczba nozykow: " << g.liczba_nozykow << endl;
	return os;
}