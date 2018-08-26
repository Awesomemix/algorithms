#include <iostream>
#include <algorithm>
#include <math.h> 
using namespace std;
 
void mountain(int x){
    if(x == 1) cout << 1;
    else if(x == 2){
        cout << 1 << 2 << 1;
    }
    else{
        mountain(x-1);
        cout << x;
        mountain(x-1);
    }
}
 
int main(){
    int n;
    cin >> n;
    
    mountain(n);
    return 0;
 
}