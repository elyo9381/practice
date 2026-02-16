#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"
#define MX 100001
using namespace std;

/*
함수 실행순서를 우선 잘 맞춰야한다. 
DFS를 이용하여서 문제를 해결하였는데 
도움을 받았다.

문제해결을 하기위해서 사이클을 이용해야했고 이를 위해서 
DFS를 사용한다.
사이클과 방문여부 그리고 속한 여부를 알기위해서 
bool 배열 2개를 이용하여 방문여부와 속한 여부를 체크하여 풀어야한다.  */


int T, N, MemCount;
int arr[MX];
bool vis[MX];
bool belong[MX];


void DFS(int n){
    vis[n] = true;
    int next = arr[n];
    if(vis[next]){
        if(!belong[next]){
            for(int i = next; i != n ; i=arr[i]){
                MemCount++;
            }
            MemCount++;
        }
    }else{
        DFS(arr[n]);
    }

    belong[n] = true;
}

void solution(){

    cin >> N;

    for(int i = 1 ; i<=N; i++){
        cin >> arr[i];
    }

    for(int i =1 ; i <=N; i++){
        if(!vis[i]){
            DFS(i);
        }
    }

    cout<< N - MemCount << endl;
}

void Initialize(){
    memset(belong, false, sizeof(belong));
    memset(vis, false, sizeof(vis));
    MemCount = 0;
    return ;
}

void Input(){

    cin >> T;
    while(T--){
        Initialize();
        solution();
    }
}

void solve(){
    Input();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
