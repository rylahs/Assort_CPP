#include <iostream>
using namespace std;

int main(void)
{
	/*
	do-while �� : �ݺ����� �� �����̴�.
	���� : do {} while(���ǽ�); �� ���·� �����ȴ�.
	while���� ó�� ���Ժ��� ���ǽ��� üũ������ do-while���� ó�� �ѹ��� ������ ������ �ǰ�
	�� �Ŀ� ���ǽ��� üũ�ؼ� true�� ��� �����ϴ� �ݺ����̴�.
	*/
	int iNumber = 0;
	int iNumber1 = 0, iNumber2 = 0, iNumber3 = 0;
	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);

	/*
	�迭 : �������� ������ �ѹ��� �������� �� �ִ� ����̴�.
	���� : ����Ÿ�� �迭��[����]; �� ���·� ������ �� �ִ�.
	�迭�� Ư¡ : �迭�� ���ӵ� �޸� ������ ������ �Ҵ��Ѵ�.
	�迭�� �ε����� �̿��ؼ� ���ϴ� �κп� �����Ͽ� ���� ������ �� �ִ�.
	�ε����� 0���� ���� -1 �����̴�. ��, 10����� 0 ~ 9������ �� 10���� �ε����� ������ �ȴ�.
	*/

	// �迭 �Ӹ� �ƴ϶� �Ϲ� �����鵵 ������ �ϰ� ���� �ʱ�ȭ���� ���� ��� ������ ����
	// ���� �ȴ�.
	//int iArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 0 ~ 4�������� 1, 2, 3, 4, 5�� ���� ���� �ǰ� �������� ��� 0���� �ʱ�ȭ �ȴ�.
	//int iArray[10] = { 1, 2, 3, 4, 5 };

	// ����ִ� �߰�ȣ�� �������� ��� ��� �ε����� 0���� �ʱ�ȭ �Ѵ�.
	int iArray[10] = {};

	iArray[0] = 0;
	iArray[1] = 12345;

	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}

	/*
	�迭 ������ 2���� �����ϸ� 2���� �迭�� �ȴ�. 3�� �����ϸ� 3���� �迭�� �ȴ�.
	2���� �迭�� ������ ���� �� * ���� �� ��ŭ ó���� �ȴ�.
	�Ʒ��� 10 * 10 �迭�� �����Ǵ� ���̴�.
	*/
	int iArray2[10][10] = { {1, 2, 3}, {4, 5, 6} };
	// int iArr[19999999999];

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << iArray2[i][j] << "\t";
		}

		cout << endl;
	}



	return 0;
}