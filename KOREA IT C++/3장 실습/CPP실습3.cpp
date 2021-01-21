#include <iostream>
#include <string>
using namespace std;

class Integer {
	int number;
public:
	Integer(int n) { number = n; };
	Integer(string s) { number = stoi(s); };
	int get();
	void set(int n);
	bool isEven();
};
int Integer::get() {
	return number;
}
void Integer::set(int n) {
	number = n;
}
bool Integer::isEven() { return true; }
int main()
{
	Integer n(30);
	cout << n.get() << ' '; //30출력
	n.set(50);
	cout << n.get() << ' '; //50출력

	Integer m("300");
	cout << m.get() << ' '; //300출력
	cout << m.isEven(); // true(정수로 1) 출력
}