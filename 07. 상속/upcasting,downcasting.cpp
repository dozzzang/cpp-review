#include <iostream>
#include <string>
/* 업캐스팅과 다운캐스팅 업캐스팅의 경우 Derived is a Base이기 때문에 Base 포인터가 Derived 객체를 가리키는 것은 당연히 가능하다.
   더 일반적인 것이 구체화 된것을 가리키는 것은 당연하거든요. 이를 업캐스팅이라 한다. 그림 생각
   위 업캐스팅의 과정을 역으로 수행하면 다운캐스팅인데 강제 형 변환이 필요하다. 다만 강제 형 변환이 다운캐스팅의 문제점을 완벽히 해결해 주진 못한다.
*/
class Base {
	std::string s;
public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() {
		std::cout << "기반 클래스입니다." << std::endl;
	}
};
class Derived : public Base {
	std::string s;
public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	void what() {
		std::cout << "파생 클래스입니다." << std::endl;
	}
};
int main() {
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_p = &c;
	p_p->what();
	/*Derived* p_c = &p; 이 같은 다운캐스팅의 경우 파생에 기반 주소를 대입하지 마라는 컴파일 에러*/
	/*Derived* p_c = static_cast<Derived*>(p_p); 1.p_p가 사실은 Derived객체를 가리킨다는 것을 안다. 2. 강제 type casting 다만 1에 어긋나면 런타임 에러*/
	Derived* p_c = dynamic_cast<Derived*>(p_p); //다형성 고려 x
	p_c->what();

	return 0;
}