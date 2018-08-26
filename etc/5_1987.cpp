//************
< 날짜 >	  : 2018-07-16
< 주소 >      : https://www.acmicpc.net/problem/1987
*************
< 해결방안 >   :

*************
< 오답노트 >   :
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 0, -1, 0, 1 };

char board[20][20];
bool visited[20][20];
int r,c;


int findBlock(int x, int y, vector<char>& alpha,int count){

	int count = 0;
	visited[x][y] = true; //현재 좌표 방문표시

	for(int i = 0; i < alpha.size(); i++){ //등장한 알파벳이었다면 종료
		if(board[x][y] == alpha[i]) return 0;
	}

	alpha.push_back(board[x][y]); //알파벳 목록에 넣음

	for(int i = 0; i < 4; i++){ //사방 체크
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!visited[nx][ny]) int next = findBlock(nx, ny, alpha,count+1);
		if(ans < next) ans = next;
	}

	alpha.pop_back(); //돌아왔다면 목록에서 빼고
	visited[x][y] = false; //방문 체크를 해제

	return count;
}

void makeVisitTrue(){
	for(int i = 0; i < c; i++){
		for(int j = 0; j <r; j++){
			visited[i][j] = true;
		}
	}
}

int main(){


	cin >> r >> c;

	vector<char> a;
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			cin >> board[i][j];
		}
	}

	findBlock(0,0,a,0);
	cout << count << endl;
	return 0;
}
*************/


#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


//board 와 check 를 &로 보내줌
int go(vector<string> &board, vector<bool> &check, int x, int y) {

	//답 초기화
    int ans = 0;

    for (int k=0; k<4; k++) {

        int nx = x+dx[k];
        int ny = y+dy[k];

        //범위 내 존재 확인
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
          
          	//
            if (check[board[nx][ny]-'A'] == false) {
                check[board[nx][ny]-'A'] = true; //배열로서 true false 체크(vs.벡터 push)
              
                int next = go(board, check, nx, ny);
              
                if (ans < next) { //ans !!!!!
                    ans = next;
                }

                check[board[nx][ny]-'A'] = false;
            }
        }
    }

    //하나씩 더해가면서!! 
    return ans + 1;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n); //string 으로 받는다!!!

    for (int i=0; i<n; i++) {
        cin >> board[i];
    }

    vector<bool> check(26); //알파벳 체크

    //벡터를 string으로 저장했을 때, 배열로 접근 가능
    check[board[0][0]-'A'] = true;

    cout << go(board, check, 0, 0) << '\n';
    return 0;
}