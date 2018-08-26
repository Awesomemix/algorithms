#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int n,cnt,mx[15],mi[15];
vector<char> op;
 
void sol(int cur,int arr[])
{
  if (cur == 0)
    return;
  if (op[cur-1] == '>' && arr[cur - 1] > arr[cur])
    return;
  if (op[cur-1] == '<' && arr[cur - 1] < arr[cur])
    return;
  swap(arr[cur - 1], arr[cur]);
  sol(cur - 1, arr);
}
 
int main()
{
  cin >> n;
  while (cnt!=n)
  {
    char tmp;
    cin >> tmp;
    if (tmp == '<' || tmp == '>')
    {
      cnt++;
      op.push_back(tmp);
    }
  }
 
  mx[0]=9;
  mi[0]=0;
 
  for (int i = 1; i <= n; i++)
  {
    mx[i] = 9 - i;
    sol(i,mx);
    mi[i] = i;
    sol(i,mi);
  }
 
  for (int i = 0; i < n+1; i++)
    cout << mx[i];
  cout << endl;
  for (int i = 0; i < n+1; i++)
    cout << mi[i];
  return 0;
 
}