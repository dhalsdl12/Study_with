#include <iostream>
using namespace std;

int main()
{
	cout << "�ʺ� �Է��ϼ���>> ";
	int width;
	cin >> width; //Ű����κ��� �ʺ� �о� width ������ ����
	//cin >> width >> h; ����! �����̳� tab���� ����



	cout << "���̸� �Է��ϼ���>> ";
	int height;
	cin >> height; //Ű����κ��� ���̸� �о� height ������ ����

	int area = width * height; //�簢�� ���� ���
	cout << "������ " << area << '\n'; //������ ����ϰ� ���� �ٷ� �Ѿ
}