#include <cstdio>
#include <iostream>

class Date {
public: 
  Date(int year = 1900, int month = 1, int day = 1) {
    _year = year;
    _month = month;
    _day = day;
  }

  ~Date(){

  }

  Date (const Date& d) {
    if(this != &d){
      _year = d._year;
      _month = d._month;
      _day = d._day;
    }
  }

  bool isLeapYear(int year) {
    if((year%4 == 0 && year%100 != 0) || (year %400 == 0)) {
      return true;
    }
    return false;
  }

  int GetMonthDay(int year, int month) {
    int days[] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year) == 1) {
      return 29;
    }
    return days[month];
  }

  Date operator=(const Date& d){
    if(*this != d){
      _year = d._year;
      _month = d._month;
      _day = d._day;
    }
    return *this;
  }

  Date operator+(int day){
    _day += day;
    while(_day > GetMonthDay(_year,_month)){
      _day -= GetMonthDay(_year,_month);
      _month++;
      if(_month == 13) {
        _month = 1;
        _year++;
      }
    }
    return *this;
  }
  
  Date operator-(int day){
    _day -= day;
    while(_day < 0){
      _day += GetMonthDay(_year, _month-1);
      _month--;
      if(_month == 0) {
        _month = 12;
        _year--;
      }
    }
    return *this;
  }

  int operator-(const Date& d) {
    int count = 0;
    while(*this - count> d ) {
      count++;
    }  
    while(*this - count < d){
      count--;
    }
    return count;
  }


  bool operator>(const Date& d) const{
    if(_year > d._year){
      return true;
    } else if(_year == d._year) {
      if(_month > d._month) {
        return true;
      } else if(_month == d._month) {
        if(_day > d._day){
          return true;
        }
      }
    }
    return false;
  }

  // 前置++
  Date& operator++() {
    *this = * this + 1;
    return *this;
  }

  // 前置--
  Date& operator--() {
    *this = *this - 1;
    return *this;
  }

  // 后置++
  Date operator++(int) {
    Date tmp(*this);
    *this = *this + 1;;
    return tmp;
  }

  // 后置--
  Date operator--(int) {
    Date tmp(*this);
    *this = *this - 1;
    return tmp;
  }

  bool operator==(const Date& d)const {
    return _year == d._year &&
         _month == d._month &&
         _day == d._day;
  }

  bool operator<(const Date& d) const {
    return !(*this > d || *this == d);
  }

  bool operator>=(const Date& d) const {
    return (*this > d || *this == d);
  }

  bool operator<=(const Date& d) const {
    return (*this < d || *this == d);
  }

  bool operator!=(const Date& d) const {
    return !(*this == d);
  }
  
  void show() {
    printf("%d-%d-%d\n", _year, _month, _day);
  }

private:
  int _year;
  int _month;
  int _day;
};

void TestDate() {
  Date d1(2019,7,31);
  d1.show();
  Date d2(d1);
  d2.show();
  d2++;
  d2.show();
  d1--;
  d1.show();
  Date d3;
  d3 = d2;
}
int main() {
  TestDate();  
  return 0;
}
