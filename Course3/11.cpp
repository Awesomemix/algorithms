#include <iostream>
#include <algorithm>
using namespace std;
long long int bm,c_bz,bz1,bz2,n,m,l,o,gc;
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
 
    cin >> n >> m >> l >> o;
    bm = lcm(m,o);
    
    bz1 = (bm/m) * n;
    bz2 = (bm/o) * l;
    
    c_bz = bz1 + bz2;
 
    gc = gcd(c_bz,bm);
    cout << c_bz / gc << " " << bm / gc << endl;
 
    return 0;
}