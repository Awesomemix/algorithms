#include <iostream>
#include <algorithm>
using namespace std;
int memo[100000];
int n;
int cnt;
 
void solve(int x, int idx) {
    if (x<0) return;
    if (x==0) {
        cout << memo[0];
        if(idx > 1){
            for (int i=1; i<idx; i++) cout<<"+"<<memo[i];
        }
        cout << endl;
        cnt++;
        return;
    }
 
    for (int i=n-1; i>0; i--) {
        if(idx != 0 && memo[idx-1] < i) continue;
        memo[idx] = i;
        solve(x-i, idx+1);  
 
    }
}
 
int main() {
    cin >> n;
    solve(n, 0);
    cout << cnt << endl;
    system("pause");
    return 0;
}