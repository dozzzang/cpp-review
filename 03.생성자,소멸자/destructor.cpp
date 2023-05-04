#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
	소멸자와 클래스의 위치를 주소값으로 갖는 포인터 배열 -> 컴파일 시점에 정해야 하는 문제 해결 / 이름 일일이 설정해줄 필요 덜어내기
	객체가 생성될 때 자동으로 호출되는 함수인 생성자가 있다면 객체가 소멸될 때 자동으로 호출 되는 함수 소멸자가 있다.
*/
class Marine {
	int hp;	//마린 hp
	int coord_x, coord_y;	//마린 위치
	int damage;	//공격력
	bool is_dead;	//생사 여부
	char* name;		//마린 이름

public:
	Marine();	//기본 생성자
	Marine(int x, int y, const char* marine_name); //생성자(이름까지 지정해주는)
	Marine(int x, int y);	// 좌표 지정 생성자
	~Marine(); // 소멸자

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);
	void show_status();
};
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {

	name = new char[strlen(marine_name) + 1]; // 이름 동적할당
	strcpy(name, marine_name);	//이름 복사

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << "*** Marine : " << name << "***" << std::endl;
	std::cout << " Location : ( " << coord_x << "," << coord_y << " ) " << std::endl;
	std::cout << "HP : " << hp << std::endl;
}
Marine::~Marine() {
	std::cout << name << "의 소멸자 호출 ! " << std::endl;
	if (name != NULL) {
		delete[] name;	// 예를 들어 marine1의 메모리가 초기화 된다고 해서 name까지 초기화 되는 것이 아니기 때문에
						// name은 별도로 동적할당 되는 것이니					
	}
}
int main() {
	Marine* marines[100]; // Marine Marine1(~,~,~)하면 생성자가 초기화

	marines[0] = new Marine(2, 3, "Marine 1");
	marines[1] = new Marine(3, 5, "Marine 2");

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}