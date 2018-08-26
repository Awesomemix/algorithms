#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int n;
    cin >> n;
    
    int na = 2;
    int ca = n;
    while(1){
        if (ca == 1){
            break;
        }
        else if(ca%na == 0) {
            ca = ca / na;
            cout << na << endl;
        }
        else if(ca%na != 0){
            na++;
        }
    }
    
    return 0;
    
}