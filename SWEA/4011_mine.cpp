/************
< 주소 >      : 
*************
< 해결방안 >   :


*************
< 오답노트 >   :

dfs 는 선택을 하는 방법이다.
로직은 다른 함수에 분리해둔다.
해당 문제는 맞물리는 것이 아닌 그냥 모양이 톱니.

*************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,result;
int num[12];
int check[12]; // 수식에 사용되는 수의 갯수
int 

void solution(int number){
	visited[number] = true;
	
	if(!check[number+1]) solution(number+1);
	if(!check[number-1]) solution(number-1);
}

int main(){

	cin >> n;
	int num_input;
	
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> cal[i];
	}

	solution(0)

}