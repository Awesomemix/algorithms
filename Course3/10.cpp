#include <iostream>
#include <algorithm>
using namespace std;
 
long long int gcd(long long int a, long long int b){
    return b ? gcd(b,a%b) : a;
}
 
int main(){
    int n;
    cin >> n;
 
    long long int arr[n+1];
    long long int min = 0;
    long long int ans = 0;
 
    for(int i=0 ; i<n ; i++) cin >> arr[i];
 
    min = arr[1] - arr[0];
    for (int i = 1; i < n-1; i++) {
        min = gcd(min, arr[i+1] - arr[i]);
    }
 
    ans = (arr[n-1] - arr[0]) / min + 1 - n;
 
    cout << ans << endl;
    return 0;
}
× D