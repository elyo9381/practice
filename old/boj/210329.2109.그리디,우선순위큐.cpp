#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

/*
    조건
    d,p값은 서로 다르다
    d일안에와서 강연하면 p만큼 강연료 지불한다.
    가장 돈을 벌수있도록 순회강연 할것이다. 또한 하루한곳에서만 강연 가능하다

    최대로 벌수있는 돈은 ? 

    설계
    pair로 값을 동시에 넣고 각 날짜별 최대값을 반환한다. 
    우선순위큐를 활용하고 구현은 날짜가 높을때부터 비교하여 최대값 하는 선별한다. 


*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int n, ret = 0;
vector<pair<int,int>> v;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}

priority_queue<int> pq;

int main(){
    int day = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
        day = max(day,b);
    }

    sort(v.begin(), v.end(), compare);


    int ans = 0;
    int idx = 0;
    for(int i = day; i>=1; i--){
        while(idx < n && i <= v[idx].second){
            pq.push(v[idx++].first);
        }
        if(!pq.empty()){ // while이 아니니깐 하나만 인출...바보냐?? 
            ans +=pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
} 