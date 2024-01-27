#include <iostream>
#include <ctime>
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
	/*
	�б⹮���� ũ�� 2���� ������ �ִ�. if��, switch ���� �����Ѵ�.
	if�� : ������ üũ���ִ� ����̴�.
	���� : if(���ǽ�) {}(�ڵ��)
	if ���� ���ǽ��� true�� �� ��� �ڵ� �� ���� �ڵ尡 �����Ѵ�.
	false�� ��쿡�� �������� �ʴ´�.
	*/

	if (false)
	{
		cout << "if�� ������ true �Դϴ�." << endl;
	}

	// ������ �ִ��� Ȯ���Ѵ�.
	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	}

	// if�� �Ʒ��� �� �ڵ尡 1���� ��� {}(�ڵ��)�� ������ �� �ִ�.
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�." << endl;

	if ((iBuf & iHp) != 0)
		cout << "Hp ������ �ֽ��ϴ�." << endl;
	
	if ((iBuf & iMp) != 0)
		cout << "Mp ������ �ֽ��ϴ�." << endl;
	
	if ((iBuf & iCritical) != 0)
		cout << "Critical ������ �ֽ��ϴ�." << endl;

	/*
	else : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� ������ false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ���۵ȴ�.

	else if : if ���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� �Ʒ��� �;��ϰ� else ���ٴ� ���� �־�� �Ѵ�.
	else if�� �ڽ��� ���� �ִ� ���ǽ��� false �� ��� ���� else if�� ���ǽ��� üũ�Ѵ�.
	else if�� ��� ����� �����ϴ�.
	*/

	if (false)
		cout << "if ���ǹ��� true �Դϴ�." << endl;

	else
		cout << "if ���ǹ��� false �Դϴ�." << endl;

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10 ~ 20 ������ �����Դϴ�." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 ������ �����Դϴ�." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "31 ~ 40 ������ �����Դϴ�." << endl;
	else
		cout << "�� ���� �����Դϴ�." << endl;

	// ���� �߻�
	srand((unsigned int)time(NULL));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	cout << (rand() % 100) << endl;
	cout << (rand() % 101) + 100 << endl;

	cout << (rand() % 10000 / 100.0f) << endl;
	
	int iUpgrade = 0;
	cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
	cin >> iUpgrade;


	// ��ȭ Ȯ���� ���Ѵ�.
	float fPercent = rand() % 10000 / 100.0f;

	// ��ȭ Ȯ�� ���׷��̵尡 
	// 0 ~ 3 : 100% ����
	// 4 ~ 6 : 40%
	// 7 ~ 9 : 10%
	// 10 ~ 13 : 1%
	// 14 ~ 15 : 0.01%

	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;

	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.0f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.0f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.0f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.1f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}


	return 0;
}