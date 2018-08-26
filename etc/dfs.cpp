#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M;
int u, v;

void dfs(int cur) {
	visited[cur] = true; //방문했음을 표시
	for (int i = 0; i < edge[cur].size(); i++) { //edge 마다 확인
		//정점의 번호가 더 작은 쪽을 먼저 방문한다
		int there = edge[cur][i]; // 현재 cur 에서 i번째로 연결된 도착정점 확인
		if (visited[there]) continue; //방문한 지점이면 해당 아래를 건너뛰고 반복 실행
		dfs(there);
		
	}
	
}

int main() {
	cin >> N >> M; //정점 개수와 간선 개수
	edge.resize(N + 1);
	visited.resize(M + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		
	}
	dfs(1);
	
}