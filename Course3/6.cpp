#include <iostream>
#include <algorithm>
using namespace std;
long long int b[1001][1001];
long long int s[1001]; 
long long int a[1001];
int main(){
    
    long long int n;
    cin >> n;
    for(int i = 0; i < n; i++){ //s
        for(int j = 0; j < n; j++){ //g 
            cin >> b[i][j];
        }
    }
    
    //S(1) = 3A(1) + A(2) + A(3) + A(4)
    //S(2) = A(1) + 3A(2) . . .
    // 
    long long int c = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s[i] += b[j][i]; 
            c += b[j][i]; 
        }
    }
    
    c /= 2*(n-1); //A(1)+A(2)+A(3)+A(4)
 
    for(int i = 0; i < n; i++){
        a[i] = (s[i] - c) / (n-2);
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
 
    return 0;
    
    
    
}