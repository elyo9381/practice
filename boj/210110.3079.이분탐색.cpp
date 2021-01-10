#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;
const int MAX = 100001;

ll n, m ;
vector<ll> arr;

bool count(ll mid){
    ll i, cnt = 0 , sum = 0;

    for(i = 0;i < arr.size(); i++){
        // if(mid / arr[i] == 0){
        //     sum++;
        // }
        sum += mid / arr[i];
    }

    return m<=sum;
}

int main(){
    cin >> n >> m;
    arr.resize(n,0);
    ll lv = 0, rv = 1e19 , mid = 0,res = 0 , maxx = 0;

    for(ll i = 0; i<n; i++){
        cin >> arr[i];
        // rv += arr[i];
    }

    while(lv<=rv){
        mid = ( lv + rv)/2;
        if( count(mid)){
            res = mid;
            rv = mid -1;
        } else {
            lv = mid+1;
        }
    }
    cout << res << '\n';
}