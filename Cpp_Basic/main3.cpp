#include <iostream>
#include <ctime>

using namespace std;

/*
����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ����̴�.
enum ����ü�� {} �� ���·� �����ȴ�.
����ü���� �̿��ؼ� ����ü Ÿ���� ������ ���� �����ϴ�.
��, ����ü ��ü�� ��������� ���� Ÿ���� �� ���� �ִ�.
����ü�� ���ڿ� �̸��� �ٿ��ִ� ����̴�.
*/

enum NUM
{
	NUM_0, // �ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο��ȴ�.
	NUM_1,
	NUM_2,
	NUM_3,
};

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

#define NUM_4	4

int main(void)
{
	/*
	switch �� : �б⹮�� �� �����̴�. if���� ������ üũ�ϴ� �б⹮�̶��
	switch���� ���� ������ üũ�ϴ� �б⹮�̴�.

	���� : switch(����) {} �� ���·� �����ȴ�.
	�ڵ� �� �ȿ��� case break ������ ���� �ȴ�
	case ���: �� ���·� ó���� �ǰ� �������� ���������� ����
	case �ڿ� ���� ����� ���ϰ� �ȴ�.
	*/
	int iNumber = 1;
	cout << "���ڸ� �Է��ϼ��� : ";
	//cin >> iNumber;

	switch (iNumber)
	{
	case NUM_1: // iNumber���� ���������� ���� ����Ǵ� case ������ �����ȴ�.
		cout << "�Է��� ���ڴ� " << iNumber << "�Դϴ�." << endl;
		break; // break �� ������ �Ǹ� switch ���� ���������� �ȴ�.
	case NUM_2:
		cout << "�Է��� ���ڴ� " << iNumber << "�Դϴ�." << endl;
		// ����ó�� break�� ���� ��� �ٷ� �Ʒ��� �ִ� case ������ ������ ������ �ǰ� �Ѵ�.
	case NUM_3:
		cout << "�Է��� ���ڴ� 3�Դϴ�." << endl;
		break;
	case NUM_4:
		cout << "�Է��� ���ڴ� " << iNumber << "�Դϴ�." << endl;
		break;
	default: // case�� �������� ���� ���ڰ� ���� ��� ���� �ȴ�.
		cout << "�� ���� �����Դϴ�." << endl;
		break;
	}

	// ����ü Ÿ���� ������ �����ߴ�.
	// ����ü Ÿ�� ������ ������ 4byte�� �����ϰ� �ȴ�.
	// ����ü�� �̿��ؼ� ������ ������ ���� ǥ�� ������
	// ����ü�� ������ ���� �ȿ��� �����ؼ� ����Ѵ�.
	NUM		eNum = (NUM)10;

	// sizeof(Ÿ�� or ����)�� �ϰ� �Ǹ� �ش� Ÿ�� Ȥ�� 
	// ������ �޸� ũ�⸦ �����ش�.

	cout << sizeof(NUM) << endl;

	// typeid(Ÿ�� or ����).name()�� �ϰ� �Ǹ� typeid �ȿ� �� Ÿ�� Ȥ��
	// ������ Ÿ���� ���ڿ��� ��ȯ���ش�.
	cout << typeid(NUM).name() << endl;
	cout << eNum << endl;

	/*
	�ݺ��� : Ư�� �۾��� �ݺ��ؼ� �������ִ� ����̴�.
	���� : for, while, do-while 3������ �����Ѵ�.
	while(���ǽ�) {} �� ���·� �����ȴ�.
	while���� ���ǽ��� üũ�ؼ� true�� ��� �ڵ� �� ���� �ڵ尡 ���۵ǰ�
	�ٽ� ���ǽ��� üũ�Ѵ�.
	���ǽ��� false�� �Ǹ� while���� ���������� �ȴ�.
	�ݺ��� �ȿ��� break�� �����ԵǸ� �ش� �ݺ����� ���������� �ȴ�.
	*/
	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}

	// ȭ���� ������ �����ش�.
	system("cls");

	// ���� ���̺� ����
	srand((unsigned int)time(0));

	int iPlayer, iAi;
	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_END)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			// �Ͻ�����
			system("pause");
			// continue : �ݺ����� ���������� �̵������ִ� ����̴�. 
			continue;
		}

		else if (iPlayer == SRP_END)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}

		// ���� ������ �Ѵ�.
		iAi = (rand() % 3) + SRP_S;

		switch (iAi)
		{
		case SRP_S:
			cout << "AI : ����" << endl;
			break;
		case SRP_R:
			cout << "AI : ����" << endl;
			break;
		case SRP_P:
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAi;
		if (iWin == 1 || iWin == -2)
			cout << "iPlayer �¸�" << endl;

		else if (iWin == 0)
			cout << "���" << endl;

		else
			cout << "AI �¸�" << endl;

		system("pause");

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "iPlayer �¸�" << endl;
			break;
		case 0:
			cout << "���" << endl;
			break;
		default:
			cout << "AI �¸�" << endl;
			break;

		}
	}

	return 0;
}