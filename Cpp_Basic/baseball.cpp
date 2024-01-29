#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand((unsigned int)time(0));
	int iNumber[9] = {};

	// 1 ~ 9까지 숫자를 설정한다.
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 설정된 숫자를 섞어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << "*\t*\t*\n";
	//cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3] = {};
	int iGameCount = 1;

	while (true)
	{
		cout << "1 ~ 9 사이의 숫자 중 숫자 3개를 입력하세요(0 : 종료) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		cout << iGameCount << "회" << endl;

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else if (iInput[0] < 0 || iInput[0] > 9
			|| iInput[1] < 0 || iInput[1] > 9
			|| iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하셨습니다." << endl;
			continue;
		}

		else if (iInput[0] == iInput[1]
			|| iInput[0] == iInput[2]
			|| iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입력하였습니다." << endl;
			continue;
		}

		// 매번 Strike와 Ball 수가 달라지기 때문에 0으로 초기화 하고 다시 계산한다.
		iStrike = iBall = 0;

		// i for문은 맞춰야할 숫자의 인덱스를 구한다.
		for (int i = 0; i < 3; ++i)
		{
			// j for문은 입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; ++j)
			{
				// i는 0일때 j는 0 ~ 2까지 반복한다. 즉
				// 0 - 0 0 - 1 0 - 2를 비교해서 같은 숫자가 있는지를 비교한다.
				// 입력에서 중복이 없기 때문에 이렇게 비교가 가능하다.
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++iStrike;
					else
						++iBall;

					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;

		else
			cout << iStrike << " Strike " << iBall << "Ball" << endl;

		++iGameCount;
	}


	return 0;
}