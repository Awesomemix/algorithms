#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
 
int main() {
 
    bool flag = true;
    int num = 0;
 
    while (true) {
        cin >> a[num] >> b[num] >> c[num];
        if (a[num] == 0 && b[num] == 0 && c[num] == 0){ break; }
        num++;
 
    }
 
    for (int i = 0; i < num; i++) {
        string XX = "";
        int V = 0;
 
        if ((c[i] - a[i]) / 2 == (c[i] - b[i])) {
            XX = "AP";
            V = c[i] + (c[i] - b[i]);
        }
        else {
            XX = "GP";
            V = a[i] * pow((b[i] / a[i]), 3);
        }
        cout << XX << " " << V << endl;
    }
    system("pause");
    return 0;
}