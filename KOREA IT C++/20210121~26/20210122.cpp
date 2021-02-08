/*
new�� �̿��Ͽ� �������� �迭�� ������ ��, �Ű����� �ִ� �����ڸ� ���� ȣ���� �� ����.
������ ���� �߻�.
��� �߰�ȣ�� �̿��Ͽ� �� ���� ��ü�� �ʱ�ȭ �� �� �ִ�.
Circle *pArray = new Circle[3]{ Circle(1), Circle(2), Circle(3) };
*/


/*
<����>
�������� �Ҵ���� �޸𸮴� �ݵ�� ��ȯ�ؾ� �ϴ°�?
��(heap)�� ���α׷� �����߿� new�� �̿��Ͽ� �������� �Ҵ�޾� ����� �� �ִ� �޸��̴�.
��κ��� �ü������ ���α׷����� ���� ���� �־����� ������,
�� ���α׷��� �������� ���� �޸𸮸� �Ҵ�޴� ����,
�ٸ� ���α׷��� ���� ���� ������ ���� �ʴ´�.
�ٸ�, �Ҵ���� �� �ʿ���Ե� �޸𸮸� ���� ��ȯ���� �ʰ��� �ڵ� �߸�����
���α׷� ���� ��, �� ��ü�� �ü���� ���� ��ȯ�ǹǷ�
���� �޸𸮿� ���� ������ ���� �ʾƵ� �ȴ�.
*/



//���� 4-9 Cuircle�迭�� ���� ���� �� ��ȯ
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {};
	Circle(int r) {
		radius = r;
		cout << "������ ���� radius = " << radius << endl;
	};
	~Circle() { cout << "������ �Ҹ� radius = " << radius << endl; };
	void setRadius(int r) { radius = r; };
	double getArea() { return 3.14*radius*radius; };
};

int main()
{
	Circle *pArray = new Circle[3]; //��ü �迭 ����
									//�� ���� ��ü�� �⺻ ������ Circle()����
	for (int i = 0; i < 3; i++)
	{
		pArray[i].setRadius((i + 1) * 10);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << (pArray + i)->getArea() << endl;
	}
	Circle *p = pArray; //������ p�� �迭�� �ּҰ����� ����
	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << endl;
		p++; //���� ������ �ּҷ� ����
	}

	delete[] pArray;
}
*/


/*
���� 4-10 ��ü ���� ���� ������ ��ȯ ����
���� ������ �Է¹ް� Circle �迭�� ���������϶�.
������ ���� �Է¹޾� Circle �迭�� �����ϰ�,
������ 100���� 200������ ���� ������ ����϶�.
*/
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();

	void setRadius(int r) { radius = r; };
	double getArea() { return 3.14*radius*radius; };
};
Circle::Circle() { radius = 1; }


int main()
{
	cout << "�����ϰ��� �ϴ� ���� ����? ";
	int n, radius;
	cin >> n;
	Circle *pArray = new Circle[n];
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << ": "; //������Ʈ ���
		cin >> radius;
		pArray[i].setRadius(radius); //�� Circle ��ü�� ���������� �ʱ�ȭ
	}
	int count = 0;
	Circle *p = pArray;
	for (int i = 0; i < n; i++)
	{
		cout << p->getArea() << ' ';
		if (p->getArea() >= 100 && p->getArea() <= 200)
			count++;
		p++;
	}
	cout << endl << "������ 100���� 200������ ���� ������ ";
	cout << count << endl;
	
	delete[] pArray;
}
*/


/*
<TIP>
���� �޸� �Ҵ�� �޸� ����(memory leak)
�������� �Ҵ���� �޸��� �ּҸ� �Ҿ���� ���� ��ȯ�� �� ���� �Ǹ�
�޸� ������ �߻��Ѵ�.
�޸� ������ ��� �߻��Ͽ� ���� ũ�Ⱑ �پ��� �Ǹ�.
���� �߿� �޸𸮸� �Ҵ���� �� ���� �ɰ��� ��Ȳ�� �߻��� �� �ִ�.
*/


/*
this�� �⺻���� :
this�� ��ü ��� �Լ��� ȣ��ɶ�, �����Ϸ��� ���� ������ �ʰ� ���޵Ǵ� ��ü�� ���� �ּ��̴�.
- this�� ��ü �ڽ��� ����Ű�� ������
- ��ü���� �ִ�.
- Ŭ������ ����Լ������� ����� �� �ִ�.
- ����Լ��� �����Ϸ� ���� ������ �Ű������̴�.
- static ��� �Լ������� ����� �� ����.
*/

/*
this�� �ʿ��� ���
1. ��� ������ �̸��� ������ �̸����� �Ű����� �̸��� ������ �ϴ� ���
-�Ű� ������ �̸��� �ҽ� ���α׷��� ������ �ּ������� �Ѵ�.
������� �Ű����� �̸��� radius�� �� Circle(int radius)�� ������
�Ű������� �������� ���޵ȴٴ� ������ �޼����� ����ִ�.

2. ��ü�� ����Լ������� ��ü �ڽ��� �ּҸ� ������ ���� �ִ�.
�̶� this�� �ݵ�� �ʿ��ϴ�.
������ �ߺ��� �����Ҷ�, �̷� ��찡 ���� �߻��ϸ�,
this���̴� �����ڸ� �ߺ��� �� ���� ��쵵 �ִ�.

this�� ��������
1. this�� Ŭ������ ����Լ������� ����� �� �ִ�.
2. ����Լ��� ��������Լ��� this�� ����� �� ����.
*/

