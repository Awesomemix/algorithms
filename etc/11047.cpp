#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m = 0;
    while(k > 0){
    for (int i = n-1; i >= 0; i--) {
            if(a[i]<=k){
		        	k-=a[i]; m++; break;
	   	    }  
        }
    }
    cout << m;
    return 0;
}
