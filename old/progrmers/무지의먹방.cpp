#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
using ll = long long;

while(summary + ((-pq.top().first - previous) * length) <=k)
 -pq.top() -  previous하는 이유는 처음에 최소시간이 걸리는 음식을 먹을때
 회전판이 순회하므로 다른것도 부분적으로 먹게 된다. 
 그러므로 다음 음식을 다먹은걸 계산하기 위해서 
 이전에 먹었던것을 계산해줘야한다.

 그리고 length까지 long long 타입으로 하는이유는
 효율성 테스트 제한 사항이 food_times 원소가 1억개이고 
 비교하는 k의 수가 2*10^13최대 1천억*2정도 되므로 long long 형을 사용하는 것이다. 



*/

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    
    long long summary = 0;
    for(int i = 0; i< food_times.size(); i++){
        summary += food_times[i];
    }
    if(summary <= k) return -1;
    
    priority_queue<pair<int,int> > pq;
    for(int i = 0; i<food_times.size(); i++){
        pq.push({-food_times[i], i+1});
    }
    
    summary = 0;// 먹기위해 사용한 시간
    long long previous = 0; // 직전에 다 먹은 음식 시간
    long long length = food_times.size(); // 남은 음식의 개수
    
    while(summary + ((-pq.top().first - previous) * length) <=k){
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1;
        previous = now;
    }
    
    vector<pair<int,int> > result;
    while(!pq.empty()){
        int tmp = pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({tmp,num});
    }
    
    sort(result.begin(),result.end(),compare);
    return result[(k-summary) % length].second;
}