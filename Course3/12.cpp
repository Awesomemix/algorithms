#include <iostream>
#include <algorithm>
using namespace std;
long long int b[101];
 
long long int sosu(long long int a)
{
    for(int i = 2; i < a; i++){
        if(a%i == 0) return false;
    }
    return true;
}
 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == 1) continue;
        if(sosu(b[i]) == true) cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}