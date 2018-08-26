#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int edge[1001][1001];
int visit[1001];
bool isDone;
int cnt;
int N, M;
int u, v;

void dfs(int cur) {
	visit[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (edge[cur][i] && !visit[i]) {
			visit[i] = true;
			dfs(i);
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u][v] = edge[v][u] = true;
	}

	for (int i = 1 ; i <= N ; i++) {
		if (visit[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	system("pause");
	return 0;

}

