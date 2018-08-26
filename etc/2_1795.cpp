/************
< 날짜 >	  : 2018-07-15
< 주소 >      : https://www.acmicpc.net/problem/1759
*************
< 해결방안 >   :
1. 서로 다른 L개의 알파벳 소문자들로 구성되며 
2. 최소 한 개의 모음과 최소 두 개의 자음으로 구성
3. 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열
4. C개의 문자들이 모두 주어졌을 때, 암호들을 모두 구하는 프로그램
*************
< 오답노트 >   :
이전의 수와 관련된 문제를 활용했으나, 해당 문제는 직접 수를 for문으로 조정

*************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(string &password) {
    int ja = 0;
    int mo = 0;
    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        } else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}

//i 개의 n길이만큼의 letter 중 password
void findencrypt(int n, vector<char>& alpha, string password, int i){
	if(n == password.length()){
		if(check(password)){
			cout << password << endl;
		}
		return;
	}
	
	if(i >= alpha.size()) return;
	findencrypt(n,alpha,password+alpha[i],i+1);
	findencrypt(n,alpha,password,i+1);
	
} 


int main(){

	int l,c;
	cin >> l >> c;
	vector<char> a(c);
	for(int i = 0; i < c; i++){
		cin >> a[i];
	}

    sort(a.begin(), a.end());
	findencrypt(l, a, "", 0);

	return 0;
}