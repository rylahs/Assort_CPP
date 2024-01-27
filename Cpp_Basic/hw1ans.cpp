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
	* 2단 3단 4단
	* 5단 6단 7단
	* 8단 9단 10단
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
	int iLine = 7; // 별의 최대 개수
	int iCount = 0;
	for (int i = 0; i < iLine; ++i)
	{
		// 공백 : 3 2 1 0 1 2 3
		// 별 : 1 3 5 7 5 3 1
		iCount = i;

		// i 값이 7줄 기준 4 5 6 즉 밑의 삼각형을 구성할 때만 if에 들어간다.

		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
		}

		// i 값이 0 1 2 3일때에는 iCount는 i값을 그대로 대입한다.
		// i 갑싱 4 5 6일때는 iCount는 2 1 0이다
		// 즉 최종 i 값은 0 1 2 3 2 1 0으로 들어가게 된다.

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
