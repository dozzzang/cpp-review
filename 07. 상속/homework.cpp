#include <cmath>
#include <iostream>
class Point
{
protected:	//상속받은 클래스에서 참조 가능
    double x, y;
public:
    Point();	//혹시나 초기화하지 않았을 경우를 위하여 디폴트 생성자 명시적 선언할 것인데 cpp파일에
    Point(double x, double y);	//좌표 x,y를 초기화 해주는 생성자

    double get_X() const;	//	거리 구하기 위해 protected 멤버 변수에 접근
    double get_Y() const; // 거리 구하기 위해 protected 멤버 변수에 접근

    double get_Distance(Point& p1, Point& p2);	//점과 점의 거리 구하기
};

class Triangle : public Point {	//Triangle 클래스가 Point 클래스를 상속 받는다.
protected:
    Point p2;
    Point p3;
public:
    Triangle() : Point() {};
    Triangle(Point& p1, Point& p2, Point& p3)
        : Point(p1), p2(p2), p3(p3) {}
    void is_Triangle(Point& p1, Point& p2, Point& p3);	//삼각형 판별
    void get_TriangleArea(Point& p1, Point& p2, Point& p3);	//삼각형 넓이
};

class Rectangle : public Point { //Rectangle 클래스가 Point 클래스를 상속 받는다.
protected:
    Point p2;
    Point p3;
    Point p4;
public:
    Rectangle() : Point() {};
    Rectangle(Point& p1, Point& p2, Point& p3, Point& p4)
        : Point(p1), p2(p2), p3(p3), p4(p4) {}
    void is_Rectangle(Point& p1, Point& p2, Point& p3, Point& p4); //사각형 판별
    void get_RectangleArea(Point& p1, Point& p2, Point& p3, Point& p4); //사각형 넓이
};
Point::Point() : x(0), y(0) {} //디폴트 생성자 명시적 선언

Point::Point(double x, double y) : x(x), y(y) {}    //생성자 선언

double Point::get_X() const // 거리 구하기 위해 protected 멤버 변수에 접근
{
    return x;
}

double Point::get_Y() const // 거리 구하기 위해 protected 멤버 변수에 접근
{
    return y;
}


double Point::get_Distance(Point& p1, Point& p2) {  //점과 점의 거리 구하기
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}
void Rectangle::is_Rectangle(Point& p1, Point& p2, Point& p3, Point& p4) {  //사각형이 만들어지는지 판별
    double edge1 = get_Distance(p1, p2); //첫 번째 변
    double edge2 = get_Distance(p2, p3); //두 번째 변
    double edge3 = get_Distance(p3, p4); //세 번째 변
    double edge4 = get_Distance(p1, p4); //네 번째 변

    if (edge1 == edge3 && edge2 == edge4) {
        std::cout << "판별 : 사각형" << std::endl;
    }//정사각형과 직사각형만 고려
    else {
        std::cout << "사각형 생성 불가" << std::endl;
    }

}
void Triangle::is_Triangle(Point& p1, Point& p2, Point& p3) {   //삼각형이 만들어 지는지 판별
    double edge1 = get_Distance(p1, p2); //첫 번째 변
    double edge2 = get_Distance(p2, p3); //두 번째 변
    double edge3 = get_Distance(p1, p3); //세 번째 변

    if ((edge1 + edge2 > edge3) && (edge2 + edge3 > edge1) && (edge3 + edge1 > edge2)) {
        //가장 긴 변의 길이는 나머지 두 변의 길이의 합보다 작아야 한다. 따로 메소드 구현?
        std::cout << "판별 : 삼각형" << std::endl;
    }
    else {
        std::cout << "삼각형 생성 불가" << std::endl;
    }
}
void Rectangle::get_RectangleArea(Point& p1, Point& p2, Point& p3, Point& p4) { //사각형 넓이
    double edge1 = get_Distance(p1, p2); //첫 번째 변
    double edge2 = get_Distance(p2, p3); //두 번째 변

    double area = edge1 * edge2; //사각형 넓이는 가로x세로

    std::cout << "넓이 : " << area << std::endl;
}
void Triangle::get_TriangleArea(Point& p1, Point& p2, Point& p3) {  //삼각형 넓이
    double edge1 = get_Distance(p1, p2); //첫 번째 변
    double edge2 = get_Distance(p2, p3); //두 번째 변
    double edge3 = get_Distance(p1, p3); //세 번째 변
    //헤론의 공식
    double temp = (edge1 + edge2 + edge3) / 2.0;
    double area = std::sqrt(temp * (temp - edge1) * (temp - edge2) * (temp - edge3));

    std::cout << "넓이: " << area << std::endl;
}
#include <iostream>
#include "Class.h"

int main() {
    Point a(0, 0), b(2, 0), c(0, 4), d(2, 4);
    Point e(7, 7), f(10, 0), g(0, 100), h(30, 30);  //생성자로 instance 초기화

    Triangle triangle[2] = {    //원소의 크기가 2인 class 배열
        Triangle(a,b,c),Triangle(b,c,d)
    };
    Rectangle rectangle[2] = {  //원소의 크기가 2인 class 배열
        Rectangle(a,b,c,d),Rectangle(e,f,g,h)
    };
    //형식에 맞게 출력
    std::cout << "a-b의 거리 : " << rectangle[0].get_Distance(a, b) << std::endl;
    std::cout << "b-c의 거리 : " << rectangle[0].get_Distance(b, c) << std::endl;
    std::cout << "c-d의 거리 : " << rectangle[0].get_Distance(c, d) << std::endl;
    std::cout << "a-d의 거리 : " << rectangle[0].get_Distance(a, d) << std::endl;
    rectangle[0].is_Rectangle(a, b, c, d);
    rectangle[0].get_RectangleArea(a, b, c, d);

    std::cout << "a-b의 거리 : " << triangle[0].get_Distance(a, b) << std::endl;
    std::cout << "b-c의 거리 : " << triangle[0].get_Distance(b, c) << std::endl;
    std::cout << "c-d의 거리 : " << triangle[0].get_Distance(c, d) << std::endl;
    triangle[0].is_Triangle(a, b, c);
    triangle[0].get_TriangleArea(a, b, c);

    return 0;
}
