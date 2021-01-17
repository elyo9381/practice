#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

#define hash 1000000007LL;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 987654321;


int BFS(vector<int> *graph, int t){
    
    queue< pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(0,0),0));
    map<pair<int,int> ,bool> v;
    v[make_pair(0,0)] = true;
    int res = -1;

    while(!q.empty()){
        int y = q.front().first.first, x = q.front().first.second, cnt = q.front().second;
        q.pop();

        if(y == t){
            res = cnt; 
            break;
        }

        cnt++;
        for (int Y = y - 2; Y <= y + 2; Y++) {
            if (Y < 0 || Y > t) continue;
            int nextLowerX = lower_bound(graph[Y].begin(),graph[Y].end(),x-2)-graph[Y].begin();
            // cout <<"Y : "  << Y <<" y:  "<<y << " " << nextLowerX << "\n";
            int len = graph[Y].size();
            for(int j = nextLowerX ; j < len &&  graph[Y][j] <= x+2; j++){
                if(v[make_pair(Y,graph[Y][j])]) continue;
                v[make_pair(Y,graph[Y][j])]= true;
                q.push(make_pair(make_pair(Y, graph[Y][j]) ,cnt));
            }
        }
    }
    return res;
}

int main(){

    int n, t;
    scanf("%d %d", &n, &t);
    vector<int> graph[50000];
    for(int i = 0,a,b; i<n; i++){
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }

    for(int i = 0; i<=t; i++){
        sort(graph[i].begin(),graph[i].end());
    }

    printf("%d\n", BFS(graph,t));
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// const int MAX = 2e5 + 1;
// set<int> se[MAX];

// int main() {
// 	int N, T, X, Y;
// 	cin >> N >> T;
	
// 	for (int i = 0; i < N; i++) {
// 		cin >> X >> Y;
// 		se[Y].insert(X);
// 	}
// 	int ans = 0, flag = 0;
// 	queue<pii> q;
// 	q.push(make_pair(0,0));
// 	while (q.size()) {
// 		int t = q.size();
// 		while (t--) {
// 			auto X = q.front().first; 
//             auto Y = q.front().second;
//             q.pop();
// 			if (Y == T) {
// 				flag = 1; break;
// 			}

// 			for (int y = Y - 2; y <= Y + 2; y++) {
// 				if (y < 0 || y > T) continue;

// 				auto it = se[y].lower_bound(X - 2);
// 				auto end = se[y].upper_bound(X + 2);
//                 // cout << *it << " "<< *end << " y : "<< y <<'\n';
// 				while (it != end) {
// 					q.push(make_pair(*it,y ));
//                     // cout <<"*it : " << *se[y].erase(it)<< '\n';
// 					it = se[y].erase(it);
//                     // cout << *it << " : erase" <<'\n';
// 				}
// 			}
// 		}
// 		if (flag) break;
// 		ans++;
// 	}
// 	cout << (flag ? ans : -1);

// 	return 0;
// }