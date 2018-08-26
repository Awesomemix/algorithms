#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M;
int u, v;

void dfs(int cur) {
	visited[cur] = true; //�湮������ ǥ��
	for (int i = 0; i < edge[cur].size(); i++) { //edge ���� Ȯ��
		//������ ��ȣ�� �� ���� ���� ���� �湮�Ѵ�
		int there = edge[cur][i]; // ���� cur ���� i��°�� ����� �������� Ȯ��
		if (visited[there]) continue; //�湮�� �����̸� �ش� �Ʒ��� �ǳʶٰ� �ݺ� ����
		dfs(there);
		
	}
	
}

int main() {
	cin >> N >> M; //���� ������ ���� ����
	edge.resize(N + 1);
	visited.resize(M + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		
	}
	dfs(1);
	
}