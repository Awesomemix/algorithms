#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node{
	int left;
	int right;
}NODE;

NODE arr[101];

void preorder(int root){
	if(root == -1) return;
	else{
		cout << root << " ";
		preorder(arr[root].left);
		preorder(arr[root].right);
	}
}

void inorder(int root){
	if(root == -1) return;
	else{
		inorder(arr[root].left);
		cout << root << " ";
		inorder(arr[root].right);
	}
}

void postorder(int root){
	if(root == -1) return;
	else{
		postorder(arr[root].left);
		postorder(arr[root].right);
		cout << root << " ";
	}
}

int main(){
	int n;
	cin >> n;
	int num1, num2, num3;
	for(int i = 0; i < n; i++){
		cin >> num1 >> num2 >> num3;
		arr[num1].left = num2;
		arr[num1].right = num3;
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);

	system("pause");
	return 0;

}