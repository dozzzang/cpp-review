#include <iostream>
/*
virtual 키워드를 Base의 소멸자에 사용하지 않으면 파생 클라스를 동적 할당하여 업캐스팅 했을 때 파생 클래스가 메모리에 남게 된다.
상속될 여지가 있는 class의 소멸자에는 virtual 키워드를 명시해주자. 다중 상속 생각하면 쉬움. 상속 받는 애는 편한데 될 여지가 있는 애만 불편
*/
class Base {
public:
	Base() { std::cout << "Base 생성자 호출" << std::endl; }
	virtual ~Base() { std::cout << "Base 소멸자 호출" << std::endl; }
};
class Derived : public Base {

public:
	Derived() : Base() { std::cout << "Derived 생성자 호출" << std::endl; }
	~Derived() { std::cout << "Derived 소멸자 호출" << std::endl; }
};

int main() {
	std::cout << "--------평범한 Base 객체--------" << std::endl;
	{
		Base b;
	}
	std::cout << "--------Base 포인터로 Derived를 가리켰을 때--------" << std::endl;
	{
		Base* d = new Derived();
		delete d;
	}
}