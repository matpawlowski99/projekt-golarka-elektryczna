#pragma once
#include <iostream>
#include <string>

using namespace std;

class Glowica
{
public:
	Glowica();
	Glowica(unsigned int, unsigned int, unsigned int);
	~Glowica();

	void ustawLiczbeGlowic(unsigned int); // ustawia liczbe glowic
	void ustawLiczbeOslonek(unsigned int); // ustawia liczbe oslonek
	void ustawLiczbeNozykow(unsigned int); // ustawia liczbe nozykow

	unsigned int zwrocLiczbeGlowic() const
	{
		return liczba_glowic; // zwraca liczbe glowic
	}
	unsigned int zwrocLiczbeOslonek() const
	{
		return liczba_oslonek; // zwraca liczbe oslonek
	}
	unsigned int zwrocLiczbeNozykow() const
	{
		return liczba_nozykow; // zwraca liczbe nozykow
	}

	bool operator <= (const Glowica&) const; // porownuje liczbe glowic
	bool operator >= (const Glowica&) const; // porownuje liczbe glowic
	
	friend ostream& operator << (ostream&, const Glowica&); // wyswietla informacje o glowicy

private:
	unsigned int liczba_glowic;
	unsigned int liczba_oslonek;
	unsigned int liczba_nozykow;
};