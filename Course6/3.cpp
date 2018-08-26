#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool board[1001][1001];
bool visited[1001];
int check[1001];
//이분그래프
const int NO_COLOR = 0;
const int RED = 1;
const int BLUE = 2;

bool flag;
int n,m;

void dfs(int a, int color){
	visited[a] = true;
	check[a] = color;
	//인접한 곳에 칠할 색 결정
	int target = color == RED ? BLUE : RED;

	for(int i = 1; i <= n; i++){	
		if(board[a][i] && board[i][a] && check[i] == color)
		flag = true;
		if(!visited[i] && board[a][i] && board[i][a]){
			dfs(i,target);
		}
	}
}

int main(){
	cin >> n >> m;
	int num1, num2;
	for(int i = 0; i < m; i++){
		cin >> num1 >> num2;
		board[num1][num2] = board[num2][num1] = true;
	}

	dfs(1,RED);

	if(!flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}


