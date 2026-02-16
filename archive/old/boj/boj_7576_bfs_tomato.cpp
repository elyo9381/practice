#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second 

#define endl "\n"
#define MX 1000

int board[MX][MX];
bool vis[MX][MX];


int N,M,H,Answer;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<pair<int,int>,int>> Q;
// queue<pair<int,int>> Q; // bfs leveling skill 2
void Initialize()
{
    memset(board, 0, sizeof(board));
    memset(vis, false, sizeof(vis));
    Answer = 0;
}

void Input(){
    cin >> M >> N >> H;

    for(int i=0; i<N; i++){
        for(int j =0; j<M ; j++){
            cin >> board[i][j];
            if(board[i][j] ==1)
            {
                vis[i][j] =1;
                Q.push({{i,j},0});
            }
        }
    }
}

bool Check_Tomato_State(){
    for(int i=0; i<N ; i++){
        for(int j =0; j<M; j++){
            if(board[i][j] == 0) return false;
        }
    }

    return true;
}

void BFS(){
    int t;

    while(!Q.empty()){
    int x = Q.front().first.first;
    int y = Q.front().first.second;
    t= Q.front().second;
    Q.pop();

    for(int dir=0 ; dir<4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx >= 0 && ny >=0 && nx<N && ny<M){
            if(!vis[nx][ny] && board[nx][ny] == 0){

                vis[nx][ny] == true;
                board[nx][ny] = 1;
                Q.push({{nx,ny},t+1});

            }
        }
    }


    }

    if(Check_Tomato_State== false) cout<< -1<< endl;
    else cout<< t<< endl;
}
// void BFS(){ // bfs leveling skill 2 with pair 하나만 사용 

//     int day = 0;

//     while(!Q.empty()){

//         int Qs = Q.size();
//         for(int q = 0; q< Qs; q++){

//             int x = Q.front().X;
//             int y = Q.front().Y;
//             Q.pop();

//             for(int i =0; i< 4; i++){

//                 int nx = x +dx[i];
//                 int ny = y +dy[i];

//                 if( nx >= 0&& ny >= 0 && nx<N && ny<M){
//                     if(!vis[nx][ny] && board[nx][ny] ==0){
//                         board[nx][ny] = 1;
//                         vis[nx][ny] = true;
//                         Q.push({nx,ny});
//                     }
//                 }
//             }
//         }
//         day++;
//     }
//     if(Check_Tomato_State== false) cout<< -1<< endl;
//     else cout<< day -1 << endl;
// }


void Solution(){
    BFS();
}


void Solve(){
    Input();
    Solution();
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Solve();
}