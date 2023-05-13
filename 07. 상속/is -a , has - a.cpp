#include <iostream>
#include <string.h>
/*
 Manager가 Employee를 상속 하고 있다. 즉 Manager is a Employee. ia - a 관계이다.
 왜냐면 Manager 클래스는 Employee 클래스의 기능을 모두 수행할 수 있기 때문이다.
 이는 잘 생각해보면 추상화와 관련이 있다. 추상화의 depth에 따라 더 "구체화"될 수 있다.
 파생 될수록 구체화되고 기반으로 거슬러 올라갈수록 일반화된다.

 EmployeeList 클래스는 Employee 클래스와 Manager 클래스를 필요로 한다. 즉, EmployeeList has a Employee,EmployeeList has a Manager관계이다.
 왜냐면 EmployeeList 클래스에는 Employee 클래스와 Manager 클래스를 포함하고 있기 때문이다.
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
