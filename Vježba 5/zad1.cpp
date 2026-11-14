#include <cassert>
#include <iostream>
using namespace std;

class Volume {
	int glasnoca;
	int prijeMute;
	static int ogranicenje(int l) {
		if (l < 0) {
			l = 0;
		}
		else if (l > 100){ 
			l = 100; 
		}
		return l;
	}

public:
	Volume(int l) {
		glasnoca = ogranicenje(l);
		prijeMute = glasnoca;
		assert(valid());
	}

	Volume() {
		glasnoca = 50;
		prijeMute = 50;
	}
	void up(int step = 10) {
		glasnoca = ogranicenje(glasnoca + step);
		assert(valid());
	}

	void down(int step = 10) {
		glasnoca = ogranicenje(glasnoca - step);
		assert(valid());
	}

	void mute() {
		prijeMute = glasnoca;
		glasnoca = 0;
		assert(valid());
	}
	void unmute() {
		glasnoca = prijeMute;
		assert(valid());
	}
	int get() const {
		return glasnoca;
	}
private:
	bool valid() const {
		return glasnoca >= 0 && glasnoca <= 100;
	}
};
int main()
{
	Volume v;
	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}
