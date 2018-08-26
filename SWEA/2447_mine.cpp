/************
< 주소 >      : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy
*************
< 해결방안 >   :


*************
< 오답노트 >   :


*************/
#include <iostream>
#include <algorithm>
#include <queue>
#include <pair>
using namespace std;
//define
#define EMPTY -1
#define DONE 0

//const
const int MAX_NM = 9;
const int MAX_AB = 20;
const int MAX_TK = 1000;


//input data
int n, m, k;
int ai[MAX_AB], bi[MAX_AB]; //창구 별 처리 시간
int tk[MAX_TK]; //사람 별 도착한 시간

queue<pair<int,int>> a_q;
queue<pair<int,int>> b_q;
int check_an[MAX_AB], check_bn[MAX_AB] = { -1, };
int check_at[MAX_TK], check_bt[MAX_TK]; //false = 정비소 비어있음

int count;

void jupsoo(){

/*
1)queue 에 넣는다.
2)while empty 가 될 때 까지 로직 진행
3)창구 비어있으면 해당 창구가 모두 찰 수 있도록 넣는다
4)창구가 비어있지 않을 때
 - 창구 처리 시간 완료 시 해당 사람 b_q에 넣는다.
*/
	for(int i = 0; i < k; i++){
		a_q.push(make_pair(k,tk[i]));
	}

	while(!a_q.empty()){

		for(int i = 0; i < n; i++){
			if(check_at[i] < DONE){ //창구 비어있으면
				int customer_time = a_q.front().first;
				int customer_num = a_q.front().second;
				a_q.pop();
				check_at[i] = customer_time; //시간과 번호 저장
				check_an[i] = customer_num;
			}
		}

		for(int i = 0; i < n; i++){
			if(check_at[i] == DONE){ //창구 처리 시간이 완료되었다면
				b_q.push(make_pair(check_an[i], tk[check_an[i]]));
				check_at[i] = EMPTY;
				check_an[i] = EMPTY;
			}
			
		}

		for(int i = 0; i < n; i++){ //check 시간 감소
			check_at[i]--;
		}
		

	}//while

	while(!b_q.empty()){

		for(int i = 0; i < n; i++){
			if(check_bt[i] < DONE){ //창구 비어있으면
				int customer_time = b_q.front().first;
				int customer_num = b_q.front().second;
				b_q.pop();
				check_bt[i] = customer_time; //시간과 번호 저장
				check_bn[i] = customer_num;
			}
		}

		for(int i = 0; i < n; i++){
			if(check_bt[i] == DONE){ //창구 처리 시간이 완료되었다면 작은순
				b_q.push(make_pair(check_an[i], tk[check_an[i]]));
				check_bt[i] = EMPTY;
				check_bn[i] = EMPTY;
			}
			
		}

		for(int i = 0; i < n; i++){ //check 시간 감소
			check_at[i]--;
		}
		

	}//while



}


int main(){

}