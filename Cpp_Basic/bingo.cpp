
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 까지 숫자를 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 숫자를 섞어 준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;
	while (true)
	{
		system("cls");

		// 숫자를 5 x 5로 출력한다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl;

		// 줄수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
		{
			cout << iBingo << "줄을 달성했습니다.!" << endl;
			cout << "You Win!" << endl;
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		// 중복 체크를 위한 변수이다.
		// 기본적으로 중복되었다고 하기 위해 true

		bool	bAcc = true;

		// 모든 숫자를 차례때로 검사해서
		// 입력한 숫자와 같은 숫자가 있는지 확인한다.

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i]) 
			{
				bAcc = false;

				// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				// 더 이상 찾아볼 이유가 없으므로 for 문을 빠져나간다.
				break;
			}
		}

		// bAcc 변수가 true인 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로
		// continue로 while문을 다시 반복하게 해준다.
		if (bAcc)
			continue;

		// 빙고 줄 수를 체크하는 것은 매 번 숫자를 입력할 때 마다
		// 처음부터 새로 카운트할 것이다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화 하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;

		// 가로 세로 줄 수를 구해준다.
		int iStarW = 0, iStarH = 0, iStarD1 = 0, iStarD2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			iStarW = iStarH = 0;
			for (int j = 0; j < 5; ++j)
			{
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStarW;

				// 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStarH;
			}
			
			// j for 문을 빠져 나오고 나면 현재 줄의 가로 별 개수가 몇 개 인지
			// iStarW 변수에 들어가게 된다.
			// iStarW 값이 5이면 한 줄이 모두 *라는 의미이므로 빙고 줄 카운트를 추가해준다.
			if (iStarW == 5)
				++iBingo;

			if (iStarH == 5)
				++iBingo;

			if (iStarD1 == 5)
				++iBingo;

			if (iStarD2 == 5)
				++iBingo;
		}
		iStarD1 = iStarD2 = 0;
		// 대각선(왼쪽 상단 -> 오른쪽 하단 별 개수 세기 
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStarD1;
		}

		// 대각선2(오른쪽 상단 -> 오른쪽 하단) 별 개수 세기
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
			{
				++iStarD2;
			}
		}

		// 대각선 빙고 줄 검사
		if (iStarD1 == 5)
			iBingo++;

		if (iStarD2 == 5)
			iBingo++;

	}

	return 0;
}