/************
< 주소 >      : https://www.acmicpc.net/problem/9095
*************
< 해결방안 >   :
재구함수 사용(n 이 11까지)
*************
< 오답노트 >   :

무조건 DFS로 생각하지 말고, 함수 파라미터에 무엇이 들어가야 하는지 체크해야함
내가 생각한 파라미터: n:used 위치, k: 1,2,3 ans:정답 
정답 파라미터: sum, goal, count => sum:지금까지의 합, goal:목표값, count:숫자개수

*************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int board[9][9];
bool check[9];

int oneSolve(int a){
	for(int i = 1; i <= 9; i++){
		
		check[]
	}
}

int main(){

	vector<pair<int,int>> one;
	int count;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> board[i][j];
			if(board[i][j] == 0) count++;
		}
		if(count == 1) oneSolve(i);
	}




}