#include <iostream>
#include <vector>
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
void print_vector(const vector<int> &v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v;
	input_vector(v);
	cout << "Vektor: ";
	print_vector(v);
	cout << "Vektor obrnutim redoslijedom: ";
	for (auto i = v.rbegin(); i != v.rend(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	vector<int> v1;
	cout<<endl << "Vektor bez reserve():\n";
	for (int i = 1; i <= 20; i++) {
		v1.push_back(i);

		cout << "Nakon push_back: "<< "size = " << v1.size()<< ", capacity = " << v1.capacity() << endl;
	}

	vector<int> v2;
	v2.reserve(100);
	cout<<endl << "Vektor s reserve(100):\n";
	for (int i = 1; i <= 20; i++) {
		v2.push_back(i);

		cout << "Nakon push_back: "<< "size = " << v2.size()<< ", capacity = " << v2.capacity() << endl;
	}
	v2.shrink_to_fit();
	cout <<endl<< "Kapacitet nakon fitanja: "<< v2.capacity() << endl;
}