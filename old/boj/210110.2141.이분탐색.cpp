#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const int MAX = 100001;

int n;
vector<pair<ll,ll> > vec;

int func(ll x){
    ll r = 0, l = 0, now =0;
    for(int i = 0; i<n; i++){
        if(vec[i].first < x) l+=vec[i].second;
        else if(vec[i].first > x) r+=vec[i].second;
        else now = vec[i].second;
    }    
    if( l - r < now && r-l < now ) return 2;
    return (r <= l ? 1 : 0);
}
int main(){

    cin >> n;
    for(ll i = 0; i<n ;i++){
        ll home , num;
        cin >> home >> num;
        vec.push_back(make_pair(home,num));
    }

    sort(vec.begin(),vec.end());
    ll lv = vec[0].first, rv = vec[n-1].first;
    while(lv <= rv){
        ll mid = (lv + rv) / 2;
        if(func(mid) == 1) {
            rv = mid -1;
        }
        else if( func(mid) == 0){
            lv = mid +1;
        } 
        else {
            cout << mid << '\n';
            return 0;
        }
    }
    cout << rv << '\n';
}