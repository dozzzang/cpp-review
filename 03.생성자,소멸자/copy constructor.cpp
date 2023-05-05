#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
	복사 생성자 : 아래 코드에서 선언한 형태가 곧 디폴트 복사 생성자이다.
	즉 복사 생성자를 아래와 같이 선언해주지 않아도, Photon_Cannon pc2 = pc1; 사용가능
	다만 name을 복사해야할 경우가 생긴다면
	이는 소멸자가 같은 메모리 공간을 두 번 접근하게 되므로 런타임 에러가 발생한다.(얕은 복사)
	따라서 아래 코드와 같이 복사 생성자에서 그대로 복사하는 것이 아닌 메모리에 동적 할당을 해서 복사한다.
	(깊은 복사)
*/
class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon Cannon& pc);	//복사 생성자
	~Photon_Cannon();	//소멸자

	void show_status();
};
Photon_Cannon::Photon_Cannon(int x, int y) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}
Photon_Cannon::Photon_Cannon(const char* cannon_name) {
	std::cout << "복사 생성자 호출" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
	if (name) delete[] name;
}

void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon :: " << name << std::endl;
	std::cout << "Location : ( " << coord_x << " , " << coord_y << ")" << std::endl;
	std::cout << "HP : " << hp << std::endl;
}
int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;

	pc1.show_status();
	pc2.show_status();
}