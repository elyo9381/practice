#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,l,r, totalCnt = 0;
int map[51][51];
int ch[51][51];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void bfs(int x, int y, int idx){
	vector<pair<int, int> > united;
	united.push_back(make_pair(x,y));

	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	ch[x][y] = idx;
	int summary = map[x][y];
	int cnt = 1;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if( nx >= 0 && ny >=0 && nx < n && ny < n && ch[nx][ny] == -1){
				int gap = abs(map[nx][ny] - map[x][y]);
				if(l <= gap && gap <=r){
					q.push(make_pair(nx,ny));
					ch[nx][ny] = idx;
					summary += map[nx][ny];
					cnt+=1;
					united.push_back(make_pair(nx,ny));
				}
			}
		}
	}

	for(int i = 0; i< united.size(); i++){
		int x = united[i].first;
		int y = united[i].second;
		map[x][y] = summary/cnt;
	}
	return ;
}


int main(){
	cin >> n >> l >> r;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> map[i][j];
		}
	}

	while(true){
		// 2차원 배열 초기화
		// for(int i=0; i<rows; i++)
		// 	memset(arr[i], 초기화하고자 하는 값, sizeof(int)* colums);
		
		for(int i = 0;i<n;i++)
			memset(ch[i],-1,sizeof(int)*n);

		int idx = 0;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n ;j++){
				if(ch[i][j] == -1){
					bfs(i,j,idx);
					idx +=1;
				}
			}
		}

		if(idx == n*n) break;
		totalCnt +=1;
	}

	cout << totalCnt;
}


