#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
    조건
    si에 시작해서 ti에 끝나는 N개의 수업이 있다.
    최소강의실을 사용해서 모든수업을 가능하게 해야한다. 

    강의실 갯수 출력

    설계
    ti 정렬하고 si보다 작으면 새로운 강의실을 사용한다. 
    초기 강의실의 pos를 기억하고 있으면 된다.
    그리고 ti의 인접한 배열값에서 si 가 작으면 같은 강의실 
    배열의 비교를 통해서 풀려고 했으나 : fail... 런타임에러 

    디버그 
    끝나는 시간을 확인하며 강의실을 체크하는것이 최적의 해 
    우선순위큐를 이용해서 끝나는 시간을 확인하자
*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int INF = 987654321;
typedef long long ll;

int main(){

    int n ,m ;
    cin >> n;

    vector<pair<int,int> > v;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    pq.push(v[0].second);

    for(int i = 1; i<n; i++){
        if( pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        } 
        else {
            pq.push(v[i].second);
        }
    }

    cout << pq.size() ;

}