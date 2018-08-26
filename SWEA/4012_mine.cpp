/************
< 주소 >      : 
*************
< 해결방안 >   :


*************
< 오답노트 >   :

dfs 는 선택을 하는 방법이다.
로직은 다른 함수에 분리해둔다.
해당 문제는 맞물리는 것이 아닌 그냥 모양이 톱니.

*************/

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 16;
int n;
int check = 999999;
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};
int board[MAX][MAX];
int visited[MAX][MAX];

void checkAbs(int x, int y, int nx, int ny){
	int result = abs((board[x][y]+board[y][x])-(board[nx][ny]+board[ny][nx]));
	if(result < check) check = result;
}


void dfs(int x, int y, int ax, int ay){
	visited[x][y] = visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nx = ax + dx[i];
		int ny = ay + dy[i];
		if( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(!visited[nx][ny] && nx != ny && x != y) {
			checkAbs(x, y, nx, ny);
			dfs(x,y,nx, ny);
		}
	}
}


int main(){
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){ //로직 시작
		
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> board[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dfs(i,j,i,j);
			}

		}


		cout << "#" << tc << " " << check << endl;

	}
}