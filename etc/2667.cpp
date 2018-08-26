#include <iostream>
#include <algorithm>
using namespace std;
int n, d;
char house[26][26];
bool visit[26][26];
int danzi[26 * 26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void DFS(int x, int y)
{
	int ax, ay;
	danzi[d]++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i], ay = y + dy[i];
		if (ax < 0 || ax >= n || ay < 0 || ay >= n)
			continue;
		if (house[ax][ay] == '1' && !visit[ax][ay])
			DFS(ax, ay);
	}
}
int main(void)
{
	int bunzi = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> house[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (house[i][j] == '1' && !visit[i][j])
			{
				d++;
				DFS(i, j);
			}
		}
	}
	cout << d << "\n"; //총 단지 수
	sort(danzi + 1, danzi + 1 + d);
	for (int i = 1; i <= d; i++)
		cout << danzi[i] << "\n"; //단지 내 집의 수
}
