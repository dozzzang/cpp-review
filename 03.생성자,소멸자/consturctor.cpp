#include <iostream>
/* 이전의 Date class 중 SetDate는 필수적으로 main함수에서 수행해주어야했지만 이는 번거롭다. >> 생성자의 도입
   위와 관련하여 아래 코드는 SetDate를 호출하지 않으니 쓰레기 값이 출력됨. 왜일까?
   Date(para1,para2,para3 . . .) // class명(인자1,인자2,) Date 생성자의 '정의' 이처럼 생성자는 '함수'이다!!!!
   이후 main함수에서 명시적으로 Date day(para1,para2,para3 . . .) 암시적으로 Date day = Date(para1,para2,para3.,,)
   암시적 잘 보면 그냥 대입연산자 정의 잘 생각해보면 됨
   Date day;에서 사실 생성자가 호출되었는데 이를 default constructor이라 부름. 사용자가 명시적으로 클래스에서 선언해주지 않는다면 컴파일러가 자동으로 초기화
   따라서 2번 질문에서 쓰레기값이 나오는 이유 해결!
   디폴트 생성자는 인자 없이 바로 중괄호 안에서 선언해주면 된다. 역시 명시적 방법과 암시적 방법 모두 사용 가능 다만, Date = day3;과 Date = day3();은 다르다.
   생성자는 '함수'이기 때문에 오버로딩도 당연히 가능하다.
*/
class Date {
	int year_;
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);
	int GetCurrentMonthTotalDays(int year, int month);
	void ShowDate();
};
void Date::SetDate(int year, int month, int date) {
	year_ = year;
	month_ = month;
	day_ = date;
}
int Date::GetCurrentMonthTotalDays(int year, int month) {	//2월과 윤년 고려
	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 == 0) {
		return 29;
	}
	else {
		return month_day[month - 1];
	}
}
void Date::AddDay(int inc) {
	while (true) {
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}

}
void Date::AddMonth(int inc) {
	AddYear((inc + month_ / 12));
	month_ += (inc % 12);
	month_ = (month_ == 12 ? 12 : month_ % 12);
}
void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
	std::cout << year_ << "년" << month_ << "월" << day_ << "일 입니다." << std::endl;
}

int main() {
	Date day;
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  // 윤년
	day.AddDay(29);

	return 0;
}
