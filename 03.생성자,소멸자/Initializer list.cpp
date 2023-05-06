#include <iostream>
/* 생성자의 초기화 리스트 == 디폴트 생성자를 실행한 후 대입하는 것과 복사 생성자가 실행되는 것의 차이 즉, 생성과 초기화가 동시에 일어날 수 있음.
   생성과 초기화가 분리된 과정으로 진행되면 안되는 레퍼런스와 상수를 클래스 내에서 다룰 수 있다.
   +변할 가능성이 없는 값을 상수형으로 선언하는 습관을 들이자.
*/
class Marine {
    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine()        //생성자의 초기화 리스트 방법 (클래스 이름)::(생성자 이름) : var1(arg),var2(arg) 
                        //var은 클래스의 멤버 변수, arg는 멤버 변수를 무엇으로 초기화 할지
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10);
    Marine marine2(3, 5, 10);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}