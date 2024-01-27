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

int main(void)
{
	hw1();
	hw2();
	hw3();
	hw4();
	return 0;
}
