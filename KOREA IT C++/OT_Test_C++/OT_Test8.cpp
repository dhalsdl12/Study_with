#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	int per;

	while (num != 4)
	{
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4 >> ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "몇인분? ";
			cin >> per;
			cout << "짬뽕 " << per << "인분 나왔습니다\n";
			break;
		case 2:
			cout << "몇인분? ";
			cin >> per;
			cout << "짜장 " << per << "인분 나왔습니다\n";
			break;
		case 3:
			cout << "몇인분? ";
			cin >> per;
			cout << "군만두 " << per << "인분 나왔습니다\n";
			break;
		case 4:
			cout << "오늘 영업은 끝났습니다.\n";
			break;
		default:
			cout << "다시 주문하세요!!\n";
			break;
		}
	}
}