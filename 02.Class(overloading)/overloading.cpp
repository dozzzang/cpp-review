/*
함수의 overloading : overload의 사전적 def : 과부하가 걸리게 하다. 즉 이름에 과부하가 걸린다 == 함수의 이름에 같은 이름이 여러개다!
C언어에서는 지원해주지 않는다. 4단계의 과정을 거치게 된다.
*/
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b); // 2단계에 의해 char은 int로 형변환된다. 이후 첫 번째 print함수의 인자type과 일치하게 된다.
	print(c);

	return 0;
}