// #include : 헤더 파일을 여기에 포함시키는 기능이다.
#include <iostream>

using namespace std;

// 실행 과정 : 컴파일 -> 빌드 -> 실행
// 컴파일 : 번역 작업
// Ctrl + Shift + B를 이용해서 컴파일을 할 수 있다. (F7)

// C++의 시작점은 main 함수이다. main 함수는 반드시 있어야 한다.
int main(void)
{
	// C++ 표준 기능의 대부분은 std라는 namespace 안에 존재하고 있다.
	// 이름이 겹치는 것을 방지해주기 위해서이다.
	// cout : 콘솔창에 출력해주는 기능이다.
	//		  뒤에 있는 ""(큰따옴표) 안에 있는 문자들을 화면에 출력해준다.
	//		  문자 여러개를 사용할 때는 반드시 "" 안에 넣어주고 이런 것을 문자열이라고 한다.
	// endl : 개행 기능이다.
	
	std::cout << "Test Output" << std::endl;
	std::cout << "가나다라" << std::endl;
	
	cout << "std namespace 사용" << endl;
	/*
	변수 : 변하는 수. 값이 바뀔 수 있다.
        용량의 최소 단위 : bit
        1byte = 8bit
        1kbyte = 1024byte
        1mbyte = 1024kbyte
        1gbyte = 1024mbyte
        1tbyte = 1024gbyte

        문자를 표현하는 방법 ASCI 코드 표를 가지고 있다.
        false : 0
        true : 0이 아닌 모든 수

        unsigned : 부호가 없다.
        종류   ㅣ  용량  ㅣ  데이터  ㅣ   표현범위       ㅣ  unsigned     ㅣ
        char   ㅣ 1byte ㅣ   문자   ㅣ  -128 ~ 127     ㅣ  0 ~ 255      ㅣ
        bool   ㅣ 1byte ㅣ 참, 거짓 ㅣ true / false    ㅣ  true / false ㅣ
        short  ㅣ 2byte ㅣ   정수   ㅣ -32768 ~ 32767  ㅣ 0 ~ 65535     ㅣ
        int    ㅣ 4byte ㅣ   정수   ㅣ 약 -21억 ~ 21억  ㅣ 0 ~ 약 43억   ㅣ
        float  ㅣ 4byte ㅣ   실수   ㅣ
        double ㅣ 8byte ㅣ   실수   ㅣ
	*/
    // = : 대입연산자이다. 오른쪽에 있는 값을 왼쪽으로 대입한다.
    int number = 10;
    number = 20;

    cout << number << endl;

    bool    bTest = true;
    bTest = false;

    cout << bTest << endl;

    // 영문이나 숫자는 1byte를 차지한다.
    // 하지만 한글이나 한문 등의 문자열은 2byte를 차지하기 떄문에
    // char 변수 하나에 저장하기가 힘들다.
    char    cTest = 't';

    cout << cTest << endl;

    float fNumber = 3.14f;

    cout << fNumber << endl;

    double dNumber = 123.4567;

    cout << dNumber << endl;



	return 0;
}