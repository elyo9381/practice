#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring> //memset
typedef unsigned long long ll;
#define hash 1000000007LL;
using namespace std;
const int MAX = 100001;

int n, m, start, finish;
vector<pair<int, int> > graph[MAX];
bool visited[MAX];

bool BFS(int cost){

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int x = q.front(); // curFactory
        q.pop();

        if(x == finish){
            return true;
        }

        for(int i = 0; i<graph[x].size();i++){
            int NextFactory = graph[x][i].first;
            int NextCost = graph[x][i].second;

            if(!visited[NextFactory] && cost<=NextCost){
                visited[NextFactory] = true;
                q.push(NextFactory);
            }
        }
    }
    return false;
}

int main(){
    int maxx = 0;

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int f1,f2,cost; //Factory1, Factory2;
        cin >> f1 >> f2 >> cost;
        graph[f1].push_back(make_pair(f2,cost));
        graph[f2].push_back(make_pair(f1,cost));
        maxx = max(maxx,cost);
    }
    cin >> start >> finish;

    int lv = 0, rv = maxx , mid;
    while(lv <= rv){
        memset(visited,0,sizeof(visited));

        mid = (lv+rv)/2;
        if(BFS(mid)) lv = mid+1;
        else rv = mid-1;
    }
    cout << rv << '\n';
}