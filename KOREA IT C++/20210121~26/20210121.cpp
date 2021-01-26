/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	void setRadius(int r) { radius = r; };
	double getArea();
};
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle circles[2][3];
	
	//�ʱⰪ���� ��� �����
	//Circle circles[2][3] = {{Circle(1),Circle(2),Circle(3)},{Circle(4),Circle(5),Circle(6)}};
	//�̷��� �ٷ� �ʱⰪ���� ���� ����!!
	
	int cnt = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//circles[i][j].setRadius(cnt);
			//tRadius�� ����ϴ� ������ �ʱⰪ���� �ٷ� ���� �ʾұ� ������
			//radius�� �����ϱ� ���ؼ� class�ȿ� �ִ� �Լ��� �̿��Ͽ� �ִ´�.
			cnt++;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Circle [" << i << "," << j << "]�� ������ ";
			cout << circles[i][j].getArea() << endl;
		}
	}
	return 0;
}
*/


/*
���� �����⳪ �׷��������⸦ �����ϴ� ���, ������ �ؽ�Ʈ�� �Է��� ������,
�� ���� ������ �׸��������� ������� ������ �޷��ֱ� ������,
�ʿ��� �޸𸮸� ���α׷��� �ۼ��ϴ� �ܰ迡�� ��� �����ϴ� ���� �Ұ����ϴ�.
�̷� ������ �������α׷��� ����, �����߿� �ʿ��� ��ŭ �޸𸮸� �Ҵ�ް�
�ʿ� ������ ��ȯ�ϴ� '���� �޸� �Ҵ�/��ȯ ��Ŀ����'�� �ʿ��ϴ�.
*/

/*
C++������ new, delete �����ڸ� �̿��Ѵ�.
new�����ڴ� heap(��)�̶�� �ý��� �������κ��� �޸𸮸� �Ҵ�ް�,
delete �����ڴ� �Ҵ���� �޸𸮸� ������ ��ȯ�Ѵ�.
*/

/*
new�����ڴ� '������Ÿ��'�� ũ�⸸ŭ �����κ��� �޸𸮸� �Ҵ�ް� �ּҸ� �����Ѵ�.
�� ��� '������ ����'�� �Ҵ���� �޸��� �ּҸ� ������.
delete�����ڴ� '�����ͺ���'�� ����Ű�� �޸𸮸� ������ ��ȯ�Ѵ�.
'������Ÿ��'�� int, char, double �� �⺻ Ÿ�Ի� �ƴ϶� ����ü(struct),
Ŭ����(class)�� �����Ѵ�.
*/

/*
�� �޸𸮰� �����ϸ� new NULL�� �����ϹǷ�,
new�� ���ϰ��� NULL���� �˻��ϴ� ���� ����.
*/


/*
#include <iostream>
using namespace std;
int main()
{
	int *p;
	p = new int;
	if (!p) // p==NULL�� ����
	{		//�� �޸𸮰� �����ϸ� null�� �����ϹǷ�, ���ϰ��� null���� �˻�
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}
	*p = 5; //�Ҵ� ���� ���� ������ 5����
	int n = *p; //p�� ����Ű�� �ִ� ���� ���� n������ �־���
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;
	delete p;
}
*/


/*
new & delete
malloc()�� ����ϴ� �޸��� �����Ҵ� ���!
ũ�⸦ ����Ʈ ������ ����ϴ� ���� ��ġ�� �ʾƵ� �ȴ�!
int �� ������ �Ҹ� : int *ptr1 = new int;
double �� ������ �Ҹ� : double *ptr2 = new double;
���̰� 3�� int �� �迭�� �Ҵ� : int *arr1 = new int[3];
���̰� 7�� double �� �迭�� �Ҵ� : double *arr2 = new double[7];
*/

/*
free()�� ����ϴ� �޸��� ���� ���!
�Ҵ��� int �� ������ �Ҹ� : delete ptr1;
�Ҵ��� double �� ������ �Ҹ� : delete ptr2;
�Ҵ��� int �� ������ �Ҹ� : delete [] arr1;
�Ҵ��� double �� ������ �Ҹ� : delete [] arr2;
*/

/*
new �����ڷ� �Ҵ�� �޸� ������ �ݵ�� delete �Լ� ȣ���� ���ؼ� �Ҹ� �ؾ��Ѵ�.
Ư�� ȣ���ϰ� �Ǵ� new & delete �������� ���� Ư����
malloc & free�� ū ���̰� �ִ�!
*/


/*
new�����ڴ� '�迭�� ũ��'���� �迭�� �Ҵ�޾Ƽ� �ּҸ� �����Ѵ�.
delete�� '������ ����'�� ����Ű�� �迭 �޸𸮸� ��ȯ�Ѵ�.
new�� �̿��ϸ� int, char �� �⺻ Ÿ�԰� ����ü, Ŭ���� �� ����ڰ� ������ Ÿ����
�迭�� �Ҵ���� �� �ִ�.
�������� �Ҵ���� �迭�� []�� �̿��ؼ� ���� �迭�� ������ ������� ����Ѵ�.
p[i] = i //p�� �迭�� ���� ������ �̹Ƿ�, *(p+1) = 1 �� ����
*/


/*
����>
����ڷκ��� �Է��� ������ ������ �Է� �޾� �迭�� ���� �Ҵ� �ް�,
�ϳ��� ������ �Է� ���� �� ���� ����ϴ� ���α׷��� �ۼ��϶�.
*/
/*
#include <iostream>
using namespace std;

int main()
{
	cout << "�Է��� ������ ������? ";
	int n;
	cin >> n;
	if (n <= 0) return 0;
	int *p = new int[n]; //n���� ���� �迭 ���� �Ҵ�
	if (!p)
	{
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�." << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "��° ���� �Է� : "; //������Ʈ ���
		cin >> p[i]; //Ű����κ��� ���� �Է�
		sum += p[i];
	}
	cout << "��� = " << sum / n << endl;
	delete[] p; //�迭 �޸� ��ȯ
}
*/


/*
�迭 �����Ҵ�� �ʱ�ȭ ���
int *pArry = new int[] {1,2,3,4};
	//1,2,3,4�� �ʱ�ȭ�� ���� �迭 ����, �߰�ȣ ����Ͽ� �ʱ갪 ��������
*/


/*
<����>
C����� �޸� ���� �Ҵ�� ��ȯ �Լ��� malloc()�� free()��
C++���α׷������� ����� �� �ִ�.
������� int *p = (int*)malloc(5*sizeof(int)); //5���� ���� �迭�� �����Ҵ�
1. malloc()�� �Ҵ���� ũ�� (5*sizeof(int))�� �����ؾߵǰ�,
���ϵǴ� �����͸� ����ȯ(int*) �ؾ��ϴ� �������� ������,
new�� �̷��� �������� ����.

2. malloc()�̳� free()�� ����ϱ� ���ؼ� <cstdlib>�� include�ؾ�������.
new�� delete�� �⺻ C++�����ڷμ� ��� ������ϵ� include �� �ʿ䰡 ����.
c++ �����ڷν� malloc(), free()�� �ؾ������ ���� ����.
*/


//��ü�������� �� ��ȯ ����
/*#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {}; //���� ������
	Circle(int r) { //Ÿ�� ������
		radius = r;
		cout << "������ ���� radius = " << radius << endl;
	};
	~Circle() { //�Ҹ���
		cout << "�Ҹ��� ���� radius = " << radius << endl;
	};
	void setRadius(int r) { radius = r; }; //����Լ�
	double getArea() { return 3.14*radius*radius; }; //����Լ�
};

int main()
{
	Circle *p, *q; //������ ���� ����
	p = new Circle; //�����޸��Ҵ�(�����ڽ���)
	q = new Circle(30); //�����޸��Ҵ�(�Ű������ִ� �����ڽ���)
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p; //�����޸� ��ȯ - ������ ������ ������� ���ϴ� ������� delete����
	delete q; //�����޸� ��ȯ
}
*/


/*
<����>
�Ű����� ���� �����ڸ� ȣ���� ��
Circle waffle; ��� �ۼ��ؾ��Ѵ�
Circle waffle(); �̿� ���� �ۼ��ϸ� ������ �߻���Ű���� ������
�Լ��� �����ϱ� ������ ��� �߻���Ű�⵵ �Ѵ�.
�׷���
Circle *p = new Circle;
Circle *p = new Circle(); �� ���� ����.
*/

#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() :Circle(1) {}; //���� ������
	Circle(int r) { //Ÿ�� ������
		radius = r;
		cout << "������ ���� radius = " << radius << endl;
	};
	~Circle() { //�Ҹ���
		cout << "�Ҹ��� ���� radius = " << radius << endl;
	};
	void setRadius(int r) { radius = r; }; //����Լ�
	double getArea() { return 3.14*radius*radius; }; //����Լ�
};

int main()
{
	int radius;
	while (true)
	{
		cout << "���� ������ �Է�(�����̸� ����)>> ";
		cin >> radius;
		if (radius < 0) break;
		Circle *p = new Circle(radius); //���� ��ü ����
		cout << "���� ������ " << p->getArea() << endl;
		delete p; //��ü ��ȯ
	}
}