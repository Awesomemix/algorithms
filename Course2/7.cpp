
 
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int board[1010][10];
int cnt[1010];
 
int main(){
 
    cin >> n; //학생수
    for(int i = 0; i < n; i++){                    //행: 학생 번호
        for(int j = 0; j < 5; j++){                //열: 학년 별 반 번호 
            cin >> board[i][j];                    //번호순으로 몇학년 떄 몇반
        }
    }
 
 
    int maxtemp = -1; int ans = 0; int count = 0;                //chk:temp, ans:학생들과 같은 반이었던 횟수가 많은 학생
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < 5; j++){             // 5학년 동안의
            for(int k = 0; k < n; k++){         // 모든 학생들과 비교
                if(i == k) continue;
                if(board[i][j] == board[k][j]) cnt[k]++;
            }                                    // 특정 학년때 같은 반이었다면 추가
        }
 
        for(int l = 0; l < n; l++){
            if(cnt[l] != 0)
                count++;
                cnt[l] = 0;
        }
 
        if(maxtemp < count){
            maxtemp = count;
            count = 0;
            ans = i;
        }
        else{
            count = 0;
        }
    }
 
    cout << ans + 1 << endl;                        //배열이 0부터 시작
    return 0;
 
}

/*************
< 날짜 >        :2018-08-04 ~ 2018-08-
< 문제 >        :임시반장정하기
< 주소 >        :http://www.algorithmlabs.net/company/swtest/index.php/problems/129/7
*************
< 문제요약 >    :    
- 전체 학생 중에서 같은 반이었던 학생 수가 제일 많으므로 임시 반장이 된다.
- 자기반 학생 중에서 1학년부터 5학년까지 지내오면서 한번이라도 같은 반이었던 
  사람이 가장 많은 학생을 임시 반장으로 정하려 한다.
*************
< 해결방안 >    :
- 열 별로 같은 수가 가장 많은 행의 번호를 찾는다.
*************
< 오답노트 >    :
**************/