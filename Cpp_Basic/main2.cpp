#include <iostream>

using namespace std;

int main(void)
{
	// ��� : ������ �ʴ� ��, ���� �ѹ� �����س����� �ٲ� �� ����.
	// ����� ����� ���ÿ� ���� �����صξ�� �Ѵ�.
	const int	iAttack = 0x00000001;	//		1
	const int	iArmor = 0x00000002;	//	   10
	const int	iHp = 0x00000004;		//	  100
	const int	iMp = 0x00000008;		//   1000
	const int	iCritical = 0x00000010; //	10000

	// 1 | 100 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHp | iCritical;
	
	// ������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
	// �Ʒ��� Ǯ� ���� iBuf = iBuf & iHp;

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
	����Ʈ ������ : <<, >> ���� ���� �����Ͽ� ������ ������ �ȴ�.
	�� ������ ���� ������ ������ ������ �ϰ� �ȴ�.

	20 << 2 = 80  : 20 * 2^2
	20 << 3 = 160 : 20 * 2^3
	20 << 4 = 320 : 20 * 2^4
	
	20�� 2������ ��ȯ�Ѵ�.
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

	// iNumber���� 187 ���ִ�. �� ���� <- �� �������� 16��Ʈ �̵���Ű�� 
	// ���� 16��Ʈ�� iHigh ���� ���ִ�.

	iNumber <<= 16;

	// ���� 16��Ʈ�� ä���.
	iNumber |= iLow;

	// High ���� ����Ѵ�.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// ���������� : ++, --�� �ִ�. 1����, 1�����̴�.
	iNumber = 10;

	// ��ġ
	++iNumber;

	// ��ġ
	iNumber++;

	cout << ++iNumber << endl;	// 13
	cout << iNumber++ << endl;	// 13
	cout << iNumber << endl;	// 14
	

	return 0;
}