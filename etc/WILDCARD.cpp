#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int cache[100][100];
int n;
vector<string> v;

string wildcard;
string filename;

//version last
/*
bool check(int w, int f){
	int &ret = cache[w][f];
	if(ret != -1) return ret;
	if(w < wildcard.size() && f < filename.size() 
		&& (wildcard[w] == '?' || wildcard[w] == filename[f])) return ret = check(w+1, f+1);
	if(W[w] == '*') {
		if(check(w+1,s) || (s < S.size() && check(w,f+1))) return ret = 1;
	}	
}
*/

//완전탐색
bool check(const string& wildcard, const string& filename){
	int pos = 0;
	while(pos < filename.size() && pos < wildcard.size()
		&& (wildcard[pos] == '?' || wildcard[pos] == filename[pos])) pos++;
	if(pos == w.size()) return pos == s.size();

}

int main(){
	int testcase;
	cin >> testcase;
	for(int t = 0; t < testcase; t++){
		cin >> wildcard;
		cin >> n;
		for(int i = 0; i < n; i++){
			memset(cache, -1, sizeof(cache));
			cin >> filename;
//			if(check(0,0) == 1) v.push_back(filename);
			if(check(wildcard,filename) == 1) v.push_back(filename);
		}
	}

	return 0;
}

