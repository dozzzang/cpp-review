/*-----------------------------------------------------------------------------
  struct와 new의 사용 runtime에 배열의 size를 결정할 수 있음.
  P : main함수에서 함수 call할때마다 parameter set
      함수 내부의 -> operator not effcient
	  아래 코드에서 new Animal을 통해 동물을 생성한 다음에 반드시 create_animal함수를 호출하여 초기화해주어야함. 이는 번거롭다.
	  아래 코드를 발전시켜 animal뿐만 아니라 fish와 bird도 추가하여야한다면 코드가 굉장히 complex해진다.
  S : struct에 data 뿐 아니라 operation도 가능하게끔하자.
	  animal과 동일한 부분은 가져다 쓰고 새로 추가된 부분만 추가해서 쓸 수 없을까.
	  -> class의 도입
--------------------------------------------------------------------------------*/
#include <iostream.h>
	
typedef struct Animal {
	char name[30]; // 이름
	int age; // 나이

	int health; // 체력
	int food; //배부른 정도
	int clean; // 깨끗한 정도
}Animal;

void create_animal(Animal* animal) {
	std::cout << "동물의 이름? ";
	std::cin >> animal->name;

	std::cout << "동물의 나이? ";
	std::cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal* animal) {
	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal* animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}
void one_day_pass(Animal* animal) {
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}
void show_stat(Animal* animal) {
	std::cout << animal->name << "의 상태" << std::endl;
	std::cout << "체력 : " << animal->health << std::endl;
	std::cout << "배부름 : " << animal->food << std::endl;
	std::cout << "청결 : " << animal->clean << std::endl;
}
int main() {
	Animal* list[10];
	int animal_num = 0;
}

for (;;) {
	std::cout << "1. 동물 추가하기" << std::endl;
	std::cout << "2. 놀기 " << std::endl;
	std::cout << "3. 상태 보기" << std::endl;

	int input;
	std::cin >> input;

	switch (input) {
		int play_with;
	case 1:
		list[animal_num] = new Animal;
		create_animal(list[animal_num]);

		animal_num++;
		break;
	case 2:
		std::cout << "누구랑 놀건가요? : ";
		std::cin >> play_with;

		if (play_with < animal_num) play(list[play_with]);

		break;

	case 3:
		std::cout << "누구껄 볼건가요? : ";
		std::cin >> play_with;
		if (play_with < animal_num) show_stat(list[play_with]);
		break;
	}

	for (int i = 0; i != animal_num; i++) {
		one_day_pass(list[i]);
	}
	for (int i = 0; i != animal_num; i++) {
		delete list[i];
	}
}