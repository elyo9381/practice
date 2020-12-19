#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
왕실 나이트 문제
입력 a1, 1a 등등
출력 2 
체스판의 나이트가 갈수있는 경우의수 구하기 입력의 a는 1을뜻함
*/

string inputData;
int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};


int check(int x, int y){
	int cnt = 0;
	for(int i = 0; i<8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx > 8 || nx < 1 || ny > 8 || ny < 1) continue;
		cnt++;
	}

	// cout << cnt <<"\n";
	return cnt;
}

int main(){
	
	cin >> inputData;
	int x = 0, y= 0 , cnt = 0;
	for(int i = 0; inputData[i]!='\0'; i++){
		if(inputData[i] >= 97 && inputData[i] <=122){
			x = inputData[i] - 96;
		}
		else if( inputData[i] > 48 && inputData[i] <=57){
			y = inputData[i] - 48;
		}
	}
	// cout << x << y;

	cnt = check(x,y);
	cout << cnt << "\n";

	return 0;
}