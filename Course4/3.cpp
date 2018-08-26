#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[100];
 
void tobin(int x, int y){
    if(x == n){ 
        if(y == k){
            for(int i = 0; i < n; i++) cout << a[i];
            cout << endl;
        }
        return;
    }
 
    if(y < k){ // less than k
        a[x] = 1;
        tobin(x+1,y+1);
    }
 
    a[x] = 0;
    tobin(x+1,y);
 
}
 
int main(){
    cin >> n >> k;
    tobin(0,0);
 
    system("pause");
    return 0;
}