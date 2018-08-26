#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 5;
const int BINGO = 3;
 
typedef struct p{
    int x;
    int y;
}POS;
 
int a[MAX+5][MAX+5];
POS B[MAX*MAX+5];
int n, check, bingo, cy, ans;
 
int main(){
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> n;
            B[n].x = i;
            B[n].y = j;
        }
    }
    
    int ans = 99999;
    int cnt = 0; //count
    
    for(int i = 1; i <= MAX*MAX; i++){
        cin >> n;
        a[B[n].x][B[n].y] = -1;
        cnt++;
        
        //bingo check 
        bingo = 0;
        
        for(int j = 0; j < MAX; j++){
            for(int k = 0; k < MAX; k++){  
                if(a[j][k] == -1) check++;
            }
            if(check == 5) bingo++;
            check = 0;
        }
        
        for(int j = 0; j < MAX; j++){        
            for(int k = 0; k < MAX; k++){
                if(a[k][j] == -1) check++;
            }
            if(check == 5) bingo++;
            check = 0;
        }
            
        // cross 
        for(int j = 0; j < MAX; j++){
            if(a[j][j] == -1) check++;
        }
        if(check == 5) bingo++;
        check = 0;
            
        cy = 4;
        for(int j = 0; j < MAX; j++){
            if(a[j][cy--] == -1) check++;
        }
        if(check == 5) bingo++;
        check = 0;    
        
        //total
        if(bingo >= BINGO) ans = min(ans, cnt);
    }
    
    cout << ans << endl;
    return 0;
 
}


/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/4
*************
< 문제명 >    : 빙고 (bingo.cpp)
< 문제 >      :
빙고 (bingo.cpp)
 

문제
빙고 게임은 다음과 같은 방식으로 이루어진다.

먼저 아래와 같이 25개의 칸으로 이루어진 빙고판에 1부터 25까지 자연수를 한 칸에 하나씩 쓴다


다음은 사회자가 부르는 수를 차례로 지워나간다. 예를 들어 5, 10, 7이 불렸다면 이 세 수를 지운 뒤 빙고판의 모습은 다음과 같다.

차례로 수를 지워가다가 같은 가로줄, 세로줄 또는 대각선 위에 있는 5개의 모든 수가 지워지는 경우 그 줄에 선을 긋는다.


이러한 선이 세 개 이상 그어지는 순간 "빙고"라고 외치는데, 가장 먼저 외치는 사람이 게임의 승자가 된다.

철수는 친구들과 빙고 게임을 하고 있다. 철수가 빙고판에 쓴 수들과 사회자가 부르는 수의 순서가 주어질 때, 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지를 출력하는 프로그램을 작성하시오.


입력
첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 가장 위 가로줄부터 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 여섯째 줄부터 열째 줄까지 사회자가 부르는 수가 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 빙고판에 쓰여진 수와 사회자가 부르는 수는 각각 1부터 25까지의 수가 한 번씩 사용된다.


출력
첫째 줄에 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지 출력한다.


< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/