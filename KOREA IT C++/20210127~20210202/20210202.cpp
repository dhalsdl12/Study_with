//���� 9-6 �߻� Ŭ���� ���� ����
//���� �߻�Ŭ���� Calsuclator�� ��ӹ޾� GoodCalc Ŭ������ �����϶�
/*
#include <iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0; //�� ������ �� ����
	virtual int subtract(int a, int b) = 0; //�� ������ �� ����
	virtual double avg(int a[], int size) = 0; //��� ����
};
class GoodCalc : public Calculator {
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	double avg(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};
int main()
{
	int a[] = { 1,2,3,4,5 };
	Calculator *p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3)<<endl;
	cout << p->avg(a, 5) << endl;
	delete p;
}
*/


//���� 9-7�ǽ�
/*
#include <iostream>
using namespace std;

class Calc {
	void input() {
		cout << "���� 2���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "���� ���� " << calc(a, b) << endl;
	}
};
class Add : public Calc {
protected:
	int calc(int a, int b) { return a + b; }
};
class Sub : public Calc {
protected:
	int calc(int a, int b) { return a - b; }
};
int main()
{
	Add add;
	Sub sub;
	add.run();
	sub.run();
}
*/


//----------------------------------------------
//���� 10-1 ���׸� myswap�Լ� �����
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};
template <class T>
void myswap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << "c=" << c << ", d=" << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut������ = " << donut.getRadius() << endl;
	cout << "pizza������ = " << pizza.getRadius() << endl;
}
*/


/*
[��üȭ ����]
1. �����Ϸ��� myswap(a,b); ȣ�⹮�� �������Ҷ� myswap()�Լ��� ã�´�.
2. ���ø����� ����� myswap()�Լ��� �߰��Ѵ�.
3. ��üȭ�Ѵ�.
myswap(a,b);�� �Լ� ȣ�⹮���� ������ a,b�� ��� intŸ���̹Ƿ�,
���ø��� ���׸� Ÿ�� T�� int�� ���Խ��� ��üȭ�� ������
myswap(int &a, int &b);�� �ҽ��ڵ带 ������.
4. ��üȭ�� �Լ��� �ҽ��ڵ带 �������ϰ�, �� �Լ��� ȣ���ϵ��� �������Ѵ�.
*/


//10-4 �迭�� �����ϴ� ������ �Լ� mcopy()�Լ� �����
//�� ���� �迭�� �Ű������� �޾� �迭�� �����ϴ� ���׸� �Լ��� �ۼ��϶�
/*
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n)
{
	for (int i = 0; i < n; i++)
		dest[i] = (T2)src[i];
}
int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H','E','L','L','O' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
		{
			cout << e[i] << ' ';
		}
	cout << endl;
}
*/


//�迭�� ����ϴ� ������ ���ø� �Լ��� ������
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}
void print(char array[], int n) //char�迭�� ����ϱ� ���� �Լ� �ߺ�
{
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
		//array[i]�� intŸ������ ��ȯ�Ͽ� ���� ���
	cout << endl;
}
int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };
	print(x, 5); //���ø� print()�Լ��κ��� ��äȭ
	print(d, 5); //���ø� print()�Լ��κ��� ��äȭ

	char c[5] = { 1,2,3,4,5 };
	print(c, 5); //�ߺ��� print()�Լ��� �켱 ���ε��ȴ�.
}