// #include : ��� ������ ���⿡ ���Խ�Ű�� ����̴�.
#include <iostream>

using namespace std;

// ���� ���� : ������ -> ���� -> ����
// ������ : ���� �۾�
// Ctrl + Shift + B�� �̿��ؼ� �������� �� �� �ִ�. (F7)

// C++�� �������� main �Լ��̴�. main �Լ��� �ݵ�� �־�� �Ѵ�.
int main(void)
{
	// C++ ǥ�� ����� ��κ��� std��� namespace �ȿ� �����ϰ� �ִ�.
	// �̸��� ��ġ�� ���� �������ֱ� ���ؼ��̴�.
	// cout : �ܼ�â�� ������ִ� ����̴�.
	//		  �ڿ� �ִ� ""(ū����ǥ) �ȿ� �ִ� ���ڵ��� ȭ�鿡 ������ش�.
	//		  ���� �������� ����� ���� �ݵ�� "" �ȿ� �־��ְ� �̷� ���� ���ڿ��̶�� �Ѵ�.
	// endl : ���� ����̴�.
	
	std::cout << "Test Output" << std::endl;
	std::cout << "�����ٶ�" << std::endl;
	
	cout << "std namespace ���" << endl;
	/*
	���� : ���ϴ� ��. ���� �ٲ� �� �ִ�.
        �뷮�� �ּ� ���� : bit
        1byte = 8bit
        1kbyte = 1024byte
        1mbyte = 1024kbyte
        1gbyte = 1024mbyte
        1tbyte = 1024gbyte

        ���ڸ� ǥ���ϴ� ��� ASCI �ڵ� ǥ�� ������ �ִ�.
        false : 0
        true : 0�� �ƴ� ��� ��

        unsigned : ��ȣ�� ����.
        ����   ��  �뷮  ��  ������  ��   ǥ������       ��  unsigned     ��
        char   �� 1byte ��   ����   ��  -128 ~ 127     ��  0 ~ 255      ��
        bool   �� 1byte �� ��, ���� �� true / false    ��  true / false ��
        short  �� 2byte ��   ����   �� -32768 ~ 32767  �� 0 ~ 65535     ��
        int    �� 4byte ��   ����   �� �� -21�� ~ 21��  �� 0 ~ �� 43��   ��
        float  �� 4byte ��   �Ǽ�   ��
        double �� 8byte ��   �Ǽ�   ��
	*/
    // = : ���Կ������̴�. �����ʿ� �ִ� ���� �������� �����Ѵ�.
    int number = 10;
    number = 20;

    cout << number << endl;

    bool    bTest = true;
    bTest = false;

    cout << bTest << endl;

    // �����̳� ���ڴ� 1byte�� �����Ѵ�.
    // ������ �ѱ��̳� �ѹ� ���� ���ڿ��� 2byte�� �����ϱ� ������
    // char ���� �ϳ��� �����ϱⰡ �����.
    char    cTest = 't';

    cout << cTest << endl;

    float fNumber = 3.14f;

    cout << fNumber << endl;

    double dNumber = 123.4567;

    cout << dNumber << endl;



	return 0;
}