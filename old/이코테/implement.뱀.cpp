#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
뱀문제 
맵에 군데군데 사과가 놓여있고 
사과를 먹으면, 그칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
사과를 먹지 않으면 몸길이를 줄여서 꼬리가 위치한 칸을 비워줍니다.
  몸길이는 변하지 않는다. 



*/
int n, k , l;
int arr[101][101];
vector<pair<int, char> > info;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int turn(int direction, char c){
	if( c == 'L') direction = (direction==0)? 3 : direction -1;
	else direction = (direction + 1) %4;
	return direction;
}

int simulation(){
	int x = 1, y = 1;
	arr[x][y] = 2; // 뱀이 시작하는 위치를 2로 표시
	int direction = 0 ;
	int time = 0; 
	int index = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	

	while(true){
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if(nx >= 1 && ny >=1 && nx <= n && ny <= n && arr[nx][ny]!=2){
			if(arr[nx][ny] == 0){
				arr[nx][ny] = 2;// 방문함을 표시함
				q.push(make_pair(nx,ny));
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0; // 꼬리를 또 방문할수있도록 하는것이다. 
				
			}

			if( arr[nx][ny] == 1){
				arr[nx][ny] = 2; 
				q.push(make_pair(nx,ny));
			}
		} else {
			time+=1;
			break;

		}

		x = nx;
		y = ny;
		time +=1;
		if(index < l && time == info[index].first) {
			direction = turn(direction, info[index].second);
			index +=1;
		}
	}
	return time;
}
int main(){
	cin >> n >> k ;
	for(int i = 0; i<k; i++){
		int a, b;
		cin >> a>> b;
		arr[a][b] = 1;
	}

	cin >> l;
	for(int i = 0; i<l; i++){
		int x;
		char c;
		cin >> x >> c;
		info.push_back(make_pair(x,c));
	}
	cout << simulation() << '\n';
}