//headers
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//global values
const int MUL = 1;
const int DIV = 2;
int n; //( 0 ≤ N ≤ 99,999 )
int ans;
vector<int> a;
//functions
/* 
Mul : 현재까지의 계산 결과에 2를 곱한다
Div : 현재까지의 계산 결과를 3으로 나눈다. 
단, 결과가 정수가 아닐 경우, 소수점 이하를 모두 버린다.
*/
//계산기를 작동시키면 1이 출력되고, 여기서 Mul를 누르면 2가 되며, 또 Mul을 누르면 4가 출력
//계산기를 작동시켜 숫자 N을 만들기 위하여 최소 몇 번 버튼을 눌러야 하는지를 구하는 프로그램
void solve(int cur, int cnt){
	if(cur / 10 > 5 || cur <= 0) return;
	if(cur == n) {
		a.push_back(cnt);
		return;
	}
	else{
		solve(cur * 2, cnt+1);
		solve(cur / 3, cnt+1);
	}
}

int main(){
	cin >> n;
	solve(1, 0);
	int mi = 99999999;
	for(int i = 0; i < a.size(); i++){
		mi = min(mi,a[i]);
	}
	system("pause");
	return 0;
}