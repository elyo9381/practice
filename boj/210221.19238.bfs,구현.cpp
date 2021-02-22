#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

typedef struct
{
	int y, x;
	int gas;
}State;

bool operator <(State a, State b)
{
	if (a.gas < b.gas)
	{
		return true;
	}

	if (a.gas == b.gas)
	{
		if (a.y > b.y)
		{
			return true;
		}

		if (a.y == b.y)
		{
			if (a.x > b.x)
			{
				return true;
			}
		}
	}

	return false;
}

int N, M, gas;
int road[MAX][MAX];
map<pair<int, int>, pair<int, int>> start2Destination;

bool func(pair<int, int> start)
{
	pair<int, int> destination = start2Destination[start];

	queue<pair<State, int>> q;
	q.push({ { start.first, start.second, gas }, 0 });

	bool visited[MAX][MAX] = { false, };
	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		int y = q.front().first.y;
		int x = q.front().first.x;
		int curGas = q.front().first.gas;
		int cnt = q.front().second;
		q.pop();

		if (curGas == -1)
		{
			return false;
		}

		if (y == destination.first && x == destination.second)
		{
			gas = curGas + cnt * 2;

			return true;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (visited[nextY][nextX] || road[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;

			q.push({ { nextY, nextX, curGas - 1 }, cnt + 1 });
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> gas;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> road[i][j];
		}
	}

	pair<int, int> start;
	cin >> start.first >> start.second;
	start.first--, start.second--;

	for (int i = 0; i < M; i++)
	{
		int y, x, y2, x2;
		cin >> y >> x >> y2 >> x2;

		start2Destination[{y - 1, x - 1}] = { y2 - 1,x2 - 1 };
	}

	while (1)
	{
		priority_queue<State> pq;
		pq.push({ start.first, start.second, gas });

		bool visited[MAX][MAX] = { false, };
		visited[start.first][start.second] = true;

		bool flag = false;

		while (!pq.empty())
		{
			int y = pq.top().y;
			int x = pq.top().x;
			int curGas = pq.top().gas;
			pq.pop();

			if (curGas == -1)
			{
				break;
			}

			if (start2Destination.count({ y, x })
				&& start2Destination[{y, x}].first != -1)
			{
				start = { y, x };
				flag = true;
				gas = curGas;

				break;
			}

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				{
					continue;
				}

				if (visited[nextY][nextX] || road[nextY][nextX])
				{
					continue;
				}

				visited[nextY][nextX] = true;

				pq.push({ nextY, nextX, curGas - 1 });
			}
		}

		if (flag == false)
		{
			cout << -1 << "\n";

			return 0;
		}

		if (func(start) == false)
		{
			cout << -1 << "\n";

			return 0;
		}

		if (--M == 0)
		{
			cout << gas << "\n";

			return 0;
		}
		pair<int, int> temp = start;
		start = start2Destination[{start.first, start.second}];
		start2Destination[{temp.first, temp.second}] = { -1, -1 };
	}

	return 0;
}


// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <queue>

// using namespace std;
// #define INF 987654321
// #define hash 1000000007LL
// typedef long long ll;
// typedef pair<int,int> pii;
// const int MAX = 21;

// /**
//  * 승객을 도착지점까지 이동하는것은 bfs를 2번 사용하는것
//  * 이동후 연료 2배는 결국 오고 가고 한 연료를 채우는 행위이다. 
//  * 그러므로 2배에 얽매이지 않고 배달시에 왔던 거리많큼 더해주면 된다. 
//  */
  
// // 고객의 출발과 목적지 정보를 담는 구조체
// struct CUSTOMER
// {
//     pii start;
//     pii end;
// };

// // 택시 좌표와 거리를 담고 우선순위 체크 하는 구조체
// struct TAXI {
//     int y;
//     int x;
//     int dis;

//     bool operator<(const TAXI &b) const{
//         if(dis != b.dis) return dis > b.dis ; // 내림차순 최소힙
//         if(y != b.y) return y > b.y;
//         else return x> b.x;
//     }

// };

// // 고객의 순번이 0부터 시작하므로 벽과 빈곳을 음수로 설정
// const int WALL = -1;
// const int EMPTY = -2;

// // 상하좌우 탐색을 위한 좌표 
// const int dy[4] = {-1,0,1,0}; 
// const int dx[4] = {0,-1,0,1};

// // 매번 공유 되는 택시좌료를 표현하기 위한 변수
// int taxi_y,taxi_x;
// int n, m, fuel;
// int board[MAX][MAX];

// // 여러 고객의 정보를 담기위한 배열
// CUSTOMER customer[400];

// // 고객을 찾는 최단거리 bfs
// int find_customer(){

//     // bfs의 여러조건을 위한 우선순위 큐 사용
//     priority_queue<TAXI> pq;
//     bool visited[MAX][MAX] = {false,};

//     TAXI cur = {taxi_y,taxi_x,0};
//     visited[taxi_y][taxi_x] = true;

//     pq.push(cur);

//     int useFuel = -1;
//     int ret = -1;

//     //기본적인 bfs
//     while(!pq.empty()){
        
//         cur = pq.top();
//         pq.pop();

//         int y = cur.y;
//         int x = cur.x;
//         int dis = cur.dis;

//         // 고객을 찾았을시 loop 중지
//         if(board[y][x] >= 0){
//             ret = board[y][x];
//             useFuel = cur.dis;
//             break;
//         }
      
//         for(int d = 0; d<4; d++){
//             int ny = y + dy[d];
//             int nx = x + dx[d];

//             if(nx < 0 || ny < 0 || nx >= n || ny >= n 
//                 || board[ny][nx] == WALL || visited[ny][nx] == true) {
//                     continue;
//             }
//             visited[ny][nx] = true;
//             TAXI next = {ny , nx, dis+1 };
//             pq.push(next);
            
//         }


//     }

//     // 주어진 연료보다 많은 연료사용시 종료
//     if(useFuel > fuel) {
//         return -1;
//     }

//     // 찾은 고객의 위치에 택시 위치 
//     taxi_y = customer[ret].start.first;
//     taxi_x = customer[ret].start.second;
//     board[taxi_y][taxi_x] = EMPTY;
//     // 사용 연료 계산
//     fuel -= useFuel;

//     return ret;
// }


// // 고객을 목적지로 옮기는 bfs
// bool move_customer(int target){
//     queue<TAXI> q;
//     bool visited[20][20] = {false,};
//     TAXI cur = {taxi_y,taxi_x,0};
//     visited[taxi_y][taxi_x] = true;
//     q.push(cur);

//     while(!q.empty()){
//         cur = q.front();
//         q.pop();

//         // 이동중에 연료가 바닥나면 실패( 종료 )
//         if(cur.dis > fuel){
//             return false;
//         }

//         // 목적지에 도착시 종료 연료 반환을 위한 연료 계산
//         if(cur.y == customer[target].end.first 
//             && cur.x == customer[target].end.second){
//             taxi_y = customer[target].end.first;
//             taxi_x = customer[target].end.second;
//             fuel += cur.dis;
//             return true;

//         }

//         int y = cur.y;
//         int x = cur.x;
//         for(int d = 0; d < 4; d++){
//             int ny = y + dy[d];
//             int nx = x + dx[d];
//             if(nx < 0 || ny < 0 || nx >=n || ny >=n 
//                 || board[ny][nx] == WALL || visited[ny][nx] == true ){
//                     continue;
//                 }

//             TAXI next = {ny,nx,cur.dis +1};
//             q.push(next);
//             visited[ny][nx] = true;
//         }
//     }

//     return false;
// }

// // 고객 to 목적지
// // 목적지 to 고객  을 위한 함수 사용
// int solve(){

//     int ret = -1;
//     for(int i = 0; i<m; i++){
//         int target = find_customer();
//         if(target == -1){
//             return ret;
//         }
//         bool success = move_customer(target);
//         if(success == false){
//             return ret;
//         }
//     }

//     ret = fuel;
//     return ret;
// }


// int main(){

//     // WALL,EMPTY 설정을 위한 음수설정 입력및
//     // 인덱스 조절

//     cin >>  n >> m >> fuel;

//     for(int i = 0; i < n ; i++){
//         for(int j = 0; j < n ; j++){
//             cin >>  board[i][j];
//             board[i][j] -= 2;
//         }
//     }


//     cin >> taxi_y >> taxi_x ;
//     --taxi_x, --taxi_y;

//     for(int i = 0; i< m; i++){
//         int sx,sy,ex,ey;
//         cin >>  sy >> sx >> ey >> ex;
//         --sx, --sy, --ex, --ey;
//         customer[i].start.first = sy;
//         customer[i].start.second = sx;

//         customer[i].end.first = ey;
//         customer[i].end.second = ex;

//         board[sy][sx] = i;

//     }

//     int ret = solve();
//     cout << ret <<"\n";

//     return 0;
// }

