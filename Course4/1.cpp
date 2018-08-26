#include <iostream>
#include <algorithm>
using namespace std;
int n;
void printBinary(int a){
    if(a == 0) cout << 0;
    else if(a == 1) cout << 1;
    else {
        printBinary(a/2);
        cout << a%2;    
    }
}
 
int main(){
    cin >> n;
    printBinary(n);
    return 0;
        
}