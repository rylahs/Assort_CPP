#include <iostream>

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
	

	return 0;
}