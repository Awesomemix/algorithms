//headers
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//global values
int n, m;
int board[1001][1001];
int visit[1001][1001]; //!!
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

//functions
bool checkArea(int y, int x){
	return (y >= 0 && y < n && x >= 0 && x < m);
}

int bfs(int y, int x){
	queue< pair<int,int> > q;
	visit[y][x] = 0;
	q.push(make_pair(y,x));

	while(!q.empty()){
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();

		if(fy == 0 && fy == m-1) break; //this part!

		for(int i = 0; i < 4; i++){
			int ny = fy+dy[i];
			int nx = fx+dx[i];
			if(checkArea(ny,nx) && visit[ny][nx] == 0 && board[ny][nx] == 0){
				visit[ny][nx] = visit[fy][fx]+1; //and this part!
				q.push(make_pair(ny,nx));
			}
		}
	}

	return visit[0][m-1];
}

int main(){

	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
		for(int j = 0 ; j < m; j++)
			cin >> board[i][j];

	cout << bfs(n-1,0) << endl;
	system("pause");
	return 0;

}