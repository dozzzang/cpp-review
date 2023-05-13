#include <iostream>
#include <string>
/*
 Derived가 상속한 Base를 type으로 포인터를 선언하여 Derived의 객체의 주소값을 받아오면 우리는 코드를 절약할 수 있다.
 하지만 Derived와 Base에 완전히 같은 메소드가 존재할 때, Derived의 메소드가 실행되는 것이 아닌 Base의 메소드가 실행되었다.
 해결하기 위해 virtual 키워드가 도입된다. Base의 메소드에 붙여줌으로써 컴파일러가 알아서 기계어 잘 적어서 런타임에서 판단될 수 있다.
 override 키워드는 함수가 완전히 같지 않은 경우 즉 실수로 오버라이드를 하지 않는 경우를 방지해준다.
 virtual 키워드를 잘 생각해보면 하나의 메소드에서 사실은 다른 작업들을 할 수 있게 된다. 이 다른 작업들을 '다형성'이라 뜻한다.
*/
class Base {
	std::string s;
public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void what() {
		std::cout << "기반 클래스의 what." << std::endl;
	}
};
class Derived : public Base {
	std::string s;
public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	void what() override {
		std::cout << "파생 클래스의 what." << std::endl;
	}
};
int main() {
	Base p;
	Derived c;

	Base* p_p = &p;
	Base* p_c = &c;

	std::cout << "== 실제 객체는 Base ==" << std::endl;
	p_p->what();

	std::cout << "==실제 객체는 Derived ==" << std::endl;
	p_c->what();

	return 0;
}