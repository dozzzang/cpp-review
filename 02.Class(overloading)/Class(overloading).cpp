# include <iostream>
/*---------------------------------------------------------------
 멤버 변수는 private 접근 지시자로 보호하자. -> encapsualtion?
 animal이라는 class가 data와 operation 모두를 포함하기 때문에
 struct를 사용했을 때 처럼 play(list[play_With])같이 animal 정보를 play
 함수의 인자로 전달하지 않아도 그 정보가 이미 class 안에 들어있기 때문에
 animal.play();로 animal 자체가 play 한다라는 개념으로 받아들일 수 있다.
------------------------------------------------------------------*/
class Animal {
private:
	int food;
	int weight;

public:
	void set_animal(int _food, int _weight)
	{
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};

int main() {
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}