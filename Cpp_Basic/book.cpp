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
	_iBook iBookArr[BOOK_MAX] = {}; // 초기화
	char strSearchName[NAME_SIZE] = {};
	//배열에 추가된 개수를 저장할 변수를 만들어준다. 
	int iBookCount = 0;
	int iBookNumber = 1;
	int flag = 1;
	while (true)
	{
		system("cls");

		// 메뉴를 출력한다.
		cout << "1. 책등록" << endl;
		cout << "2. 책반납" << endl;
		cout << "3. 책대여" << endl;
		cout << "4. 책목록" << endl;
		cout << "5. 종료" << endl;


		int iMenu;
		cout << "메뉴입력 : ";
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

				cout << "========================= 책추가=====================" << endl;
				cin.ignore(1024, '\n');
				cout << "책 제목 : ";
				cin.getline(iBookArr[iBookCount].BookName, NAME_SIZE);

				cout << "대여금액 : ";
				cin >> iBookArr[iBookCount].Bookmoney;

				cout << "대여 여부 [Yes :1 , NO : 0] ";
				cin >> iBookArr[iBookCount].BookRental;
				if (iBookArr[iBookCount].BookRental == 0 || iBookArr[iBookCount].BookRental == 1)
				{
					flag = 0;
				}
				else
				{
					system("cls");
					cout << "1,0 중 하나만 입력해주세요" << endl;
				}

			}

			iBookArr[iBookCount].BookNumber = iBookNumber;
			flag = 1;
			++iBookNumber;
			++iBookCount;

			cout << "책 추가 완료" << endl;




			break;
		case MEMU_RETURN:
			system("cls");




			cout << "========================= 책리턴=====================" << endl;

			cin.ignore(1024, '\n');
			cout << "대여할 책이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(iBookArr[i].BookName, strSearchName) == 0)
				{
					if (iBookArr[i].BookRental == 1)
					{
						cout << "반납했습니다. " << endl;
						iBookArr[i].BookRental = 0;

					}
					else
					{
						cout << "대여중이 아닙니다." << endl;

					}
					break;

				}
			}


			break;
		case MENU_RENTAL:
			system("cls");


			cout << "========================= 책대여=====================" << endl;

			cin.ignore(1024, '\n');
			cout << "대여할 책이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(iBookArr[i].BookName, strSearchName) == 0)
				{
					if (iBookArr[i].BookRental == 1)
					{
						cout << "대여중입니다." << endl;
					}
					else
					{
						cout << "대여했습니다." << endl;
						iBookArr[i].BookRental = 1;

					}
					break;

				}
			}


			break;
		case MENU_OUTPUT:
			system("cls");

			cout << "========================= 책목록=====================" << endl;

			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "책 제목 : " << iBookArr[i].BookName << endl;
				cout << "책 번호 : " << iBookArr[i].BookNumber << endl;
				cout << "대여 금액 : " << iBookArr[i].Bookmoney << endl;
				if (iBookArr[i].BookRental == 1)
				{
					cout << "대여 여부 : 대여중" << endl;
				}
				else
					cout << "대여 여부 : 대여가능" << endl;

			}



			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;



		}
		system("pause");





	}




}