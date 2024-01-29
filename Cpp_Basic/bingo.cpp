
#include <iostream>
#include <ctime>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT,
};

int main(void)
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};
	// 1 ~ 25 까지 숫자를 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
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
		
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}
	int iBingo = 0, iAIBingo = 0;
	// AI 난이도를 선택 한다.
	int iAIMode = 0;
	while (true)
	{
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요 : ";

		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}


	// 선택 안된 목록 배열을 만들어 준다.
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		// 숫자를 5 x 5로 출력한다.
		cout << "============= Player =============" << endl;
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

		cout << "Bingo Line : " << iBingo << endl << endl;
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "AI Mode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AI Mode : Hard" << endl;
			break;
		}
		// AI 빙고 판을 출력한다.
		cout << "============= Computer =============" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		// AI 빙고 줄 수를 출력한다
		cout << "Computer Bingo Line : " << iAIBingo << endl << endl;

		// 줄수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
		{
			cout << iBingo << "줄을 달성했습니다!" << endl;
			cout << "You Win!" << endl;
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		else if (iAIBingo >= 5)
		{
			cout << iAIBingo << "줄을 Computer가 달성했습니다!" << endl;
			cout << "Computer Win!" << endl;
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


		// 중복이 아니라면 AI 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// AI가 선택을 한다. AI가 선택하는 것은 AI 모드에 따라서 달라진다.
		
		switch (iAIMode)
		{
			/*
			AI Easy 모드는 현재 AI의 숫자 목록 중 *로 바뀌지 않은 숫자 목록을 만들어서
			그 목록 중 하나를 선택하게 한다.(랜덤하게
			*/
		case AM_EASY:
			// 선택 안된 숫자 개수는 목록을 만들 때 카운팅해준다.
			iNoneSelectCount = 0;
			// 선택 안된 숫자 목록을 만들어 준다.
			for (int i = 0; i < 25; ++i)
			{
				if (iAINumber[i] != INT_MAX)
				{
					// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
					// 선택 안된 목록에 숫자를 추가할 떄 마다 1씩 증가
					// 시켜서 총 선택 안된 개수를 구해준다.
					// 0부터 카운트가 시작이므로 0번에 넣고 ++해서 1개가 추가되었다고 한다
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}
			// 선택 안된 목록이 만들어 지고
			// 목록의 개수도 만들어 진다.
			// 선택 안된 목록의 숫자 중 랜덤한 하나의 숫자를 얻어오기 위해 
			// 인덱스를 랜덤하게 구해준다.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;

		case AM_HARD:
			// 하드모드는 현재 숫자 중 빙고 완성 가능성이 가장 높은 줄을
			// 찾아서 그 줄에 있는 숫자 중 하나를 *로 만들어 준다.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// 가로 라인 중 가장 *이 많은 라인을 찾아 낸다.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// 별이 5개미만 이어야 빙고 줄이 아니고
				// 기존에 가장 많은 라인의 별보다 커야 가장 별이 많은 라인이라
				// 라인을 바꿀 수 있다.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// 여기는 가로 라인 중 가장 많은 라인을 체크하는 곳
					// 가로 라인은 0 ~ 4로 의미를 부여했다.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로 라인 중 가장 별이 많은 라인은 이미 구했다.
			// 이 값과 세로 라인들을 비교하여 별이 가장 많은 라인을 구한다.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// 여기는 가로 라인 중 가장 많은 라인을 체크하는 곳
					// 세로 라인은 5 ~ 9로 의미를 부여했다.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}
			// 왼쪽 -> 오른쪽 대각선 체크
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 여기는 가로 라인 중 가장 많은 라인을 체크하는 곳
				// 세로 라인은 5 ~ 9로 의미를 부여했다.
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}
			// 오른쪽 -> 왼쪽 대각선 체크
			iStarCount = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 여기는 가로 라인 중 가장 많은 라인을 체크하는 곳
				// 세로 라인은 5 ~ 9로 의미를 부여했다.
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장 되었다.
			// 그 줄 번에 있는 *이 아닌 숫자 중 하나를 선택하게 한다.
			switch (iLine)
			{
			case LN_H1:
			case LN_H2:
			case LN_H3:
			case LN_H4:
			case LN_H5:
				// 가로 줄일 경우 iLine은 0 ~ 4
				for (int i = 0; i < 5; ++i)
				{
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
				break;
			case LN_V1:
			case LN_V2:
			case LN_V3:
			case LN_V4:
			case LN_V5:
				// 세로 줄일 경우 iLine은 5 ~ 9
				for (int i = 0; i < 5; ++i)
				{
					// 현재 줄에서 *이 아닌 숫자를 찾아낸다
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
				break;
			case LN_LT:
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
				break;
			case LN_RT:
				for (int i = 4; i <= 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
				break;
			}
			break;
		}
		// AI가 숫자를 선택했으므로 플레이어와 AI 숫자를 *로 바꿔준다.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}

		}
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}
		// 빙고 줄 수를 체크하는 것은 매 번 숫자를 입력할 때 마다
		// 처음부터 새로 카운트할 것이다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화 하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;
		iAIBingo = 0;
		// 가로 세로 줄 수를 구해준다.
		int iStarW = 0, iStarH = 0, iStarD1 = 0, iStarD2 = 0;
		int iAIStarW = 0, iAIStarH = 0, iAIStarD1 = 0, iAIStarD2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			iStarW = iStarH = 0;
			iAIStarW = iAIStarH = 0;
			for (int j = 0; j < 5; ++j)
			{
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStarW;

				// 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStarH;
				
				// AI 가로 별 개수를 구해준다.
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStarW;

				// AI세로 별 개수를 구해준다.
				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStarH;
			}
			
			// j for 문을 빠져 나오고 나면 현재 줄의 가로 별 개수가 몇 개 인지
			// iStarW 변수에 들어가게 된다.
			// iStarW 값이 5이면 한 줄이 모두 *라는 의미이므로 빙고 줄 카운트를 추가해준다.
			if (iStarW == 5)
				++iBingo;

			if (iStarH == 5)
				++iBingo;

			if (iAIStarW == 5)
				++iAIBingo;

			if (iAIStarH == 5)
				++iAIBingo;
		}
		iStarD1 = iStarD2 = 0;
		iAIStarD1 = iAIStarD2 = 0;
		// 대각선(왼쪽 상단 -> 오른쪽 하단 별 개수 세기 
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStarD1;
			if (iAINumber[i] == INT_MAX)
				++iAIStarD1;
		}

		// 대각선2(오른쪽 상단 -> 오른쪽 하단) 별 개수 세기
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStarD2;
			
			if (iAINumber[i] == INT_MAX)
				++iAIStarD2;
			
		}

		// 대각선 빙고 줄 검사
		if (iStarD1 == 5)
			iBingo++;

		if (iStarD2 == 5)
			iBingo++;
		
		if (iAIStarD1 == 5)
			iAIBingo++;

		if (iAIStarD2 == 5)
			iAIBingo++;

	}

	return 0;
}