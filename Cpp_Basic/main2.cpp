#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	// 상수 : 변하지 않는 수, 값을 한번 지정해놓으면 바꿀 수 없다.
	// 상수는 선언과 동시에 값을 지정해두어야 한다.
	const int	iAttack = 0x00000001;	//		1
	const int	iArmor = 0x00000002;	//	   10
	const int	iHp = 0x00000004;		//	  100
	const int	iMp = 0x00000008;		//   1000
	const int	iCritical = 0x00000010; //	10000

	// 1 | 100 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHp | iCritical;
	
	// 연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
	// 아래를 풀어서 쓰면 iBuf = iBuf & iHp;

	// 10101 ^ 00100 = 10001
	iBuf ^= iHp;

	// 10001 ^ 00100 = 10101
	iBuf ^= iHp;


	// 10101 & 00001 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl; // 1

	// 10101 & 00010 = 00000
	cout << "Armor : " << (iBuf & iArmor) << endl; // 0
	
	// 10101 & 00100 = 00100
	cout << "HP : " << (iBuf & iHp) << endl; // 4

	// 10101 & 01000 = 00000
	cout << "MP : " << (iBuf & iMp) << endl; // 0

	// 10101 & 10000 = 10000
	cout << "Critical : " << (iBuf & iCritical) << endl; // 16


	/*
	쉬프트 연산자 : <<, >> 값대 값을 연산하여 값으로 나오게 된다.
	이 연산자 또한 이진수 단위의 연산을 하게 된다.

	20 << 2 = 80  : 20 * 2^2
	20 << 3 = 160 : 20 * 2^3
	20 << 4 = 320 : 20 * 2^4
	
	20을 2진수로 변환한다.
	10100 -> 1010000
	10100 -> 10100000
	10100 -> 101000000

	20 >> 2 = 5 : 20 / 2^2
	20 >> 3 = 2 : 20 / 2^3
	20 >> 4 = 1 : 20 / 2^4
	
	10100 -> 0101
	10100 -> 0010
	10100 -> 0001

	*/

	/*
		187 / 13560
	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	// iNumber에는 187 들어가있다. 이 값을 <- 이 방향으로 16비트 이동시키면 
	// 상위 16비트에 iHigh 값이 들어가있다.

	iNumber <<= 16;

	// 하위 16비트는 채운다.
	iNumber |= iLow;

	// High 값을 출력한다.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// 증감연산자 : ++, --가 있다. 1증가, 1감소이다.
	iNumber = 10;

	// 전치
	++iNumber;

	// 후치
	iNumber++;

	cout << ++iNumber << endl;	// 13
	cout << iNumber++ << endl;	// 13
	cout << iNumber << endl;	// 14
	/*
	분기문에는 크게 2가지 종류가 있다. if문, switch 문이 존재한다.
	if문 : 조건을 체크해주는 기능이다.
	형태 : if(조건식) {}(코드블럭)
	if 문은 조건식이 true가 될 경우 코드 블럭 안의 코드가 동작한다.
	false일 경우에는 동작하지 않는다.
	*/

	if (false)
	{
		cout << "if문 조건이 true 입니다." << endl;
	}

	// 버프가 있는지 확인한다.
	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack 버프가 있습니다." << endl;
	}

	// if문 아래에 들어갈 코드가 1줄일 경우 {}(코드블럭)을 생략할 수 있다.
	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다." << endl;

	if ((iBuf & iHp) != 0)
		cout << "Hp 버프가 있습니다." << endl;
	
	if ((iBuf & iMp) != 0)
		cout << "Mp 버프가 있습니다." << endl;
	
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	/*
	else : if문과 반드시 같이 사용이 되어야 한다.
	if문 조건이 false일 경우 else가 있다면 else 구문 안의 코드가 동작된다.

	else if : if 문과 반드시 같이 사용이 되어야 한다.
	if문 아래에 와야하고 else 보다는 위에 있어야 한다.
	else if는 자신의 위에 있는 조건식이 false 일 경우 다음 else if의 조건식을 체크한다.
	else if는 몇개든 사용이 가능하다.
	*/

	if (false)
		cout << "if 조건문이 true 입니다." << endl;

	else
		cout << "if 조건문이 false 입니다." << endl;

	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10 ~ 20 사이의 숫자입니다." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 사이의 숫자입니다." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "31 ~ 40 사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;

	// 난수 발생
	srand((unsigned int)time(NULL));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	cout << (rand() % 100) << endl;
	cout << (rand() % 101) + 100 << endl;

	cout << (rand() % 10000 / 100.0f) << endl;
	
	int iUpgrade = 0;
	cout << "Upgrade 기본 수치를 입력하세요 : ";
	cin >> iUpgrade;


	// 강화 확률을 구한다.
	float fPercent = rand() % 10000 / 100.0f;

	// 강화 확률 업그레이드가 
	// 0 ~ 3 : 100% 성공
	// 4 ~ 6 : 40%
	// 7 ~ 9 : 10%
	// 10 ~ 13 : 1%
	// 14 ~ 15 : 0.01%

	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;

	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.0f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.0f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.0f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.1f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}


	return 0;
}