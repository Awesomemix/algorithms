/************
< 날짜 >	  : 2018-07-15
< 주소 >      : https://www.acmicpc.net/problem/9095
*************
< 해결방안 >   :
재구함수 사용(n 이 11까지)
*************
< 오답노트 >   :

무조건 DFS로 생각하지 말고, 함수 파라미터에 무엇이 들어가야 하는지 체크해야함
내가 생각한 파라미터: n:used 위치, k: 1,2,3 ans:정답 
정답 파라미터: sum, goal, count => sum:지금까지의 합, goal:목표값, count:숫자개수

count 변수(횟수제한)가 필요할 땐 함수 내에 사용한다
해당하는 횟수를 구하기 위해선 함수 내에 변수 선언 후 return 에서 1씩 더하는 구조, 마지막에 변수를 리턴!

*************/

/*
정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <algortihm>
using namespace std;

//sum ; 지금까지의 변화(체크), count,  goal: 제약
int findsum(int count, int sum, int goal){
    if(count > 11) return 0; //count 값 종료조건
	if(sum > goal) return 0; //goal 종료조건 
	if(sum == goal) return 1; //찾았다는 return(마지막에 호출된 함수는 findsum하지 않음(한개씩 찾음))
    
    //방법의수
	int now = 0;
    
    //하나씩 옮겨가며 탐색해본다
	for(int i = 1; i <= 3; i++){
		now += findsum(count+1, sum+i, goal); //함수 호출 횟수마다 1씩 더함
	}
	
	return now;
}

int main(){
	int testcase;
	cin >> testcase;
	for(int tc = 0; tc < testcase; tc++){
		int n;
		cin >> n;
		cout << findsum(0,0,n) << endl;
	}
	return 0;
}