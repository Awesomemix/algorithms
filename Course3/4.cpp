#include <iostream>
#include <algorithm>
using namespace std;
int f[100];
 
int fibo(int n)
{
  int f0, f1, fi;
 
  // 초기값 설정
  f0 = 0;
  f1 = 1;
 
  // 예외처리
  if (n == 0) return 0;
  else if (n == 1) return 1;
 
  else
  {
    for (int i = 2; i <= n; i++)
    {
      fi = f0 + f1;
      f0 = f1;
      f1 = fi;
    }
  }
  return fi;
}
 
 
int main(){
    int a;
    cin >> a;
    cout << fibo(a) << endl;
 
    return 0;
 
}