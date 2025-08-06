#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"
#define MX 100
using namespace std;

int M, N, H, Answer;
int board[MX][MX][MX];
bool vis[MX][MX][MX];
bool Tomato_State; 
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int df[] = { 0, 0, 0, 0, 1, -1 };

queue<pair<pair<int,int>,int>> Q;

void Initialize(){
    memset(board, 0, sizeof(board));
    memset(vis, false, sizeof(vis));
    Answer = 0;
}

void Input(){
    Tomato_State = true;
    cin >> M >> N >> H;
    for(int h = 0; h<H; h++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> board[i][j][h];
                if(board[i][j][h] == 0) Tomato_State = false;
                if(board[i][j][h] == 1) Q.push({{i,j},h});
            }
        }
    }
}

bool Check_Tomato_State()
{
    for(int h = 0; h<H; h++){
        for(int i = 0; i<N ;  i++){
            for(int j= 0; j<M; j++){
                if(board[i][j][h] == 0) return false;
            }
        }
    }
    return true;
}

void BFS(){

    while(!Q.empty()){

        int QS = Q.size();

        for(int Q_S =0; Q_S<QS; Q_S++){
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int f = Q.front().Y;
            Q.pop();

            for(int i  = 0 ; i < 6; i++)
                {
                    int nx = x +dx[i];
                    int ny = y +dy[i];
                    int nf = f +df[i];

                    if(nx >= 0 && ny>= 0 && nf>=0 && nx<N &&ny<M &&nf<H)
                    {
                        if(board[nx][ny][nf] == 0)
                        {
                            board[nx][ny][nf] = 1;
                            Q.push({{nx,ny},nf});
                        }
                    }
                }

                if(Q.size() == 0 && Check_Tomato_State() == true){
                    cout<< Answer <<endl; return ;
                }
                else if ( Q.size() == 0 && Check_Tomato_State() == false){
                    cout<< -1<< endl; return;
                }
        }
        Answer++;
    }
}

void Solution()
{
    if(Tomato_State == true){
        cout << 0 << endl;
        return ;
    }

    BFS();
}

void solve(){
    Initialize();
    Input();
    Solution(); 
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}