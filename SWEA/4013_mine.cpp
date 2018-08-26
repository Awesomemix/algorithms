#include <iostream>
#include <algorithm>
using namespace std;

const int score_chart[4] = {1,2,4,8};
int k;
int magnet[4][8];
bool check[4];


void turn(int magnet_no, int dir){
	if(dir == 1){ //시계방향
		int temp = magnet[magnet_no][7];
		for(int i = 0; i < 7; i++){
			magnet[magnet_no][i+1] = magnet[magnet_no][i];
		}
		magnet[magnet_no][0] = temp;
	}
	else if(dir == -1){ //시계방향
		int temp = magnet[magnet_no][0];
		for(int i = 0; i < 7; i++){
			magnet[magnet_no][i] = magnet[magnet_no][i+1];
		}
		magnet[magnet_no][7] = temp;
	}

}


void initCheck(){
	for(int i = 0; i < 4; i++){
		check[i] = false;
	}
}


bool dfs(int magnet_no, int dir){ 

	check[magnet_no] = true;

	if(magnet_no < 3 && !check[magnet_no + 1] && magnet[magnet_no][2] != magnet[magnet_no + 1][6]) dfs(magnet_no + 1, -1 * dir);
	
	if(magnet_no > 0 && !check[magnet_no - 1] && magnet[magnet_no][6] != magnet[magnet_no - 1][2]) dfs(magnet_no - 1, -1 * dir);

	turn(magnet_no, dir);
}


int main(){

    int t;
    cin >> t;
    for(int tc = 0; tc < t ; tc++){
		cin >> k;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 8; j++){
				cin >> magnet[i][j];
			}
		}
        
        int score = 0;
		for(int i = 0; i < k; i++){
			int magnet_no, dir;
			cin >> magnet_no >> dir;
			dfs(magnet_no - 1, dir);
			initCheck(); 
		}

	if(magnet[0][0] == 1) score += 1;
	if(magnet[1][0] == 1) score += 2;
	if(magnet[2][0] == 1) score += 4;
	if(magnet[3][0] == 1) score += 8;

	cout << "#" << tc + 1<< " " << score << endl;

    }

	return 0;

}