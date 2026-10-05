#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	int god, br;
	cout << "Unesite godinu rodenja: ";
	cin >> god;
	cin.ignore();
	string imePrezime;
	cout << "Unesite ime i prezime: ";
	getline(cin, imePrezime);
	int razmak = imePrezime.find(' ');
	cout << imePrezime[0] << "." << imePrezime[razmak + 1]<<endl;
	br = 0;
	for (int i : imePrezime) {
		br++;
	}
	cout << br - 1<<endl;
	cout << "Osoba ove godine navrsava " << 2026 - god << " godina!";
}