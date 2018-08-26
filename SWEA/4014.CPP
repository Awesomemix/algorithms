

/*파악한 것
1. 가로부터 시작하든 세로부터 시작하든 1 이하의 수는 불가능

2. 경사로의 길이는 맵 밖으로 나갈 수 없다.

3. 높이 차이는 1이 날 경우 + X값 만큼의 거리차가 있을 때 경사로를 놓을 수 있다.
11211 => 왼쪽과 오른쪽에 

4. 이미 설치된 곳에는 설치 불가

*/
#include <iostream>
#include <memory.h>
using namespace std;
 
int t, n, k;
int map[20][20];
bool check[20][20];
 
//가로방향
bool dfs(int x,int y) {
    if (y == n - 1) return true; 
    //높이 같은경우
    if (map[x][y] == map[x][y + 1]) return dfs(x, y + 1); //더있나 찾아보기
    //내리막

    else if (map[x][y] == map[x][y + 1] + 1) {
    //범위 벗어남
        if (y + k >= n) return false;

        for (int i = 1; i <= k; i++) {
        //경사로 설치
            check[x][y + i] = true;
            //높이 다르면
            if (map[x][y] != map[x][y + i] + 1)return false;
        }
        return dfs(x, y + k); //K만큼 뛰어서 더있나 찾아보기
    }

    //오르막
    else if (map[x][y] == map[x][y + 1] - 1) {
    //범위 벗어남
        if (y - k + 1 < 0) return false;
        for (int i = 0; i < k; i++) {
        //이미 경사로 설치됨
            if (check[x][y - i]) return false;
            //높이 다름
            if (map[x][y] != map[x][y - i]) return false;
            check[x][y - i] = true;
        }
        return dfs(x, y + 1);
    }
    return false;
}
 
//세로방향
bool dfs2(int x, int y) {
    if (x == n - 1) return true;
 
    //높이 같은경우
    if (map[x][y] == map[x + 1][y]) return dfs2(x + 1, y);
    //내리막
    else if (map[x][y] == map[x+1][y] + 1) {
        //범위 벗어남
        if (x + k >= n) return false;
        for (int i = 1; i <= k; i++) {
            //경사로 설치
            check[x + i][y] = true;
            //높이 다르면
            if (map[x][y] != map[x+i][y] + 1)return false;
        }
        return dfs2(x + k, y);
    }
    //오르막
    else if (map[x][y] == map[x+1][y] - 1) {
        //범위 벗어남
        if (x - k + 1 < 0) return false;
        for (int i = 0; i < k; i++) {
            //이미 경사로 설치됨
            if (check[x - i][y]) return false;
            //높이 다름
            if (map[x][y] != map[x-i][y]) return false;
            check[x - i][y] = true;
        }
        return dfs2(x + 1, y);
    }
    return false;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
 
    cin >> t;
 
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> k;
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
 
        int res = 0;
        for (int i = 0; i < n; i++)if (dfs(i, 0))res++;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; i++)if (dfs2(0, i))res++;
        memset(check, 0, sizeof(check));
        cout << "#" << tc << " " << res << endl;
    }
}

