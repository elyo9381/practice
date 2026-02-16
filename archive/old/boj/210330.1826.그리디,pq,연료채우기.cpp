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
    1km 1L의 연료가 샌다. 다행히 곳곳에 주유소가 N개 있다. 
    최소한으로 멈춰야하는 횟수를 구해라

    설계 
    어디에서 안넣을지 정해야하는데 
    다른 표현으로하자면 p로 갈수있는곳에서 가장 많은 연료를 넣을수있는곳으로 가는것이다. 
    
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

int n,l,p;
vector<ii> v;
priority_queue<int> pq;

int main(){

    cin >> n;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    cin >> l >> p;

    sort(v.begin(),v.end());

    int i = 0, ans = 0;
    bool out = false;

    while(p < l){
        while(i < n && p >= v[i].first){
            pq.push(v[i].second);
            i++;
        }
        if(pq.empty()){
            out = true;
            break;
        }
        p += pq.top();
        pq.pop();
        ans++;
    }
    cout << (out ? -1 : ans);
    return 0;
}
