#include <iostream>
using namespace std;
long long c[101][101];
 
int solve(int n, int r){
    if(n==r || r==0) return 1;
 
    return solve(n-1,r-1) + solve(n-1,r);
}
 
int main(){
 
    int n;
    int m;
    cin >> n >> m;
    cout << solve(n,m) << endl;
    return 0;
}