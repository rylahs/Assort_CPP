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
	 
	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
	// 사용할 건데 INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미 정의되어 있는 값으로
	// INT를 표현할 수 있는 최대 값이다.

	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarIndex = 24;

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 
	// 즉 인덱스는 0 ~ 23번 인덱스까지만 섞어준다.
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
		
		// i for문의 세로줄을 의미한다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				// i가 0일때 j는 0 ~ 4를 반복한다.
				// 이 경우 0 * 5 + 0 ~ 4를 더하게 되서 
				// 인덱스는 0 1 2 3 4가 나오게 된다.
				// 
				// i가 1일때 j는 0 ~ 4를 반복한다.
				// 이 경우 1 * 5 + 0 ~ 4를 더하게 되서 
				// 인덱스는 5 6 7 8 9가 나오게 된다.
				// 
				// i가 2일때 j는 0 ~ 4를 반복한다.
				// 이 경우 2 * 5 + 0 ~ 4를 더하게 되서 
				// 인덱스는 10 11 12 13 14가 나오게 된다.
				// 
				// i가 3일때 j는 0 ~ 4를 반복한다.
				// 이 경우 3 * 5 + 0 ~ 4를 더하게 되서 
				// 인덱스는 15 16 17 18 19가 나오게 된다.
				// 
				// i가 4일때 j는 0 ~ 4를 반복한다.
				// 이 경우 4 * 5 + 0 ~ 4를 더하게 되서 
				// 인덱스는 20 21 22 23 24가 나오게 된다.
				// 
				// 줄 번호 * 가로개수 + 칸 번호
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

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		// _getch() 함수는 문자 1개를 입력받는 함수이다.
		// 이 함수는 enter를 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		char	cInput = _getch();
		
		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// 가장 윗줄일 때 위로 올라가서는 안된다.
			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에서 별을 넣어주어서 두 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별의 위치를 변경한다.
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			// 가장 아랫줄이 아닌 경우 움직인다
			if (iStarIndex < 20)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				// 위의 위치에서 별을 넣어주어서 두 값을 서로 교체한다.
				iNumber[iStarIndex + 5] = INT_MAX;
				// 별의 위치를 변경한다.
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			// 0 5 10 15 20
			if (iStarIndex % 5 != 0)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				// 위의 위치에서 별을 넣어주어서 두 값을 서로 교체한다.
				iNumber[iStarIndex - 1] = INT_MAX;
				// 별의 위치를 변경한다.
				--iStarIndex;
			}
			break;
		case 'd':
		case 'D':
			// 4 9 14 19 24 
			if (iStarIndex % 5 != 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				// 위의 위치에서 별을 넣어주어서 두 값을 서로 교체한다.
				iNumber[iStarIndex + 1] = INT_MAX;
				// 별의 위치를 변경한다.
				++iStarIndex;
			}
			break;
		}

		bool	bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
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
			cout << "숫자를 모두 맞췄습니다!" << endl;
			break;
		}
	}


	return 0;
}