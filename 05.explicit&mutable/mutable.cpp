#include <iostream>
/*mutable : 변이가능한 무엇을 ? const 함수의 멤버 변수들을
왜 쓸까? 그냥 const 떼버리면 안될까? : const함수 즉 읽기 전용 함수임에도 반드시 읽기만 하지 않을 수도 있다.
ex)캐시에 userid요청하고 없을 시 db에 userid요청하고 캐시에 update하는 경우
*/
#include <iostream>

class A {
	mutable int data_;

public:
	A(int data) : data_(data) {}
	void Dosomething(int x) const {
		data_ = x; //가능!
	}

	void PrintData() const { std::cout << "data : " << data_ << std::endl; }
};

int main() {
	A a(10);
	a.Dosomething(3);
	a.PrintData();
}
