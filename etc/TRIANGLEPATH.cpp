/*#include <iostream>
#include <cstring>
#include <algorithm>
using namespade std;

int n;
int triangle[100][100];
int cache[100][100];

int path(int y, int x){  // x,y에서 시작해서 얻을 수 있는 부분 최대합
	if(y == n-1) return triangle[y][x]; //마지막이라면 값을 return
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	return ret = max(path(y+1,x), path(y+1,x+1)) + triangle[y][x];
}

int main(){

	int t;
	cin >> t;

	for(int testcase = 0; testcase < t; testcase++){
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i+1 ; j++){
				cin >> triangle[i][j];
			}
		}
		cout << path(0,0) << endl << endl;
	}
	return 0;
}*/


/*

삼각형으로 배치된 자연수들이 있다.(정사각을 왼쪽 위에서 오른쪽 아래 대각선 기준으로 잘랐을 때 아래 부분)

맨 위의 숫자에서 시작해서, 한번에 한 칸씩 아래로 내려가

맨 아래 줄까지 닿는 경로를 만들려고 한다.

경로는 아래줄로 내려갈 때마다 바로 아래 숫자 혹은 오른쪽 아래 숫자로 내려갈 수 있다.

이 때 모든 경로 중 숫자의 합을 최대화하는 경로는?

또한 경로에 포함된 숫자들의 최대 합은 얼마인가

*/

#include <iostream>

#include <cstring> //memset

#include <algorithm>

using namespace std;

 

int height;

int triangle[100][100]; 

int cache[100][100];

 
int path(int y, int x)

{


        if (y == height - 1)

               return triangle[y][x];



        int &result = cache[y][x];

        if (result != -1)

               return result;

        return result = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x]; 

}

 

int main(void)

{

        int test_case;

        cin >> test_case;

        if (test_case < 0 || test_case>50)

               exit(-1);

       

        for (int i = 0; i < test_case; i++)

        {

               memset(cache, -1, sizeof(cache)); 

               cin >> height;

               if (height < 2 || height > 100)

                       exit(-1);

               for (int i = 0; i < height; i++)

                       for (int j = 0; j < i + 1; j++)

                       {

                              cin >> triangle[i][j];

                              if (triangle[i][j] < 1 || triangle[i][j]>100000)

                                      exit(-1);

                       }

               cout << path(0, 0) << endl << endl;

        }

        return 0;

}