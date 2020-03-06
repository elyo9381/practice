
#include <bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define endl '\n'
#define MAXN 100001
#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

using namespace std;

/*
    a,b가 주어졌을때 a가 b 의 앞에 서야한다는 의미는
    a<-b 그래프의 의미이다. 
    정점 b가 정점 a에 들어가는 의미이고 이때 
    위상정렬을 이용하여 풀수있다. 

    위상정렬은 그래프로 받고 동시에 indeg[b]++;을 선언해서 
    배열입력을 받는다. 
    내보내는 간선이 있으면 indeg배열의 인덱스를 ++한다.
    그리고 indeg[i] == 0이면 모두 큐에 넣는다. 
    indeg를 하나식지우면고 indeg 0이되면 그정점을 큐에 추가한다. 
    위의내용 반복
    -사이클존재시 그냥 리턴 & 함수내부에서 결과 출력
*/

int n,m,j;
vector<int> adj[MAXN];
int indeg[32001];

void topo_sort(){
    queue<int> q;
    vector<int> result;
    for( int i =1; i <= n; i++)
        if(indeg[i] == 0) q.push(i);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        result.push_back(cur);
        for(int i = 0; i< adj[cur].size(); i++){
            int nxt = adj[cur][i];
            indeg[nxt]--;
            if(indeg[nxt] == 0) q.push(nxt);
        }
    }
    if(result.size() != n){
        cout << "cycle exists";
        return;
    }
    for( int i = 0; i<n; i++)
        cout << result[i]<<' ';
}


void Input()
{   
   cin >> n >> m;
   for(int i = 0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
   }

}


void Solution()
{  
    topo_sort();
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

