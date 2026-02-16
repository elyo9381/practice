
#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 4000
using namespace std;

// 연결요소란 vertex랑 edge가 사이클을 이루는 것을 말한다. 
// 단순그래프의 개수를 구하는 문제였다. 

int v,e;
vector<int> adj[1001];
bool vis[1001];


void Input()
{
    cin >> v >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int Solution()
{   
    int ret = 0;
    stack<int> s;
    for(int i =1; i<= v; i++){
        if(vis[i]) continue;
        ret++;
        s.push(i);
        vis[i] = true;
        while(!s.empty()){
            int cur = s.top();
            s.pop();
            for( int i =0 ; i<adj[cur].size(); i++){
                int nxt = adj[cur][i];
                if(vis[nxt]) continue;
                s.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    return ret;
}

void Solve()
{
    Input();
    cout<< Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}