#include <iostream>
using namespace std;
void hw1()
{
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " x " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void hw1_1()
{
	/*
	* 2�� 3�� 4��
	* 5�� 6�� 7��
	* 8�� 9�� 10��
	*/
	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " x " << j << " = " << i * j << "\t";
			cout << i + 1 << " x " << j << " = " << i * j << "\t";
			cout << i + 2 << " x " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
}

void hw2()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
}
void hw3()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 - i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
void hw4()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4 - i - 1; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}

void hw5()
{
	/*
	    *
	   ***
	  *****
	 *******
	  *****
	   ***
	    *
	*/
	int iLine = 7; // ���� �ִ� ����
	int iCount = 0;
	for (int i = 0; i < iLine; ++i)
	{
		// ���� : 3 2 1 0 1 2 3
		// �� : 1 3 5 7 5 3 1
		iCount = i;

		// i ���� 7�� ���� 4 5 6 �� ���� �ﰢ���� ������ ���� if�� ����.

		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
		}

		// i ���� 0 1 2 3�϶����� iCount�� i���� �״�� �����Ѵ�.
		// i ���� 4 5 6�϶��� iCount�� 2 1 0�̴�
		// �� ���� i ���� 0 1 2 3 2 1 0���� ���� �ȴ�.

		for (int j = 0; j < 3 - iCount; ++j)
		{
			cout << " ";
		}
		
		for (int j = 0; j < iCount * 2 + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main(void)
{
	hw1();
	hw1_1();
	hw2();
	hw3();
	hw4();
	hw5();
	return 0;
}
