/*
<����> �Լ� �ߺ��� ����ð�
c++�����Ϸ��� �Լ� �ߺ��� ���������� �Ǻ��ϰ�, �ߺ��� �Լ��� ȣ���� ������ Ȯ���Ѵ�.
�Լ� �ߺ��� �����Ͻÿ� �̷������ ������, �Լ� �ߺ����� ���� ����ð� ���ϴ� ����.
*/


//���� 6-1 big() �Լ� �ߺ� ����
//ū ���� �����ϴ� ���� �� ���� big �Լ��� �ߺ� �����϶�.
/*
#include <iostream>
using namespace std;

int big(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int big(int a[], int size)
{
	int res = a[0];
	for (int i = 1; i < size; i++)
		if (res < a[i]) res = a[i];
	return res;
}
int main()
{
	int array[5] = { 1,9,-2,8,6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
	return 0;
}
*/

//���� 6-2 sum() �Լ� �ߺ� ����
//�Լ� sum()�� ȣ���ϴ� ��찡 ������ ������, �Լ� sum()�� �ߺ� �����϶�.
//sum()�� ù��° �Ű������� �ι�° �Ű��������� ���� ���� ������ ȣ��ȴٰ� �����Ѵ�.
/*
#include <iostream>
using namespace std;
int sum(int a, int b)
{
	int s = 0;
	for (int i = a; i <= b; i++) s += i;
	return s;
}
int sum(int a)
{
	int s = 0;
	for (int i = 0; i < a; i++) s += i;
	return s;
}
int main()
{
	cout << sum(3,5) << endl << sum(3) << endl << sum(100) << endl;
	return 0;
}
*/


/*
����Ʈ �Ű������� ���� �Ű����� �տ� ����� �� ����.
����Ʈ �Ű������� �ǳ��� ������ ����Ǿ�� �Ѵ�.
*/

//6-3 ����Ʈ �Ű������� ���� �Լ� ���� �� ȣ��
/*
#include <iostream>
using namespace std;
#include <string>

void star(int a = 5);
void msg(int id, string text = " ");

void star(int a)
{
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text)
{
	cout << id << ' ' << text << endl; ;
}
int main()
{
	star();
	star(10);
	msg(10);
	msg(10, "hello");
	return 0;
}
*/


// 6-4  ����Ʈ �Ű������� ���� �Լ� ����� ����
//�Լ� f()�� ȣ���ϴ� ��찡 ������ ������ f()�� ����Ʈ �Ű������� ���� �Լ��� �ۼ��϶�.
/*
f(); //�� �ٿ� ��ĭ�� 10�� ����Ѵ�.
f('%'); // ���ٿ� '%'�� 10�� ����Ѵ�.
f('@', 5); //�ټ��ٿ� '@'�� 10�� ����Ѵ�
*/
/*
#include <iostream>
using namespace std;
void f(char c = ' ', int line = 1);
void f(char c, int line)
{
	for (int m = 0; m < line; m++)
	{
		for (int n = 0; n < 10; n++)
			cout << c;
		cout << endl;
	}
}
int main()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}
*/


//�ߺ� �Լ���� ����Ʈ �Ű������� ���� �Լ��� �Բ� ��� �Ұ�

//���� 6-5 ����Ʈ �Ű������� �̿��Ͽ� �ߺ� �Լ� ����ȭ ����
/*
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') //n���� c���ڸ� �� ���ο� ���
{
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
}
int main()
{
	fillLine(); //25���� *�� �Ѷ��ο� ���
	fillLine(10, '%'); //10���� %�� �� ���ο� ���
}
*/

/*
#include <iostream>
using namespace std;

class MyVector
{
	int *p;
	int size;
public:
	MyVector(int n = 100)
	{
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};
int main()
{
	MyVector *v1, *v2;
	v1 = new MyVector();
	v2 = new MyVector(1024);

	delete v1;
	delete v2;
}
*/



/*
static�� ���� �� �Լ��� �����ֱ�(life cycle)�� ������(scope)�� �����ϴ� ����� �ϳ��μ�
static���� ����� ������ �Լ��� �����ֱ�� �������� ������ ���� Ư¡�� ������.
�����ֱ� - ���α׷��� ������ �� �����ǰ� ���α׷��� ������ �� �Ҹ�
������ - ������ �Լ��� ����� ���� ������ ���. ���� Ȥ�� �������� �����Ѵ�.

�ܺ� ������ ������ ������ ����.........
*/
/*
static���� : ������ �������� ���α׷� ����ñ��� ��밡��
static�Լ� : �ش� ���� �������� ��밡��     
*/


#include <iostream>
using namespace std;

class Person {
public:
	int money; //���� ������ ��
	void addMoney(int money)
	{
		this->money += money;
	}
	static int sharedMoney; //����
	static void addShared(int n)
	{
		sharedMoney += n;
	}
};
//static ���� ����. ���� ������ ����
int Person::sharedMoney = 10; //10���� �ʱ�ȭ

int main()
{
	Person han;
	han.money = 100; //���ε� 100
	han.sharedMoney = 200; //static ��� ���� 200

	Person lee;
	lee.money = 150;
	lee.addMoney(200); //lee�� ���ε� = 350
	lee.addShared(200); //static��� ���� , ���� = 400

	cout << han.money << ' ' << lee.money << endl;
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}