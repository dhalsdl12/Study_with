#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	int per;

	while (num != 4)
	{
		cout << "«��:1, ¥��:2, ������:3, ����:4 >> ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "���κ�? ";
			cin >> per;
			cout << "«�� " << per << "�κ� ���Խ��ϴ�\n";
			break;
		case 2:
			cout << "���κ�? ";
			cin >> per;
			cout << "¥�� " << per << "�κ� ���Խ��ϴ�\n";
			break;
		case 3:
			cout << "���κ�? ";
			cin >> per;
			cout << "������ " << per << "�κ� ���Խ��ϴ�\n";
			break;
		case 4:
			cout << "���� ������ �������ϴ�.\n";
			break;
		default:
			cout << "�ٽ� �ֹ��ϼ���!!\n";
			break;
		}
	}
}