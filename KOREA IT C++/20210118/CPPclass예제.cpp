#include <iostream>
using namespace std;

class Circle { //circle class ����
public:		   //class �����
	int radius;
	double getArea();
};
/*
class �����:
class Ű����� Ŭ���� �̸����� ����
�ɹ������� �Լ��� ������ ����
{} �߰�ȣ�� �̿��Ͽ� ���ΰ�, �������� �����ݷ�(;)
*/

/*
���� ������
public: class�ܺη� ���� ������ ���
private: ���������� ����Ʈ��, �ܺο��� ���� �Ұ���
protected: ��Ӱ��迡�� ����
*/
double Circle::getArea() { //class ������(����Լ��� �ڵ屸��)
	return 3.14*radius*radius;
}
/*
�Լ��� ����Ÿ��
Ŭ�����̸�
��������������
����Լ���� �Ű�����
*/

int main()
{
	Circle donut; //donut��ü ����
	donut.radius = 1; //donut ��ü�� �������� 1�� ����
	double area = donut.getArea(); //donut ��ü�� ���� �˾Ƴ��� 
	cout << "donut ������ " << area << endl;

	Circle pizza; //pizza��ü ����
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}