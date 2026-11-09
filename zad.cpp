#include <iostream>
using namespace std;
class IntStack {
private:
	int* niz;   
	int n;       
	int kapacitet;

public:
	
	IntStack(int pocetniKapacitet = 2) {
		kapacitet = pocetniKapacitet;
		n= 0;
		niz = new int[kapacitet];
	
	}
	~IntStack() {
		delete[] niz;
	}

	IntStack(const IntStack& objekt) {
		n = objekt.n;
		kapacitet = objekt.kapacitet;
		niz = new int[kapacitet];
		for (int i = 0; i < n; i++) {
			niz[i] = objekt.niz[i];
		}
	}

	void push(int x) {
		if (n == kapacitet) {
			int noviKapacitet = kapacitet * 2;
			int* noviNiz = new int[noviKapacitet];

			for (int i = 0; i < n; i++) {
				noviNiz[i] = niz[i];
			}
			delete[] niz;
			niz = noviNiz;
			kapacitet = noviKapacitet;
		}
		niz[n] = x;
		n++;
	}

	void pop() {
		if (n > 0) {
			n--;
		}
	}

	int top() const {
		if (n == 0) {
			cout << "Stog je prazan!"<<endl;
			return 0;
		}
		return niz[n - 1];
	}

	bool empty() const {
		return n == 0;
	}
	int size() const {
		return n;
	}
	int capacity() const {
		return kapacitet;
	}
};

int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
	cout << '\n';
	return 0;
}
