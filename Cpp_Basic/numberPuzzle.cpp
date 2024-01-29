#include <iostream>
#include <ctime>

#include <conio.h>
using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}
	 
	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ����
	// ����� �ǵ� INT_MAX��� ���� ����� ���̴�. INT_MAX�� �̹� ���ǵǾ� �ִ� ������
	// INT�� ǥ���� �� �ִ� �ִ� ���̴�.

	iNumber[24] = INT_MAX;

	// ���� �ִ� ��ġ�� ������ ������ ������ش�.
	int iStarIndex = 24;

	// ������ ������ �����ϰ� 1 ~ 24 ������ ���ڸ� �����ش�. 
	// �� �ε����� 0 ~ 23�� �ε��������� �����ش�.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		
		// i for���� �������� �ǹ��Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				// i�� 0�϶� j�� 0 ~ 4�� �ݺ��Ѵ�.
				// �� ��� 0 * 5 + 0 ~ 4�� ���ϰ� �Ǽ� 
				// �ε����� 0 1 2 3 4�� ������ �ȴ�.
				// 
				// i�� 1�϶� j�� 0 ~ 4�� �ݺ��Ѵ�.
				// �� ��� 1 * 5 + 0 ~ 4�� ���ϰ� �Ǽ� 
				// �ε����� 5 6 7 8 9�� ������ �ȴ�.
				// 
				// i�� 2�϶� j�� 0 ~ 4�� �ݺ��Ѵ�.
				// �� ��� 2 * 5 + 0 ~ 4�� ���ϰ� �Ǽ� 
				// �ε����� 10 11 12 13 14�� ������ �ȴ�.
				// 
				// i�� 3�϶� j�� 0 ~ 4�� �ݺ��Ѵ�.
				// �� ��� 3 * 5 + 0 ~ 4�� ���ϰ� �Ǽ� 
				// �ε����� 15 16 17 18 19�� ������ �ȴ�.
				// 
				// i�� 4�϶� j�� 0 ~ 4�� �ݺ��Ѵ�.
				// �� ��� 4 * 5 + 0 ~ 4�� ���ϰ� �Ǽ� 
				// �ε����� 20 21 22 23 24�� ������ �ȴ�.
				// 
				// �� ��ȣ * ���ΰ��� + ĭ ��ȣ
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
					continue;
				}
				cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << endl;
		for (int i = 0; i < 25; i++)
		{

			if (iNumber[i] == INT_MAX)
			{
				cout << "*\t";
				if (i % 5 == 4)
					cout << endl;
				continue;
			}

			cout << iNumber[i] << "\t";
			if (i % 5 == 4)
				cout << endl;

		}
		cout << endl;

		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� : ";
		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�.
		// �� �Լ��� enter�� ġ�� �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.
		char	cInput = _getch();
		
		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// ���� ������ �� ���� �ö󰡼��� �ȵȴ�.
			if (iStarIndex > 4)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// ���� ��ġ���� ���� �־��־ �� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 5] = INT_MAX;
				// ���� ��ġ�� �����Ѵ�.
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			// ���� �Ʒ����� �ƴ� ��� �����δ�
			if (iStarIndex < 20)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				// ���� ��ġ���� ���� �־��־ �� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex + 5] = INT_MAX;
				// ���� ��ġ�� �����Ѵ�.
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			// 0 5 10 15 20
			if (iStarIndex % 5 != 0)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				// ���� ��ġ���� ���� �־��־ �� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 1] = INT_MAX;
				// ���� ��ġ�� �����Ѵ�.
				--iStarIndex;
			}
			break;
		case 'd':
		case 'D':
			// 4 9 14 19 24 
			if (iStarIndex % 5 != 4)
			{
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				// ���� ��ġ���� ���� �־��־ �� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex + 1] = INT_MAX;
				// ���� ��ġ�� �����Ѵ�.
				++iStarIndex;
			}
			break;
		}

		bool	bWin = true;

		// ������ ���߾����� üũ�Ѵ�.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin)
		{
			cout << "���ڸ� ��� ������ϴ�!" << endl;
			break;
		}
	}


	return 0;
}