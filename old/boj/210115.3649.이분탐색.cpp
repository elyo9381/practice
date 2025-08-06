#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
typedef long long ll;
#define hash 1000000007LL;
using namespace std;
// const int MAX = 1000001;


ll x,n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> x){
    
    cin >> n;
    vector<ll> lego;
    lego.resize(n);

    x *= 1e7;
    for(int i = 0;i<n; i++){
        cin >> lego[i];
    }

    sort(lego.begin(), lego.end());

    bool f = false;
    for(int i = 0; i < n && lego[i] <= x/2; i++){
        ll cur = lego[i];
        ll lv = i+1, rv = n-1, mid = 0,ans;
        while(lv<=rv){
            mid = (lv+rv)/2;
            if (cur+lego[mid] == x){
                f = true;
                cout << "yes " << cur << " " << lego[mid] << '\n';
                break;
            } else if (cur + lego[mid] < x){
                lv = mid +1;
            } else {
                rv = mid - 1;
            }
        }

        if(f) break;

    }

    if(!f) cout << "danger" <<'\n';
    }
}

