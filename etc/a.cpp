/*************
< 날짜 >      :2018-08-11
< 문제 >      :tobin
< 주소 >      :
*************
< 문제요약 >    :두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력
*************
< 해결방안 >    :백트래킹, 재귀
*************
< 오답노트 >    :
제약조건->   1)n이 다 채워져있는가?
            2)1의 수가 k만큼인가?
해당 여부를 상단의 if문 조건으로 만든다. 1)은 종결조건,
2)는 함수 호출 조건. 해당 함수 조건을 마치면 *아래 문단으로 이동*
**************/
#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[100];
 
void tobin(int x, int y){
    if(x == n){ 
        if(y == k){
            for(int i = 0; i < n; i++) cout << a[i];
            cout << endl;
        }
        return;
    }
 
    if(y < k){ // less than k
        a[x] = 1;
        tobin(x+1,y+1);
    }
 
    a[x] = 0;
    tobin(x+1,y);
 
}
 
int main(){
    cin >> n >> k;
    tobin(0,0);
 
    system("pause");
    return 0;
}