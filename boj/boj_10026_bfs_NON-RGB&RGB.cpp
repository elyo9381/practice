#include <bits/stdc++.h>

#define endl "\n"
#define MX 100
using namespace std;



int T,N;
char board[MX][MX];
bool visit[MX][MX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};



void Init()
{
    memset(visit, false, sizeof(visit));
}

void Input(){

    cin >> N;

    for(int i =0 ; i< N ; i++)
    {
        for(int j  =0  ;j < N ;j++){
            cin >> board[i][j];
        }
    }
    // for(int i = 0; i<N;i++){
    //     string str;
    //     cin >> str;
    //     for(int j = 0;j <N; j++){
    //         int tmp = str[i] -'0';
    //         board[i][j] = tmp;
    //     }
    // }
}

void BFS(int a, int b)
{ 
    queue<pair<int,int> > Q;

    Q.push({a,b});
    visit[a][b] = true;

    while(!Q.empty()){
        int x  = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int  i = 0 ; i <4; i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];

            if(nx >=0 && ny>= 0 && nx<N && ny<N)
            {
                if(!visit[nx][ny]){
                    if(board[nx][ny] == board[x][y]){

                    visit[nx][ny] =true;
                    Q.push({nx,ny});
                    }
                }
            }
        }
    }

}

void Solution(){

    int Answer, Answer2;

    Answer  = Answer2  =0 ;


    for(int  i= 0 ;  i< N ; i++){
        for(int  j = 0; j  < N ; j++){
            if(!visit[i][j]){
                BFS(i,j);
                Answer++;
            }
        }
    }

    Init();

    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 'G') board[i][j] ='R';
        }
    }



    for(int i = 0; i<N ; i++)
    {
        for( int j = 0 ; j < N; j++)
        {
            if(!visit[i][j]){
                BFS(i,j);
                Answer2++;
            }
        }
    }

    cout<< Answer << " " <<Answer2 <<endl;
}
   

void solve(){
    
  Input();
  Solution();
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    solve();

    return 0;
}