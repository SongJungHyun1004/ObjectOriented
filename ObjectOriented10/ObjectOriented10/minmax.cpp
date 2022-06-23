/*#include <iostream>
#include <queue>
using namespace std;
int main() {
	int data[10];
	priority_queue<int> max;
	priority_queue<int,vector<int>,greater<int>> min;
	for (int i = 0; i < 10; i++) {
		cin >> data[i];
		max.push(data[i]);
		min.push(data[i]);
	}
	cout << "max : " << max.top() << endl;
	cout << "min : " << min.top() << endl;
	return 0;
}*/

#include<vector>
#include<algorithm>
#include<iostream>

int main() {
	int size = 10;
	std::vector<int> vec(size);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "vec[" << i << "]";
		std::cin >> vec[i];
	}
	std::cout << "-------------------" << std::endl;
	std::cout << "max: " << *max_element(vec.begin(), vec.end()) << std::endl;
	std::cout << "min: " << *min_element(vec.begin(), vec.end()) << std::endl;
	return 0;
}