#include <iostream>
#include <string> 
using namespace std;

int main()
{
	string song("Falling in love with you"); // ���ڿ� song
	string elvis("Elvis Presley"); // ���ڿ� elvis
	string singer; // ���ڿ� singer

	cout << song + "�� �θ� ������"; // + �� ���ڿ� ����
	cout << "(��Ʈ : ù���ڴ� " << elvis[0] << ")?";  // [] ������ ���

	getline(cin, singer); // ���ڿ� �Է� getline�� ��ĭ�� �����ϴ� ���ڿ� �Է°���
	if (singer == elvis)  // ���ڿ� ��
		cout << "�¾ҽ��ϴ�.\n";
	else
		cout << "Ʋ�Ƚ��ϴ�. " + elvis + "�Դϴ�." << endl; // +�� ���ڿ� ����
}