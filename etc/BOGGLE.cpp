#include <iostream>
#include <string.h>
using namespace std;

bool areFriend[10][10];
int n;


int countFriends(bool taken[]){ //방법의 수 카운트하는 함수

	//같은 답을 중복으로 세는 경우를 방지하기 위해 사전순 먼저 오는 답 하나만 카운트
	int firstFree = -1; //남은 학생 중 번호가 가장 빠른 학생
	for(int i = 0; i < n; i++){
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}

	//모든 학생이 짝을 찾았으면 한가지 방법 찾았으니 종료
	if(firstFree == -1) return 1;

	//재귀호출 시작
	int ret = 0;

	//해당 학생과 짝지을 학생 결정
	//firstFree + 1 : 짝지을 학생은 자기 자신이면 안되니까
	for(int pairWith = firstFree + 1; pairWith < n; pairWith++){
		if(!taken[pairWith] && areFriend[firstFree][pairWith]){
			taken[firstFree] = taken[pairWith] = true;
			ret += countFriends(taken); //firstFree, pairWith 제외하고 탐색 진행
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;

}

int main(){
	int testcase, m, one, two;
	cin >> testcase;

	for(int t = 0; t < testcase; t++){
		cin >> n;
		cin >> m;
		// (1,0) (0,2) 와 같이 무작위 배열 받는 방법 
		// 변수 두 개 선언받고 해당 배열 인자로 넣는다
		for(int i = 0; i < m; i++){
			cin >> one >> two;

			//좌우만 바뀐 건 같은 취급한다
			areFriend[one][two] = areFriend[two][one] = true;
		}

		bool taken[10] = {};
		cout << countFriends(taken) << endl;

		areFriend[10][10] = {false, }; 
		for (int i = 0; i < 10; i++) {
			memset(areFriend[i], 0, sizeof(bool) * 10);
		}

	}
}



/*
문제
안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다. 
원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다. 

그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 
않기 때문에, 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.

각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 
학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요. 

짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다. 
예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.

(태연,제시카) (써니,티파니) (효연,유리)
(태연,제시카) (써니,유리) (효연,티파니)

입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 
각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과 
친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다. 
그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 
번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 
학생들의 수는 짝수입니다.

출력
각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어줄 수 있는 방법의 수
*/