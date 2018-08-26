#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
 
    //1, 1+6=7, 1+6+6+6=19, 1+6+6+6+6+6+6=37
    cin >> n;
    int chk = 1;
    int temp = 1;
    int cnt = 1;
 
    while(true){
        if(chk >= n){
            break;
        }
        temp = 6 * (cnt++);
        chk += temp;
    }
 
    cout << cnt;
 
    system("pause");
    return 0;
    
}