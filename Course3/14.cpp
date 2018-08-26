#include <iostream>
#include <algorithm>
using namespace std;
long long int b[1000000];
long long int c[1001]; 
long long int d[1000000];
 
bool sosu(long long int x){
    for(int i = 2; i < x; i++){
        if(x%i == 0) return false;
    }
    return true;
}
 
int main(){
    int cnt = 0;    //input
    while(true){
        cin >> b[cnt];
        if(b[cnt] == 0) break;
        else cnt++;
    }
    
    int cnt2 = 0;
    for(int i = 2; i < 1500; i++){ //find
        if(sosu(i)) c[cnt2++] = i;
    } 
    
    d[0] = d[1] = -1;
    for(int i = 0; i < cnt2; i++){
        for(int j = 0; j <= 270000; j++){ //check
            if(j != c[i] && j % c[i] == 0){
                d[j] = -1; 
            }
        }
    }
    
    for(int i = 0; i < cnt; i++){
        int ans = 0; 
        for(int j = b[i]+1; j <= 2*b[i]; j++){
            if(d[j] != -1) ans++;
        }
        cout << ans << endl;
    }
 
    return 0;
} 