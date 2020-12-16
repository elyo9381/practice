#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
    pq에 y,x를 푸시하는 이유!
    : 종료 되는 시점부터 또다른 하나가 시작 될수있으니
    종료시점을 기준으로 해야한다.
    그리고 뒷날은 앞날보다 무조건 큰수이니 내림차순으로 (최대힙)으로
    진행하는것이다. 
*/

int main(){
    int n;
    cin >> n ;
    priority_queue<pair<int,int> > pq;
    for(int i = 0; i<n; i++){
        int sm,sd,em,ed;
        cin >> sm >> sd >> em >> ed;
        int x  = sm*100 + sd;
        int y = em *100 + ed;
        pq.push(y,x);
    }
    int ans = 1;
    int pos = pq.top().second; pq.pop();
    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        if(pos >= x) pos = max(pos,y);
        else {
            ans+=1; pos =y;
        }
    }

    cout << ans << endl;
}