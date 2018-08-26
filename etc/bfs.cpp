#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M;
int u, v;

void bfs(int cur) {
	queue<int> q; //순서대로 빼서 확인하기 위해 q생성
	visited[cur] = true; //현재 위치를 true 로 변경
	q.push(cur);
	while(!q.empty()){
		int here = q.front(); //q의 가장 앞의 원소를 다음 확인 정점으로 선택
		q.pop();
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i]; // 연결된 정점 중 작은 순서로
			if (visited[there]) continue; //true 라면 아래문장 실행X
			visited[there] = true; //방문 처리 해두고
			q.push(there); //방문 점을 q에 넣는다
		}
	}
}

int main() {
	cin >> N >> M;
	edge.resize(N+1);
	visited.resize(N+1);

	for (int i = 0; i < M; i++) { //간선의 수 만큼
		cin >> u >> v;
		edge[u].push_back(v); //u에 v가 연결되어있음을 표시
	}
	bfs(1);
}