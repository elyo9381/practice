#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second 


int board[52][52];
bool vis[52][52];


int n,m,t,k;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >>t;
    while(t--)
    {
     memset(board, 0, sizeof(board));
     memset(vis, false, sizeof(vis));

    // // for(int i = 0; i < n; i++) fill(dist[i],dist[i]+m,-1);
        cin >> n >> m >> k;

        for(int i=0; i<k; i++){
            int num1,num2;
            cin >> num1 >> num2;
            board[num1][num2] = 1;
        }

        int cnt = 0;

        for(int i =0; i<n;i++){
            for(int j= 0; j<m ;j++){

                if(vis[i][j] or board[i][j] ==0 )continue;

                queue<pair<int, int> > Q;
                cnt++;
                vis[i][j] = true;
                Q.push({i,j});

                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();

                    for(int dir = 0; dir<4; dir++){
                        int nx  = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];


                        if(nx < 0 or nx >=n or ny <0 or ny>=m) continue;
                        if(vis[nx][ny] or board[nx][ny] != 1)continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout<<cnt<<endl;   

    }

   
}