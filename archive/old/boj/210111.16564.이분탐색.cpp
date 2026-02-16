#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
typedef unsigned long long ll;
using namespace std;
const int MAX = 100001;

#define hash 1000000007LL;

ll n, m ;
vector<ll> vec;

bool count(ll mid){
    ll i,cnt = 0;

    for(i = 0; i<vec.size(); i++){
        if(vec[i] < mid){
            cnt +=  mid - vec[i];
        }
    }

    return m>=cnt;
}


int main() {

    cin >> n >> m;
    vec.resize(n,0);

    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }

    ll lv = 0 , rv = 1e19 , mid = 0, res = 0;

    while(lv <= rv){
        mid = (lv+rv)/2;

        if(count(mid)){
            res = mid;
            lv = mid+1;
        } else {
            rv = mid -1;
        }
    }
    cout << res <<'\n';

}   