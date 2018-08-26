#include <iostream>
#include <algorithm>
using namespace std;
 
int n;
int d[88];
 
void dfs(int cnt) {
    for (int i = 1; i <= cnt / 2; i++) {
        if (equal(d + cnt - i, d + cnt, d + cnt - i * 2)) return;
    }
 
    if (cnt == n) {
        for (int i = 0; i < n; i++) cout << d[i];
        exit(0);
    }
 
    for (int i = 1; i <= 3; i++) {
        d[cnt] = i;
        dfs(cnt + 1);
    }
}
 
int main() {
 
    cin >> n;
    dfs(0);
    return 0;
}