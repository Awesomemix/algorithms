#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[100];
int s[100];
int b[100];
int check[1000];
 
 
//숫자야구
//서로 다른 3자리의 수를 맞춘다
//자리수와 수가 맞으면 strike, 수만 맞으면 boll
int strike(int number, int number2) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if ((number / (int)pow(10, i)) % 10 == (number2 / (int)pow(10, i)) % 10) cnt++;
    }
    return cnt;
}
 
int boll(int number, int number2) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if ((number / (int)pow(10, i)) % 10 == (number2 / (int)pow(10, j)) % 10) cnt++;
        }
    }
    return cnt;
}
 
 
int main() {
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> s[i] >> b[i];
    }
 
 
    int ans = 0;
    for (int i = 123; i < 988; i++) {
        int check = 0;
        for (int j = 0; j < n; j++) {
            if (strike(i, arr[j]) == s[j] && boll(i, arr[j]) == b[j]) check++;
        }
        if (check == n) ans++;
    }
 
    cout << ans << endl;
 
    system("pause");
    return 0;
}

/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/2
*************
< 문제명 >    : 영팔이 (eightnine.cpp)
< 문제 >      :
5x5 2차원 배열이 주어질 때 어떤 원소가 상하좌우에 있는 원소보다 작을 때 
해당 위치에 * 을 표시하는 프로그램을 작성하시오.
경계선에 있는 수는 상하좌우 중 존재하는 원소만을 비교한다.

< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/
