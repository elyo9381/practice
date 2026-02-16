#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1000001;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n,k,l;
int arr[101][101];
vector<pair<int, char> > info;

int turn (int direction, char c){
	if(c == 'L') direction = (direction == 0) ? 3 : direction -1;
	else direction = (direction + 1 ) % 4;
	return direction;
}

int simul(){
	int x = 1, y = 1;
	arr[x][y] = 2;
	int direction = 0;
	int time = 0;
	int index = 0;
	queue<pii> q;
	q.push(make_pair(x,y));

	while(!q.empty()){
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		
		if( 1 <=nx && nx <= n && 1 <=ny && ny <= n  && arr[nx][ny] !=2){

		if(arr[nx][ny] == 0){
			arr[nx][ny] = 2;
			q.push(make_pair(nx,ny));
			int px = q.front().first;
			int py = q.front().second;
			q.pop();
			arr[px][py] = 0;
		}

		if(arr[nx][ny] ==1){
			arr[nx][ny] = 2;
			q.push(make_pair(nx,ny));
		}
		} else {
			time +=1;
			break;
		}

		x = nx;
		y = ny;
		time+=1;
		if(index < l && time == info[index].first){
			direction = turn(direction, info[index].second);
			index += 1;
		}
	}
	return time;
}

int main(){

	cin >> n >> k;
	for(int i = 0 ;i<k; i++){
		int a ,b;
		cin >>  a >> b;
		arr[a][b] = 1;
	}

	cin >> l ;
	for(int i = 0; i<l; i++){
		int a; char b;
		cin >> a >> b;
		info.push_back(make_pair(a,b));
	}

	cout << simul() << '\n';
}