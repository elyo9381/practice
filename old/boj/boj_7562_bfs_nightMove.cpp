#include <bits/stdc++.h>

#define endl "\n"
#define MX 300
using namespace std;

/*
    4방향이 아닌 8방향으로 설정해준다. 
    그리고 출발지점과 도착지점에서 
    몇번 왔는지를 출력해주면 되는데 
    pair를 통해서 파라미터를 3개 받아도 되고 
    2개를 받은후 그값을 true가 아닌 
    1식 더해주어서 총값이 몇인지 출력하면 
    해를 얻을수있다. 
    
*/

int T,N;
bool visit[MX][MX];

int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {1,-1,-2,-2,-1,1,2,2};

pair<int, int> Start, End;

void Init()
{
    memset(visit, false, sizeof(visit));
}

void Input(){

    cin >> N;
    cin>> Start.first >> Start.second;
    cin>>  End.first >> End.second;
}

void BFS(int a, int b)
{   
    queue<pair<pair<int,int>, int >> Q;
    Q.push(make_pair(make_pair(a,b),0));
    visit[a][b] = true;

    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int cnt = Q.front().second;
        Q.pop();

        if(x == End.first && y == End.second){
            cout<< cnt<< endl; return ;
        }

        for(int i = 0; i<8 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if(!visit[nx][ny])
                {
                    visit[nx][ny] = true;
                    Q.push({{nx,ny},cnt+1});
                }
            }
        }
    }
}

void Solution(){

    BFS(Start.first, Start.second);
}

void solve(){
    
    cin >> T;
    for(int i = 0 ; i< T ; i++){

    Init();
    Input();
    Solution();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    solve();
}


// /////////////////////////////////////////////////////
// #ifdef _DEBUG
// #include "bits_stdc++.h"
// #else
// #include "bits/stdc++.h"
// #endif
// using namespace std;
// typedef pair<int, int> pii;
// typedef vector<vector<pii > > Edge;
// typedef unsigned long long llu;
// typedef long long ll;
// typedef priority_queue<pii > Pq;
// typedef vector<int>::iterator It;
// #define INF 0x3f3f3f3f
// #define UINF 0xffffffffu
// #define LINF 0x3f3f3f3f3f3f3f3fll
// #define MOD 1000000007
// #define EOD 1e-9
// #define all(x) x.begin(),x.end()
// const double PI = acos(0.0)*2.0;
// /////////////////////////////////////////////////////
// int N;
// int trip[300][300];
// int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
// int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
// bool safe(int x, int y) {
//     return x >= 0 && y >= 0 && x < N&&y < N;
// }
// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         memset(trip, -1, sizeof(trip));
//         int sx, sy, fx, fy;
//         scanf("%d%d%d%d%d", &N, &sx, &sy, &fx, &fy);
//         queue<pii> q;
//         q.push({ sx,sy });
//         trip[sx][sy] = 0;
//         int ans;
//         while (!q.empty()) {
//             int nx = q.front().first;
//             int ny = q.front().second;
//             q.pop();
//             if (nx == fx&&ny == fy) {
//                 ans = trip[nx][ny];
//                 break;
//             }
//             for (int i = 0; i < 8; i++) {
//                 int tx = nx + dx[i];
//                 int ty = ny + dy[i];
//                 if (safe(tx, ty) && trip[tx][ty] == -1) {
//                     trip[tx][ty] = trip[nx][ny] + 1;
//                     q.push({ tx,ty });
//                 }
//             }
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }