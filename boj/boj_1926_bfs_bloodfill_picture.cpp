#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second 

// 보드 생성및 방문체크 vis다차원 배열
int board[502][502];
bool vis[502][502];

// 입력받을 n,m
int n,m;


// 상하좌우를 가르킬 좌표 배열들//
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m ;


    // 보드를 입력받는 방법
    // 배열에 하나식 입력받는다. 
    // 계산 하기 편하기 위해서 인트형을 받는다. 
    for(int i =0; i<n; i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    int mx = 0;
    int num = 0;


    // 맵을 순회 하면서 블러드플을 확인해야한다.
    // 위의 조건을 구현하기 위해서 이중포문을 수행
    for(int i=0 ;i<n;i++){
        for(int j=0; j<m;j++){
            // 맵에서 그림이 아닐경우와
            // 그림을 방문한경우 계산을 수행하지 않음 (넘어감)
            if(board[i][j] == 0 or vis[i][j]) continue;

            queue<pair<int,int> >Q;
            // 순차적으로 그림에 방문했다는 가정
            vis[i][j] = 1;
            num++;
            Q.push({i,j}); //방문한 그림의 bfs를 수행

            // 그림의 사이즈를 체크하기 위한 area
            int area = 0;

            while(!Q.empty()){
                // bfs시작으로 부터 주변에 방문할곳이 있으면
                // 순차적으로 방문 하고 area 증가 시켜야한다.
                // 큐에 뭔가 들어갔다는것은 주변에 방문 할곳이 있다는 소리 

                area++;
                // 맵에서 방문한 곳의 좌표를 알기위해서 
                // pair를 통해 좌표구현
                // stl을 사용하지 못한다면
                // 구조체나 배열을 통해서 구현해야한다.

                pair<int,int> cur = Q.front(); 
                Q.pop();

                // 상하좌우를 검색함
                for(int dir = 0; dir <4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                // 범위 밖으로 갔을때의 예외 처리 
                if(nx < 0 or nx >= n or ny <0 or ny >= m) continue;
                
                // 방문했고 맵에서 1이 아니면(0이면) 계산하지않고 
                // 넘어감 -즉 0이면 방문 할필요도 없고 그림이 아니란 소리다-
                if(vis[nx][ny] or board[nx][ny] != 1)continue;
                vis[nx][ny] = 1;

                // 탐색한곳의 주변에 방문할곳이 있으면 큐에 넣음
                Q.push({nx,ny});

                }
            }
        // 그림의 area를 매번 측정해야하므로 
        // mx변수르 두어서 가장 큰 맵의 수치만 확보 
        mx = max(mx, area);
        }
    }
    cout<< num << '\n' << mx;
}