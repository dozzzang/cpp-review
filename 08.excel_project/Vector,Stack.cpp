#include <string>
#include <iostream>
using std::string;

namespace MyExcel {
    class Vector {
        string* data;
        int capacity;
        int length;

    public:
        // 생성자
        Vector(int n = 1);

        // 맨 뒤에 새로운 원소를 추가
        void push_back(string s);

        // 임의의 위치의 원소에 접근
        string operator[](int i);

        // x 번째 위치한 원소를 제거
        void remove(int x);

        // 현재 벡터의 크기
        int size();

        ~Vector();
    };

    class Stack {
        struct Node {
            Node* prev;
            string s;

            Node(Node* prev, string s) : prev(prev), s(s) {}
        };

        Node* current;
        Node start;

    public:
        Stack();

        // 최상단에 새로운 원소를 추가
        void push(string s);

        // 최상단의 원소 제거+반환
        string pop();

        // 최상단의 원소 반환
        string peek();

        // 스택은 비어있는가
        bool is_empty();

        ~Stack();
    };
    class NumStack {
        struct Node {
            Node* prev;
            double s;

            Node(Node* prev, double s) : prev(prev), s(s) {}
        };

        Node* current;
        Node start;

    public:
        NumStack();
        void push(double s);
        double pop();
        double peek();
        bool is_empty();

        ~NumStack();
    };
}

namespace MyExcel {
    Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}
    void Vector::push_back(string s) {
        if (capacity <= length) {
            string* temp = new string[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }
    string Vector::operator[](int i) { return data[i]; }
    void Vector::remove(int x) {
        for (int i = x + 1; i < length; i++) {  //index로 접근해야 배열의 마지막을 처리하지 못한다는 단점이 있다.
            data[i - 1] = data[i];
        }
        length--;
    }
    int Vector::size() { return length; }
    Vector::~Vector() {
        if (data) {
            delete[] data;
        }
    }

    Stack::Stack() : start(NULL, "") { current = &start; }
    void Stack::push(string s) {
        Node* n = new Node(current, s);
        current = n;
    }
    string Stack::pop() {   //어렵다. 최상위를 prev로 그 하위를 current로
        if (current == &start) return "";

        string s = current->s;
        Node* prev = current;
        current = current->prev;

        // 이전 노드 제거
        delete prev;
        return s;
    }
    string Stack::peek() { return current->s; }
    bool Stack::is_empty() {
        if (current == &start) return true;
        return false;
    }
    Stack::~Stack() {
        while (current != &start) {
            Node* prev = current;
            current = current->prev;
            delete prev;
        }
    }
    NumStack::NumStack() : start(NULL, 0) { current = &start; }
    void NumStack::push(double s) {
        Node* n = new Node(current, s);
        current = n;
    }
    double NumStack::pop() {
        if (current == &start) return 0;

        double s = current->s;
        Node* prev = current;
        current = current->prev;

        // 이전 노드 제거
        delete prev;
        return s;
    }
    double NumStack::peek() { return current->s; }
    bool NumStack::is_empty() {
        if (current == &start) return true;
        return false;
    }
    NumStack::~NumStack() {
        while (current != &start) {
            Node* prev = current;
            current = current->prev;
            delete prev;
        }
    }
}
int main() {
    MyExcel::Vector a(3);
    a.push_back("str");
    a.push_back("sss");
    a.push_back("skt");
    std::cout << a.size() << std::endl;
    a.remove(1);
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl; //마지막 원소 문제 있음 수정 필요
}