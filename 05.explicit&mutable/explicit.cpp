#include <iostream>
/*컴파일러는 형변환을 자동으로 해주는 경우가 있다. (암시적 변환) 
원하지 않는 형변환이 일어날 수 있다. explicit으로 막아주자.
이는 앞서 공부했던 복사 생성자의 암시적 변환도 막아준다.
*/

class MyString {
	char* string_content;  // 문자열 데이터를 가리키는 포인터
	int string_length;     // 문자열 길이

	int memory_capacity;

public:
	// capacity 만큼 미리 할당함. 
	MyString(int capacity);
	//explicit MyString(int capacity);로 선언한다면 아래 컴파일 오류

	// 문자열로 부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
};

// .. (생략) ..

void DoSomethingWithString(MyString s) {
	// Do something...
}

int main() {
	DoSomethingWithString(3);  // 가능
}