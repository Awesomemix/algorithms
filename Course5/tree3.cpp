#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[101];
int totroot;

int count(int root,int cnt){
	int ans = 0;
	if(root == totroot) return cnt;
	ans = count(arr[root],cnt+1);
	return ans;
}

int main(){
	int n;
	int root;
	cin >> n >> totroot;
	int num1, num2;
	for(int i = 1; i < n; i++){
		cin >> num1 >> num2;
		// arr[i] = num1;
		arr[num2] = num1;
	}

	int mx = 0;
	int temp = 0;
	for(int i = 1; i < n; i++){
		temp = count(i,0);
		mx = max(temp,mx);
	}

	cout << mx << endl;

	system("pause");
	return 0;
}