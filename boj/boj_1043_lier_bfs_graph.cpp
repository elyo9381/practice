#include <bits/stdc++.h>
#define endl '\n'
#define MAX 20002
using namespace std;

#define pf1l(a) cout << a << '\n'
#define pf1(a) cout << a << ' '
#define sf1(a) cin >> a
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define sf2(a,b) cin >> a >> b

typedef long long ll;
typedef vector<int> vi;


/*
    지민이가 거짓말쟁이로 알려지지 않아야 하므로 
    진실을 알고있는 파티가 있으면 같은 파티에 들어있는 인원들도 진실을 알게된다. 
    그래서 
    같은파티인원들의 방문여부를 체크해야한다. 

     어떤 사람이 어떤 파티에서는 진실을 듣고, 
     또다른 파티에서는 과장된 이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다. 
     지민이는 이런 일을 모두 피해야 한다.

     백터로 그래프 만들때 백터에다가는 정점의 갯수 
     for문을 통해서 간선의 갯수만큼 그래프 그림
     
*/

vector<int> truth;
int N, M;
int conn[53][53];



int main(void){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int tmp;
    cin >> tmp;
    for(int i = 0; i<tmp; i++){
    int t;
    cin >> t;
    truth.push_back(t);
    }

    vector<int> party[53];
    for(int p = 0; p<M; p++){
        int num; 
        cin >> num;
            for(int i = 0; i<num; i++){
                int t;
                cin >> t;
                party[p].push_back(t);
            }
            for(int i = 0; i<num ; i++){
                for(int j =i+1; i<num; i++){
                    conn[party[p][i]][party[p][j]] = true;
                    conn[party[p][j]][party[p][i]] = true;
                    }
                }
    }

    queue<int> q;
    vector<int> isVisited(N+1,0);
        for( auto t : truth){
            q.push(t);
            isVisited[t] = 1;
            }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;  i< N+1; i++){
            if(conn[cur][i]){
            if(!isVisited[i]){
            isVisited[i] =1;
            q.push(i);
                    }
                }
            }
    }

    int cnt = 0;
    for(int i = 0; i<M; i++){
        bool isPossible = true;
        for(auto p : party[i])
            if(isVisited[p]) isPossible =false;
        cnt+= isPossible;
    }
    cout << cnt << ' ';
}




// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;

// const int MAX = 50 + 1;

// vector<int> relatedParties[MAX];
// bool revealed[MAX];
// bool participatedParty[MAX][MAX];
// bool revealedParty[MAX];

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N, M;
//     cin >> N >> M;

//     int truth;
//     cin >> truth;

//     for (int i = 0; i < truth; i++)
//     {
//         int idx;
//         cin >> idx;

//         revealed[idx]++;
//     }

//     queue<int> q;

//     for (int i = 0; i < M; i++)
//     {
//         int num;
//         cin >> num;

//         for (int j = 0; j < num; j++)
//         {
//             int idx;
//             cin >> idx;

//             participatedParty[i][idx] = true;

//             if (revealed[idx] && revealedParty[i] == false)
//             {
//                 revealedParty[i] = true;

//                 q.push(i);
//             }

//             for (int k = 0; k < i; k++)
//             {
//                 bool hasParticipated = participatedParty[k][idx];

//                 if (hasParticipated)
//                 {
//                     relatedParties[k].push_back(i);
//                     relatedParties[i].push_back(k);
//                 }
//             }
//         }
//     }

//     while (!q.empty())
//     {
//         int partyIdx = q.front();
//         q.pop();

//         for (int i = 0; i < relatedParties[partyIdx].size(); i++)
//         {
//             int party = relatedParties[partyIdx][i];

//             if (revealedParty[party] == false)
//             {
//                 revealedParty[party] = true;

//                 q.push(party);
//             }
//         }
//     }

//     int result = 0;

//     for (int i = 0; i < M; i++)
//     {
//         if (revealedParty[i] == false)
//         {
//             result++;
//         }
//     }

//     cout << result << "\n";

//     return 0;
// }




//koosaga code

#include <bits/stdc++.h>
using namespace std;

int n,m,t;
int adj[55][55], p[55];
vector<int> v[55];

int vis[55];

void dfs(int x){
    if(vis[x]) return;
    vis[x] = 1;
    for(int i=1; i<=n; i++) if(adj[x][i]) dfs(i);
}

int main(){
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0; i<t; i++) cin >> p[i];
    for(int i=0; i<t; i++){
        for(int j=0; j<i; j++){
            adj[p[i]][p[j]] = adj[p[j]][p[i]] = 1;
        }
    }
    for (int i=0; i<m; i++) {
        int q;
        cin >> q;
        v[i].resize(q);
        for(int j=0; j<q; j++){
            cin >> v[i][j];
            for(int k=0; k<j; k++){
                adj[v[i][j]][v[i][k]] = 1;
                adj[v[i][k]][v[i][j]] = 1;
            }
        }
    }
    dfs(p[0]);
    int cnt = 0;
    for(int i=0; i<m; i++){
        if(!vis[v[i][0]]) cnt++;
    }
    printf("%d",cnt);
}
