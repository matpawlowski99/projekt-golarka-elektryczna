#include <iostream>
#include "Golarka elektryczna.h"

using namespace std;

void testujKlasy();
void testujOperatory();



int main()
{
#ifdef _DEBUG
	cout << "*******************************************************" << endl << endl;

	testujKlasy();
	testujOperatory();
#endif
}