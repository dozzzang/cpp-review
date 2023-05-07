#include <iostream>
/*
C언어에서의 static과 목적은 같되 c++에서는 클래스와 연관지어 볼 수 있다. 객체에 종속되지 않기 때문에 인스턴스를 생성하지 않고 호출 가능하다.
static 함수도 마찬가지
자기 자신의 레퍼런스를 리턴하는 함수는 이전 코드에서 공부해보았다. 86번째 코드에서 marine2.be_attacked(marine1.attack())가 먼저 호출되고
레퍼런스(별명)가 리턴되기 때문에 이후 marine2.be_attacked(marine1.attack());을 수행하는 것과 같다.
*/
class Marine {
    static int total_marine_num;    //static은 객체에 종속되지 않는다. public과는 쓰는 목적이 다르다. 
                                    //인스턴스를 생성하지 않고 호출가능 왜? 객체에 종속되지 않기 때문
    const static int i = 0;         //상수 static형 변수도 만들 수 있다.

    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    bool is_dead;

    const int default_damage;  // 기본 공격력

public:
    Marine();              // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);

    int attack() const;                    // 데미지를 리턴한다.
    Marine& be_attacked(int damage_earn);  // 입는 데미지,자기 자신의 레퍼런스를 리턴하는 함수
    void move(int x, int y);               // 새로운 위치

    void show_status();  // 상태를 보여준다.
    static void show_total_marine();    //static 함수
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
    coord_y(y),
    hp(50),

    default_damage(5),
    is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;

    return *this;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}