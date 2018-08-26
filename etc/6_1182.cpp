/************
< 날짜 >	  : 2018-07-16
< 주소 >      : https://www.acmicpc.net/problem/1182
*************
< 해결방안 >   :

*************
< 오답노트 >   :


*************/
//N개의 정수로 이루어진 집합이 있을 때, 
//이 집합의 공집합이 아닌 부분집합 중에서 
//그 집합의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int board[20];

int findSub(vector<int>& arr){

}

int main(){
	int n,s;
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> board[i];

	cout << findSub() << endl;
}