//미완
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 21;    
int b[MAX][MAX];
int c,r;
 
void color(int i, int j){
    for(int k = j; k < j+4; k++){
        if(b[k][i] == 0) b[k][i] = -1;
    }
}
 
void decolor(int i, int j){
    for(int k = j; k < j+4; k++){
        if(b[k][i] == -1) b[k][i] = 0;
    }
}
 
int count(int i, int j){ //c,r
    int cnt = 0; int ret = 0;
    for(int k = 0; k < c; k++){
        for(int l = 0; l < r; l++){
            if(b[k][l] == 1 || b[k][l] == -1) cnt++;
        }
        if(cnt == r) ret++; cnt = 0;
    }
    return ret;
}
 
int main(){
    
    cin >> r >> c; // 가로 세로
 
    for(int i = 0; i < c; i++){ //각 행 마다
        for(int j = 0; j < r; j++){ // 모든 열들에
            cin >> b[i][j];
        }
    }
 
    int cnt = 0; // 0 count
    int temp = 0; // for answer swapping
    int ans = 0; // tatal column
    int ans_x; // hightest score X
    
    for(int i = 0; i < r; i++){ //각 열에 대해
        for(int j = c-1; j >= 0; j--){ //행 하나씩 올라가면서
            if(b[j][i] == 0) {
                cnt++; //빈칸 카운트
            } 
            if(cnt >= 4) {
                color(i,j); //cover          
                temp = count(i,j);
                if(ans < temp){
                    ans = temp;
                    ans_x = i;
                }
                decolor(i,j); //open 
                break;
            }
        }
        cnt = 0;
    }
 
    if(ans == 0) cout << "0" << " " << "0" << endl;
    else cout << ans_x+1 << " " << ans << endl;
    
    system("pause");
    return 0;
}


/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/4
*************
< 문제명 >    : 테트리미노 (tetris.cpp)
< 문제 >      :
이때 가로가 1칸이고 세로가 4칸인 1×4 직사가형 작대기 모양의 테트리미노(테트리미노는 항상 1×4)를 왼쪽에서 5번째 칸에 둘 경우 총 세줄의 수평선을 메울 수 있다.
테트리스는 한번에 여러 수평선을 메울수록 큰 점수를 얻는 게임이므로, 위 경우에서는 이 방법이 가장 높은 점수를 얻을 수 있는 방법이다.

윤성이를 도와 작대기 모양 테트리미노를 어디에 두었을 때 가장 높은 점수를 얻을 수 있는지 알려주자. 
(윤성이는 작대기 모양 테트리미노가 나왔을때 게임오버를 당할지언정 가로가 더 길도록 눕혀서 두지 않는다는 나름의 테트리스 철학이 있다.)
< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/
