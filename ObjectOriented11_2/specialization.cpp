#include <iostream>

template <typename T>
void swapA(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template <>
void swapA(std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";
	swapA<int>(a, b); //swap(a,b)도 가능
	swapA<float>(c, d); //swap(c,d)도 가능
	//(추가) e, f의 swap이 가능하도록 swap template 호출
	swapA<std::string>(e, f);//swap으로 하면 내장함수가 실행한다 따라서 이름을 바꿈
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;
	return 0;
}