#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 1001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;


/*
    bfs를 이용해서 풀었다 
    그래프로 연결하고 bfs 연결이 최대인 노드를 반환받는것이다. 
    그런데 init을 안해줘서 오래걸렸다 .
    모든 배열 백터 그래프 등을 초기화 하여야한다. 
*/

bool vis[MAXN];
int a, m, n, t,cnt = 0;
vector<int> adj[MAXN];
vector<int>  sum;


void bfs(int root)
{
    memset(vis, false, sizeof(vis));

    queue<int> q;
    q.push(root);
    vis[root] =true;
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0 ; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(vis[nxt]) continue;
            q.push(nxt);
            cnt++;
            vis[nxt] = true;
        }
    }
    sum.push_back(cnt);
}
 
int main() {

     cin >> t;


     while(t--){

        memset(vis, false, sizeof(vis));
        memset(adj, 0, sizeof(adj));
        cin >> n >> m;

        for(int i = 0; i<m; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1);
     }


     for(int i = 0; i<sum.size(); i++)
     {
        cout << sum[i] << endl;
     }
}
