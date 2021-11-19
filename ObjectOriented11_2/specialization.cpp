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
	swapA<int>(a, b); //swap(a,b)�� ����
	swapA<float>(c, d); //swap(c,d)�� ����
	//(�߰�) e, f�� swap�� �����ϵ��� swap template ȣ��
	swapA<std::string>(e, f);//swap���� �ϸ� �����Լ��� �����Ѵ� ���� �̸��� �ٲ�
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;
	return 0;
}