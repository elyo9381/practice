#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; 
int map[1000][1000],ch[1000][1000];

queue<pair<int,int> > q;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs(int a, int b){
	q.push(make_pair(a,b));
	ch[a][b] = 1;
	while(!q.empty()){
		int x =  q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || ny < 0|| nx >= n || ny >= m) continue;
			if(map[nx][ny] != 0 && ch[nx][ny] == 0 ){
				ch[nx][ny] = ch[x][y] +1 ;
				q.push(make_pair(nx,ny));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i<n ; i++){
		for(int j= 0 ; j<m; j++){
			cin >> map[i][j];
		}
	}
    // map에 0,0부터 넣어서 1,1아닌 0,0에서 출발
	bfs(0,0);

	cout << ch[n-1][m-1] <<'\n';

}