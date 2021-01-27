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

/*
	board에 하나만 올리고 그 최대값을 찾는 문제이다.
	dfs를 이용한 백트래킹 문제이다. 
	
*/

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

const int MAX = 500;

int board[MAX][MAX];
bool v[MAX][MAX];

int ex[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int ey[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};


int n, m,ret = 0;

void dfs(int x,int y, int sum, int L){

	if( L >= 4){
		ret = max(ret,sum);
		return ;
	}

	for(int i = 0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if( nx <0 || ny < 0 || nx >=n || ny >= m) continue;
		if(!v[nx][ny]){
			v[nx][ny] = true;
			dfs(nx,ny,sum+board[nx][ny], L+1);
			v[nx][ny] = false;
		}
	}
}

void check_exshape(int x, int y){
	for(int i = 0; i<4; i++){
		bool isOut = false;
		int sum_val = 0;

		for(int j = 0; j<4; j++){
			int nx = x + ex[i][j];
			int ny = y + ey[i][j];

			if( nx <0 || ny < 0 || nx >=n || ny >= m){
				isOut = true;
				break;
			} else {
				sum_val += board[nx][ny];
			}
		}

		if(!isOut) ret = max(ret,sum_val);
	}
}
 
int main(){

	cin >> n >> m;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >>  board[i][j];
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			v[i][j] = true;
			dfs(i,j,board[i][j],1);
			v[i][j] = false;

			check_exshape(i,j);
		}
	}

	cout << ret << '\n';


}