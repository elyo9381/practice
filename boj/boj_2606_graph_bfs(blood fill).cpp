
#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
typedef long long ll;
using namespace std;

/*
    연결리스트를 이용한 그래프의 부모 구하는 방법은 
    parent배열을 놓은뒤에 DFS를 돌리는것이다.
    vis 배열을 통해서 방문여부를 체크하고 방문하였으면 
    연결되어있는 노드에 1-6 1-4가 연결되어있을때
    adj[1][0], adj[1][1]를 방문하고 배열안에 들어있는값을 p[nxt]에 cur이 부모가 된다. 

*/



int v,e;
bool vis[MAXN];
int p[MAXN];
int cnt= 0;
vector<int> adj[MAXN];



void dfs(int root){
    stack<int> s;
    s.push(root);
    vis[root] = true;
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        for(int i = 0 ; i<adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(vis[nxt]) continue;
                p[nxt] = cur;
                s.push(nxt);
                vis[nxt] = true;            
        }
    }
}


void bfs(int root){
    queue<int> q;
    q.push(root);
    vis[root] =true;
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
}

void Input()
{
    cin >> v;
    cin >> e;
    for(int i = 0; i<e; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    
    cout<< cnt << '\n';
}

void Solution()
{  

}

void Solve()
{
    Input();
    Solution();
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}

    