#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 51;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n, m ,result = 1e9, ans=0;

int board[MAX][MAX];
int ch[MAX][MAX];

vector<pii> virus;

queue<pii> q;


int bfs(queue<pii> q) {

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<= nx && nx <n && 0 <= ny && ny <n){
                if(board[nx][ny] != 1 && ch[nx][ny]  == -1){
                    ch[nx][ny] = ch[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    bool isClear = true;
    int max_Time = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ;j++){
            if(board[i][j] == 0){
                if(ch[i][j] == -1){
                    isClear =false;
                    break;
                }
                else {
                    max_Time = max(max_Time, ch[i][j]);
                }
            }
        }
    }
    // cout << max_Time << "\n";
    if(isClear) result = min(result,max_Time);
    return result;
}


int main(){

    cin >> n >> m;

        

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                virus.push_back(make_pair(i,j));
            } 
           
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //        cout << board[i][j];
    //     }
    //     cout << "\n";
    // }    
    vector<bool> binary;

    binary.resize(virus.size());

    fill(binary.end() - m, binary.end(), true);

    do
    {
        queue<pii> q;
        memset(ch,-1,sizeof(ch));
        for(int i = 0; i<virus.size(); i++){
            if(binary[i]){
                int x = virus[i].first;
                int y = virus[i].second;
                q.push(make_pair(x,y));
                ch[x][y] = 0;
            }
        }

        ans = bfs(q);

    } while (next_permutation(binary.begin(), binary.end()));
    
    if(ans == 1e9) cout << -1 <<endl;
    else  cout << ans << "\n";
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //        cout << ch[i][j] << "   " ;
    //     }
    //     cout << "\n";
    // }    



}



// #include<iostream>
// #include<queue>
// #include<vector>
// #include<cstring>
 
// #define endl "\n"
// #define MAX 50
// using namespace std;
 
// int N, M, Empty_Place, Answer = 987654321;
// int MAP[MAX][MAX];
// int Time[MAX][MAX];
// bool Select[10];
 
// vector<pair<int, int>> Virus;
 
// int dx[] = { 0, 0, 1, -1 };
// int dy[] = { 1, -1, 0, 0 };
 
// int Min(int A, int B) { if (A < B) return A; return B; }
 
// void Input()
// {
//     cin >> N >> M;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cin >> MAP[i][j];
//             if (MAP[i][j] == 0) Empty_Place++;
//             else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
//         }
//     }
// }
 
// void Spread_Virus(queue<pair<int, int>> Q)
// {
//     int Infect_Place = 0;
//     int Total_Time = 0;
//     while (Q.empty() == 0)
//     {
//         int x = Q.front().first;
//         int y = Q.front().second;
//         Q.pop();
 
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
 
//             if (nx >= 0 && ny >= 0 && nx < N && ny < N)
//             {
//                 if (MAP[nx][ny] != 1 && Time[nx][ny] == -1)
//                 {
//                     Time[nx][ny] = Time[x][y] + 1;
//                     if (MAP[nx][ny] == 0)
//                     {
//                         Infect_Place++;
//                         Total_Time = Time[nx][ny];
//                     }
//                     Q.push(make_pair(nx, ny));
//                 }
//             }
//         }
//     }
//     if (Infect_Place == Empty_Place)
//     {
//         Answer = Min(Answer, Total_Time);
//     }
// }
 
// void Select_Virus(int Idx, int Cnt)
// {
//     if (Cnt == M)
//     {
//         queue<pair<int, int>> Q;
//         memset(Time, -1, sizeof(Time));
//         for (int i = 0; i < Virus.size(); i++)
//         {
//             if (Select[i] == true)
//             {
//                 Q.push(make_pair(Virus[i].first, Virus[i].second));
//                 Time[Virus[i].first][Virus[i].second] = 0;
//             }
//         }
        
//         Spread_Virus(Q);
//         return;
//     }
 
//     for (int i = Idx; i < Virus.size(); i++)
//     {
//         if (Select[i] == true) continue;
//         Select[i] = true;
//         Select_Virus(i + 1, Cnt + 1);
//         Select[i] = false;
//     }
// }
 
// void Solution()
// {
//     Select_Virus(0, 0);
//     if (Answer == 987654321) cout << -1 << endl;
//     else cout << Answer << endl;
// }
 
// void Solve()
// {
//     Input();
//     Solution();
// }
 
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     freopen("Input.txt", "r", stdin);
//     Solve();
 
//     return 0;
// }

