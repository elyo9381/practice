
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define INF 987654321
#define hash 1000000007LL
typedef long long ll;
typedef pair<int,int> pii;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int n,t, dp[101][101];


int calDist(pii u, pii v){
    int x1 = u.first , y1 = u.second;
    int x2 = v.first , y2 = v.second;

    int dis = abs(x1 - x2)  + abs(y1-y2);
    return dis;
}


int floyd(vector<pii> &beer){

    fill(&dp[0][0],&dp[101][101],INF);
    for(int u = 0; u<n+2; u++){
        for(int v = 0; v<n+2; v++){
            if(u==v) continue;
            int dist = calDist(beer[u],beer[v]);
            if(dist <= 1000){
                dp[u][v] =1;
            }
        }
    }

    for(int k = 0; k<n+2; k++){
        for(int i = 0; i<n+2; i++){
            for(int j = 0;j<n+2; j++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
            }
        }
    }

    for(int i = 0; i<n+2; i++){
            for(int j = 0;j<n+2; j++){
                cout << dp[i][j] <<" ";
            }
            cout << '\n';
        }

    return dp[0][n+1];
}

int main(){

    cin >> t;

    while(t--){
        cin >> n;

        vector<pii> beer;
        for(int i = 0; i<n+2; i++){
            int x,y;
            cin >> x >>y;
            beer.push_back(pii(x,y));
        }
        int ans = floyd(beer);

        if(ans == INF) cout << "sad\n";
        else cout << "happy\n";
    }
}