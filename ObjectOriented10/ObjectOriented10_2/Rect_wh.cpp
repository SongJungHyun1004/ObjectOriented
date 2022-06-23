#include <iostream>
#include <list>

using namespace std;

class Rect {
	int w, h;
public:
	Rect() : w(0), h(0) {}
	Rect(int w, int h) : w(w), h(h) { }
	int area() { return w * h; }
	void print() {
		cout << "(" << w << "," << h << ")" << endl;
	}
};