#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
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


int  n , l , r, cidx = 0;
int board[MAX][MAX];
int ch[MAX][MAX];


void bfs(int a,int b){

    vector<pii> united;
    united.push_back(make_pair(a,b));
    queue<pii> q;
    q.push(make_pair(a,b));
    ch[a][b] = cidx;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        
        for(int i = 0; i<4; i++){
            int nx = x +dx[i];
            int ny = y +dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || ch[nx][ny] != -1) continue;
            int gap = abs(board[x][y] - board[nx][ny]);
            if(l<=gap && gap <=r){
                united.push_back(make_pair(nx,ny));
                ch[nx][ny] = cidx;
                q.push(make_pair(nx,ny));
            }
        }   
    }

    int sum = 0;
    for(int i = 0; i<united.size(); i++){
        sum += board[united[i].first][united[i].second] ;
    }
    sum /=united.size();
    for(int i = 0; i<united.size(); i++){
        board[united[i].first][united[i].second] = sum;
    }
    return ;
}

int main(){

    int cnt = 0;
    cin >> n >> l >> r;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j<n ; j++){
            cin >> board[i][j];
        }
    }

    while(1){
        
        fill(&ch[0][0],&ch[MAX][MAX],-1);

        cidx = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(ch[i][j] == -1){
                    bfs(i,j);
                    cidx +=1;
                }
            }
        }

        if(cidx == n*n) break;
        cnt++;
    }

    cout << cnt <<"\n";

    
}