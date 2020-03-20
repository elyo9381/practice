
#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

// #define endl '\n'
#define MAXN 101
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;


/*

*/

int m,n,e,s;
bool vis[MAXN];
int ret[MAXN];
vector<int> adj[MAXN];

int bfs(int s)
{
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int cur = q.front(); q.pop();

        if( cur == e) return ret[cur];

        for(int i = 0; i<adj[cur].size(); i++)
        {
            int nxt =  adj[cur][i];
            if(ret[nxt] == 0)
            {                
                q.push(nxt);
                ret[nxt] = ret[cur] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s >> e;
    cin >> m;

    for(int i = 0; i< m; i++)
    {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<< bfs(s) << endl;
    return 0;
}
