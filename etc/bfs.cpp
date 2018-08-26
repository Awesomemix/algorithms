#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M;
int u, v;

void bfs(int cur) {
	queue<int> q; //������� ���� Ȯ���ϱ� ���� q����
	visited[cur] = true; //���� ��ġ�� true �� ����
	q.push(cur);
	while(!q.empty()){
		int here = q.front(); //q�� ���� ���� ���Ҹ� ���� Ȯ�� �������� ����
		q.pop();
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i]; // ����� ���� �� ���� ������
			if (visited[there]) continue; //true ��� �Ʒ����� ����X
			visited[there] = true; //�湮 ó�� �صΰ�
			q.push(there); //�湮 ���� q�� �ִ´�
		}
	}
}

int main() {
	cin >> N >> M;
	edge.resize(N+1);
	visited.resize(N+1);

	for (int i = 0; i < M; i++) { //������ �� ��ŭ
		cin >> u >> v;
		edge[u].push_back(v); //u�� v�� ����Ǿ������� ǥ��
	}
	bfs(1);
}