
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 ���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
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
	}

	int iBingo = 0;
	while (true)
	{
		system("cls");

		// ���ڸ� 5 x 5�� ����Ѵ�.
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

		// �ټ��� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
		{
			cout << iBingo << "���� �޼��߽��ϴ�.!" << endl;
			cout << "You Win!" << endl;
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

		// ���� �� ���� üũ�ϴ� ���� �� �� ���ڸ� �Է��� �� ����
		// ó������ ���� ī��Ʈ�� ���̴�.
		// �׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ �ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;

		// ���� ���� �� ���� �����ش�.
		int iStarW = 0, iStarH = 0, iStarD1 = 0, iStarD2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			iStarW = iStarH = 0;
			for (int j = 0; j < 5; ++j)
			{
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStarW;

				// ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStarH;
			}
			
			// j for ���� ���� ������ ���� ���� ���� ���� �� ������ �� �� ����
			// iStarW ������ ���� �ȴ�.
			// iStarW ���� 5�̸� �� ���� ��� *��� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
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
		// �밢��(���� ��� -> ������ �ϴ� �� ���� ���� 
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStarD1;
		}

		// �밢��2(������ ��� -> ������ �ϴ�) �� ���� ����
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
			{
				++iStarD2;
			}
		}

		// �밢�� ���� �� �˻�
		if (iStarD1 == 5)
			iBingo++;

		if (iStarD2 == 5)
			iBingo++;

	}

	return 0;
}