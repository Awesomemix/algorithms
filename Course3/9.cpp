#include <iostream>
#include <algorithm>
using namespace std;
 
long long int gcd(long long int a, long long int b)
{
    long long int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
 
long long int lcm(long long int a, long long int b)
{
    return a * b / gcd(a, b);
}
 
int main(){
    long long int n, m;
    cin >> n >> m;
    cout << lcm(n,m) << endl;
 
    return 0;
}