#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//부모를 배열로
int arr[1005];

void parent(int x, int y, int cnt){
	if(cnt != 0 && (x == 0 || y == 0)) {
		return;
	}
	if(cnt == 0 && (x == 0 || y == 0)){
		cout << 0;
		return;
	}
	if(x == arr[y]){
		cout << x;
		return;
	}
	if(y == arr[x]){
		cout << y;
		return;
	}
	if(arr[x] == arr[y]){
		cout << arr[x];
		return;
	}
	else{
		if(arr[x] < arr[y]) parent(x,arr[y],cnt++);
		else if(arr[x] > arr[y]) parent(arr[x],y,cnt++);
	}
}

int main(){
	int x,y,n;
	cin >> n >> x >> y;
	int num1, num2; //parent,child
	for(int i = 1; i < n; i++){
		cin >> num1 >> num2;
		arr[num2] = num1;
	}

	parent(x,y,0);
	system("pause");
	return 0;

}