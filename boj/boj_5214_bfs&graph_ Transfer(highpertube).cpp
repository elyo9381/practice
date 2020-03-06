#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define endl '\n'
#define MAX 100001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    그래프에서 메모리가 제한적일고 양방향일때 서로 많은 edge가 존재한다면
    메모리를 절약하기 위해서 교차점(하이퍼튜브)를 두어서 메모리를 절약할수있다. 
    1,2,3이 서로 연결되어있다고 할때 교차점이 없다면 6가지 edge가 나오지만
    교차점이 존재한다면 3개의 edge가 나온다. 이를 통해서 더 간결하게 할수있고 
    교차점은 배열의 뒷부분에 더미노드에 해당하는 부분에 결속시켜 
    탐색시 특정 크기 이상 크다면 count 혹은 가중치를 두지 않는 방법으로 
    설정할수있다.
*/

int N,M,K;
int Cost[MAX+1000];
vector<int> Station[MAX + 1000];


void Input()
{   
   cin >> N >> K >> M;
   for(int i = 1; i<=M; i++){
        for(int j = 0; j < K; j++){
            int a;
            cin >> a;
            Station[a].push_back(i+N);
            Station[i+N].push_back(a);
        }
   }
}


// void dfs(int root){
//     stack<int> s;
//     s.push(root);
//     vis[root] = true;
//     while(!s.empty()){
//         int cur = s.top();
//         s.pop();
//         for(int i = 0 ; i<adj[cur].size(); i++){
//             int nxt = adj[cur][i];
//             if(vis[nxt]) continue;
//                 p[nxt] = cur;
//                 s.push(nxt);
//                 vis[nxt] = true;
//         }
//     }
// }


int bfs(int root){
    queue<int> q;
    q.push(root);
    Cost[root] =1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == N) return Cost[cur];

        for(int i = 0 ; i < Station[cur].size(); i++){
            int nxt = Station[cur][i];
            if(Cost[nxt]) continue;
            q.push(nxt);
            if(nxt > N) Cost[nxt] = Cost[cur];
            else Cost[nxt] = Cost[cur] +1;

        }
    }
    return -1;
}

void Solution()
{  
    int Answer = bfs(1);
    cout << Answer << endl;
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

