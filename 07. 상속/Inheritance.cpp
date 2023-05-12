#include <iostream>
#include <string.h>
/*
 상속 : 추상화에 따라 depth가 존재하는데 그 상관관계에 집중한 것
 부모-자식 클래스라고도 하나 이는 java의 이야기이며 c++은 다중 상속이 가능하기 때문에 기반-파생 클래스라 부르는 것이 낫다.
 class (파생 클래스의 이름) : (접근 제한자) (기반 클래스의 이름)
 생성자의 경우 반드시 기반 클래스부터 초기화 된다. 즉 컴파일러는 기반 클래스 코드부터 처리한다.
 파생 클래스와 기반 클래스 각각에 같은 메소드의 이름이 존재할 경우는 가까이에 있는 파생 클래스의 메소드를 실행한다 : Overriding
 파생 클래스에서 기반 클래스의 멤버 변수에 접근하려고 할 때 private인 경우 접근이 불가하다.
 private : 나만 아는 비밀번호 , protected : 현관문 비밀번호(가족은 알겠지), public : 제 3자도 아는 비밀번호
*/
class Employee {
protected:
	std::string name;
	int age;
	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}
	Employee() {}

	int calculate_pay() {
		return 200 + rank * 50;
	}
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}
};
class Manager : public Employee {
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		:year_of_service(year_of_service), Employee(name, age, position, rank) {}

	Manager(const Manager& manager)
		: Employee(manager.name, manager.age, manager.position, manager.rank) {
		year_of_service = manager.year_of_service;
	}

	Manager() : Employee() {}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ", "
			<< year_of_service << "년차) ==> " << calculate_pay() << "만원"
			<< std::endl;
	}
};
class Employeelist {
	int alloc_employee;	// 할당할 총 직원 수(매니저가 포괄되는 개념)

	int current_employee; // 현재 직원 수
	int current_manager; //현재 매니저 수

	Employee** employee_list; // 직원의 데이터
	Manager** manager_list; //매니저의 데이터


public:
	Employeelist(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		manager_list = new Manager * [alloc_employee];
		current_employee = 0;
		current_manager = 0;
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee; // 따로 해제와 할당을 해주지 않는다. ae가 ce보다 크다고 가정
		current_employee++;
	}
	void add_manager(Manager* manager) {
		manager_list[current_manager] = manager; // 위 함수와 동일
		current_manager++;
	}
	int currentemployeenum() { return current_employee + current_manager; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_manager; i++) {
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}
	~Employeelist() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		for (int i = 0; i < current_manager; i++) {
			delete manager_list[i];
		}
		delete[] employee_list;
		delete[] manager_list;
	}
};
int main() {
	Employeelist emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}

