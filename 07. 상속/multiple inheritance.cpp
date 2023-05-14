#include <iostream>
#include <string>
/*
 부모-자식관계라 부르지 않고 기반-파생관계라 불렀듯 c++은 다중 상속을 지원한다. 다만 주의해야 할 점도 많고 사용해야 할때도 구분해주어야한다.
 아래는 공포의 다이아몬드 상속(Dreadful Diamond of derivation)의 예시이다.
 아래 상속 관계를 도식화 해보면 왜 위와 같이 명명한 지 알 수 있고 문제점도 직관적으로 보인다.
 Human의 멤버 변수가 Me가 두 개의 클래스를 상속 받으니 겹치게 되는 것인데, 이를 해결하기 위해 Human을 virtual로 상속 받아야 한다.
*/
class Human {
	std::string name;
public:
	Human() : name("Kim") {}
};

class HandsomeHuman : public virtual Human {
public:
	HandsomeHuman() : Human() {}
};

class SmartHuman : public virtual Human {
	SmartHuman() : Human() {}
};
class Me : public HandsomeHuman, public SmartHuman {
	Me() : HandsomeHuman(),SmartHuman(),Human() {}
};