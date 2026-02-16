#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
쉬운 문제였다. 
주의할점은 bfs돌리면서 제시한 time안에 종료 할수있어야하는점이다. 
이를 위해서 time변수를 배열의 원소로 지정해야한다.
구조체 혹은 클래스가 싫다면 4페어를 사용하자 

*/
int map[201][201];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int n, k, s,x,y;

struct Virus{
	int idx,time,x,y;
	Virus(int a, int b , int c, int d){
		idx = a;
		time = b;
		x = c;
		y = d;
	}

	bool operator<(const Virus &b)const{
		return idx < b.idx;
	}
};

vector<Virus> v;
queue<Virus> q;

void bfs(){
	
	while(!q.empty()){
	Virus virus = q.front();
	q.pop();

	if(virus.time == s) break;

	for(int i = 0; i<4; i++){
			int nx = virus.x+dx[i];
			int ny = virus.y+dy[i];

			if(nx < 1 || ny < 1 ||nx >n ||ny > n) continue;
			if(map[nx][ny] == 0 ){
				map[nx][ny] = virus.idx;
				q.push(Virus(virus.idx,virus.time+1,nx,ny));
			}
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> map[i][j];
			if(map[i][j] != 0){
				v.push_back(Virus(map[i][j],0,i,j));
			}
		}
	}
	cin >> s >> x >> y;

	sort(v.begin(),v.end());
	
	for(int i = 0; i<v.size(); i++){
		q.push(Virus(v[i].idx,v[i].time,v[i].x,v[i].y));
	}
	bfs();

	cout << map[x][y] <<'\n';

}