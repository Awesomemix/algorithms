#include <iostream>
#include <algorithm>
using namespace std;
int b[100][100];
int n,x,y,r;
 
int main(){
    
    cin >> n;
    cin >> y >> x >> r;
    x -= 1;
    y -= 1;
    
    for(int i = 0; i < r+1; i++){
        for(int j = 0; j < r+1; j++){
            if(y+i < 0 || y+i > n-1 || x+j < 0 || x+j > n-1) continue;
            if(i+j > r) continue;
            b[y+i][x+j] = i + j;
        }
    }
    
    for(int i = r; i >= 0; i--){
        for(int j = r; j >= 0; j--){
            if(y-i < 0 || y-i > n-1 || x-j < 0 || x-j > n-1) continue;
            if(i+j > r) continue;
            b[y-i][x-j] = i + j;
        }
    }
 
    for(int i = 0; i < r+1; i++){
        for(int j = r; j >= 0; j--){
            if(y+i < 0 || y+i > n-1 || x-j < 0 || x-j > n-1) continue;
            if(i+j > r) continue;
            b[y+i][x-j] = i + j;
        }
    }    
 
    for(int i = r; i >= 0; i--){
        for(int j = 0; j < r+1; j++){
            if(y-i < 0 || y-i > n-1 || x+j < 0 || x+j > n-1) continue;
            if(i+j > r) continue;
            b[y-i][x+j] = i + j;
        }
    }    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == y && j == x) cout << "x" << " ";
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
    
}

/************
< 날짜 >      : 2018-07-19
< 주소 >      : http://www.algorithmlabs.net/company/swtest/index.php/problems/128/2
*************
< 문제명 >    : 사거리 (attackrange.cpp)
< 문제 >      :
윤성이는 어렸을 적부터 수없이 몰려오는 적으로부터 기지를 방어하는 디펜스 유형의 게임을 플레이하는 것을 좋아했다. 그래서 간단한 디펜스 게임을 만들어 보려고 한다.

당신은 윤성이를 도와, 디펜스 게임 내에서 플레이어가 설치하는 유닛의 사거리를 나타내는 기능을 구현하면 된다.  

입력
입력 첫째 줄에는 디펜스 게임의 맵 크기 N이 주어딘다. 맵은 N×N 크기의 2차원 형태이다. (N은 6이상 100이하의 짝수)

둘째 줄에는 유닛이 설치될 위치 X, Y와 유닛의 사거리 R이 주어진다. X는 행의 번호, Y는 열의 번호를 의미한다. (X, Y는 1이상 N이하의 자연수, R은 N/2이하의 자연수)

 

출력
예제 출력과 같이 유닛의 사거리를 나타내어 출력한다. (유닛의 사거리가 아무리 길어도 맵을 벗어날 수는 없다.)

< 해결방안 >   : 

*************
< 오답노트 >   :
 
*************/
