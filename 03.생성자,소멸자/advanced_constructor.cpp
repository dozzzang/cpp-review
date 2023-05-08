#include <iostream>
/* copy elision 최적화에 관한 설명 그것이 아니라면 main 함수의 동작흐름에 대해 알아보자.
   B b(10); -> 20번째 줄 생성자에 의해 a라는 객체를 생성하려 하므로 생성자의 존재 의의에 의해 9번째 줄 생성자가 호출되고 x멤버 변수를 c로 즉
   10으로 초기화하게 된다. (생성자 초기화 리스트)
   A a1 = b.get_A(); -> A 객체인 temp가 생성된다. 후에 객체를 복사하려고 하기 때문에 복사 생성자 A(const A&a)가 호출된다.
   이후 get_A() method는 temp라는 객체를 return하고 또 a1이라는 객체에 복사하려고 하기 때문에 다시 위 과정을 거친다.
*/
class A {
    int x;

public:
    A(int c) : x(c) {}
    A(const A& a) {
        x = a.x;
        std::cout << "복사 생성" << std::endl;
    }
};

class B {
    A a;

public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) {}
    A get_A() {
        A temp(a);
        return temp;
    }
};

int main() {
    B b(10);

    std::cout << "---------" << std::endl;
    A a1 = b.get_A();
}s