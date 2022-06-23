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
};bool areaCmp(Rect* a, Rect* b) {	return a->area() < b->area();}int main() {	int n;	list<Rect*> list;	cout << "�簢���� ����:";	cin >> n;	for (int i = 0; i < n; i++) {		int w, h;		cout << "�簢���� ��:";		cin >> w;		cout << "�簢���� ����:";		cin >> h;		list.push_back(new Rect(w, h));	}	list.sort(areaCmp);	for (auto elem : list) {		elem->print();	}	return 0;}