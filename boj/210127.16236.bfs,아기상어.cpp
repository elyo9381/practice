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
const int MAX = 25;


int board[MAX][MAX];
int ch[MAX][MAX];
int n,res;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct state{
	int x,y, dis;
	state(int a, int b, int c){
		x =a, y = b, dis =c;
	}
	bool operator<(const state &b) const {
		if(dis != b.dis) return dis > b.dis;
		if(x != b.x) return x > b.x;
		else return y > b.y;
	}
};

struct shark{
	int x, y,s,ate;
	void sizeUp(){
		ate = 0;
		s++;
	}
};

priority_queue<state> q;
shark baby;

void bfs(int a, int b,int c){ // baby.x , baby.y, dis

	q.push(state(a,b,c));
	baby.s = 2;
	baby.ate = 0;

	while(!q.empty()){
		state tmp = q.top();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;

		if( board[x][y] != 0 && board[x][y] < baby.s){
			baby.x = x;
			baby.y = y;
			baby.ate++;
			if(baby.ate >= baby.s) baby.sizeUp();
			board[x][y] = 0;
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					ch[i][j] = 0;
				}
			}
			while(!q.empty()) q.pop();
			res = tmp.dis;
		}

		for(int i = 0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];

			if(nx < 0 || ny < 0 || nx >=n || ny >=n || 
				board[nx][ny] > baby.s || ch[nx][ny]) continue;
			
			q.push(state(nx,ny,z+1));
			ch[nx][ny] =1;
		}
	}

}
int main(){

	cin >> n;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> board[i][j];
			if(board[i][j] == 9) {
				baby.x = i;
				baby.y = j;
				board[i][j] = 0;
			}
		}
	}

	bfs(baby.x,baby.y,0);

	cout << res <<"\n";
}