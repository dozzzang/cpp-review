#include <iostream>
#include <string.h>
/*
 회사의 사원들의 월급을 계산해서 한달에 얼마나 많은 돈을 월급으로 지급해야 할지 보여주는 프로그램 Employee 클래스 필요
 하지만 차장 이상 급은 근속 년수에 따라 월급이 달라지게 만들어달라는 추가 요구사항에 의해 Manager 클래스 필요
 이 둘을 만들고 보니 처음 struct에서 class로 넘어갈 당시의 문제점이 발견
 추상화에 따라 depth가 달랐고 이를 살펴보니 상관관계가 존재했다. 이 상관관계에 집중해보기 : 상속
*/
class Employee {
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
class Manager {
	std::string name;
	int age;
	std::string position;
	int rank;
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		:name(name), age(age), position(position), rank(rank), year_of_service(year_of_service) {}

	Manager(const Manager& manager) {
		name = manager.name;
		age = manager.age;
		position = manager.position;
		rank = manager.rank;
		year_of_service = manager.year_of_service;
	}

	Manager() {}

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

