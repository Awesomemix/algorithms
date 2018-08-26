#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 20;
int board[MAX][MAX];
bool check[MAX][MAX];
int n,k;

bool bfs(int x, int y){
	if(y == n - 1) return true;

	if(board[x][y] == board[x][y+1]) bfs(x,y+1);
	
	else if(board[x][y] == board[x][y+1] + 1){

		if(y + k - 1 >= n) return false;

		for(int i = 1; i <= k; i++){
			if (board[x][y] != board[x][y + i] + 1)return false;
			check[x][y+i] = true;
		}

		return bfs(x,y+k); //
	}

	else if(board[x][y] == board[x][y+1] - 1){

		if(y - k + 1 <= 0) return false;

		for(int i = 1; i <= k; i++){

			if(check[x][y-i] == true) return false;
			if (board[x][y] != board[x][y - i] + 1)return false; //
			check[x][y-i] = true;

		}
		return bfs(x,y+1); //k 만큼 가는 게 아니라 뒷부분 점검했으니까
	}
}


bool bfs(int x, int y){
	if(x == n - 1) return true;

	if(board[x][y] == board[x+1][y]) bfs(x+1,y);

	else if(board[x][y] == board[x+1][y] + 1){

		if(x + k - 1 >= n) return false;

		for(int i = 1; i <= k; i++){
			if (board[x][y] != board[x + i][y] + 1)return false;
			check[x + i][y] = true;
		}

		return bfs(x,y+k); //
	}
	else if(board[x][y] == board[x + 1][y] - 1){

		if(x - k + 1 <= 0) return false;

		for(int i = 1; i <= k; i++){

			if(check[x-i][y] == true) return false;
			if (board[x][y] != board[x - i][y] + 1)return false; //
			check[x-i][y] = true;

		}
		return bfs(x+1,y); //k 만큼 가는 게 아니라 뒷부분 점검했으니까
	}
}

int main(){

	int test_case;
	int T;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> k;

	}

	return 0;
}

/*
- 경사로는 높이 차이가 1 이고 낮은 지형의 높이가 동일하게 경사로의 길이만큼 연속되는 곳에 설치 할 수 있다.
- 경사로는 높이 차이가 1 이고 낮은 지형의 높이가 동일하게 경사로의 길이만큼 연속되는 곳에 설치 할 수 있다.
- 경사로를 지형 밖까지 설치해야 되기 때문에 활주로를 설치할 수 없다.

- N 의 크기는 6 이상 20 이하의 정수이다. ( 6 ≤ N ≤ 20 )

- 경사로의 높이는 항상 1 이고, 길이 X 는 2 이상 4 이하의 정수이다. ( 2 ≤ X ≤ 4 )

- 지형의 높이는 1 이상 6 이하의 정수이다.

- 동일한 셀에 두 개 이상의 경사로를 겹쳐서 사용할 수 없다.
*/