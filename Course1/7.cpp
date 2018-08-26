#include <iostream>
using namespace std;
 
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
 
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
 
int main(){
    int n, m;
    cin >> n >> m;
    cout << gcd(n,m) << endl;
    cout << lcm(n,m) << endl;
 
//s    system("pause");
    return 0;
}

/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/4
*************
< 문제명 >    : 최대공약수 최소공배수 (gcdlcm.cpp)
< 문제 >      :
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/