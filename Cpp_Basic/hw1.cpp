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
		for (int j = 0; j <= i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void hw3()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i; j < 5; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
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
}

void hw5()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (3 - i) - 1; ++j)
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
