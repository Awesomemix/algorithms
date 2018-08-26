/************
< 주소 >      : https://www.acmicpc.net/problem/9663
*************
< 해결방안 >   :

*************
< 오답노트 >   :
check 연산
calc 다시보기 

*************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool a[15][15];
int ans;

bool check(int row, int col){
	for(int i = 0; i < n; i++){
		if(i == row) continue; //??
		if(a[row][cal]){
			return false;
		}
	}

	int x = row-1;
	int y = col-1;

	while(x >=0 && y >= 0){
		if(a[x][y]==true) return false;
		x -= 1;
		y -= 1;
	}

	int x = row - 1;
	int y = col + 1;

	while(x >= 0 && y < n){
		if(a[x][y]==true) return false;
		x -= 1;
		y += 1;
	}

	return true;

}

void pruning(int row){
	if(row == n){
		ans +=1;
	}
	for(int i = 0; i < n; i++){
		a[row][i] = true; //놓는다
		if(check(row,i)){ //해당 행의 i열에 놓을 수 있다면
			calc(row+1); //다음 행을 찾는다(같은 행 불가니까)
		}
		a[row][i] = false; //백트래킹 되는 시점
	}
}

int main(){
	int n;
	cin >> n;
	pruning(0);
	cout << ans << endl;
	return 0;
}