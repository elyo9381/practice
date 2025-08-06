#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"
#define MX 26
using namespace std;

/*
string을 바로 받아오면 안되는이유
bfs할떄마다 칸을 세고 1이 들어갔다가 나온다.

그리고 배열로 하면 안되었던 이유
지도의 크기가 5<=T<=25 이므로 공간이 25*25이상 나올수없어서 
범위는 최대 26이 되어야 하고 
지도안의 단지의 갯수를 담는 범위 또한 넉넉하게 존재해야한다.
라인을 와리가리 치면서 단지가 존재할수있으므로 
최대 313개 정도는 보관할수있어야한다. 
그렇기 때문에 배열을 넉넉하게 잡아야 배열을 가지고 할수있다.
백터는 사이즈가 자동으로 늘어나기 때문에 갠춘한것이다.   
*/


int T, N, cnt = 0, area = 0;
string board[MX];
bool vis[MX][MX];
vector<int> vc;

queue<pair<int,int>> Q;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void BFS(int n){

}

void solution(){

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

        }
    }

    printf("%d\n",vc.size());
 
      sort(vc.begin(), vc.end());
 
      for(int i=0;i<vc.size();i++)
      {
            printf("%d\n",vc[i]);
      }


}

void Initialize(){
    memset(vis, false, sizeof(vis));
  
}

void Input(){

   cin >> T;

   for(int i=0; i<T; i++){
         string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            int Temp = Inp[j] - '0';
            board[i][j] = Temp;
        }

   }
}

void solve(){
    Input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// #include <bits/stdc++.h>
// #define X first
// #define Y second
// #define endl "\n"
// #define MX 30
// using namespace std;

// int T, N, cnt = 0, area = 0;
// int board[MX][MX];
// bool vis[MX][MX];
// int ret[314];

// queue<pair<int,int>> Q;

// int dx[4] = {-1,1,0,0};
// int dy[4] = {0,0,-1,1};



// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     memset(vis, false, sizeof(vis));
//      memset(ret, 0, sizeof(ret));

//    cin >> T;

//     for (int i = 0; i < T; i++)
//     {
//         string Inp;
//         cin >> Inp;
//         for (int j = 0; j < Inp.length(); j++)
//         {
//             int Temp = Inp[j] - '0';
//             board[i][j] = Temp;
//         }
//     }

//     cnt = 0;
//     for(int i = 0 ; i< T; i++){
//         for(int j =0; j<T ; j++){
//             if(vis[i][j] || board[i][j] == 0) continue;

//             vis[i][j] = 1;
            
//             Q.push({i,j});


//             area = 0;
//             while(!Q.empty()){
//                 area = area+1;
                
//                 int x = Q.front().first;
//                 int y = Q.front().second;
//                 Q.pop();

//                 for(int dir = 0; dir<4; dir++){
//                     int nx = x + dx[dir];
//                     int ny = y + dy[dir];


//                 if( nx >= 0 && ny >= 0 && nx<T && ny<T)
//                 {
//                     if(!vis[nx][ny] && board[nx][ny] == 1)
//                     {
//                         Q.push({nx,ny});
//                         vis[nx][ny] = 1;
//                     }
//                 }

//                 }

//             }
//             ret[cnt] = area;
//             cnt = cnt+1;
//             // cout<< area <<endl;

//         }
//     }

//     sort(ret,ret+cnt);
//     cout<<cnt<<endl;
//      for(int i=0; i<cnt; i++)
//         cout<< ret[i]<< endl;

//     return 0;
// }
