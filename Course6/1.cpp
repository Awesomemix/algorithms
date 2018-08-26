#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool board[1001][1001];
bool visited[1001];
int n,m;
vector<int> nums_dfs;
vector<int> nums_bfs;

void dfs(int a){
	visited[a] = true;
	nums_dfs.push_back(a);

	for(int i = 1; i <= n; i++){
		if(!visited[i] && board[a][i] && board[i][a]){
			dfs(i);		
		}
	}
}

void bfs(int a){
	visited[a] = true;
	queue<int> q;
	q.push(a);

	while(!q.empty()){
		int head = q.front();
		q.pop();
		nums_bfs.push_back(head);

		for(int i = 1; i <= n; i++){
			if(!visited[i] && board[head][i] && board[i][head]){
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(){


	cin >> n >> m;
	int num1,num2;
	for(int i = 0; i < m; i++){
		cin >> num1 >> num2;
		board[num1][num2] = board[num2][num1] = true;
	}

	dfs(0);
	for(int i = 0; i <= 1001; i++) visited[i] = false;
	bfs(0);

	for(int i = 0; i < nums_dfs.size(); i++){
		cout << nums_dfs[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < nums_bfs.size(); i++){
		cout << nums_bfs[i] << " ";
	}	

	return 0;

}


/************
< 날짜 >		  : 2018-08-24
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/163/1
*************
< 해결방안 >   :
- 문제:래프가 주어질 때, 0번 정점을 시작으로 하여 깊이우선탐색과 너비우선탐색의 결과를 출력하는 프로그램을 작성하시오.
단, 노드를 방문할 때는 노드 번호가 작은 순서대로 방문한다고 하자.
- 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 

*************
< 오답노트 >   :

**************/