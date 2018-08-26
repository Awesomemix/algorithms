#include <iostream>
using namespace std;
//주어진 타일행렬을 좌우로 뒤집어 출력한다.
int board[100][100];
int ans[100][100];
 
int main(){
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(m == 1) {
                ans[i][j] = board[i][j];
                continue;
            }
            ans[i][j] = board[i][m-j-1];
        }
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }    
 
  //  system("pause");
    return 0;
 
}

/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/4
*************
< 문제명 >    : 테트리미노 (tetris.cpp)
< 문제 >      :
영팔이는 숫자 0과 8을 굉장히 좋아하는 아이이다. 그 이유는 숫자가 좌우로 뒤집어져도 똑같이 생겼기 때문이라고 한다. 영팔이는 숫작 0과 8의 매력을 사람들에게 전파하기 위해 유리로된 N×M타일에 0과 8들을 잔뜩 써놓았다. 이제 영팔이는 0과 8로된 숫자들은 좌우로 뒤집어도 여전히 0과 8들이라는 것을 보여주려고 한다.
< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/
