
#include <iostream>


using namespace std;

#define NAME_SIZE		32
#define ADDRESS_SIZE	128
#define PHONE_SIZE		14
#define STUDENT_MAX		10

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_PRINT,
	MENU_EXIT
};

int main(void)
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// �迭�� �߰��� ������ ������ ������ ������ش�.
	int iStudentCount = 0;
	int iStudentNumber = 1;
	while (true)
	{
		system("cls");

		// �޴��� ����Ѵ�.
		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;
		
		// cin�� ���� �����ʿ� int������ ���� ������ �Է��ؾ��Ѵ�.
		// �����ʿ� ���� ���� Ÿ�Կ� ���缭 ���� �Է��ؾߵǴµ�
		// ������ �ƴ� ���ڸ� �Է��� ��� ������ �߻��Ѵ�.
		// ����ó���� ������ �߻��ߴ����� ���⼭ üũ�Ͽ�
		// ������ �߻��ϸ� cin ������ ���� ���۸� ����ְ�
		// cin ���ο� �Է� ���۰� �ִµ� �Է� ���۴� �Է��� ���� �����س���
		// �� ���� ������ �־��ִ� ������ �Ѵ�.
		// �� �Է� ���ۿ� \n�� ���������Ƿ� ���۸� ��ȸ�Ͽ� \n�� �����ش�.
		// ���� : �ӽð����̴�
		// ���� ������ üũ�Ѵ�. cin.fail()�� ���� �� ������ �߻����� ��
		// true ��ȯ

		if (cin.fail())
		{
			// ���� ���۸� ����ش�.
			cin.clear();

			// �Է¹��ۿ� \n�� ���� �����Ƿ� �Է� ���۸� �˻��Ͽ� \n�� �����ش�.
			// ù ��°���� �˻��ϰ��� �ϴ� ���� ũ�⸦ �����Ѵ�.
			// �˳��ϰ� 1024����Ʈ�� �������־���.
			// �� ��°�� ã���� �ϴ� ���ڸ� �־��ش�.
			// �׷��� �Է� ���� ó������ \n�� �ִ� ������ ã�Ƽ� �� �κ���
			// ��� �����༭ �ٽ� �Է� ���� �� �ֵ��� ���ش�.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;


		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "=============== �л� �߰� ===============" << endl;
			// ��ϵ� �л��� ��� �� �� �ִ� �ִ�ġ�� ��� ���̻� ����� �ȵȴ�.
			if (iStudentCount == STUDENT_MAX)
				break;
			// �л� ������ �߰��Ѵ�. �л� ������ �й�, �̸�, �ּ�, ��ȭ��ȣ
			// ����, ����, ���� ������ �Է� �ް� �й� ���� ����� 
			// ������ ���� ����Ѵ�.
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');
			cout << "�ּ� : ";
			
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;
			
			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;
			
			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;
			
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.0f;

			tStudentArr[iStudentCount].iNumber = iStudentNumber;

			++iStudentNumber;
			++iStudentCount;
			
			break;
		case MENU_DELETE:
			break;
		case MENU_SEARCH:
			break;
		case MENU_PRINT:
			system("cls");
			cout << "=============== �л� ��� ===============" << endl;

			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl;
				cout << endl;
			}
			break;

		}

		system("pause");
	}

	return 0;
}