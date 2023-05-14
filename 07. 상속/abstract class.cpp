#include <stdio.h>
/*
 **가상함수 테이블 컨셉 기억하기
 Animal 클래스의 speak 메소드의 선언이 특이하다. 이는 순수 가상 함수라고 부르며 반드시 override되어야한다. 아래 코드가 직관적이기 때문에 코드로 이해하는 것이 빠르다.
 순수 가상 함수를 최소 한 개 포함하고 있고 반드시 상속 되어야하는 클래스를 추상 클래스라 한다. 아래 코드에서는 Aniaml 클래스이다.
*/
class Animal() {
	Animal() {}
	virtual ~Animal() {}
	virtual void speak() = 0;
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
}