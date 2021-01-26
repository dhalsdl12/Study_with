/*
call by value

void SwapByValue(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = num1;
}
���� �����ϸ鼭 ȣ���ϰ� �Ǵ� �Լ��̹Ƿ� �� �Լ��� call by value�̴�.
�� ��� �Լ� �ܿ� ����� �������� ������ �Ұ��� �ϴ�.


call by reference

void SwapByRef(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr1;
}
���� ���̵�, �ּҰ��� �����ϸ鼭 ȣ���ϰ� �Ǵ� �Լ��̹Ƿ� �� �Լ��� call by reference�̴�.
�� ��� ���ڷ� ���޵� �ּ��� �޸𸮰����� ������ �����ϴ�


int *SimpleFunc(int *ptr)
{
	return ptr+1;
}
������ ptr�� ���޵� �ּҰ��� �������� ���� �̴� call by value�̴�.


int *SimpleFunc(int *ptr)
{
	if(ptr == NULL)
		return NULL;
	*ptr = 20;
	return ptr;
}
�ּҰ��� ���޹޾Ƽ� �ܺο� �ִ� �޸� ������ ���� ������ �̴� call by reference�̴�.
c++���� �ΰ��� ������ call by reference�� �����Ѵ�.
�ϳ��� �ּҰ��� �̿��ϴ� �����̸�, �ٸ� �ϳ��� �����ڸ� �̿��ϴ� �����̴�.
*/


//�����ڸ� �̿��� call by reference

/*#include <iostream>
using namespace std;
void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
int main()
{
	int val1 = 10;
	int val2 = 20;
	SwapByRef2(val1, val2);
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
	return 0;
}*/


/*
�Ű������� �Լ��� ȣ��� �� ������ �Ǵ� ���� �̹Ƿ�,
�Լ� ȣ���� �������� ����� ���ÿ� ���޵Ǵ� ������� �ʱ�ȭ �ȴ�.
��, �Ű������� ����� �����ڴ� ������ ����� ���ÿ� �ʱ�ȭ�ȴ�.
*/

//������ ������� ���� ��ȯ�ϴ� ���
/*
#include <iostream>
using namespace std;
int RefRetFuncTwo(int &ref)
{
	ref++;
	return ref;
}
int main()
{
	int val1 = 10;
	int val2 = RefRetFuncTwo(val1);
	val1 += 1;
	val2 += 100;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
	return 0;
}
*/
/*
�����ڸ� ��ȯ�ϰ�, ������ ����� ���� ��ȯ�ϰ�, ��ȯ���� �������� �ƴ϶�� ���̴� ����!
������ �����ڰ� �����ϴ� ���̳� ������ ����� ���� ��ȯ�ǹǷ�
int val2 = RefRetFuncTwo(val1); //O
int &val2 = RefRetFuncTwo(val1); //O

��ȯ���� �������� ��쿡�� ��ȯ�Ǵ� ����� �����ڷ� �׸��� ������ ���� �� �ִ�.
�׷��� ��ȯ���� ���� ���¶��, �����ڴ� �� ���� ���� �� ����!
int val2 = RefRetFuncTwo(val1); //O
int &val2 = RefRetFuncTwo(val1); //X
*/



/*
���� ���� : �ּҰ��� �ϳ��� �����
���� ���� : ������ �ٸ� ��ü�� �����. ������ �����Ҵ�

��ü�� ���� ���� ������
- ������ �纻�� ���� name�����ͷ� ���� �迭�� �����ϰ� �ֱ� ������
�纻 ��ü���� name���ڿ��� �����ϸ� ���� ��ü�� name���ڿ��� ����Ǵ� ������ �߻��Ѵ�.
�̷��� ������ ���� ��� �����ڰ� �������� ���� ���¿��� �߻��ϱ� ������
������ ã�Ƴ��� �����ϴµ� ���� �ð��� �ɸ��⵵ �Ѵ�.
������ ���� ���簡 �Ͼ�� �ʵ��� �ؾ��Ѵ�.


���������(copy constructor) : ��������� ����ȴ�.
������
class classname{
	classname(const classname& c); //��������� classname& �ڱ�Ŭ������ ���� �����Ű�����
};
Ư¡
- ����������� �Ű������� ���� �ϳ��̴�.
- �ڱ� Ŭ������ ���� ������ ����ȴ�.
- ��������ڴ� Ŭ������ ���� �Ѱ��� ������ �� �ִ�.
*/

//5-9 Circle�� ���� �����ڿ� ��ü ����
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle &c); //���� ������ ����
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
Circle::Circle(const Circle &c) //�� ������� ����
{
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << this->radius << endl;
}
int main()
{
	Circle src(30); //src��ü�� ���� ������ ȣ��
	Circle dest(src); //dest ��ü�� ���� ������ ȣ��
	
	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}
*/


/*
���� �����ڰ� ����Ǿ� ���� �ʴ� Ŭ�������� �����Ϸ��� ����Ʈ ��������ڸ� ���������� �����ϰ�
�� �����ڸ� ȣ���ϵ��� ������ �Ѵ�.
�����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�� ���� ���� ���縦 �����ϵ��� ������� �ڵ��̴�.
�����Ϸ��� ������ ���� �����ڴ� ���� ��ü�� ��� ����� �ϴ��Ϸ� �纻(this)�� �����ϵ���
�����ȴ�. ���� CircleŬ������ ��� ������ radius�ϳ� ���̹Ƿ�
radius���� �����ϴ� �ڵ�� �Ǿ��ִ�.
*/

//5-10 ���� ���� �����ڸ� ����Ͽ� ���α׷��� ������ ����Ǵ� ���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char *name;
	int id;
public:
	Person(int id, const char* name);
	~Person();
	//�����Ϸ��� ���ؼ� ����Ʈ ���� ������ ����
	//Person::Person(const Person &p)
	//{
	//this->id = p.id;
	//this->name = p.name;
	//}
	
	void changeName(const char *name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) //������
{
	this->id = id;
	int len = strlen(name); //name�� ���ڰ���
	this->name = new char[len + 1]; //name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name); //name�� ���ڿ� ����
}
Person::~Person()
{
	if (name) //���� name�� �����Ҵ�� �迭�� ������
		delete[] name; //�����Ҵ� �޸� �Ҹ�
}
void Person::changeName(const char* name) //�̸�����
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae"); //1 father ��ü ����
	Person daughter(father); //2 daughter ��ü���� ����. ��������� ȣ��

	cout << "daughter ��ü ���� ���� --- " << endl;
	father.show(); //3 father ��ü ���
	daughter.show(); //4 daughter ��ü ���

	daughter.changeName("Grace"); //4 daughter�̸� ����
	cout << "daughter �̸� ���� �� �� --- " << endl;
	father.show(); //5 father ��ü ���
	daughter.show(); //6 daughter ��ü���
	
	return 0; //6,7 daughter father ��ü �Ҹ�
}
*/


//5-11 ���� ���� �����ڸ� ���� �������� personŬ����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char *name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person); //���������
	~Person();

	void changeName(const char *name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) //������
{
	this->id = id;
	int len = strlen(name); //name�� ���ڰ���
	this->name = new char[len + 1]; //name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name); //name�� ���ڿ� ����
}
Person::Person(const Person &person)
{
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}
Person::~Person()
{
	if (name) //���� name�� �����Ҵ�� �迭�� ������
		delete[] name; //�����Ҵ� �޸� �Ҹ�
}
void Person::changeName(const char* name) //�̸�����
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae"); //1 father ��ü ����
	Person daughter(father); //2 daughter ��ü���� ����. ��������� ȣ��

	cout << "daughter ��ü ���� ���� --- " << endl;
	father.show(); //3 father ��ü ���
	daughter.show(); //4 daughter ��ü ���

	daughter.changeName("Grace"); //4 daughter�̸� ����
	cout << "daughter �̸� ���� �� �� --- " << endl;
	father.show(); //5 father ��ü ���
	daughter.show(); //6 daughter ��ü���

	return 0; //6,7 daughter father ��ü �Ҹ�
}
*/


/*
������ ���� ����
��������� father�� �������� daughter�� ���� �����ϱ� ������,
���� �����ڰ� ȣ��ɰ��� ������ ���ɼ��� ����.
�׷��� �����ڵ� �𸣰� ���� �����ڰ� ȣ��Ǵ� �ٸ� ������ �ִ�.
�̷� ��츦 ����Ͽ� �����ϸ� ���� ���� �����ڸ� ������ ���ƾ��Ѵ�.

������ ���� ������ 3���� ���(�����Ϸ��� ��������ڸ� �ڵ����� ȣ���ϴ� ���)
1. ��ü�� �ʱ�ȭ�Ͽ� ��ü�� �����ɶ�
2. '�������� ȣ��'�� ��ü�� ���޵� ��
3. �Լ��� ��ü�� ������ ��
*/