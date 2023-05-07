#include <iostream>
/*
레퍼런스를 리턴하는 함수 레퍼런스는 '별명'이라고 하였었다. 누구의 별명인지만 잘 인지하고 있으면 c에서의 포인터를 생각하면 쉽다.
*/
class A {
	int x;

public:
	A(int c) :x(c) {} // 생성자 A를 멤버 초기화 리스트를 이용하여 매개변수 c를 받아 클래스 내부의 변수 x를 초기화

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	/* 오류 코드
		int& e = a.get_x();
		e = 2;
		a.show_x();
		위 코드는 a.get_x()가 임시로 x`변수를 생성하긴 하지만 이 레퍼런스를 받을 수 없고 바로 소멸되기 때문에 에러*/

	int f = a.get_x();
	f = 1;	//실제 객체 x에는 영향을 미치지 못한다. 임시로 생긴 x`변수이기 때문
	a.show_x();

	a.access_x() = 3; //이 문장은 옳다. 레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다. 즉 이 코드는 a.x = 3;과 동일
}

