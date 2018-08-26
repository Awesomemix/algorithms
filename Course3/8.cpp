#include <iostream>
#include <algorithm>
using namespace std;
int main(){
 
    long long int n, m;
    cin >> n >> m;
 
    long long int a = 0, b = 0;
    long long int nm = n - m;
 
 
    for (int i = 2; i <= n; i *= 2)
    {
        a += n / i;
    }
 
    for (int i = 5; i <= n; i *= 5)
    {
        b += n / i;
    }
 
    for (int i = 2; i <= nm; i *= 2)
    {
        a -= nm / i;
    }
 
    for (int i = 5; i <= nm; i *= 5)
    {
        b -= nm / i;
    }
 
 
    for (int i = 2; i <= m; i *= 2)
    {
        a -= m / i;
    }
 
    for (int i = 5; i <= m; i *= 5)
    {
        b -= m / i;
    }
 
    cout << min(a,b) << endl;
 
}