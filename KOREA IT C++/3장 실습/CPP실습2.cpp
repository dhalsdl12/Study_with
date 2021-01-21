#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Date {
	int year, month, day;
public:
	Date(int y, int m, int d) { 
		year = y;
		month = m;
		day = d;
	};
	Date(string s) {
		string a = s.split('/');
	};
	void show();
	int getYear();
	int getMonth();
	int getDay();
};
int main()
{
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay << endl;
}

void Date::show() {
	
	cout << n << endl;
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}