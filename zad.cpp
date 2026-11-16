// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Money {
private:
	int centsTotal;
public:
	Money(int euros = 0, int cents = 0) {
		centsTotal = euros * 100 + cents;
	}

	Money& operator+=(const Money& other) {
		centsTotal += other.centsTotal;
		return *this;
	}

	friend Money operator+(const Money& a, const Money& b) {
		Money result = a;
		result += b;
		return result;
	}

	friend bool operator<(const Money& a, const Money& b) {
		return a.centsTotal < b.centsTotal;
	}
	friend ostream& operator<<(ostream& out, const Money& m) {
		out << m.centsTotal / 100 << ".";

		if (m.centsTotal % 100 < 10)
			out << "0";

		out << m.centsTotal % 100 << " EUR";

		return out;
	}
	friend istream& operator>>(istream& in, Money& m) {
		int euros, cents;
		char separator;

		if (in >> euros >> separator >> cents) {
			if (separator != '.') {
				in.setstate(ios::failbit);
			}
			else {
				m.centsTotal = euros * 100 + cents;
			}
		}

		return in;
	}
};
int main()
{
	Money a(1, 5);
	Money b(0, 95);
	std::cout << a << " + " << b << " = " << a + b << '\n';

	std::ifstream in("racun.txt");
	if (!in) {
		std::cout << "Datoteka racun.txt ne postoji\n";
		return 1;
	}

	std::string item;
	Money price;
	Money total;
	Money max_price;
	std::string max_item;
	int count = 0;
	while (in >> item >> price) {
		total += price;
		if (max_price < price) {
			max_price = price;
			max_item = item;
		}
		++count;
	}
	if (!in.eof())
		std::cout << "Neispravan zapis: " << item << '\n';
	std::cout << "Stavki: " << count << '\n';
	std::cout << "Ukupno: " << total << '\n';
	std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
	return 0;
}

/*
Ocekivani ispis:

	1.05 EUR + 0.95 EUR = 2.00 EUR
	Neispravan zapis: Sok
	Stavki: 5
	Ukupno: 17.23 EUR
	Najskuplje: Kava 7.99 EUR
*/
