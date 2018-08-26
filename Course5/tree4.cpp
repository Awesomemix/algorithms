#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
int common;
//1. 공통조상이 0보다 클 때
//1.1 y가 x의 조상들 중 하나일 때
//2. 공통조상이 0일 때
int findparent(int root, int cnt, int tot){
	int ans = 0;
	if(root == tot) return cnt;
	ans = findparent(arr[root],cnt+1,tot);
	return ans;
}

int parent(int x, int y, int cnt){
	int ans = 0;
	//return 0: 대칭, return 1:비대칭
	if(cnt != 0 && (x == 0 || y == 0)) {
		return 0;
	}
	if(cnt == 0 && (x == 0 || y == 0)){
		return 0;
	}
	if(arr[x] == arr[y]){
		common = arr[x];
		return 0;
	}
	if(x == arr[y]){
		common = x;
		return 1;
	}
	if(y == arr[x]){
		common = y;
		return 1;
	}

	else{
		if(arr[x] < arr[y]) ans = parent(x,arr[y],cnt++);
		else if(arr[x] > arr[y]) ans =parent(arr[x],y,cnt++);
	}
	return ans;
}

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	int num1, num2;
	for(int i = 1; i < n; i++){
		cin >> num1 >> num2;
		arr[num2] = num1;
	}
	int answer = 0;

	if(parent(x,y,0) == 0){
		if(common == 0) answer = findparent(x,0,0) + findparent(y,0,0);
		else answer =  findparent(x,0,common) + findparent(y,0,common);
	}
	else if(parent(x,y,0) == 1){
		if(x > y){
			answer = findparent(x,0,common);
		}
		else{
			answer = findparent(y,0,common);
		}

	}

	cout << answer << endl;
	system("pause");

	return 0;
}