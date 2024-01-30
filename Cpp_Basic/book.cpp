#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define MONEY_SIZE 16
#define BOOK_MAX 32


struct _iBook
{
	char BookName[NAME_SIZE];
	char Bookmoney[MONEY_SIZE];
	int  BookNumber;
	int  BookRental;

};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MEMU_RETURN,
	MENU_RENTAL,
	MENU_OUTPUT,
	MENU_EXIT

};




int main()
{
	_iBook iBookArr[BOOK_MAX] = {}; // �ʱ�ȭ
	char strSearchName[NAME_SIZE] = {};
	//�迭�� �߰��� ������ ������ ������ ������ش�. 
	int iBookCount = 0;
	int iBookNumber = 1;
	int flag = 1;
	while (true)
	{
		system("cls");

		// �޴��� ����Ѵ�.
		cout << "1. å���" << endl;
		cout << "2. å�ݳ�" << endl;
		cout << "3. å�뿩" << endl;
		cout << "4. å���" << endl;
		cout << "5. ����" << endl;


		int iMenu;
		cout << "�޴��Է� : ";
		cin >> iMenu;


		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');
			continue;

		}

		if (iMenu == MENU_EXIT)
			break;
		switch (iMenu)
		{
		case MENU_INSERT:



			system("cls");
			if (iBookCount == BOOK_MAX)
				break;
			while (flag)
			{

				cout << "========================= å�߰�=====================" << endl;
				cin.ignore(1024, '\n');
				cout << "å ���� : ";
				cin.getline(iBookArr[iBookCount].BookName, NAME_SIZE);

				cout << "�뿩�ݾ� : ";
				cin >> iBookArr[iBookCount].Bookmoney;

				cout << "�뿩 ���� [Yes :1 , NO : 0] ";
				cin >> iBookArr[iBookCount].BookRental;
				if (iBookArr[iBookCount].BookRental == 0 || iBookArr[iBookCount].BookRental == 1)
				{
					flag = 0;
				}
				else
				{
					system("cls");
					cout << "1,0 �� �ϳ��� �Է����ּ���" << endl;
				}

			}

			iBookArr[iBookCount].BookNumber = iBookNumber;
			flag = 1;
			++iBookNumber;
			++iBookCount;

			cout << "å �߰� �Ϸ�" << endl;




			break;
		case MEMU_RETURN:
			system("cls");




			cout << "========================= å����=====================" << endl;

			cin.ignore(1024, '\n');
			cout << "�뿩�� å�̸��� �Է��ϼ��� : ";
			cin.getline(strSearchName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(iBookArr[i].BookName, strSearchName) == 0)
				{
					if (iBookArr[i].BookRental == 1)
					{
						cout << "�ݳ��߽��ϴ�. " << endl;
						iBookArr[i].BookRental = 0;

					}
					else
					{
						cout << "�뿩���� �ƴմϴ�." << endl;

					}
					break;

				}
			}


			break;
		case MENU_RENTAL:
			system("cls");


			cout << "========================= å�뿩=====================" << endl;

			cin.ignore(1024, '\n');
			cout << "�뿩�� å�̸��� �Է��ϼ��� : ";
			cin.getline(strSearchName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(iBookArr[i].BookName, strSearchName) == 0)
				{
					if (iBookArr[i].BookRental == 1)
					{
						cout << "�뿩���Դϴ�." << endl;
					}
					else
					{
						cout << "�뿩�߽��ϴ�." << endl;
						iBookArr[i].BookRental = 1;

					}
					break;

				}
			}


			break;
		case MENU_OUTPUT:
			system("cls");

			cout << "========================= å���=====================" << endl;

			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "å ���� : " << iBookArr[i].BookName << endl;
				cout << "å ��ȣ : " << iBookArr[i].BookNumber << endl;
				cout << "�뿩 �ݾ� : " << iBookArr[i].Bookmoney << endl;
				if (iBookArr[i].BookRental == 1)
				{
					cout << "�뿩 ���� : �뿩��" << endl;
				}
				else
					cout << "�뿩 ���� : �뿩����" << endl;

			}



			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;



		}
		system("pause");





	}




}