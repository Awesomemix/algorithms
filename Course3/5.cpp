#include <iostream>
#include <algorithm>
using namespace std;
int n;
int b[1001];
int a[1001];
 
int main(){
 
    cin >> n;
 
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
 
    for(int i = 0; i < n; i++){
        if(i == 0) { a[0] = b[0]; continue; }
        else if(i == 1) { a[1] = b[1] * 2 - b[0]; continue; }
        else a[i] = (b[i]*(i+1)) - (b[i-1]*i);
    }
 
    for(int i = 0; i < n; i++) cout << a[i] << " ";
 
    system("pause");
    return 0;
 
}