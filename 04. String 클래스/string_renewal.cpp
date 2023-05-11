#include <iostream>
#include <string.h>
/*
C++ 내장되어 있는 String class 흉내내본 MyString class
1.단일 문자 혹은 문자열을 통해 생성할 수 있는 생성자와 복사생성자
2.문자열의 길이 return 함수 length
3.문자열 할당 함수 assign
4.문자열 메모리 할당 함수 reserve 및 현재 할당된 크기를 알아오는 함수 capacity
5.특정 문자의 위치를 return 함수 at
6.특정 위치에 특정 문자열 삽입 함수 insert
7.특정 위치의 특정 개수의 문자열 삭제 함수 erase
8.특정 위치를 시작으로 특정 문자열 검색하는 함수 find
9.두 문자열을 비교하는 함수 compare
+erase함수 아래 주석에 따라 개선 필요,KMP와 Boyer-Moore 알고리즘 알아보고 구현해보기..
*/
class MyString {
    char* string_content;
    int string_length;
    int memory_capacity;

public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로 부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
    void print() const;
    void println() const;

    int capacity();
    void reserve(int size);
    char at(int i) const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, const char c);

    MyString& erase(int loc, int num);
    int find(int find_from, MyString& str) const;
};
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString() { //소멸자
    delete[]string_content;
}
int MyString::length() const { return string_length; } //문자열의 길이 return

void MyString::print() const {  //화면 출력
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {    //화면 출력 + 개행
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

int MyString::capacity() { return memory_capacity; }    //배열의 용량 력

void MyString::reserve(int size) {  //size만큼 메모리 미리 할당
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];

        for (int i = 0; i != string_length; i++) {
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        memory_capacity = size;
    }
}
MyString& MyString::assign(const MyString& str) { // why return type? ex) b.assign(a.assign(str))
    if (str.string_length > string_length) {
        delete[] string_content;
        string_content = new char[str.string_length];
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str) {   // why reeturn type? ex) b.assign(a.assign(str)) *복사가 아닌 할당
    int str_length = strlen(str);
    if (str_length > string_length) {
        string_content = new char[str_length];
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = strlen(str);
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, const MyString& str) { //문자열 index 입력받고 insert하기
    /*생각해 볼 idea : insert함수를 사용하는 경우는 대게 많은 문자열을 insert시키는 경우보다는 자잘한 문자열을 insert시키는 경우일 것
      그렇다면 매번 메모리 할당 해제를 해줘야 할 필요가 있는가?
      --> C++ 동적할당에서 자주 쓰는 idea인 그냥 바로 메모리 2배 할당해버리기 */
    if (loc < 0 || loc > string_length) { return *this; }
    if (memory_capacity < str.string_length + string_length) {
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity + str.string_length];
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        return *this;
    }
    //초과하지 않는 경우 밀어버리기
    for (int i = string_length - 1; i >= loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    for (int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

MyString& MyString::erase(int loc, int num) { // 문자열 길이보다 긴 loc를 받았을 때나 num > loc인 경우 고려 x
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1;  
}
int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();
}