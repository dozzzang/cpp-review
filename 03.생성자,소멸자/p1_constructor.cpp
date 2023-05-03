#include <iostream>
#include <math.h>
/*P1)Point는 점에 대한 정보를 담는 클래스이고 Geometry는 점들을 가지고 연산을 하는 클래스이다. 다음 코드가 주어졌을 때 알맞게 수정하시오.
* 못 풀겠어서 넘기려 했으나 생성자와 encapsulation 특징을 잘 이용한 코드가 있어서 클론하였음.
class Point {
  int x, y;
 public:
  Point(int pos_x, int pos_y);
};
class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }
  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.x, point.y);
  }
  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance();
// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets();
private:
  // 점 100 개를 보관하는 배열.
  Point* point_array[100];
  int num_points;
};*/
class Point {
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int pos_x, int pos_y) {
        x = pos_x;
        y = pos_y;
    }
    int GetX();
    int GetY(); //이 두 함수를 이용하여 x,y 변수는 private으로 접근 제한하면서 Addpoint에서 x와y변수 값 참조 가능! 'method를 이용하자'
};

class Geometry {
    Point* point_array[100]; // 점 100개를 보관하는 배열
    int num_points;
public:
    Geometry() {
        num_points = 0;
    }

    void AddPoint(Point point);
    double GetDistance(Point point);
    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance(Point point);
    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    void PrintNumMeets();
};
int Point::GetX() {
    return x;
};
int Point::GetY() {
    return y;
};

void Geometry::AddPoint(Point point) {
    point_array[num_points++] = new Point(point.GetX(), point.GetY()); //++연산자 위치 주목,new 사용 주목 new는 본디 T* VAR_NAME = T[SIZE]으로 쓰이지만
                                                                       //그냥 메모리 아끼려고 사용한 듯 형태에 주목 
};
double GetDistance(Point point) {
    return sqrt(pow())  //좌표 어떻게 받아와야할까
}