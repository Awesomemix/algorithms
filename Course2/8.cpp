
#include <iostream>
#include <algorithm>
using namespace std;
int board[102][102];
int n,m,px,py;
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,1,-1,-1};
 
int main(){
    cin >> n >> m;
    cin >> px >> py;
    for(int i = 1; i <= n; i++){ //행,세로
        for(int j = 1; j <= m; j++){ //열,가로
            cin >> board[i][j];
        }
    }
 
    int x = 0; int y = 0; int cnt = 0;
 
    if(board[px][py] == 1) cout << "game over" << endl;
    else{
        for(int i = 0; i < 8; i++){
            x = px+dx[i]; y = py+dy[i];
            if(x < 1 || y < 1 || x > n || y > n) continue;
            if(board[x][y] == 1) cnt++;
        }
        cout << cnt << endl;
    }
 
    system("pause");
    return 0;
}

/*************
< 날짜 >        :2018-08-04 ~ 2018-08-
< 문제 >        :지뢰찾기
< 주소 >        :http://www.algorithmlabs.net/company/swtest/index.php/problems/129/8
*************
< 문제요약 >    :    
- 어떤 지점을 클릭했을 때, 주변에 몇개의 지뢰들이 존재하는지를 출력하는 프로그램을 작성해보자  
*************
< 해결방안 >    :
- 
*************
< 오답노트 >    :
**************/