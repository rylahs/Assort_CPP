
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
	// 1 ~ 25 ���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	// ���ڸ� ���� �ش�.
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
	// AI ���̵��� ���� �Ѵ�.
	int iAIMode = 0;
	while (true)
	{
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����ϼ��� : ";

		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}


	// ���� �ȵ� ��� �迭�� ����� �ش�.
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		// ���ڸ� 5 x 5�� ����Ѵ�.
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
		// AI ���� ���� ����Ѵ�.
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
		// AI ���� �� ���� ����Ѵ�
		cout << "Computer Bingo Line : " << iAIBingo << endl << endl;

		// �ټ��� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
		{
			cout << iBingo << "���� �޼��߽��ϴ�!" << endl;
			cout << "You Win!" << endl;
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		else if (iAIBingo >= 5)
		{
			cout << iAIBingo << "���� Computer�� �޼��߽��ϴ�!" << endl;
			cout << "Computer Win!" << endl;
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		// �ߺ� üũ�� ���� �����̴�.
		// �⺻������ �ߺ��Ǿ��ٰ� �ϱ� ���� true

		bool	bAcc = true;

		// ��� ���ڸ� ���ʶ��� �˻��ؼ�
		// �Է��� ���ڿ� ���� ���ڰ� �ִ��� Ȯ���Ѵ�.

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i]) 
			{
				bAcc = false;

				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				// �� �̻� ã�ƺ� ������ �����Ƿ� for ���� ����������.
				break;
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� �ٲ��� �������Ƿ�
		// continue�� while���� �ٽ� �ݺ��ϰ� ���ش�.
		if (bAcc)
			continue;


		// �ߺ��� �ƴ϶�� AI ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI ��忡 ���� �޶�����.
		
		switch (iAIMode)
		{
			/*
			AI Easy ���� ���� AI�� ���� ��� �� *�� �ٲ��� ���� ���� ����� ����
			�� ��� �� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�
			*/
		case AM_EASY:
			// ���� �ȵ� ���� ������ ����� ���� �� ī�������ش�.
			iNoneSelectCount = 0;
			// ���� �ȵ� ���� ����� ����� �ش�.
			for (int i = 0; i < 25; ++i)
			{
				if (iAINumber[i] != INT_MAX)
				{
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					// ���� �ȵ� ��Ͽ� ���ڸ� �߰��� �� ���� 1�� ����
					// ���Ѽ� �� ���� �ȵ� ������ �����ش�.
					// 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1���� �߰��Ǿ��ٰ� �Ѵ�
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}
			// ���� �ȵ� ����� ����� ����
			// ����� ������ ����� ����.
			// ���� �ȵ� ����� ���� �� ������ �ϳ��� ���ڸ� ������ ���� 
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;

		case AM_HARD:
			// �ϵ���� ���� ���� �� ���� �ϼ� ���ɼ��� ���� ���� ����
			// ã�Ƽ� �� �ٿ� �ִ� ���� �� �ϳ��� *�� ����� �ش�.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� �� ���� *�� ���� ������ ã�� ����.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// ���� 5���̸� �̾�� ���� ���� �ƴϰ�
				// ������ ���� ���� ������ ������ Ŀ�� ���� ���� ���� �����̶�
				// ������ �ٲ� �� �ִ�.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					// ����� ���� ���� �� ���� ���� ������ üũ�ϴ� ��
					// ���� ������ 0 ~ 4�� �ǹ̸� �ο��ߴ�.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ���� �� ���� ���� ���� ������ �̹� ���ߴ�.
			// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
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
					// ����� ���� ���� �� ���� ���� ������ üũ�ϴ� ��
					// ���� ������ 5 ~ 9�� �ǹ̸� �ο��ߴ�.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}
			// ���� -> ������ �밢�� üũ
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// ����� ���� ���� �� ���� ���� ������ üũ�ϴ� ��
				// ���� ������ 5 ~ 9�� �ǹ̸� �ο��ߴ�.
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}
			// ������ -> ���� �밢�� üũ
			iStarCount = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// ����� ���� ���� �� ���� ���� ������ üũ�ϴ� ��
				// ���� ������ 5 ~ 9�� �ǹ̸� �ο��ߴ�.
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ�� ���� �Ǿ���.
			// �� �� ���� �ִ� *�� �ƴ� ���� �� �ϳ��� �����ϰ� �Ѵ�.
			switch (iLine)
			{
			case LN_H1:
			case LN_H2:
			case LN_H3:
			case LN_H4:
			case LN_H5:
				// ���� ���� ��� iLine�� 0 ~ 4
				for (int i = 0; i < 5; ++i)
				{
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���
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
				// ���� ���� ��� iLine�� 5 ~ 9
				for (int i = 0; i < 5; ++i)
				{
					// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���
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
		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI ���ڸ� *�� �ٲ��ش�.
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
		// ���� �� ���� üũ�ϴ� ���� �� �� ���ڸ� �Է��� �� ����
		// ó������ ���� ī��Ʈ�� ���̴�.
		// �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ �ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAIBingo = 0;
		// ���� ���� �� ���� �����ش�.
		int iStarW = 0, iStarH = 0, iStarD1 = 0, iStarD2 = 0;
		int iAIStarW = 0, iAIStarH = 0, iAIStarD1 = 0, iAIStarD2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			iStarW = iStarH = 0;
			iAIStarW = iAIStarH = 0;
			for (int j = 0; j < 5; ++j)
			{
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStarW;

				// ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStarH;
				
				// AI ���� �� ������ �����ش�.
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStarW;

				// AI���� �� ������ �����ش�.
				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStarH;
			}
			
			// j for ���� ���� ������ ���� ���� ���� ���� �� ������ �� �� ����
			// iStarW ������ ���� �ȴ�.
			// iStarW ���� 5�̸� �� ���� ��� *��� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
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
		// �밢��(���� ��� -> ������ �ϴ� �� ���� ���� 
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStarD1;
			if (iAINumber[i] == INT_MAX)
				++iAIStarD1;
		}

		// �밢��2(������ ��� -> ������ �ϴ�) �� ���� ����
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStarD2;
			
			if (iAINumber[i] == INT_MAX)
				++iAIStarD2;
			
		}

		// �밢�� ���� �� �˻�
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