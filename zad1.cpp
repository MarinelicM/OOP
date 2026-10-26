#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void input_vector(vector<int>& v) {
	int broj;
	do {
		cout << "Unesite broj (0 za kraj): ";
		cin >> broj;

		if (broj != 0) {
			v.push_back(broj);
		}
	} while (broj != 0);
}

int main() {
	vector<int> v;
	int k;
	input_vector(v);
	do {
		cout << "Unesite k (mora biti ve?i od 0): ";
		cin >> k;
	} while (k <= 0);

	auto negativan = [](int x) {return x < 0;};
	auto visekratnik = [&](int x) {return x % k == 0; };

	int broj_negativnih = count_if(v.begin(), v.end(), negativan);
	cout << "Broj negativnih brojeva: "<< broj_negativnih << endl;
	auto prvi_visekratnik = find_if(v.begin(), v.end(), visekratnik);
	cout << "Prvi visekratnik: " << *prvi_visekratnik<<" (Pozicija: "<< prvi_visekratnik - v.begin() <<")" << endl;

	auto najmanji = min_element(v.begin(), v.end());
	cout << "Najmanji broj: " << *najmanji <<" (Pozicija: "<< najmanji - v.begin()<<")" << endl;

	auto najveci = max_element(v.begin(), v.end());
	cout << "Najveci broj: " << *najveci <<" (Pozicija: "<< najveci - v.begin() <<")"<< endl;

	v.erase(remove_if(v.begin(), v.end(), visekratnik), v.end());
	cout << "Vektor bez visekratnika: ";
	for (int x : v) {
		cout << x << " ";
	}
}
