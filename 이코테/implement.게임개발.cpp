#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
게임 개발 시뮬 문제
시뮬문제는 주어진 조건에 의해서 구해야하는데 
애매한 조건은 함수를 만들기로 하자 
ex) 무엇을 체크한다든지, 이동한다든지 이런것에 대해서 함수로 만들자 

*/

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int direction, n,m,x,y;
int arr[53][53], d[53][53];

void turn_left(){
	direction -= 1;
	if(direction == -1) direction = 3;
}
int main(){

	cin >> n >> m;
	cin >> x >> y >> direction;
	d[x][y] = 1;

	for(int i = 0; i<n ;i++){
		for(int j = 0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	int turn_time = 0;
	while(true){
		turn_left();
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if(arr[nx][ny] == 0 && d[nx][ny] == 0){
			d[nx][ny] = 1;
			x = nx;
			y = ny;
			cnt+=1;
			turn_time = 0;
			continue;
		} else turn_time +=1;
		
		if(turn_time == 4){
			nx = x - dx[direction];
			ny = y - dy[direction];

			if(arr[nx][ny] == 0){
				x= nx;
				y = ny;
			}
			else break;
			turn_time = 0;
		}
	}

	cout << cnt << '\n';
}