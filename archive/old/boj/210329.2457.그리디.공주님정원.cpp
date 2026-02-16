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
    4
    1 1 5 31
    1 1 6 30
    5 15 8 31
    6 10 12 10
    
    3.1 ~ 11.30일까지 꽃이 한가이 이상 피어있어야한다. 
    꽃은 최소갯수로만
    두 조건을 만족하는 꽃의 갯수는? 

    설계
    회의실과 같은 문제이다. 
    다만 조건이 들어있다.
    라인스위핑 문제이다. 

*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

int n, ret = 0;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}

int main(){

    int n;
    cin >> n;
    vector<ii> flower;
    for(int i = 0; i<n; i++){
        int a,b,c,d; cin >> a >>b >>c >>d;
        int start = 100*a + b;
        int end = 100*c + d;
        flower.pb({start,end});
    }

    sort(flower.begin(),flower.end());

    int endTime = 301;
    if(flower[0].first > endTime){
        cout << "0\n";
        return 0;
    }

    int i = 0;
    int cnt = 0;
    while(endTime <= 1130){
        int new_endTime = 0;
        for(; i<n ; i++){
            if(flower[i].first >= flower[i].second) continue;
            if(endTime >= flower[i].first){
                if(new_endTime < flower[i].second){
                    new_endTime = flower[i].second;
                }
            }
            else break;
        }
        if(new_endTime == 0){
            break;
        }
        else {
            endTime = new_endTime;
            cnt++;
        }
        
    }
    if(endTime > 1130) cout << cnt << '\n';
    else cout << "0\n";
    return 0;

}
