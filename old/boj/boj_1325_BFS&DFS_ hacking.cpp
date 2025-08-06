#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> adj[10001]; 
int D[10001]; 
int mx = 0;
bool isVisited[10001];
int main(void) {
    cin >> N >> M;
        while (M--) {
		int a, b;
        cin >> a >> b;

		adj[b].push_back(a);
	}
	for (int st = 1; st <= N; st++) { 
        memset(isVisited, false, sizeof(isVisited));
		isVisited[st] = true;
		stack<int> S;
		S.push(st);
		int cnt = 1;
		while (!S.empty()) {
			int cur = S.top();
			S.pop();
			for ( int i = 0; i<adj[cur].size(); i++) 
            {
                int near = adj[cur][i];

				if (!isVisited[near]) {
					isVisited[near] = true;
					S.push(near);
					cnt++;
				}
			}
		}
		D[st] = cnt;
		mx = max(mx, cnt);
	}
	for (int i = 1; i <= N; i++) {
		if (D[i] == mx)
                cout << i<<" ";
	}
}






#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int n,m, mx, cnt ;

bool vis[MAXN];

vector<int> adj[MAXN];
vector<int> ans;

void bfs(int a)
{
    queue<int> q;
    q.push(a); 
    vis[a] = true;

    cnt =1;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

    for(int i = 0; i<adj[now].size(); i++)
    {
        int nx = adj[now][i];

        if(!vis[nx]){
            q.push(nx);
            vis[nx] = true;
            cnt++;
        }
    }
    }

    if(mx == cnt)
    {
        ans.push_back(a);
    }
    else if(mx < cnt)
    {
        ans.clear();
        ans.push_back(a);
        mx = cnt;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> n >> m;

    for(int i =0 ; i<m; i++)
    {
        int u,v;
        cin >> u >>v;
        adj[v].push_back(u);
    }

    for(int i = 1; i<=n; i++)
    {
        memset(vis, false, sizeof(vis));
        bfs(i);
    }

    for(int i = 0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return  0;


}