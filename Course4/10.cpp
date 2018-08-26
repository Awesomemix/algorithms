#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
bool board[101][101];
bool visited[101];
 
int main(){
    int n , m;
    cin >> n >> m;
 
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        board[a][b] = board[b][a] = true;
    }
    
    queue<int> q;
    q.push(1);    
    int cnt = 0;
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++){
            if(!visited[i] && board[a][i] && board[i][a]){
                visited[i] = true;
                if(i!=1){
                    cnt++;      
                }
                q.push(i);
            } 
        }
    }
    
    cout << cnt << endl;
    system("pause");
    return 0;
    
}