#include <iostream>
/*
4-3 P1.string class 직접 구현해보기 생성자,소멸자,복사생성자 이용
4-5 시작
*/
class string {
	char* str;
	int len;

public:
	string(char c, int n);	//문자 c가 n개 있는 문자열로 정의
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);	//str 뒤에 s 추가
	void copy_string(const string& s);	//str에 s를 복사
	int strlen();	//문자열 길이를 리턴

	void print_string(); // str 프린트
};

string::string(char c, int n) {
	str = new char[n + 1];
	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
	str[n] = '\0';
	len = n;
}

string::string(const char* s) {
	for (len = 0; s[len] != '\0'; len++) {
		str = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			str[i] = s[i];
		}
	}
}

string::string(const string& s) {
	str = new char[s.len + 1];
	for (int i = 0; i <= s.len + 1; i++) {
		str[i] = s.str[i];
	}
	len = s.len;
}

string::~string() {
	delete[] str;
	std::cout << "소멸자 호출" << std::endl;
}

void string::add_string(const string& s) {
	char* new_str = new char[s.len + len + 1];
	for (int i = 0; i < len; i++) {
		new_str[i] = str[i];
	}
	for (int i = len; i < len + s.len + 1; i++) {
		new_str[i] = s.str[i - len];
	}
	delete str;
	str = new_str;
	len += s.len;
}

void string::copy_string(const string& s) {
	char* new_str = new char[s.len + 1];
	for (int i = 0; i < s.len + 1; ++i) new_str[i] = s.str[i];
	delete str;
	str = new_str;
	len = s.len;
}

int string::strlen() {
	return len;
}

void string::print_string() {
	std::cout << str << std::endl;
}

int main()
{
	string s1('a', 10);
	string s2("goddamn");
	string s3(s2);
	std::cout << s1.strlen() << std::endl << s2.strlen() << std::endl << s3.strlen() << std::endl;
	s1.print_string();
	s2.print_string();
	s3.print_string();

	s1.add_string(s2);
	s3.copy_string(s1);
	std::cout << s1.strlen() << std::endl << s2.strlen() << std::endl << s3.strlen() << std::endl;
	s1.print_string();
	s2.print_string();
	s3.print_string();
	return 0;
}
