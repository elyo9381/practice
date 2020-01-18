#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second 

const int MX =100001;

/* 숨바꼭질은 하나의 배열에서 이동하는 문제고 
한번간 곳은 다시 방문하면 안된다. 
*/
int dx[] = {-1,1};
bool vis[MX];
int N,K;
void bfs(int a){
        queue<pair<int,int> > Q;
        
        Q.push({a,0});
        vis[a] =true;

        while(!Q.empty()){

            int x = Q.front().first;
            int t = Q.front().second;
            Q.pop();

            if( x == K ){
                cout << t <<'\n';
                return;
            }

            for(int i=0; i<2 ; i++){
                int nx = x + dx[i];
                if(nx >= 0 && nx < MX){
                    if(vis[nx] == false){
                        Q.push({nx,t+1});
                        vis[nx] =true;
                    }
                }
            }

            if( x * 2< MX){
                if( vis[x*2] == false)
                {
                    Q.push({x*2,t+1});
                    vis[x*2] =true;
                }
            }
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs(N);

    return 0;

   
}