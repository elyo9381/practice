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
    N개의 보석, 보석의 무게 Mi와 가격 Vi를 가지고 있다 
    가방을 K개 가지고 있고 최대무게는 Ci이다. 가방에는 최대 한개의 보석만 넣을수 있다. 
    보석의 최대 가격을 구하라 

    설계 
    가방에는 한개만 넣을수있으므로 가격을 최대힙에 넣는다. 
    그리고 가방은 내림차순으로 정렬해 가방에 넣는다.
    실패..

    디버그
    접근은 맞았다. 그런데 보석을 가격기준 최대힙에 집어 넣었다. 
    이것을 통해서 다시 무게가 작은 순서로 최소힙을 만들었는데 두번 작업하니 복잡해지고 실패했다. 

    모두 배열로 받아서 객체들의 weight를 기준으로 정렬후 가방에 담긴다면 이때 최대힙에 넣어 최대값을 
    뽑아내는 접근을 했어야했다. 

    바보야 왜 구현을 못하냐... ㅠㅠ 

*/


const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

const int MAX = 300000;
const int INF = 987654321;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back

// struct Jewelry{
//     int weight;
//     int price;

//     Jewelry(int a, int b){
//         weight = a;
//         price = b;
//     }

//     bool operator<(const Jewelry &b) const{
//         if(price == b.price) return weight > b.weight; // 최소힙
//         return price < b.price; // 최대힙
//     }
// };


int n , k;



int main(){

    int sum = 0;
    cin >> n >> k ;

    priority_queue<int> pq;
    vector<ii> jewel;
    vector<int> bag(k);
    
    for(int i =0 ; i<n; i++){
        int a,b;
        cin >> a >> b;
        jewel.push_back({a,b});
    }

    for(int i = 0; i<k; i++){
        cin >> bag[i];
    }

    sort(jewel.begin(),jewel.end());
    sort(bag.begin(),bag.end());

    
    ll result = 0;
    int idx = 0;
    
    for(int i = 0; i< k; i++){
        while(idx < n && jewel[idx].first <= bag[i]){
            pq.push(jewel[idx++].second);
        }

        if(!pq.empty()){
            result +=pq.top();
            pq.pop();
        }
    }
    cout << result <<"\n";
    return 0;
}

