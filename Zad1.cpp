#include <iostream>
using namespace std;
#define MAX(a, b) a > b ? a : b
inline int mymax(int a, int b) {
	return (a > b) ? a : b;
}
template<typename T>
T mymax2(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}

int main(){
	int a = MAX(3, 5);
	int b = 2 * (MAX(3, 5));
	int c = MAX(3, 5) + 1;
	int i = 3;
	int d = MAX(++i, 2);
	cout << a<<endl;
	cout << b << endl;
	cout << c << endl;
	cout << "Poziv za MAX: "<<d << endl;
	cout << "Poziv za mymax: " << mymax(++i, 2);
	cout <<"Poziv za int: "<< mymax2(5, 2) << endl;
	cout << "Poziv za double: " << mymax2(1.5, 3.2) << endl;
	cout << "Poziv za char: " << mymax2('e','z') << endl;
	cout << "Poziv za string: " << mymax2("ana", "pero") << endl;
}