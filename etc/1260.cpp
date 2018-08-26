#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, m, v;
int edge[1005][1005];
int visit[1005];

void dfs(int cur)
{
	visit[cur] = true;
	cout << cur << " ";
	for (int i = 1; i <= n; i++) {
		if (edge[cur][i] && !visit[i]) {
			visit[i] = true;
			dfs(i);
		}
	}
}

void bfs(int cur)
{
	queue<int> q;

	q.push(cur);
	visit[cur] = true; //처음값 초기화

	while (!q.empty()) {
		int here = q.front();
		cout << here << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (edge[here][i] && !visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}
}
int main()
{
	scanf_s("%d%d%d", &n, &m, &v);
	int x, y;

	for (int i = 0; i<m; ++i) {
		scanf_s("%d%d", &x, &y);
		edge[x][y] = edge[y][x] = true;
	}

	dfs(v);
	cout << "\n" ;

	for (int i = 1; i <= n; i++) {
		visit[i] = false;
	}

	bfs(v);
	system("pause");
	return 0;

}

