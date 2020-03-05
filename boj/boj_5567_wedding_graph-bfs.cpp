

#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10002
typedef long long ll;
using namespace std;

/*
    결혼식 문제는 깊이를 이용해서 풀수 있다. 
    길이배열을 만들어서 루트와의 길이를 측정하고 
    루트의 친구의 친구까지만이므로 
    길이가 1, 2인 녀석들을 배열에서 체크하여주면 된다. 
*/



int v,e;
bool vis[MAXN];
int p[MAXN];
int cnt= 0;
int depth[MAXN];
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
            vis[nxt] = true;
            depth[nxt] = depth[cur]+1;      
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

    for(int i = 2; i <= v;i++){
       cout << depth[i] << ' ';
       if(depth[i] == 2 || depth[i] == 1){
        cnt++;
       }

    }

    cout<< '\n'<<cnt << endl;
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

    