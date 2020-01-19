#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"
#define MX 30
using namespace std;

int T, N, cnt = 0, area = 0;
int board[MX][MX];
bool vis[MX][MX];
bool belong[MX];
string str;
vector<int> vc;

queue<pair<int,int>> Q;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(vis, false, sizeof(vis));

   cin >> T;

    for (int i = 0; i < T; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            int Temp = Inp[j] - '0';
            board[i][j] = Temp;
        }
    }

    cnt = 0;
    for(int i = 0 ; i< T; i++){
        for(int j =0; j<T ; j++){
            if(vis[i][j] || board[i][j] == 0) continue;

            vis[i][j] = 1;

            Q.push({i,j});


            area = 0;
            while(!Q.empty()){
                area++;
                
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();

                for(int dir = 0; dir<4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];


                if( nx >= 0 && ny >= 0 && nx<T && ny<T)
                {
                    if(!vis[nx][ny] && board[nx][ny] == 1)
                    {
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }

                }

            }
            vc.push_back(area);
            // cout<< area <<endl;

        }
    }

 printf("%d\n",vc.size());
 
      sort(vc.begin(), vc.end());
 
      for(int i=0;i<vc.size();i++)
      {
            printf("%d\n",vc[i]);
      }

    return 0;
}